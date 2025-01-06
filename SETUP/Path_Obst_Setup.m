save_scenarios = true;

roadWidth = 2; % Width of the road
stepSize = 1; % Step size for motion primitives
roadLength = 300;
minObstDist = 2;
stepNumber = 100;
nScenarios = 10;
nCases = 6;
step_multiplier = 10;
nObstmin = 4;
nObstmax = 10;

v_0 = 50/3.6;
Ts = 0.05;
stepNumber = round(v_0 * Ts / stepSize);
stepSize = v_0 * Ts / stepNumber;
stepNumber = stepNumber * step_multiplier;

%% Vehicle MPC parameters (for spacing)
% 
scenarios = struct();
for icase = 1:nCases
    for i = 1:nScenarios
        % Define sinusoidal road centerline
        A = rand;
        B = rand;
        
        roadCenterlineX = linspace(0, 2*roadLength, 10000);

        switch icase
            case 1
                nObstacles = 0;
                roadCenterlineY = zeros(1,10000);
            case 2
                nObstacles = 0;
                roadCenterlineY = roadWidth / 2 + (A * 5 * sin(B * 0.05 * roadCenterlineX)); 
            case 3
                nObstacles = 1;
                roadCenterlineY = zeros(1,10000);
            case 4
                nObstacles = 1;
                roadCenterlineY = roadWidth / 2 + (A * 5 * sin(B * 0.05 * roadCenterlineX)); 
            case 5
                nObstacles = randi([nObstmin,nObstmax]);
                roadCenterlineY = zeros(1,10000);
            case 6
                nObstacles = randi([nObstmin,nObstmax]);
                roadCenterlineY = roadWidth / 2 + (A * 5 * sin(B * 0.05 * roadCenterlineX)); 
        end
        
        start = [roadCenterlineX(1), roadCenterlineY(1), 0]; % Start position [x, y, theta]
        goal = [roadCenterlineX(5000), roadCenterlineY(5000), 0]; % Goal position [x, y, theta]

       % Sinusoidal road % New curved road
        obstacles = defineObstacles(nObstacles,roadCenterlineX,roadCenterlineY,roadWidth,start(1:2),goal(1:2),minObstDist);
      
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
save('TestPath.mat','scenarios')
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