clear all; close all; clc

check_acados_requirements()
import casadi.*

%% system dimensions
nx = 5;
nu = 2;
ny = nu+nx; % number of outputs in lagrange term
ny_e = nx;  % number of outputs in mayer term

%% discretization
N = 500;     % Prediction Horizon
Ts = .25;    % sampling time [s]
T = N*Ts;    % time horizon length
L = 2.57;    % [m] vehicle wheelbase 

%% named symbolic variables 
x = SX.sym('x');         % x cartesian position  [m]
y = SX.sym('y');         % y cartesian position  [m]
psi = SX.sym('psi');     % hading angle          [rad]
v = SX.sym('v');         % vehicle speed         [m/s]
a = SX.sym('a');         % vehicle acceleration        [m/s]
delta = SX.sym('delta');        % steer wheel angle    [rad]
d_delta = SX.sym('d_delta');    % steer wheel speed    [rad/s]

%% (unnamed) symbolic variables
sym_x = vertcat(x, y, psi,v,delta);
sym_xdot = SX.sym('xdot', nx, 1);
sym_u = vertcat(a,d_delta);

%% dynamics
expr_phi = vertcat(...
            v*cos(psi),...
            v*sin(psi),...
            v/L*tan(Ts*delta),...
            a,...
            d_delta);

%% cost
cost_t   = 'ext_cost';
x0 = [10; 50; 0; 0 ; 0];
x_ref = [140;50;deg2rad(0); 0; 0];
u_ref = zeros(nu, 1);

Qf= diag([10, 10, 60, 0 , 0]);
R = diag([1e-1, 1e-2]);

yr = sym_u - u_ref;
yr_e = sym_x - x_ref;

expr_ext_cost = 0.5 * yr' * (R * yr);
expr_ext_cost_e = 0.5 * yr_e' * (Qf * yr_e);

%% constraints
Jbx_0 = eye(nx) ;
lbx_0 = x0 ;
ubx_0 = x0 ;

Jbx = [ 1 0 0 0 0; 0 1 0 0 0; 0 0 0 1 0; 0 0 0 0 1];  
lbx = [  0;   0; - 15/3.6; -deg2rad(30)] ;             
ubx = [150; 100;   15/3.6;  deg2rad(30)] ; 

Jbx_e = [0 0 0 1 0; 0 0 0 0 1];
lbx_e = [0;0];
ubx_e = [0;0];

Jbu = eye(nu);
lbu = [- 1 ; -deg2rad(30)];
ubu = [  1 ;  deg2rad(30)];

%% Circle Obstacle
h = [...
     (x-70)^2+(y-55)^2-5^2;...
     (x-70)^4+(y-50)^4-5^4;...
     (x-70)^2+(y-45)^2-5^2;
     ];
lh=[...
    0;...
    0;...
    0;...
];

h = (x-70)^2+(y-55)^2-5^2;
lh = 0;
uh=10000*ones(size(h,1),1);

h_e  = h;
lh_e = lh;
uh_e = uh;

%% acados ocp model
ocp_model = acados_ocp_model();
name = 'PathPlanning';
ocp_model.set('name', name);
ocp_model.set('T', T);

% === symbolics ===
ocp_model.set('sym_x', sym_x);
ocp_model.set('sym_u', sym_u);
% ocp_model.set('sym_p', sym_p);
%ocp_model.set('sym_xdot', sym_xdot);

% ===   cost   === 
ocp_model.set('cost_type',cost_t); %'linear_ls', 'ext_cost'
ocp_model.set('cost_type_e',cost_t);
ocp_model.set('cost_expr_ext_cost', expr_ext_cost );
ocp_model.set('cost_expr_ext_cost_e', expr_ext_cost_e );

% === dynamics === 
ocp_model.set('dyn_type', 'discrete');
ocp_model.set('dyn_expr_phi', expr_phi);

% === constraints === 
if exist('Jbx_0','var')
    ocp_model.set('constr_Jbx_0', Jbx_0);
    ocp_model.set('constr_lbx_0', lbx_0);
    ocp_model.set('constr_ubx_0', ubx_0);
end

if exist('Jbx','var')
    ocp_model.set('constr_Jbx', Jbx);
    ocp_model.set('constr_lbx', lbx);
    ocp_model.set('constr_ubx', ubx);
end

if exist('Jbu','var')
    ocp_model.set('constr_Jbu', Jbu);
    ocp_model.set('constr_lbu', lbu);
    ocp_model.set('constr_ubu', ubu);
end

if exist('C_m','var')
    ocp_model.set('constr_C', C_m);
    ocp_model.set('constr_D', D_m);
    ocp_model.set('constr_lg', lg);
    ocp_model.set('constr_ug', ug);
