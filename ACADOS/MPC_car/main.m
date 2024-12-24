clear all; clc;
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

%% Horizon and sampling
Ts = 0.01;
N = 40;    % prediction horizon
T = N*Ts;  % horizon length
N_sim = 200;

%% Create Model
model = MPC_model(par);

nx = length(model.x);
nu = length(model.u);

% State definition for clarity:
% x = [ vx, Xp, Yp, vy, yaw, r, delta ]'
idx_vx = 1; idx_Xp = 2; idx_Yp = 3; idx_vy = 4; idx_yaw = 5; idx_r = 6; idx_delta = 7;
% u = [ d_delta ]

% Initial condition
x0 = [par.V0; 0; 0; 0; 0; 0; 0]; % vx, Xp, Yp, vy, yaw, r, delta

%% Create OCP model
ocp = AcadosOcp();
ocp.model = model;

%% Cost in nonlinear least squares form
% Weights
w_vx = 1e-2;      
w_Xp = 1e2;    
w_Yp = 1e2;    
w_vy = 1e-2;      
w_yaw = 1e-2;     
w_r = 1e-2;       
w_delta = 1e-2; 
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

% path cost term
ny = nx + nu;
ocp.cost.cost_type = 'NONLINEAR_LS';
ocp.cost.W = blkdiag(W_x, W_u);
ocp.cost.yref = [par.V0; Xp_ref_terminal*0.5; Xp_ref_terminal*0.5; 0; 0; 0; 0; 0]; % [vx; Xp; Yp; vy; yaw; r; delta]
ocp.model.cost_y_expr = vertcat(model.x, model.u); 

% terminal cost term
ny_e = nx;
ocp.cost.cost_type_e = 'NONLINEAR_LS';
ocp.model.cost_y_expr_e = model.x;
ocp.cost.yref_e = [par.V0; Xp_ref_terminal*0.5; Xp_ref_terminal*0.5; 0; 0; 0; 0]; % [vx; Xp; Yp; vy; yaw; r; delta]
ocp.cost.W_e = W_x;

%% Define constraints
% mu = 1;
% 
% vx_thd      = 170 /3.6;           % absolute longitudinal velocity threshold (example)
% beta_thd    = 5 * pi / 180;       % absolute sideslip angle threshold
% d_beta_thd  = 25 * pi / 180;      % absolute sideslip angle rate threshold
% d_vy_thd    = 0.85 * mu * par.g;  % absolute lateral acceleration threshold
% delta_thd   = 2.67 * 360/180*pi/par.i_steer; % max steering angle
% d_delta_thd = 800 * pi/180/par.i_steer;       % max steering rate
% 
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
% % Bounds on delta (state)
% % delta is state #7 (index_delta = 7)
% ocp.constraints.idxbx = idx_delta;
% ocp.constraints.lbx = -delta_thd;
% ocp.constraints.ubx =  delta_thd;
% 
% % Bounds on d_delta (input)
% ocp.constraints.idxbu = 1; % only one input: d_delta
% ocp.constraints.lbu = -d_delta_thd;
% ocp.constraints.ubu =  d_delta_thd;

% Optional velocity constraint (if needed)
% For example, to limit vx:
% ocp.constraints.idxbx = [ocp.constraints.idxbx; idx_vx];
% ocp.constraints.lbx = [ocp.constraints.lbx; 0];
% ocp.constraints.ubx = [ocp.constraints.ubx; vx_thd];

%% define constraints
% only bound on u on initial stage and path
% ocp.model.con_h_expr = model.u;
% ocp.model.con_h_expr_0 = model.u;
% 
% U_max = 80;
% ocp.constraints.lh = -U_max;
% ocp.constraints.lh_0 = -U_max;
% ocp.constraints.uh = U_max;
% ocp.constraints.uh_0 = U_max;
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
% ocp.simulink_opts = simulink_opts;

ocp_solver = AcadosOcpSolver(ocp);

% solver initial guess
x_traj_init = repmat(x0,1,N+1);%[x0,zeros(nx, N)]; %zeros(nx, N+1); %[x0;zeros(nx, N)];
u_traj_init = zeros(nu, N);

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

