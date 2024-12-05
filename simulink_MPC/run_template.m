% Dr. Barys Shyrokau
% Extended vehicle model for Group Project
% RO47017 Vehicle Dynamics & Control, 2024
% Use and distribution of this material outside the RO47017 course 
% only with the permission of the course coordinator

clc; clear all; close all;


% General
par.g = 9.81;
% Tire
par.Reff     = 0.3035;              % wheel effective radius, m
par.RL       = 0.294;               % wheel loaded radius, m
% Road
par.friction = 1.0;                 % friction coefficient, -
% Vehicle/Body (Camry)
par.mass     = 1380;                % vehicle mass, kg      
par.Ixx      = 649.1;               % body inertia around x-axis, kgm^2
par.Iyy      = 2415.6;              % body inertia around y-axis, kgm^2
par.Izz      = 2634.5;              % body inertia around z-axis, kgm^2
par.L        = 2.79;                % wheelbase, m
par.l_f      = 1.384;               % distance from front axle to CoG, m
par.hcg      = 0.609;               % height of vehicle CoG above road, m
par.hBf      = 0.788;               % half of front track width, m
par.hBr      = 0.782;               % half of rear track width, m
par.unm_f    = 71.5;                % front axle mass, kg       
par.unm_r    = 64.5;                % rear axle mass, kg    
par.hroll_f  = -0.05;               % front roll height, m             
par.hroll_r  = 0.12;                % rear roll height, m
par.hcg_r = par.hcg - par.hroll_f + (par.hroll_r - par.hroll_f)*par.l_f/par.L;
% Suspension
par.Kz_f     = 53690;               % front vertical stiffness, N/m     
par.Kz_r     = 64964;               % rear vertical stiffness, N/m  
par.Dz_f     = 2742;                % front vertical damping, Ns/m     
par.Dz_r     = 3018;                % rear vertical damping, Ns/m     
par.roll_gradient = 4.32 / 180*pi; %roll gradient deg/g
par.Kroll    = par.mass * par.g * par.hcg_r / par.roll_gradient; % total roll stiffness, N/rad    
par.Kroll_f  = 0.60*par.Kroll;          % front roll stiffness, N/rad    
par.Kroll_r  = par.Kroll - par.Kroll_f; % rear roll stiffness, N/rad  
par.Droll_f  = 4500;                % front roll damping, Ns/rad   
par.Droll_r  = 4500;                % rear roll damping, Ns/rad   
% Steering
par.i_steer  = 15.4;                % steering ratio, -
par.wn_ss    = 30;                  % natural frequency of steering system
par.zeta_ss = 0.7;                  % damping ratio of steering system
par.teta_ss  = 0.01;                % delay time of steering system                

% Additional
par.I        = diag([par.Ixx par.Iyy par.Izz]); % inertia matrix  
par.l_r      = par.L - par.l_f;                 % distance from rear axle to CoG, m
par.m_f      = par.mass * par.l_r / par.L;      % front sprung mass, kg
par.m_r      = par.mass * par.l_f / par.L;      % rear sprung mass, kg
par.length_f = par.m_f*par.g/par.Kz_f;          % front spring offset, m
par.length_r = par.m_r*par.g/par.Kz_r;          % rear spring offset, m

% Reference Generator (only for a fixed speed of 90 km/h)
par.Calpha_front = 120000; % Front axle cornering stiffness
par.Calpha_rear  = 190000; % Rear axle cornering stiffness
par.Kus = par.m_f/par.Calpha_front - par.m_r/par.Calpha_rear; % understeer gradient
% Dynamic response by the second-order transfer function parameters
par.wn      = 14.5;           % yaw frequency
par.kseta   = 0.6;            % yaw damping
par.tau     = 0.002;          % yaw delay

% Minimal speed
par.V0 = 50/3.6;                % initial speed, km/h
par.w0 = par.V0 / par.Reff;         % initial wheel angular velocity, rad/s


%% Add/ Change after this line
% Maneuver settings
V_ref = 60 /3.6;                % pre-maneuver speed, km/h
% V_ref = 100/3.6;                % pre-maneuver speed, km/h
