clear all; clc;
import casadi.*

check_acados_requirements()

% options needed for Simulink
if ~exist('simulink_opts','var')
    disp('using acados simulink default options')
    simulink_opts = get_acados_simulink_opts;
    % disp('using empty simulink_opts to generate solver without simulink block')
    % simulink_opts = [];
end

%% Load parameters (par)
par.g = 9.81;          
% Vehicle/Body (Camry)
par.Reff     = 0.3035;              % wheel effective radius, m
par.mass     = 1380;                
par.Izz      = 2634.5;              
par.L        = 2.79;                
par.l_f      = 1.384;               
par.i_steer  = 15.4;                
par.l_r      = par.L - par.l_f;                   
par.Calpha_front = 120000; 
par.Calpha_rear  = 190000; 

par.V0 = 50/3.6;               
par.w0 = par.V0 / par.Reff;     

%% Horizon and sampling
Ts = 0.01;
N = 100; %20    % prediction horizon
T = N*Ts;  % horizon length
V0 = par.V0;

%% Create Model
[model, constraint] = car_PDM_model_vel(par);

nx = length(model.x);
nu = length(model.u);


% Initial condition
x0 = [0; 10; 50; 0; 0]; % v, Xp, Yp, yaw, delta
x_ref = [140;50;0;0;0];
u_ref = zeros(nu,1);

%% Create OCP model
ocp = AcadosOcp();
ocp.model = model;

%% Cost in nonlinear least squares form
% Weights

Qf= diag([0, 10, 10, 60, 0]);
R = diag([1e-1, 1e-2]);

yr = model.u - u_ref;
yr_e = model.x - x_ref;

expr_ext_cost = 0.5 * yr' * (R * yr);
expr_ext_cost_e = 0.5 * yr_e' * (Qf * yr_e);

% path cost term
ocp.cost.cost_type = 'AUTO';%'ext_cost';
ocp.model.cost_expr_ext_cost = expr_ext_cost;

% terminal cost term
ocp.cost.cost_type_e = 'AUTO';%'ext_cost';
ocp.model.cost_expr_ext_cost_e = expr_ext_cost_e;

%% Define constraints
mu = 1;

vx_thd      = 170 /3.6;           % absolute longitudinal velocity threshold (example)
beta_thd    = 5 * pi / 180;       % absolute sideslip angle threshold
d_beta_thd  = 25 * pi / 180;      % absolute sideslip angle rate threshold
d_vy_thd    = 0.85 * mu * par.g;  % absolute lateral acceleration threshold
delta_thd   = 2.67 * 360/180*pi/par.i_steer;  % max steering angle
d_delta_thd = 800 * pi/180/par.i_steer;       % max steering rate
 

% % Extract states/inputs
% x_sym = model.x;    % [vx; Xp; Yp; vy; yaw; r; delta]
% u_sym = model.u;     % [d_delta]
% f_sym = model.f_expl_expr; % [dvx; dXp; dYp; dvy; dyaw; dr; ddelta]
% 
% vx = x_sym(idx_vx);
% vy = x_sym(idx_vy);
% r  = x_sym(idx_r);
% delta = x_sym(idx_delta);
% d_delta = u_sym; 
% dot_vy = f_sym(4);  % from the model definition: f_expl = [dvx; dXp; dYp; dvy; dyaw; dr; ddelta]

% % Nonlinear constraints:
% % h = [vy/vx; dot(vy)/vx; dot(vy)+vx*r]
% h_expr = [vy/vx; dot_vy/vx; dot_vy + vx*r];
% ocp.model.con_h_expr = h_expr;
% ocp.constraints.lh = [-beta_thd; -d_beta_thd; -d_vy_thd];
% ocp.constraints.uh = [ beta_thd;  d_beta_thd;  d_vy_thd];
% 


% Bounds on delta (state)
% delta is state #7 (index_delta = 6)
% ocp.constraints.idxbx = [0 1 6];
% ocp.constraints.lbx = [0 -20 -delta_thd];
% ocp.constraints.ubx =  [vx_thd 114 delta_thd];
% lbx = reshape([zeros(1,N-1); repmat(-20,1,N-1); repmat(-delta_thd,1,N-1)]       ,1,[]);
% ubx = reshape([repmat(vx_thd,1,N-1); repmat(114,1,N-1); repmat(delta_thd,1,N-1)]     ,1,[]);

% ocp.constraints.idxbx = [0 6];
% ocp.constraints.lbx = [0 -delta_thd];
% ocp.constraints.ubx =  [vx_thd delta_thd];


% % Bounds on d_delta (input)
% ocp.constraints.idxbu = 0; % only one input: d_delta
% ocp.constraints.lbu = -d_delta_thd;
% ocp.constraints.ubu =  d_delta_thd;
% 
% % Assign the nonlinear constraint expression to the ocp model:
% ocp.model.con_h_expr = constraint;
% ocp.model.con_h_expr_0 = constraint;
% 
% % Set lower and upper bounds for h_expr, TODO: set uh to inf
% ocp.constraints.lh = 0;        % h_expr_obs must be >= 0
% ocp.constraints.uh = 1e9;      % a sufficiently large upper bound
% ocp.constraints.lh_0 = 0;        % h_expr_obs must be >= 0
% ocp.constraints.uh_0 = 1e9;      % a sufficiently large upper bound

