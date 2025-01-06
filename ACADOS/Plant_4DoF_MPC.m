%% ========================================================================
%  1) LOADING AND GENERIC SETUP
% ========================================================================
clear all; clc; %close all;
import casadi.*

% Check requirements for acados
check_acados_requirements()

% Load vehicle parameters
veh_parameters

% Load scenario + case
load TestPath.mat
load index
icase = index.icase;
j = index.j;

path.x = scenarios(icase,j).roadCenterline(:,1);
path.y = scenarios(icase,j).roadCenterline(:,2);
Yaw0 = atan((path.y(2)-path.y(1))/(path.x(2)-path.x(1)));

% Time and horizon settings
Ts   = 0.05;
N    = 50;               % Prediction horizon
T    = N * Ts;           % Horizon length
resol = 500;             % Resolution for substeps
TSPAN = 0 : Ts/resol : Ts;

% Create the simple car model for MPC
model = car_PDM_model(par);
nx    = length(model.x);
nu    = length(model.u);

% Initial condition for MPC states: [vx, Xp, Yp, vy, yaw, r, delta]
x0 = [par.V0; path.x(1); path.y(1); 0; Yaw0; 0; 0];

% OpenVD model states: [X, Y, PSI, THETA, V, ALPHAT, dPSI, dTHETA]
x_adv0 = [path.x(1); path.y(1); Yaw0; 0; par.V0; 0; 0; 0];

%% ========================================================================
%  2) ACADOS + OCP SETTINGS
% ========================================================================
ocp = AcadosOcp();
ocp.model = model;

% Cost Weights
w_vx     = 1e-3;
w_Xp     = 1e1;
w_Yp     = 1e1;
w_vy     = 1e-3;
w_yaw    = 0e-2;
w_r      = 0e-2;
w_delta  = 1e1;

w_d_delta= 1e-1;
w_Fx = 1e-5;

W_x = diag([w_vx, w_Xp, w_Yp, w_vy, w_yaw, w_r, w_delta]);
W_u = diag([w_d_delta,w_Fx]);

% Cost function setup
ny      = nx + nu;
ny_e    = nx;

% Initial cost
ocp.cost.cost_type_0      = 'NONLINEAR_LS';
ocp.model.cost_y_expr_0   = vertcat(model.x, model.u);
ocp.cost.W_0              = blkdiag(W_x, W_u);
ocp.cost.yref_0           = [par.V0; zeros(ny-1,1)];

% Path cost
ocp.cost.cost_type        = 'NONLINEAR_LS';
ocp.cost.W               = blkdiag(W_x, W_u);
ocp.model.cost_y_expr    = vertcat(model.x, model.u);
ocp.cost.yref           = [par.V0; zeros(ny-1,1)];

% Terminal cost
Xp_ref_terminal = par.V0 * Ts * N;
ocp.cost.cost_type_e      = 'NONLINEAR_LS';
ocp.model.cost_y_expr_e   = model.x;
ocp.cost.yref_e           = [par.V0; Xp_ref_terminal; 0; 0; 0; 0; 0];
ocp.cost.W_e              = 5 * W_x;

% Constraints
vx_thd      = 170 / 3.6;             % max vx [m/s]
beta_thd    = 5 * pi / 180;          % sideslip threshold [rad]
d_beta_thd  = 25 * pi / 180;         % sideslip angle rate threshold
d_vy_thd    = 0.85 * par.mu * par.g; % lateral accel threshold
delta_thd   = 2.67 * 360/180 * pi / par.i_steer;  % steering angle limit
d_delta_thd = 800 * pi/180 / par.i_steer;         % steering rate limit

% Simple Bounds on [vx, delta]
ocp.constraints.idxbx    = [0, 6];             % state indices [vx, delta]
ocp.constraints.lbx       = [0; -delta_thd];
ocp.constraints.ubx       = [vx_thd; delta_thd];

% Bounds on steering rate input: d_delta
ocp.constraints.idxbu     = [0,1];  % only one input
ocp.constraints.lbu       = [-d_delta_thd,-par.mass*par.g];
ocp.constraints.ubu       = [d_delta_thd,par.mass*par.g];


%% Obstacles
% % Obstacle constraint
% Xobs = [20;21;30];    % Obstacle X
% Yobs = [5;5;5];  % Obstacle Y
% R    = 1;     % Min radius from obstacle
% theta = [0;0;0.2];
% a = [4.8;4.8;4.8]; % minor-axis
% b = [1.84;1.84;1.84]; % major-axis

