clear
clc
% Add folder with startup functions
addpath("MPC_functions\")

model_continuous = false;

% Initialize the sampling time
Ts = 0.01;

% Reference speed
V_ref = 50/3.6;
linearization_point = [0;0;0;0;0];

% Generate state space model
generate_state_space

% Define MPC parameters here (horizon and weights)
% You can easily change these without touching the MPC_controller.m
N_horizon = 15;           % Prediction horizon
Q_MPC = eye(size(sysd.A,1)); % State weighting
R_MPC = 1;                   % Control input weighting
L_MPC = 0;                   % Rate of change weighting

x0 = linearization_point;

% Call the MPC setup script
MPC_controller

% Just to be sure
disp("Yes, I've calculated whatever you wanted...")