ocp.constraints.x0 = x0;

%% Solver options
% define solver options
ocp.solver_options.N_horizon = N;
ocp.solver_options.tf = T;
ocp.solver_options.nlp_solver_type = 'SQP';
ocp.solver_options.integrator_type = 'ERK';
ocp.solver_options.qp_solver = 'PARTIAL_CONDENSING_HPIPM';
ocp.solver_options.qp_solver_mu0 = 1e3;
ocp.solver_options.qp_solver_cond_N = 5;
ocp.solver_options.hessian_approx = 'GAUSS_NEWTON';
ocp.solver_options.ext_fun_compile_flags = '-O2';
ocp.solver_options.globalization = 'MERIT_BACKTRACKING';
% ocp.solver_options.qp_solver_iter_max = 100
ocp.simulink_opts = simulink_opts;

ocp.solver_options.regularize_method = 'PROJECT_REDUC_HESS';
ocp.solver_options.nlp_solver_max_iter = 500;
ocp.solver_options.nlp_solver_tol_stat = 1e-2;
ocp.solver_options.nlp_solver_tol_eq = 1e-2;
ocp.solver_options.nlp_solver_tol_ineq = 1e-2;
ocp.solver_options.nlp_solver_tol_comp = 1e-2;
ocp.solver_options.qp_solver_warm_start = 1;

ocp_solver = AcadosOcpSolver(ocp);

% solver initial guess
x_traj_init = repmat(x0,1,N+1);%[x0,zeros(nx, N)]; %zeros(nx, N+1); %[x0;zeros(nx, N)];
u_traj_init = zeros(nu, N);

target1_delta = deg2rad(25);
target2_delta = deg2rad(-25);

% x1 = [x0(1) zeros(1,N)]
% x2 = [x0(2) (x0(2):(70-x0(1))/(N/2):70) (70:(x_ref(1)-70)/(N/2):x_ref(1))]
% x3 = [x0(3) (x0(3):(60-x0(2))/(N/2-1):60) (60:(x_ref(2)-60)/(N/2-1):x_ref(2))]
% x4 = [x0(4), (linspace(x0(3), target1_delta, ceil(N/3))), (linspace(target1_delta, target2_delta, ceil(N/3))), (linspace(target2_delta, x_ref(3), floor(N/3)))]
% x5 = []
% 
% xi=[...
%     x0(1) zeros(1,N) ;...
%     x0(2) (x0(2):(70-x0(1))/(N/2):70) (70:(x_ref(1)-70)/(N/2):x_ref(1)) ;...
%     x0(3) (x0(3):(60-x0(2))/(N/2):60) (60:(x_ref(2)-60)/(N/2):x_ref(2)) ;...
%     x0(4), (linspace(x0(3), target1_delta, ceil(N/3))), (linspace(target1_delta, target2_delta, ceil(N/3))), (linspace(target2_delta, x_ref(3), floor(N/3))) ;...
%     x0(5) zeros(1,N);...
%    ];


xi=[...
    x0(1) zeros(1,N);...
    x0(2) (x0(2):(70-x0(2))/(N/2-1):70) (70:(x_ref(2)-70)/(N/2-1):x_ref(2)) ;...
    x0(3) (x0(3):(60-x0(3))/(N/2-1):60) (60:(x_ref(3)-60)/(N/2-1):x_ref(3)) ;...
    x0(4), (linspace(x0(4), target1_delta, ceil(N/3))), (linspace(target1_delta, target2_delta, ceil(N/3))), (linspace(target2_delta, x_ref(4), floor(N/3))) ;...
    x0(5) zeros(1,N);...
   ];

ocp_solver.set('constr_x0', x0);

% set trajectory initialization
ocp_solver.set('init_x', x_traj_init); % states
ocp_solver.set('init_u', u_traj_init); % inputs
ocp_solver.set('init_pi', zeros(nx, N)); % multipliers for dynamics equality constraints

% change values for specific shooting node using:
%   ocp_solver.set('field', value, optional: stage_index)

% solve
ocp_solver.solve();
% get solution
utraj = ocp_solver.get('u');
xtraj = ocp_solver.get('x');

status = ocp_solver.get('status'); % 0 - success
ocp_solver.print('stat')

%% plots
figure(1),
subplot(2,1,1)
plot(xtraj(2,:),xtraj(3,:),'Linewidth',1); legend('Cartesian Coord'), ylabel('m'); xlabel('m');
hold on , grid on
subplot(2,1,2)
plot([1:N+1],rad2deg(xtraj(4,:)),'Linewidth',1);legend('Heading'), ylabel('deg');
hold on , grid on

figure
plot(xtraj(2,:));
grid on

figure
plot(xtraj(3,:));
grid on