if scenarios(icase,j).obstacles ~= 0

    jobstacles = scenarios(icase,j).obstacles;
    
    Xobs = jobstacles(:,1);
    Yobs = jobstacles(:,2);
    theta = jobstacles(:,5);
    a = jobstacles(:,3);
    b = jobstacles(:,4);

    n_obs = length(Xobs);
    
    x = model.x(2);
    y = model.x(3);
    
    % Translate point so that obstacle center is at origin
    dx = x - Xobs;
    dy = y - Yobs;
    
    % Rotate by theta to align ellipse with axes in its local frame
    cos_t = cos(theta);
    sin_t = sin(theta);
    
    x_rot =  dx.*cos_t + dy.*sin_t;
    y_rot =  dx.*sin_t - dy.*cos_t;
    
    % Ellipse constraint: h_obs >= 0 means "outside the ellipse"
    h_obs = (x_rot.^2)./(a.^2) + (y_rot.^2)./(b.^2) - 1;
    % h_obs = (model.x(2) - Xobs)^2 + (model.x(3) - Yobs)^2 - R^2;
    
    % Nonlinear constraints: h >= 0
    h = [h_obs];
    ocp.model.con_h_expr   = h;
    ocp.model.con_h_expr_0 = h;
    
    Inf_val = get_acados_infty();
    ocp.constraints.lh    = zeros(n_obs,1);
    ocp.constraints.uh    = ones(n_obs,1)*Inf_val;
    ocp.constraints.lh_0  = zeros(n_obs,1);
    ocp.constraints.uh_0  = ones(n_obs,1)*Inf_val;
    
    % Slack variables (soft constraints)
    ocp.constraints.idxsh    = 0:n_obs-1;
    ocp.constraints.idxsh_0  = 0:n_obs-1;
    ns                       = n_obs;
    slack_penalty            = 1e12;
    
    ocp.cost.Zl_0 = slack_penalty * ones(ns,1);
    ocp.cost.Zu_0 = slack_penalty * ones(ns,1);
    ocp.cost.zl_0 = zeros(ns,1);
    ocp.cost.zu_0 = zeros(ns,1);
    
    ocp.cost.Zl   = slack_penalty * ones(ns,1);
    ocp.cost.Zu   = slack_penalty * ones(ns,1);
    ocp.cost.zl   = zeros(ns,1);
    ocp.cost.zu   = zeros(ns,1);

end

% Set initial state constraint
ocp.constraints.x0 = x0;

% Initial cost
ocp.cost.cost_type_0      = 'NONLINEAR_LS';
ocp.model.cost_y_expr_0   = vertcat(model.x, model.u);
ocp.cost.W_0              = blkdiag(W_x, W_u);
ocp.cost.yref_0           = [par.V0; zeros(ny-1,1)];

% Path cost
ocp.cost.cost_type        = 'NONLINEAR_LS';
ocp.cost.W               = blkdiag(W_x, W_u);
ocp.model.cost_y_expr    = vertcat(model.x, model.u);
ocp.cost.yref           = [par.V0; zeros(ny-1,1)];

% Terminal cost
Xp_ref_terminal = par.V0 * Ts * N;
ocp.cost.cost_type_e      = 'NONLINEAR_LS';
ocp.model.cost_y_expr_e   = model.x;
ocp.cost.yref_e           = [par.V0; Xp_ref_terminal; 0; 0; 0; 0; 0];
ocp.cost.W_e              = 5 * W_x;

% Constraints
vx_thd      = 170 / 3.6;             % max vx [m/s]
beta_thd    = 5 * pi / 180;          % sideslip threshold [rad]
d_beta_thd  = 25 * pi / 180;         % sideslip angle rate threshold
d_vy_thd    = 0.85 * par.mu * par.g; % lateral accel threshold
delta_thd   = 2.67 * 360/180 * pi / par.i_steer;  % steering angle limit
d_delta_thd = 800 * pi/180 / par.i_steer;         % steering rate limit

% Simple Bounds on [vx, delta]
ocp.constraints.idxbx    = [0, 6];             % state indices [vx, delta]
ocp.constraints.lbx       = [0; -delta_thd];
ocp.constraints.ubx       = [vx_thd; delta_thd];

% Bounds on steering rate input: d_delta
ocp.constraints.idxbu     = [0,1];  % only one input
ocp.constraints.lbu       = [-d_delta_thd,-par.mass*par.g];
ocp.constraints.ubu       = [d_delta_thd,par.mass*par.g];

%% Acados solver options
ocp.solver_options.N_horizon          = N;
ocp.solver_options.tf                 = T;
ocp.solver_options.nlp_solver_type    = 'SQP';
ocp.solver_options.integrator_type    = 'ERK';
ocp.solver_options.qp_solver          = 'PARTIAL_CONDENSING_HPIPM';
ocp.solver_options.qp_solver_mu0      = 1e3;
ocp.solver_options.qp_solver_cond_N   = 5;
ocp.solver_options.hessian_approx     = 'GAUSS_NEWTON';
ocp.solver_options.ext_fun_compile_flags = '-O2';
ocp.solver_options.globalization      = 'MERIT_BACKTRACKING';

