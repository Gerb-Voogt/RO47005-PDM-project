save_scenarios = false;

roadWidth = 5; % Width of the road
stepSize = 1; % Step size for motion primitives
roadLength = 300;
minObstDist = 10;
stepNumber = 100;
nScenarios = 10;
nCases = 6;
step_multiplier = 10;

v_0 = 50/3.6;
Ts = 0.05;
stepNumber = round(v_0 * Ts / stepSize);
stepSize = v_0 * Ts / stepNumber;
stepNumber = stepNumber * step_multiplier;

rng(9)
%% Vehicle MPC parameters (for spacing)
% 
scenarios = struct();
% for icase = 1:nCases
for icase = 1:6
    for i = 1:nScenarios
        % Define sinusoidal road centerline
        A = rand;
        B = rand;
        
        roadCenterlineX = linspace(0, 2*roadLength, 10000);

        switch icase
            case 1
                nObstacles = 0;
                roadCenterlineY = roadWidth / 2*ones(1,10000);
            case 2
                nObstacles = 0;
                roadCenterlineY = roadWidth / 2 + (A * 5 * sin(B * 0.05 * roadCenterlineX)); 
            case 3
                nObstacles = 1;
                roadCenterlineY = roadWidth / 2*ones(1,10000);
            case 4
                nObstacles = 1;
                roadCenterlineY = roadWidth / 2 + (A * 5 * sin(B * 0.05 * roadCenterlineX)); 
            case 5
                nObstacles = 5;
                roadCenterlineY = roadWidth / 2*ones(1,10000);
            case 6
                nObstacles = 5;
                roadCenterlineY = roadWidth / 2 + (A * 5 * sin(B * 0.05 * roadCenterlineX)); 
        end
        
        start = [roadCenterlineX(1), roadCenterlineY(1), 0]; % Start position [x, y, theta]
        goal = [roadCenterlineX(5000), roadCenterlineY(5000), 0]; % Goal position [x, y, theta]

       % Sinusoidal road % New curved road
        obstacles = defineObstaclesFixedSize(nObstacles,roadCenterlineX(1:round(end/2)),roadCenterlineY(1:round(end/2)),roadWidth,start(1:2),goal(1:2),minObstDist);
        figure;  hold on;
        plotEllipses(obstacles);
        plot(roadCenterlineX, roadCenterlineY, "Color", [0.5, 0.5, 0.5], "LineStyle", "--");
        plot(roadCenterlineX, roadCenterlineY+roadWidth, "Color", "k", "LineWidth", 1.5);
        plot(roadCenterlineX, roadCenterlineY-roadWidth, "Color", "k", "LineWidth", 1.5);
        xlim([0, 300]);
      
        % Calculate the cumulative distance along the road
        dx = diff(roadCenterlineX);
        dy = diff(roadCenterlineY);
        distances = sqrt(dx.^2 + dy.^2); % Euclidean distances between consecutive points
        cumulativeDistances = [0, cumsum(distances)]; % Cumulative distances starting at 0
        
        % Resample at equal intervals
        desiredSpacing = stepSize; % Desired spacing between points
        newCumulativeDistances = 0:desiredSpacing:cumulativeDistances(end); % New sampling points
        
        % Interpolate to find new centerline points
        resampledX = interp1(cumulativeDistances, roadCenterlineX, newCumulativeDistances);
        resampledY = interp1(cumulativeDistances, roadCenterlineY, newCumulativeDistances);
        resampledRoad = [resampledX(:), resampledY(:)];
        scenarios(icase,i).roadCenterline = resampledRoad;
        scenarios(icase,i).obstacles = obstacles;
    end
end

if save_scenarios
save('..\SETUP\TestPathFixed.mat','scenarios')
end

function obstacles = defineObstacles(n,roadCenterlineX,roadCenterlineY,roadWidth,start,goal,min_obst_dist)
    obstacles = zeros(n,5);
    min_bound = 0.1*roadWidth;
    max_bound = 0.5*roadWidth;
    n_el = 0;
    while n_el < n
        randomStatei = sampleRandomState(roadCenterlineX, roadCenterlineY, roadWidth);
        ai = min_bound + (max_bound-min_bound)*rand;
        bi = min_bound + (max_bound-min_bound)*rand;
        obstaclei = [randomStatei(1),randomStatei(2),ai,bi,randomStatei(3)];
        disti = minDistanceToEllipses(randomStatei(1:2), obstacles);
        if ~isPointInEllipse(start,obstaclei) && ~isPointInEllipse(goal,obstaclei) && disti>min_obst_dist 
            n_el = n_el + 1;
            obstacles(n_el,:) = obstaclei;
        end
        
    end
end

