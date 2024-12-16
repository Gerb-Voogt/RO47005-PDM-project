clear
clc
% Add folder with startup functions
addpath("MPC_functions\")
addpath("9DoF\")

model_continuous = false;
veh_parameters;

% Initialize the sampling time
Ts = 0.01;

% Reference speed
V_ref = 50/3.6;
linearization_point = [0;0;0;0];

% Generate state space model
generate_state_space

% Define MPC parameters here (horizon and weights)
% You can easily change these without touching the MPC_controller.m
N_horizon = 15;           % Prediction horizon
Q_MPC = 1*eye(size(sysd.A,1)); % State weighting
R_MPC = 20;                   % Control input weighting
L_MPC = 5;                   % Rate of change weighting

ff = zeros(N_horizon,1);
x0 = linearization_point;

% Call the MPC setup script
MPC_controller

% Just to be sure
disp("Yes, I've calculated whatever you wanted...")