end

if exist('h','var')
    ocp_model.set('constr_expr_h', h);
    ocp_model.set('constr_lh', lh);
    ocp_model.set('constr_uh', uh);
end

if exist('Jbx_e','var')
    ocp_model.set('constr_Jbx_e', Jbx_e);
    ocp_model.set('constr_lbx_e', lbx_e);
    ocp_model.set('constr_ubx_e', ubx_e);
end

if exist('C_m_e','var')
    ocp_model.set('constr_C_e', C_m_e);
    ocp_model.set('constr_lg_e', lg_e);
    ocp_model.set('constr_ug_e', ug_e);
end

if exist('h_e','var')
    ocp_model.set('constr_expr_h_e', h);
    ocp_model.set('constr_lh_e', lh);
    ocp_model.set('constr_uh_e', uh);
end


%% acados ocp set opts
compile_interface = 'true'; %'auto';
codgen_model = 'true';

ocp_opts = acados_ocp_opts();
% ocp_opts.set('compile_interface', compile_interface);
% ocp_opts.set('codgen_model', codgen_model);
ocp_opts.set('param_scheme_N', N);      % uniform grid: number of shooting nodes (int>1)

ocp_opts.set('nlp_solver', 'sqp');         % sqp, sqp_rti
%ocp_opts.set('nlp_solver_exact_hessian', nlp_solver_exact_hessian); %'true', 'false'
ocp_opts.set('regularize_method', 'project_reduc_hess'); %'no_regularize','project','project_reduc_hess','mirror','convexify';
%ocp_opts.set('nlp_solver_ext_qp_res', nlp_solver_ext_qp_res); %0 (int)
ocp_opts.set('nlp_solver_max_iter', 500);   %100
ocp_opts.set('nlp_solver_tol_stat', 1e-2); %1e-6
ocp_opts.set('nlp_solver_tol_eq',   1e-2); %1e-6
ocp_opts.set('nlp_solver_tol_ineq', 1e-2); %1e-6
ocp_opts.set('nlp_solver_tol_comp', 1e-2); %1e-6

ocp_opts.set('qp_solver', 'partial_condensing_hpipm'); % 'full_condensing_hpipm', 'partial_condensing_hpipm', 'full_condensing_qpoases'
ocp_opts.set('qp_solver_cond_N', 5);                   % for partial condensing
%ocp_opts.set('qp_solver_cond_ric_alg', qp_solver_cond_ric_alg); % (int) 0, 1
%ocp_opts.set('qp_solver_warm_start', qp_solver_warm_start); %(int) 0 cold start, 1 warm start primal var, 2 warm start and dual var 
ocp_opts.set('qp_solver_iter_max', 50);    %50

% ocp_opts.set('sim_method', 'erk');  
% ocp_opts.set('sim_method_num_stages', 4);
% ocp_opts.set('sim_method_num_steps', 3);
ocp_opts.set('sim_method', 'discrete');   

ocp = acados_ocp(ocp_model, ocp_opts);

% initialize data structs
ocp.set('constr_lbu', [0 0],0);
ocp.set('constr_ubu', [0 0],0);
ocp.set('constr_lbu', [0 0],N-1);
ocp.set('constr_ubu', [0 0],N-1);

xi=[...
    x0(1) (x0(1):(70-x0(1))/(N/2-1):70) (70:(x_ref(1)-70)/(N/2-1):x_ref(1)) ;...
    x0(2) (x0(2):(60-x0(2))/(N/2-1):60) (60:(x_ref(2)-60)/(N/2-1):x_ref(2)) ;...
    x0(3) (x0(3):(deg2rad(25)-x0(3))/(149):deg2rad(25)) (deg2rad(25):(deg2rad(-25)-deg2rad(25))/(149):deg2rad(-25)) (deg2rad(-25):(x_ref(3)-deg2rad(-25))/(199):x_ref(3));...
    x0(4) zeros(1,N);...
    x0(5) zeros(1,N);...
   ];

ocp.set('init_x', xi);

ocp.solve();
states=ocp.get('x');
input = ocp.get('u');
sts=ocp.get('status');
iter=ocp.get('sqp_iter');

figure(1),
subplot(2,1,1)
plot(states(1,:),states(2,:),'Linewidth',1); legend('Cartesian Coord'), ylabel('m'); xlabel('m');
hold on , grid on
subplot(2,1,2)
plot([1:N+1],rad2deg(states(3,:)),'Linewidth',1);legend('Heading'), ylabel('deg');
hold on , grid on