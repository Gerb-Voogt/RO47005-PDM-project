function [v_ref, x_ref, y_ref] = reference_real_time(V_ref, t)
% REFERENCE_REAL_TIME Generates a straight-line reference position and speed at the current time.
%
% Inputs:
%   V_ref - Reference speed in m/s (scalar)
%   t     - Current simulation time in seconds (scalar)
%
% Outputs:
%   v_ref - Reference speed in m/s (scalar)
%   x_ref - Reference x position in meters (scalar)
%   y_ref - Reference y position in meters (scalar)

    % The vehicle moves along the x-axis at constant speed:
    x_ref = V_ref * t; 
    y_ref = 0;

    % The reference speed remains constant:
    v_ref = V_ref;

end