ocp.solver_options.regularize_method  = 'PROJECT';
ocp.solver_options.nlp_solver_max_iter= 500;
ocp.solver_options.nlp_solver_tol_stat= 1e-2;
ocp.solver_options.nlp_solver_tol_eq  = 1e-2;
ocp.solver_options.nlp_solver_tol_ineq= 1e-2;
ocp.solver_options.nlp_solver_tol_comp= 1e-2;
ocp.solver_options.qp_solver_warm_start= 2;

% Create the solver
ocp_solver = AcadosOcpSolver(ocp);

% Initial solver guesses
x_traj_init = repmat(x0,1,N+1);
u_traj_init = zeros(nu, N);

ocp_solver.set('constr_x0', x0);

% Allocate matrix for states
x_init = zeros(nx, N);

for k = 1 : N
    x_init(1,k) = par.V0;         % vx
    x_init(2,k) = path.x(k);      % Xp
    x_init(3,k) = path.y(k);      % Yp
    x_init(4,k) = 0.0;            % vy
    x_init(5,k) = 0.0;            % yaw
    x_init(6,k) = 0.0;            % r
    x_init(7,k) = 0.0;            % delta
end

% Now flatten or keep as (nx, N). The Acados OCP solver expects
% a single vector of dimension nx*N. We can reshape accordingly:
x_init = reshape(x_init, nx*N, 1);

ocp_solver.set('init_x', [x0;x_init]);


%% ========================================================================
%  3) OPENVD VEHICLE PLANT DEFINITION
% ========================================================================
import VehicleDynamicsLateral.*
vehicle_4dof   = VehicleSimpleNonlinear4DOF();
tire_model     = TirePacejka();
vehicle_4dof.tire = tire_model;
vehicle_4dof.muy  = 1;

% Basic vehicle parameters
vehicle_4dof.mT  = par.mass;
vehicle_4dof.a   = par.l_f;
vehicle_4dof.b   = par.l_r;
vehicle_4dof.H   = par.hcg;
vehicle_4dof.L   = (2*par.hBf + 2*par.hBr)/2;
vehicle_4dof.wT  = (2*par.hBf + 2*par.hBr)/2;
vehicle_4dof.lT  = par.L;

% Inertia properties
vehicle_4dof.IXX = par.Ixx;
vehicle_4dof.IYY = par.Iyy;
vehicle_4dof.IZZ = par.Izz;
vehicle_4dof.IT  = par.Izz;
vehicle_4dof.IXY = 0;
vehicle_4dof.IXZ = 0;
vehicle_4dof.IYZ = 0;

% Torsional stiffness/damping
vehicle_4dof.K   = par.Kroll;
vehicle_4dof.C   = par.Droll_f + par.Droll_r;

% Sprung mass
vehicle_4dof.mF0 = par.m_f;
vehicle_4dof.mR0 = par.m_r;


%% ========================================================================
%  4) SIMULATION
% ========================================================================
% Simulation length
N_sim       = length(path.x)-50;   % 10-second simulation
x_sim       = zeros(nx, N_sim+1);
x_sim(:,1)  = x0;
u_sim       = zeros(nu, N_sim);

% Store OpenVD states
X_adv_data  = zeros(8, N_sim+1);
X_adv_data(:,1) = x_adv0;
delta_data  = zeros(1, N_sim+1);
sol_time = zeros(1, N_sim);

