clear all; clc; close all;
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
N = 200; %20    % prediction horizon
T = N*Ts;  % horizon length
V0 = par.V0;

%% Create Model
model = car_PDM_model(par);

nx = length(model.x);
nu = length(model.u);

% Initial condition
x0 = [par.V0; 0; 0; 0; 0; 0; 0]; % vx, Xp, Yp, vy, yaw, r, delta

%% Create OCP model
ocp = AcadosOcp();
ocp.model = model;

%% Cost 
% Weights
w_vx = 1e-2;      
w_Xp = 1e0;    
w_Yp = 1e3;    
w_vy = 1e-2;      
w_yaw = 1e-2;     
w_r = 1e-2;       
w_delta = 1e2; 
w_d_delta = 5e0;  

W_x  = diag([w_vx, w_Xp, w_Yp, w_vy, w_yaw, w_r, w_delta]);
W_u  = w_d_delta;

Xp_ref_terminal = par.V0 * Ts * N; % Final Xp reference

% initial cost term
ny_0 = nu;
ocp.cost.cost_type_0 = 'NONLINEAR_LS';
ocp.cost.W_0 = W_u;
ocp.cost.yref_0 = zeros(ny_0, 1);
ocp.model.cost_y_expr_0 = model.u;

% % path cost term
% ny = nx + nu;
% ocp.cost.cost_type = 'NONLINEAR_LS';
% ocp.cost.W = blkdiag(W_x, W_u);
% ocp.cost.yref = [par.V0;zeros(nx,1)]; %[par.V0; Xp_ref_terminal*0.5; Xp_ref_terminal*0.5; 0; 0; 0; 0; 0]; % [vx; Xp; Yp; vy; yaw; r; delta]
% ocp.model.cost_y_expr = vertcat(model.x, model.u); 

% path cost term
ny = nu;
ocp.cost.cost_type = 'NONLINEAR_LS';
ocp.cost.W = W_u;
ocp.cost.yref = zeros(ny_0, 1); %[par.V0; Xp_ref_terminal*0.5; Xp_ref_terminal*0.5; 0; 0; 0; 0; 0]; % [vx; Xp; Yp; vy; yaw; r; delta]
ocp.model.cost_y_expr = model.u; 

% terminal cost term
ny_e = nx;
ocp.cost.cost_type_e = 'NONLINEAR_LS';
ocp.model.cost_y_expr_e = model.x;
ocp.cost.yref_e = [par.V0; Xp_ref_terminal; 0; 0; 0; 0; 0]; % [vx; Xp; Yp; vy; yaw; r; delta]
ocp.cost.W_e = W_x;

%% Define constraints
mu = 1;

vx_thd      = 170 /3.6;           % absolute longitudinal velocity threshold (example)
beta_thd    = 5 * pi / 180;       % absolute sideslip angle threshold
d_beta_thd  = 25 * pi / 180;      % absolute sideslip angle rate threshold
d_vy_thd    = 0.85 * mu * par.g;  % absolute lateral acceleration threshold
delta_thd   = 2.67 * 360/180*pi/par.i_steer;  % max steering angle
d_delta_thd = 800 * pi/180/par.i_steer;       % max steering rate
 
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

ocp.constraints.idxbx = [0 6];
ocp.constraints.lbx = [0 -delta_thd];
ocp.constraints.ubx =  [vx_thd delta_thd];


% Bounds on d_delta (input)
ocp.constraints.idxbu = 0; % only one input: d_delta
ocp.constraints.lbu = -d_delta_thd;
ocp.constraints.ubu =  d_delta_thd;


Xobs = 20;%114;    % Obstacle's X-position
Yobs = 3;%120;     % Obstacle's Y-position
R = 5;        % Minimum radius from the obstacle

% h = [...
%     (model.x(2)-10)^2+(model.x(3)-4)^2-R^2;...
%     (model.x(2)-Xobs)^2+(model.x(3)-Yobs)^2-R^2;...
% ];
% 
% % Assign the nonlinear constraint expression to the ocp model:
% ocp.model.con_h_expr = h;
% ocp.model.con_h_expr_0 = h;
% 
% % Set lower and upper bounds for h_expr, TODO: set uh to inf
% ocp.constraints.lh = [0;0];        % h_expr_obs must be >= 0
% ocp.constraints.uh = [1e9;1e9];      % a sufficiently large upper bound
% ocp.constraints.lh_0 = [0;0];        % h_expr_obs must be >= 0
% ocp.constraints.uh_0 = [1e9;1e9];      % a sufficiently large upper bound

