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