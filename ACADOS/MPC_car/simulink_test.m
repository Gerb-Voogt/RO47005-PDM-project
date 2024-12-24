%% Simulink
%
clear all; clc; close all;

%% Run minimal example
% get default simulink_opts
simulink_opts = get_acados_simulink_opts;
car_PDM_ocp;

V_ref = 50/3.6;
lbx = reshape([zeros(1,N-1); repmat(-delta_thd,1,N-1)]       ,1,[]);
ubx = reshape([repmat(vx_thd,1,N-1); repmat(delta_thd,1,N-1)]     ,1,[]);
%% Compile Sfunctions
cd c_generated_code

make_sfun; % ocp solver
make_sfun_sim; % integrator

%% Copy Simulink example blocks into c_generated_code
source_folder = fullfile(pwd, '..');
target_folder = pwd;
copyfile( fullfile(source_folder, 'simulink_acados_vehicle_model.slx'), target_folder );

open_system(fullfile(target_folder, 'simulink_acados_vehicle_model'))