Xobs = 20;%114;    % Obstacle's X-position
Yobs = 4;%120;     % Obstacle's Y-position
R = 5;        % Minimum radius from the obstacle

h = [...
    (model.x(2)-Xobs)^2+(model.x(3)-Yobs)^2-R^2;...
];

% Assign the nonlinear constraint expression to the ocp model:
ocp.model.con_h_expr = h;
ocp.model.con_h_expr_0 = h;

% Set lower and upper bounds for h_expr, TODO: set uh to inf
ocp.constraints.lh = 0;        % h_expr_obs must be >= 0
ocp.constraints.uh = 1e9;      % a sufficiently large upper bound
ocp.constraints.lh_0 = 0;        % h_expr_obs must be >= 0
ocp.constraints.uh_0 = 1e9;      % a sufficiently large upper bound



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
ocp.solver_options.qp_solver_warm_start = 2;

ocp_solver = AcadosOcpSolver(ocp);

% solver initial guess

x_traj_init = repmat(x0,1,N+1); 
u_traj_init = zeros(nu, N);

ocp_solver.set('constr_x0', x0);

t = Ts*(0:N);

[~, x_init, y_init] = reference_real_time(par.V0, t);

if length(x_init) == 1
    x_init = repmat(x_init,1,N+1); 
end

if length(y_init) == 1
    y_init = repmat(y_init,1,N+1);
end

x_traj_init = reshape([repmat(par.V0,1,N+1);x_init;y_init;zeros(4,N+1)],1,[]);

% set trajectory initialization
ocp_solver.set('init_x', x_traj_init); % states
ocp_solver.set('init_u', u_traj_init); % inputs
ocp_solver.set('init_pi', zeros(nx, N)); % multipliers for dynamics equality constraints

% solve
ocp_solver.solve();
% get solution
utraj = ocp_solver.get('u');
xtraj = ocp_solver.get('x');

status = ocp_solver.get('status'); % 0 - success
ocp_solver.print('stat')

%% plots
ts = linspace(0, T, N+1);
figure; hold on;
states = {'vx', 'Xp', 'Yp', 'vy','yaw','r','delta'};
for i=1:4
    subplot(4, 1, i);
    plot(ts, xtraj(i,:)); grid on;
    ylabel(states{i});
    xlabel('t [s]')
end

figure; hold on;
for i=1:3
    subplot(3, 1, i);
    plot(ts, xtraj(i+4,:)); grid on;
    ylabel(states{i+4});
    xlabel('t [s]')
end