function obstacles = defineObstaclesFixedSize(n,roadCenterlineX, roadCenterlineY, roadWidth, start, goal, min_obst_dist)
    %% Round these up for clearance
    % Car => a = 4.7 m, b = 1.8 m
    % Truck => a = 13.9 m, b = 2.9 m
    % Pedestrian => a = 0.41 m, b = 0.41 m % Make pedestrians a circle
    % 1 = Car
    % 2 = Truck
    % 3 = Pedestrian
    % options = [1, 2, 3];
    car_width = 1.8; % [m]
    car_length = 4.7; % [m]
    truck_width = 2.5; % [m]
    truck_length = 8.2; % [m]
    pedestrian_width = 0.5; % [m]
    pedestrian_length = 0.5; % [m]

    margin = 1;

    % Car Dimensions
    obstacle_data(1).a = car_length/2 + margin;
    obstacle_data(1).b = car_width/2 + margin;

    % Truck Dimensions
    obstacle_data(2).a = truck_length/2 + margin;
    obstacle_data(2).b = truck_width/2 + margin;

    % Pedestrian Dimensions
    obstacle_data(3).a = pedestrian_length/2 + margin;
    obstacle_data(3).b = pedestrian_width/2 + margin;
    
    obstacles = zeros(n,5);
    n_el = 0;
    path.x = roadCenterlineX;
    path.y = roadCenterlineX;
    roadAngles = computeHeadingAnglesRoad(roadCenterlineX, roadCenterlineY);

    if n > 1
        %% Generate a single car at the edge of the road
        % Select a random index for a random location along the road
        random_idx = randi([round(1/4*length(roadCenterlineX)) round(3/4*length(roadCenterlineX))], 1);
        x = roadCenterlineX(random_idx);
        y = roadCenterlineY(random_idx) + roadWidth + car_width;
        theta = roadAngles(random_idx);
        n_el = n_el + 1;
        obstacles(n_el,:) = [x, y, obstacle_data(1).a, obstacle_data(1).b, theta];
    end


    while n_el < n
        % Select a random obstacle
        random_idx = randi([1 3], 1); % Generate a random integer from 1 to 3
        ai = obstacle_data(random_idx).a;
        bi = obstacle_data(random_idx).b;

        % Sample a random state, find the corresponding heading angle of the road 
        % at this point. Orient the obstacle such that it has the same heading as the road.
        randomStatei = sampleRandomState(roadCenterlineX, roadCenterlineY, roadWidth);
        roadHeadingAngleIdx = findClosestIndex(randomStatei(1), randomStatei(2), path);
        centerlineYCoordinate = roadCenterlineY(roadHeadingAngleIdx);
        roadHeadingAngle = roadAngles(roadHeadingAngleIdx);
        
        obstaclei = [randomStatei(1),randomStatei(2),ai,bi,roadHeadingAngle];
        disti = minDistanceToEllipses(randomStatei(1:2), obstacles);

        % If the obstacles overlap, generate a new one.
        % If the obstacles are too close to one another, we also generate a new one.
        if ~isPointInEllipse(start,obstaclei) && ~isPointInEllipse(goal,obstaclei) && disti > min_obst_dist && randomStatei(1) >= 30 && randomStatei(1) <= 230
            if n == 1
                if abs(obstaclei(2) - centerlineYCoordinate) <= bi
                    n_el = n_el + 1;
                    obstacles(n_el,:) = obstaclei;
                end
            else
                n_el = n_el + 1;
                obstacles(n_el,:) = obstaclei;
            end
        end
    end
end


function randomState = sampleRandomState(roadCenterlineX, roadCenterlineY, roadWidth)
    % Sample a random x-coordinate within the road length
    x = rand * max(roadCenterlineX);
    
    % Get the y-coordinate of the road centerline at the sampled x
    yCenter = interp1(roadCenterlineX, roadCenterlineY, x, 'linear', 'extrap');
    
    % Add a random offset within the road width
    y = yCenter + (rand - 0.5) * roadWidth;
    
    % Ensure theta (orientation) is uniformly sampled
    theta = rand * 2 * pi - pi;
    
    % Return the sampled state
    randomState = [x, y, theta];
end

function minDistance = minDistanceToEllipses(point, ellipseSet)
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


function theta = computeHeadingAnglesRoad(roadCenterlineX, roadCenterlineY)
    theta = diff(roadCenterlineY)./diff(roadCenterlineX);
end

function idx = findClosestIndex(curX, curY, path)
% findClosestIndex: returns the index in path.x,path.y that is closest to (curX, curY).
    dist_array = (path.x - curX).^2 + (path.y - curY).^2;
    [~, idx]   = min(dist_array);
end


function plotEllipses(obstacles)
    % PLOTELLIPSES Plots ellipses defined in the obstacles array.
    % Input:
    %   obstacles: A matrix where each row defines an ellipse with the format
    %              [x_center, y_center, semi_major, semi_minor, rotation_angle]
    
    for i = 1:size(obstacles, 1)
        % Extract ellipse parameters
        xCenter = obstacles(i, 1);
        yCenter = obstacles(i, 2);
        a = obstacles(i, 3); % Semi-major axis
        b = obstacles(i, 4); % Semi-minor axis
        theta = obstacles(i, 5); % Rotation angle in radians

        % Generate ellipse points
        t = linspace(0, 2*pi, 100); % Parameter for ellipse points
        x = a * cos(t); % X-coordinates in the ellipse frame
        y = b * sin(t); % Y-coordinates in the ellipse frame

        % Rotate and translate ellipse points
        R = [cos(theta), -sin(theta); sin(theta), cos(theta)]; % Rotation matrix
        ellipsePoints = R * [x; y]; % Apply rotation
        xWorld = ellipsePoints(1, :) + xCenter; % Translate x-coordinates
        yWorld = ellipsePoints(2, :) + yCenter; % Translate y-coordinates

        % Plot the ellipse
        fill(xWorld, yWorld, 'r', 'FaceAlpha', 0.5, 'EdgeColor', 'none'); % Transparent red ellipse
    end
end
