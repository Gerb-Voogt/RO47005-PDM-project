%% ========================================================================
%  1) LOADING AND GENERIC SETUP
% ========================================================================
clear all; clc; %close all;
import casadi.*

% Check requirements for acados
check_acados_requirements()

% Load vehicle parameters
veh_parameters

%Load reference path
if exist('SimData.mat', 'file') == 2
    data = load('SimData.mat');
else
    data = load('../SETUP/TestPathFixed.mat');
end

load index
icase = index.icase;
j = index.j;

path.x = data.scenarios(icase,j).roadCenterline(:,1);
path.y = data.scenarios(icase,j).roadCenterline(:,2);
Yaw0 = atan((path.y(2)-path.y(1))/(path.x(2)-path.x(1)));

% Time and horizon settings
Ts   = 0.05;
N    = length(path.x);   % Prediction horizon
T    = N * Ts;           % Horizon length

% Create the simple car model for MPC
model = car_PDM_model(par);
nx    = length(model.x);
nu    = length(model.u);

% Initial condition for MPC states: [vx, Xp, Yp, vy, yaw, r, delta]
x0 = [par.V0; path.x(1); path.y(1); 0; Yaw0; 0; 0];
%% ========================================================================
%  2) ACADOS + OCP SETTINGS
% ========================================================================
ocp = AcadosOcp();
ocp.model = model;

% Cost Weights
w_vx     = 1e-3;
w_Xp     = 1e1;
w_Yp     = 1e1;
w_vy     = 0e-2;
w_yaw    = 0e-2;
w_r      = 0e-2;
w_delta  = 0e1;

w_d_delta= 1e1;
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
ocp.cost.W                = blkdiag(W_x, W_u);
ocp.model.cost_y_expr     = vertcat(model.x, model.u);
ocp.cost.yref             = [par.V0; zeros(ny-1,1)];

% Terminal cost
Xp_ref_terminal = par.V0 * Ts * N;
ocp.cost.cost_type_e      = 'NONLINEAR_LS';
ocp.model.cost_y_expr_e   = model.x;
ocp.cost.yref_e           = [par.V0; Xp_ref_terminal; 0; 0; 0; 0; 0];
ocp.cost.W_e              = 1 * W_x;

% Constraints
vx_thd      = 170 / 3.6;             % max vx [m/s]
beta_thd    = 5 * pi / 180;          % sideslip threshold [rad]
d_beta_thd  = 25 * pi / 180;         % sideslip angle rate threshold
d_vy_thd    = 0.85 * par.mu * par.g; % lateral accel threshold
delta_thd   = 2.67 * 360/180 * pi / par.i_steer;  % steering angle limit
d_delta_thd = 800 * pi/180 / par.i_steer;         % steering rate limit

% Simple Bounds on [vx, delta]
ocp.constraints.idxbx     = [0, 6];             % state indices [vx, delta]
ocp.constraints.lbx       = [0; -delta_thd];
ocp.constraints.ubx       = [vx_thd; delta_thd];

% Bounds on steering rate input: d_delta
ocp.constraints.idxbu     = [0,1];  % only one input
ocp.constraints.lbu       = [-d_delta_thd,-par.mass*par.g];
ocp.constraints.ubu       = [d_delta_thd,par.mass*par.g];

%% Obstacles
if data.scenarios(icase,j).obstacles ~= 0

    jobstacles = data.scenarios(icase,j).obstacles;
    
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
%  3) Path optimisation
% ========================================================================

% Set path references
for k = 1 : N-1
    yref_stage      = zeros(nx+nu, 1);
    yref_stage(1)   = par.V0;      
    yref_stage(2)   = path.x(k);
    yref_stage(3)   = path.y(k);

    ocp_solver.set('cost_y_ref', yref_stage, k);
end

% Terminal reference
yref_stage_e = [par.V0; path.x(N); path.y(N); 0; 0; 0; 0];
ocp_solver.set('cost_y_ref_e', yref_stage_e);

% Solve OCP
ocp_solver.solve();
status = ocp_solver.get('status');
if status ~= 0
    warning('acados OCP solver returned status %d, not successful!', status);
    ocp_solver.print('stat');
end

x_sim = ocp_solver.get('x');
solver_time = ocp_solver.get('time_tot');
solver_status = ocp_solver.get('status');

%% ========================================================================
%  4) PLOTTING
% ========================================================================
% t_sim       = 0 : Ts : (N * Ts);
% 
% figure(1); clf(1); hold on;
% plot(x_sim(2,:), x_sim(3,:), 'b-', 'DisplayName','Closed-loop (OpenVD)');
% plot(path.x, path.y, 'r--', 'DisplayName','Reference');
% % plot(path.x, path.y, 'r--', 'DisplayName','Reference');
% if data.scenarios(icase,j).obstacles ~= 0
%     plotEllipses(jobstacles)
% end
% % viscircles([Xobs, Yobs], R, 'Color','k');
% 
% xlabel('X [m]'); ylabel('Y [m]');
% title('Vehicle Trajectory vs. Reference for sim',j);
% legend; grid on;
% 
% figure(3); clf(3);
% plot(t_sim,x_sim(1,:))
% xlabel('Time [s]');
% ylabel('Velocity [m/s]');
% title('Velocity Over Time');
% grid on;
% 
