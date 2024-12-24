clear all; clc; close all;
import casadi.*

check_acados_requirements()

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


%% OCP DESCRIPTION
ocp = AcadosOcp();

%% IVP DESCRIPTION
sim = AcadosSim();

%% Create Model
[model, constraint] = car_PDM_model(par);
ocp.model = model;
sim.model = model;

nx = length(model.x);
nu = length(model.u);

% Initial condition
x0 = [par.V0; 0; 0; 0; 0; 0; 0]; % vx, Xp, Yp, vy, yaw, r, delta

%% discretization
Ts = 0.01; % sampling time = length of first shooting interval
N = 20; % number of shooting intervals
% nonuniform discretization
shooting_nodes = [0.0 Ts*(1:N)];%[0.0 0.01, 0.05*(1:N-1)];
T = shooting_nodes(end);
N_sim = 1000;%20/Ts;

ocp.solver_options.tf = T;
ocp.solver_options.N_horizon = N;
ocp.solver_options.shooting_nodes = shooting_nodes;
ocp.solver_options.nlp_solver_type = 'SQP';
ocp.solver_options.qp_solver = 'PARTIAL_CONDENSING_HPIPM';
% FULL_CONDENSING_HPIPM, PARTIAL_CONDENSING_HPIPM
% FULL_CONDENSING_QPOASES, PARTIAL_CONDENSING_OSQP
ocp.solver_options.qp_solver_cond_N = 5; % for partial condensing
ocp.solver_options.globalization = 'MERIT_BACKTRACKING'; % turns on globalization

% we add some model-plant mismatch by choosing different integration
% methods for model (within the OCP) and plant:

% integrator model
model_integrator_type = 'ERK';
model_sim_method_num_stages = 1;
model_sim_method_num_steps = 2;

ocp.solver_options.sim_method_num_stages = model_sim_method_num_stages;
ocp.solver_options.sim_method_num_steps = model_sim_method_num_steps;
ocp.solver_options.integrator_type = model_integrator_type;

% integrator plant
plant_integrator_type = 'IRK';
plant_sim_method_num_stages = 3;
plant_sim_method_num_steps = 3;

sim.solver_options.num_stages = plant_sim_method_num_stages;
sim.solver_options.num_steps = plant_sim_method_num_steps;
sim.solver_options.Tsim = Ts;
sim.solver_options.integrator_type = plant_integrator_type;

%% COST: nonlinear-least squares cost
ocp.cost.cost_type_0 = 'NONLINEAR_LS';
ocp.cost.cost_type = 'NONLINEAR_LS';
ocp.cost.cost_type_e = 'NONLINEAR_LS';

w_vx = 1e-2;      
w_Xp = 1e0;    
w_Yp = 1e0;    
w_vy = 1e-2;      
w_yaw = 1e-2;     
w_r = 1e-2;       
w_delta = 1e-2; 
w_d_delta = 5e0;  

W_x  = diag([w_vx, w_Xp, w_Yp, w_vy, w_yaw, w_r, w_delta]);
W_u  = w_d_delta;

model.cost_y_expr_0 = model.u;
model.cost_y_expr = vertcat(model.x, model.u);
model.cost_y_expr_e = model.x;

ocp.cost.W_0 = W_u;
ocp.cost.W = blkdiag(W_x, W_u);
ocp.cost.W_e = W_x;

% initialize reference to zero, can be changed after solver creation
ocp.cost.yref_0 = zeros(size(model.cost_y_expr_0)); % x0? xref?
ocp.cost.yref = zeros(size(model.cost_y_expr));     % x0? xref?
ocp.cost.yref_e = zeros(size(model.cost_y_expr_e)); % x0? xref?


%% CONSTRAINTS

ocp.constraints.x0 = x0;

mu = 1;