fprintf("\nstarting scenario/simulation %d \n",j);
for i = 1 : N_sim
    
    tStart = tic;
    % Provide current state to MPC + warmup
    ocp_solver.set('constr_x0', x_sim(:,i));
    ocp_solver.set('init_x', reshape(ocp_solver.get('x'),1,[]));
    ocp_solver.set('init_u', reshape(ocp_solver.get('u'),1,[]));

    closest_idx = findClosestIndex(x_sim(2,i), x_sim(3,i), path);

    % Set path references
    for k = 0 : N-1
        ref_idx      = closest_idx + k;
        % Clamp if we exceed path length
        ref_idx      = min(ref_idx, length(path.x));

        yref_stage      = zeros(nx+nu, 1);
        yref_stage(1)   = par.V0;       % vx reference
        yref_stage(2)   = path.x(ref_idx);
        yref_stage(3)   = path.y(ref_idx);

        ocp_solver.set('cost_y_ref', yref_stage, k);
    end

    % Terminal reference
    ref_idx_e  = closest_idx + N;
    ref_idx_e  = min(ref_idx_e, length(path.x));
    yref_stage_e = [par.V0; path.x(ref_idx_e); path.y(ref_idx_e); 0; 0; 0; 0];
    ocp_solver.set('cost_y_ref_e', yref_stage_e);

    % Solve OCP
    ocp_solver.solve();
    status = ocp_solver.get('status');
    if status ~= 0
        ocp_solver.print('stat');
        warning('acados OCP solver returned status %d, at timestep %d, not successful!', status,i*Ts);
    end

    sol_time(i) = ocp_solver.get('time_tot');

    % Get new control (steering rate)
    u_sim(:, i) = ocp_solver.get('u', 0);
    d_delta = u_sim(1, i);
    Fx = u_sim(2, i);

    % Current steering angle
    delta_current = delta_data(i);

    % Compute final steering angle after Ts
    delta_new    = delta_current + d_delta * Ts;

    % Steering angle vs. time for [0, Ts]
    vehicle_4dof.deltaf = delta_current + d_delta * TSPAN;

    % Longitudinal force wheels
    vehicle_4dof.FXFRONTLEFT = Fx/2;
    vehicle_4dof.FXFRONTRIGHT = Fx/2;

    % Create local simulator
    sim_openvd = Simulator(vehicle_4dof, TSPAN);

    % Initialize simulator with OpenVD states
    x_adv_i = X_adv_data(:, i);
    sim_openvd.X0     = x_adv_i(1);
    sim_openvd.Y0     = x_adv_i(2);
    sim_openvd.PSI0   = x_adv_i(3);
    sim_openvd.THETA0 = x_adv_i(4);
    sim_openvd.V0     = x_adv_i(5);
    sim_openvd.ALPHAT0= x_adv_i(6);
    sim_openvd.dPSI0  = x_adv_i(7);
    sim_openvd.dTHETA0= x_adv_i(8);

    % Simulate one step
    sim_openvd.Simulate();

    % Extract final states
    X_final    = sim_openvd.XT(end);
    Y_final    = sim_openvd.YT(end);
    PSI_final  = sim_openvd.PSI(end);
    THETA_fin  = sim_openvd.THETA(end);
    VEL_final  = sim_openvd.VEL(end);
    ALPHAT_fin = sim_openvd.ALPHAT(end);
    dPSI_fin   = sim_openvd.dPSI(end);
    dTHETA_fin = sim_openvd.dTHETA(end);

    % Store updated states
    X_adv_data(:, i+1) = [X_final; Y_final; PSI_final; THETA_fin; ...
                          VEL_final; ALPHAT_fin; dPSI_fin; dTHETA_fin];
    delta_data(i+1)    = delta_new;

    % Map OpenVD states -> 7D MPC state
    vx    = VEL_final * cos(ALPHAT_fin);
    vy    = VEL_final * sin(ALPHAT_fin);
    yaw   = PSI_final;
    r     = dPSI_fin;
    deltaMPC = delta_new;

    x_sim(:, i+1) = [vx; X_final; Y_final; vy; yaw; r; deltaMPC];
end


%% ========================================================================
%  5) PLOTTING
% ========================================================================
t_sim       = 0 : Ts : (N_sim * Ts);

figure(1+(j-1)*5); clf(1+(j-1)*5); hold on;
plot(x_sim(2,:), x_sim(3,:),'-o', 'DisplayName','Closed-loop (OpenVD)');
plot(path.x, path.y, 'r--', 'DisplayName','Reference');
% plot(path.x, path.y, 'r--', 'DisplayName','Reference');
if scenarios(icase,j).obstacles ~= 0
    plotEllipses(jobstacles)
end
% viscircles([Xobs, Yobs], R, 'Color','k');

xlabel('X [m]');ylabel('Y [m]');
title('Vehicle Trajectory vs. Reference for sim',j);
legend; grid on;

% figure(2+(j-1)*5); clf(2+(j-1)*5); hold on;
% plot(t_sim, delta_data, 'LineWidth',2);
% xlabel('Time [s]');
% ylabel('Steering Angle [rad]');
% title('Steering Angle Over Time for sim',j);
% grid on;
% 
% figure(3+(j-1)*5); clf(3+(j-1)*5);
% plot(t_sim,x_sim(1,:))
% xlabel('Time [s]');
% ylabel('Velocity [m/s]');
% title('Velocity Over Time for sim',j);
% grid on;
% 
% figure(4+(j-1)*5); clf(4+(j-1)*5);
% plot(t_sim(1:N_sim),u_sim(2,:))
% xlabel('Time [s]');
% ylabel('Torque [N]');
% title('Torque Over Time for sim',j);
% grid on;

%% ========================================================================
%  HELPER FUNCTION
% ========================================================================
function idx = findClosestIndex(curX, curY, path)
% findClosestIndex: returns the index in path.x,path.y that is closest to (curX, curY).
    dist_array = (path.x - curX).^2 + (path.y - curY).^2;
    [~, idx]   = min(dist_array);
end