figure
stairs(ts, [utraj'; utraj(end)])
ylabel('d-{\delta}')
xlabel('t [s]')
grid on


%% Closed-loop simulation
t_final = 10; % seconds
Ts = 0.1;
N_sim = t_final/Ts; % timeseps

par_sim = par;

% sim solver/integrator set-up
% Change these values to create a mismatch between the plant and
% control model
% par_sim.g = 9.81;          
% par_sim.Reff     = 0.3035;              
% par_sim.mass     = 1380;                
% par_sim.Izz      = 2634.5;              
% par_sim.L        = 2.79;                
% par_sim.l_f      = 1.384;               
% par_sim.i_steer  = 15.4;                
% par_sim.l_r      = par.L - par.l_f;                   
% par_sim.Calpha_front = 120000; 
% par_sim.Calpha_rear  = 190000; 

% par_sim.V0 = 50/3.6;               
% par_sim.w0 = par.V0 / par.Reff; 

model_sim = car_PDM_model(par_sim);

sim = AcadosSim();
sim.model = model_sim;
sim.solver_options.num_stages = 3;
sim.solver_options.num_steps = 3;
sim.solver_options.Tsim = Ts;
sim.solver_options.integrator_type = 'IRK';

sim_solver = AcadosSimSolver(sim);

x_sim = zeros(nx, N_sim+1);
u_sim = zeros(nu, N_sim);

x_sim(:,1) = x0;

t_N = [0 Ts*(1:N)];

% yref = zeros(ny, 1);
yref_e = zeros(nx, 1);

for i = 1:N_sim

    t = t_N + (i-1)*Ts;

    % update initial state
    x0 = x_sim(:,i);
    ocp_solver.set('constr_x0', x0);

    [~, x_ref, y_ref] = reference_real_time(par.V0, t);
    % 
    % for k=1:N-1 % intermediate stages
    %     % yref(2) = x_ref(k);
    %     % yref(3) = y_ref(k);
    %     % 
    %     % ocp_solver.set('cost_y_ref', yref, k); % last argument is the stage
    % end
    % 
    % yref_e(2) = x_ref(k+1); % terminal stage
    % % yref_e(3) = y_ref(k+1); % terminal stage
    % ocp_solver.set('cost_y_ref_e', yref_e, N);

    % ocp.cost.yref_e = [par.V0; x_ref(N+1); 0; 0; 0; 0; 0]; 
    % if i > 1
    %     x_traj_init = ocp_solver.get('x');
    %     u_traj_init = ocp_solver.get('u');
    % 
    %     ocp_solver.set('init_x', x_traj_init); % states
    %     ocp_solver.set('init_u', u_traj_init); % inputs 
    % end
    ocp_solver.solve();

    % get solution
    u0 = ocp_solver.get('u', 0);
    status = ocp_solver.get('status'); % 0 - success

    if status ~= 0
        warning('acados OCP solver returned status %d, not successful!', status);
        ocp_solver.print('stat');
    end

    % set initial state for the simulation
    sim_solver.set('x', x0);
    sim_solver.set('u', u0);

    % simulate one step
    sim_status = sim_solver.solve();
    if sim_status ~= 0
        disp(['acados integrator returned error status ', num2str(sim_status)])
    end

    % get simulated state
    x_sim(:,i+1) = sim_solver.get('xn');
    u_sim(:,i) = u0;

    if i*Ts < 1.5 && i*Ts > 1

        % get solution
        utraj = ocp_solver.get('u');
        xtraj = ocp_solver.get('x');

        ts = linspace(i*Ts, T+i*Ts, N+1);
        figure; hold on;
        states = {'vx', 'Xp', 'Yp', 'vy','yaw','r','delta'};
        for j=1:4
            subplot(4, 1, j);
            plot(ts, xtraj(j,:)); grid on;
            ylabel(states{j});
            xlabel('t [s]')
        end

        figure; hold on;
        for j=1:3
            subplot(3, 1, j);
            plot(ts, xtraj(j+4,:)); grid on;
            ylabel(states{j+4});
            xlabel('t [s]')
        end

        figure
        stairs(ts, [utraj'; utraj(end)])
        ylabel('d-{\delta}')
        xlabel('t [s]')
        grid on
    end
end

%% plots
t_sim = [0, Ts*(1:N_sim)];
figure; hold on;
states = {'vx', 'Xp', 'Yp', 'vy','yaw','r','delta'};

y_ref = zeros(nx, N_sim+1);
y_ref(1, :) = par.V0;
[~, y_ref(2,:), ~] = reference_real_time(par.V0,t_sim); %:Xp_ref(1:N_sim);
y_ref(3, 2:end) = zeros(1,N_sim);

for i=1:4
    subplot(4, 1, i);
    grid on; hold on;
    plot(t_sim, x_sim(i,:));
    plot(t_sim, y_ref(i, :));
    ylabel(states{i});
    xlabel('t [s]')
    legend('closed-loop', 'reference')
end

figure;
for i=1:3
    subplot(3, 1, i);
    grid on; hold on;
    plot(t_sim, x_sim(i+4,:));
    plot(t_sim, y_ref(i+4, :));
    ylabel(states{i+4});
    xlabel('t [s]')
    legend('closed-loop', 'reference')
end

figure
stairs(t_sim, [u_sim'; u_sim(end)])
ylabel('d-{\delta}')
xlabel('t [s]')
grid on

centers = [Xobs,Yobs];
radii = R;
figure;hold on;
plot(x_sim(2,:),x_sim(3,:));
plot(y_ref(2,:),y_ref(3,:));
viscircles(centers,radii);
grid on;








