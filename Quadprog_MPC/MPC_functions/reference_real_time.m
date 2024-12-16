function [x_ref, y_ref, R, yaw_ref, psi_dot_des] = reference_real_time(V_ref, t)
% REFERENCE_REAL_TIME Generates a sinusoidal reference path and associated parameters.
%
% Inputs:
%   V_ref - Reference speed in m/s (scalar)
%   t     - Current simulation time in seconds (scalar)
%
% Outputs:
%   x_ref       - Reference x-coordinate at current time t (scalar)
%   y_ref       - Reference y-coordinate at current time t (scalar)
%   R           - Radius of curvature at (x_ref, y_ref) (scalar)
%   yaw_ref     - Yaw angle at (x_ref, y_ref) in radians (scalar)
%   psi_dot_des - Feedforward yaw rate vector over the prediction horizon (N_horizon x 1)

    % Simulation parameters
    Ts = 0.01;            % Sampling time in seconds
    N_horizon = 15;      % Prediction horizon steps
    
    % Sinusoidal path parameters
    A = 1.0;              % Amplitude of the sine wave in meters
    wavelength = 100.0;   % Wavelength in meters (distance for one full sine cycle)
    k_wave = 2 * pi / wavelength; % Wave number
    
    % Initialize current position
    x_current = V_ref * t;
    y_current = A * sin(k_wave * x_current);
    
    % First derivative (dy/dx) and second derivative (d²y/dx²)
    dy_dx_current = A * k_wave * cos(k_wave * x_current);
    d2y_dx2_current = -A * k_wave^2 * sin(k_wave * x_current);
    
    % Compute curvature (kappa) and radius of curvature (R)
    denominator = (1 + dy_dx_current^2)^(3/2);
    if denominator ~= 0
        curvature_current = abs(d2y_dx2_current) / denominator;
        R_current = 1 / curvature_current;
    else
        curvature_current = 0;
        R_current = Inf; % Straight line
    end
    
    % Compute yaw angle (psi_ref)
    yaw_ref_current = atan(dy_dx_current); % In radians
    
    % Compute x-component of velocity to maintain total speed V_ref
    Vx_current = V_ref / sqrt(1 + dy_dx_current^2);
    
    % Initialize feedforward yaw rate vector
    psi_dot_des = zeros(N_horizon, 1);
    
    % Preallocate variables for the prediction horizon
    x_ref_horizon = zeros(N_horizon, 1);
    y_ref_horizon = zeros(N_horizon, 1);
    R_horizon = zeros(N_horizon, 1);
    yaw_ref_horizon = zeros(N_horizon, 1);
    
    % Set initial values for the loop
    x_prev = x_current;
    dy_dx_prev = dy_dx_current;
    d2y_dx2_prev = d2y_dx2_current;
    Vx_prev = Vx_current;
    
    % Iterate over the prediction horizon to compute future references
    for k = 1:N_horizon
        % Predict next x position based on current velocity
        x_next = x_prev + Vx_prev * Ts;
        
        % Predict next y position using the sinusoidal path equation
        y_next = A * sin(k_wave * x_next);
        
        % Compute first and second derivatives at the next position
        dy_dx_next = A * k_wave * cos(k_wave * x_next);
        d2y_dx2_next = -A * k_wave^2 * sin(k_wave * x_next);
        
        % Compute curvature at the next position
        denominator_next = (1 + dy_dx_next^2)^(3/2);
        if denominator_next ~= 0
            curvature_next = abs(d2y_dx2_next) / denominator_next;
            R_next = 1 / curvature_next;
        else
            curvature_next = 0;
            R_next = Inf; % Straight line
        end
        
        % Compute yaw angle at the next position
        yaw_ref_next = atan(dy_dx_next); % In radians
        
        % Compute x-component of velocity to maintain total speed V_ref
        Vx_next = V_ref / sqrt(1 + dy_dx_next^2);
        
        % Compute feedforward yaw rate (psi_dot_des) for this step
        if curvature_next ~= 0
            psi_dot_des(k) = Vx_next * curvature_next; % Equivalent to Vx / R
        else
            psi_dot_des(k) = 0; % No yaw rate for straight segments
        end
        
        % Store horizon references (optional, can be used for visualization)
        x_ref_horizon(k) = x_next;
        y_ref_horizon(k) = y_next;
        R_horizon(k) = R_next;
        yaw_ref_horizon(k) = yaw_ref_next;
        
        % Update variables for the next iteration
        x_prev = x_next;
        dy_dx_prev = dy_dx_next;
        d2y_dx2_prev = d2y_dx2_next;
        Vx_prev = Vx_next;
    end
    
    % Assign outputs for the current time step
    x_ref = x_current;
    y_ref = y_current;
    R = R_current;
    yaw_ref = yaw_ref_current;
    % psi_dot_des contains the feedforward yaw rates for the prediction horizon
end


% function [x_ref, y_ref, R, yaw_ref, psi_dot_des] = reference_real_time(V_ref, t)
% % REFERENCE_REAL_TIME Generates a straight-line reference position and speed at the current time.
% %
% % Inputs:
% %   V_ref - Reference speed in m/s (scalar)
% %   t     - Current simulation time in seconds (scalar)
% %
% % Outputs:
% % x_ref, y_ref, R, yaw_ref, psi_dot_des
% 
%     Ts = 0.01;
%     N_horizon = 15;
% 
%     t_vec = 0:Ts:10;
%     x_ref_vec = V_ref*t_vec; 
%     y_ref_vec = 1*ones(size(t_vec));
%     R_vec = Inf(size(t_vec));
%     yaw_ref_vec = zeros(size(t_vec));
% 
%     x_ref = x_ref_vec(round(t/Ts)+1);
%     y_ref = y_ref_vec(round(t/Ts)+1);
%     R = R_vec(round(t/Ts)+1);
%     yaw_ref = yaw_ref_vec(round(t/Ts)+1);
%     psi_dot_des = zeros(N_horizon,1);
% end
