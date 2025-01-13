clear all; close all;

icase = 6;
j = 8;

data = load('../METRICS/metrics_data.mat');

jobstacles = data.scenarios(icase,j).obstacles;

path.x = data.scenarios(icase,j).roadOptimalReference(:,1);
path.y = data.scenarios(icase,j).roadOptimalReference(:,2);

ref_x = data.scenarios(icase,j).roadCenterline(:,1);
ref_y = data.scenarios(icase,j).roadCenterline(:,2);

x_sim = data.scenarios(icase,j).outputGlobalMPC(:,3);
y_sim = data.scenarios(icase,j).outputGlobalMPC(:,4);

figure(1+(j-1)*5); clf(1+(j-1)*5); hold on;
plot(x_sim(2,:), x_sim(3,:),'-o', 'DisplayName','Closed-loop (OpenVD)');
plot(path.x, path.y, 'r--', 'DisplayName','Reference');
roadWidth = 5;
plot(ref_x,ref_y,'g','DisplayName','Center line')
plot(ref_x,ref_y+roadWidth,'k--','DisplayName','Road')
plot(ref_x,ref_y-roadWidth,'k--')
% plot(path.x, path.y, 'r--', 'DisplayName','Reference');
if data.scenarios(icase,j).obstacles ~= 0
    plotEllipses(jobstacles)
end
% viscircles([Xobs, Yobs], R, 'Color','k');

xlabel('X [m]');ylabel('Y [m]');
title('Vehicle Trajectory vs. Reference for sim',j);
% legend; 
grid on;


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