% %% Set Up Acados Simulator
% sim = AcadosSim();
% sim.model = model;
% sim.solver_options.Tsim = Ts; % Simulation time step
% sim.solver_options.integrator_type = 'ERK'; % Explicit Runge-Kutta integrator
% 
% %% Create Simulator Solver
% sim_solver = AcadosSimSolver(sim);
% 
% %% Initialize Simulation Storage
% nx = length(x0);               % Number of states
% nu = length(model.u);          % Number of inputs (should be 1)
% x_sim = zeros(nx, N_sim+1);    % State trajectory storage
% u_sim = zeros(nu, N_sim);      % Control input storage
% x_sim(:,1) = x0;               % Set initial state
% 
% 
% %% Simulate in Loop
% for ii = 1:N_sim
%     % Set current state
%     sim_solver.set('x', x_sim(:,ii));
% 
%     % Set control input for this step
%     u_current = u_sequence(:,ii);
%     sim_solver.set('u', u_current);
% 
%     % Solve simulation step
%     status = sim_solver.solve();
% 
%     if status ~= 0
%         disp(['Simulation failed at step ', num2str(ii)]);
%         break;
%     end
% 
%     % Get new state
%     x_sim(:,ii+1) = sim_solver.get('xn');
% 
%     % Store control input
%     u_sim(:,ii) = u_current;
% end
% 
% %% Plot State and Control Trajectories
% ts = linspace(0, Ts*N_sim, N_sim+1);     % Time vector for states
% ts_u = linspace(0, Ts*N_sim, N_sim);     % Time vector for inputs
% 
% figure; hold on;
% 
% state_names = {'vx (m/s)', 'Xp (m)', 'Yp (m)', 'vy (m/s)', 'yaw (rad)', 'r (rad/s)', 'delta (rad)'};
% for i = 1:nx
%     plot(ts, x_sim(i,:), '-o', 'DisplayName', state_names{i});
% end
% xlabel('Time [s]');
% ylabel('States');
% title('State Trajectories over Time');
% legend('show');
% grid on;

% %% Prepare simulation
% sim = AcadosSim();
% sim.model = model;
% sim.solver_options.Tsim = 0.1; % simulation time
% sim.solver_options.integrator_type = 'ERK';
% 
% sim_solver = AcadosSimSolver(sim);
% 
% N_sim = 500; % simulation steps
% x_sim = zeros(nx, N_sim+1);
% x_sim(:,1) = x0;
% u_sim = zeros(nu, N_sim);
% 
% for i=1:N_sim
%     sim_solver.set('x', x_sim(:,i));
%     sim_solver.set('u', 0);
% 
%      % solve
%     sim_solver.solve();
% 
%     % get simulated state
%     x_sim(:,i+1) = sim_solver.get('xn');
% end
% 
% S_forw = sim_solver.get('S_forw');
% 
% %% Plot results
% time = (0:N_sim)*Ts;
% 
% figure;
% subplot(3,1,1);
% plot(time, x_sim(idx_Xp,:));
% hold on;
% plot(time, A*sin(k*x_sim(idx_Xp,:)), 'r--');
% xlabel('time [s]');
% ylabel('X position [m] & Reference');
% legend('X','X-based Y_{ref}','Location','Best');
% 
% subplot(3,1,2);
% plot(time, x_sim(idx_Yp,:));
% hold on;
% plot(time, A*sin(k*x_sim(idx_Xp,:)), 'r--');
% xlabel('time [s]');
% ylabel('Y position [m]');
% legend('Y','Y_{ref}','Location','Best');
% 
% subplot(3,1,3);
% plot(time(1:end-1), u_sim(1,:));
% xlabel('time [s]');
% ylabel('Steering rate d\_delta [rad/s]');
% legend('d\_delta','Location','Best');
% 
% figure;
% plot(x_sim(idx_Xp,:), x_sim(idx_Yp,:));
% hold on;
% plot(x_sim(idx_Xp,:), A*sin(k*x_sim(idx_Xp,:)), 'r--');
% xlabel('X position [m]');
% ylabel('Y position [m]');
% title('Trajectory');
% legend('vehicle path','reference','Location','Best');
% grid on;
