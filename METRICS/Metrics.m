dataFilePath = '../ACADOS/output_data.mat'; % Relative path to the .mat file
load(dataFilePath);
nCase = size(scenarios,1);
nScenarios = 4 ;%size(scenarios,2);
roadLength = 300;
%Ranging over all cases and scenarios
for icase = 4 %1:nCase
    for j = 1:nScenarios
        output = scenarios(icase,j).output_loc; % The different outputs for different controllers
        
        %Define the path in between 0 and roadlength and select x an y 
        endindex = find(output(3,:)>roadLength,1);
        route = output(3:4,1:endindex);%adjust to where t, x and y is in data
         
        %Calculating the clearances and collisions
        clearances = [];
        collision = 0;


        for ipoint = 1:length(route)
            
            [minDistance,nEllipse] = minDistanceToEllipses(point, scenarios(icase,j).obstacles);
            if isPointInEllipse(point,scenarios(icase,j).obstacles(nEllipse,:))
                collision = collision + 1;
                clearances(ipoint) = -minDistance;
            else
                clearances(ipoint) = minDistance;
            end
        end 

        path_length = 0;
        for ipoint = 2:length(route)
            point_old = route(:,ipoint-1);
            point_new = route(:,ipoint);
            dist = (sum((point_new-point_old).^2))^0.5;
            path_length = path_length + dist;
        end

        scenarios(icase,j).metrics.collisions = collision;
        scenarios(icase,j).metrics.clearances = clearances;
        scenarios(icase,j).metrics.time_to_goal = output(1,1:endindex);
        scenarios(icase,j).metrics.path_length = path_length;
        scenarios(icase,j).metrics.solver_time = output(10,1:endindex);
    end
end

save metrics_data scenarios



function isInside = isPointInEllipse(point, ellipse)
    % ISPOINTINELLIPSE Checks if a point is inside an ellipse.
    %
    % Inputs:
    %   point  - A 1x2 vector [x, y] representing the point.
    %   ellipse - A 1x5 vector [x_center, y_center, semi_major, semi_minor, rotation_angle]
    %             representing the ellipse parameters.
    %
    % Output:
    %   isInside - Boolean, true if the point is inside the ellipse, false otherwise.

    % Extract ellipse parameters
    xCenter = ellipse(1);
    yCenter = ellipse(2);
    a = ellipse(3); % Semi-major axis
    b = ellipse(4); % Semi-minor axis
    theta = ellipse(5); % Rotation angle in radians

    % Translate the point to the ellipse's center
    translatedPoint = point - [xCenter, yCenter];

    % Rotate the point to align with the ellipse's axes
    R = [cos(theta), sin(theta); -sin(theta), cos(theta)];
    rotatedPoint = R * translatedPoint';

    % Evaluate the point in the ellipse's normalized equation
    xNorm = rotatedPoint(1) / a;
    yNorm = rotatedPoint(2) / b;
    value = xNorm^2 + yNorm^2;

    % Check if the value is less than or equal to 1 (inside the ellipse)
    isInside = value <= 1;
end

function [minDistance,nEllipse] = minDistanceToEllipses(point, ellipseSet)
    % MINDISTANCETOELLIPSES Calculates the minimum distance from a point to a set of ellipses.
    %
    % Inputs:
    %   point      - A 1x2 vector [x, y] representing the point.
    %   ellipseSet - A Nx5 matrix, where each row represents an ellipse with the format
    %                [x_center, y_center, semi_major, semi_minor, rotation_angle].
    %
    % Output:
    %   minDistance - The smallest distance from the point to the set of ellipses.

    % Initialize the minimum distance to infinity
    minDistance = Inf;

    % Loop through each ellipse in the set
    for i = 1:size(ellipseSet, 1)
        % Extract the current ellipse
        ellipse = ellipseSet(i, :);

        % Calculate the distance from the point to the ellipse
        distance = pointToEllipseDistance(point, ellipse);

        % Update the minimum distance
        if distance < minDistance
            minDistance = distance;
            nEllipse = i;
        end
    end
end

function distance = pointToEllipseDistance(point, ellipse)
    % POINTTOELLIPSEDISTANCE Calculates the minimum distance from a point to an ellipse.
    %
    % Inputs:
    %   point   - A 1x2 vector [x, y] representing the point.
    %   ellipse - A 1x5 vector [x_center, y_center, semi_major, semi_minor, rotation_angle].
    %
    % Output:
    %   distance - The shortest distance from the point to the ellipse's perimeter.

    % Extract ellipse parameters
    xCenter = ellipse(1);
    yCenter = ellipse(2);
    a = ellipse(3);
    b = ellipse(4);
    theta = ellipse(5);

    % Translate and rotate the point into the ellipse's local coordinate frame
    translatedPoint = point - [xCenter, yCenter];
    R = [cos(theta), sin(theta); -sin(theta), cos(theta)];
    localPoint = R * translatedPoint';

    % Solve for the closest point on the ellipse numerically
    t = linspace(0, 2*pi, 360); % Fine sampling for the ellipse perimeter
    ellipseX = a * cos(t);
    ellipseY = b * sin(t);
    distances = sqrt((ellipseX - localPoint(1)).^2 + (ellipseY - localPoint(2)).^2);
    distance = min(distances); % Closest distance to the ellipse perimeter
end