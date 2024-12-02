function [v_ref, x_ref, y_ref] = reference_real_time(V_ref,t)
% REFERENCE_REAL_TIME Generates the reference position and speed at current time
%
% Inputs:
%   t     - Current simulation time in seconds (scalar)
%
% Outputs:
%   v_ref - Reference speed in m/s (scalar)
%   x_ref - Reference x position in meters (scalar)
%   y_ref - Reference y position in meters (scalar)

    %% Parameters
    a_y_comf = 1.5;                 % Lateral acceleration (m/s^2)
    R = V_ref^2 / a_y_comf;         % Turn radius (m)
    delta_theta = pi/2;        % 90 degrees in radians
    L_turn = R * delta_theta;  % Arc length for the turn (m)
    L_straight = 100;          % Length of the straight segment before the turn (m)
    
    %% Time Calculations
    t_straight = L_straight / V_ref;   % Time to traverse the straight segment (s)
    t_turn = L_turn / V_ref;           % Time to traverse the turn (s)
    t_total = t_straight + t_turn;     % Total time for maneuver (s)
    
    %% Generate Reference Based on Current Time
    if t <= t_straight
        % Straight segment
        x_ref = V_ref * t;
        y_ref = 0;
    elseif t <= t_total
        % Circular turn
        t_turn_current = t - t_straight;
        theta = (V_ref * t_turn_current) / R;  % Current angle in radians
        
        % Clamp theta to not exceed delta_theta
        if theta > delta_theta
            theta = delta_theta;
        end
        
        % Position on the circular arc
        x_ref = L_straight + R * sin(theta);
        y_ref = R * (1 - cos(theta));
    else
        % After maneuver: maintain final position
        x_ref = L_straight + R * sin(delta_theta);
        y_ref = R * (1 - cos(delta_theta));
    end
    
    % Reference speed remains constant
    v_ref = V_ref;
end