vx_thd      = 170 /3.6;           % absolute longitudinal velocity threshold (example)
beta_thd    = 5 * pi / 180;       % absolute sideslip angle threshold
d_beta_thd  = 25 * pi / 180;      % absolute sideslip angle rate threshold
d_vy_thd    = 0.85 * mu * par.g;  % absolute lateral acceleration threshold
delta_thd   = 2.67 * 360/180*pi/par.i_steer; % max steering angle
d_delta_thd = 800 * pi/180/par.i_steer;       % max steering rate

% Bounds on delta (state)
% delta is state #7 (index_delta = 6)
ocp.constraints.idxbx = [0 6];
ocp.constraints.lbx = [0 -delta_thd];
ocp.constraints.ubx =  [vx_thd delta_thd];

% Bounds on d_delta (input)
ocp.constraints.idxbu = 0; % only one input: d_delta
ocp.constraints.lbu = -d_delta_thd;
ocp.constraints.ubu =  d_delta_thd;

% % Assign the nonlinear constraint expression to the ocp model:
% ocp.model.con_h_expr = constraint;
% 
% % Set lower and upper bounds for h_expr, TODO: set uh to inf
% ocp.constraints.lh = 0;        % h_expr_obs must be >= 0
% ocp.constraints.uh = 1e9;      % a sufficiently large upper bound

% ocp.subjectTo(0 <= vx <= vx_thd);
% ocp.subjectTo(-delta_thd <= delta <= delta_thd);
% ocp.subjectTo(-d_delta_thd <= d_delta <= d_delta_thd);


%% OCP SOLVER
ocp_solver = AcadosOcpSolver(ocp);

% % set parameter for all stages
% for i = 0:N
%     ocp_solver.set('p', 1., i);
% end

%% SIM SOLVER/INTEGRATOR
sim_solver = AcadosSimSolver(sim);

% set parameter
% sim_solver.set('p', 1.05); % model-plant mismatch in the parameters

%% SIMULATION

% preallocate memory
x_sim = zeros(nx, N_sim+1);
u_sim = zeros(nu, N_sim);

x_sim(:,1) = x0;

% par.V0 = v_mean

yref_0 = zeros(nu, 1);
yref = zeros(nx+nu, 1);
yref_e = zeros(nx, 1);

yref(1) = par.V0;
yref_e(1) = par.V0;

Xp_ref = zeros(1,N_sim+1);
Yp_ref = zeros(1,N_sim+1);

for i=1:N_sim
    % update initial state
    x0 = x_sim(:,i);
    ocp_solver.set('constr_x0', x0);

    % compute reference position on the nonuniform grid
    t = ((i-1)*Ts + shooting_nodes);
    [~, x_ref, y_ref] = reference_corner(par.V0, t);

    if length(x_ref) == 1
        x_ref = repmat(x_ref,1,N+1); 
    end

    if length(y_ref) == 1
        y_ref = repmat(y_ref,1,N+1);
    end

    Xp_ref(i+1:i+1+N) = x_ref;
    Yp_ref(i+1:i+1+N) = y_ref;

    for k=1:N-1 % intermediate stages
        yref(2) = x_ref(k);
        yref(3) = y_ref(k);

        ocp_solver.set('cost_y_ref', yref, k); % last argument is the stage
    end
    yref_e(2) = x_ref(k+1); % terminal stage
    yref_e(3) = y_ref(k+1); % terminal stage
    ocp_solver.set('cost_y_ref_e', yref_e, N);

    % solve
    ocp_solver.solve();

    % get solution
    u0 = ocp_solver.get('u', 0)
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
end

%% plots
% ts = linspace(0, T, N+1);
figure; hold on;
states = {'vx', 'Xp', 'Yp', 'vy','yaw','r','delta'};

t_sim = [0, Ts*(1:N_sim)];

% [~,Xp_ref,Yp_ref] = reference_corner(par.V0,t_sim);

y_ref = zeros(nx, N_sim+1);
y_ref(1, :) = par.V0;
y_ref(2, 2:end) = Xp_ref(1:N_sim);
y_ref(3, 2:end) = Yp_ref(1:N_sim);

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















