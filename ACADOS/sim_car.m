function model = sim_car(par)
    % sim_car: 7-state vehicle model with user-specified EoMs:
    %
    %   dvx     = ( F_x_f*cos(delta)
    %              - C_alpha_f * (delta - (vy+L_f*r)/vx)*sin(delta)
    %              + F_x_r )/m + vy*r
    %
    %   dvy     = ( F_x_f*sin(delta)
    %              - C_alpha_f*(delta - (vy+L_f*r)/vx)*cos(delta)
    %              - C_alpha_r*(vy-L_r*r)/vx )/m - vx*r
    %
    %   dr      = ( (F_x_f*sin(delta)
    %                - C_alpha_f*(delta - (vy+L_f*r)/vx)*cos(delta)) * L_f
    %              + C_alpha_r*(vy-L_r*r)/vx * L_r ) / I_z
    %
    %   dpsi    = r
    %   dXp     = vx*cos(psi) - vy*sin(psi)
    %   dYp     = vx*sin(psi) + vy*cos(psi)
    %   ddelta  = d_delta
    %
    % States (x):
    %   x(1) = vx    (longitudinal velocity)
    %   x(2) = Xp    (global x-position)
    %   x(3) = Yp    (global y-position)
    %   x(4) = vy    (lateral velocity)
    %   x(5) = psi   (yaw angle)
    %   x(6) = r     (yaw rate)
    %   x(7) = delta (steering angle)
    %
    % Input (u):
    %   u(1) = d_delta (steering rate)
    %
    % The cornering stiffness terms C_alpha_f, C_alpha_r are from 'par'.
    % The user can also incorporate Dugoff or more advanced tire models
    % by replacing these linear expressions with their chosen formula.
    %
    % - By default, F_x_f and F_x_r below are set to zero, but you can turn
    %   them into symbolic parameters, functions, or additional inputs.
    %
    % Returns an AcadosModel for the AcadosSimSolver.

    import casadi.*

    %% Extract vehicle parameters
    m      = par.mass;          % vehicle mass
    I_z    = par.Izz;           % yaw inertia
    L_f    = par.l_f;           % distance from CG to front axle
    L_r    = par.l_r;           % distance from CG to rear axle
    Cf     = par.Calpha_front;  % front cornering stiffness
    Cr     = par.Calpha_rear;   % rear cornering stiffness

    nx = 7;
    nu = 1;


    % (Optionally define F_x_f, F_x_r if you want them to come from throttle, brake, etc.)
    % For illustration, set them to zero or placeholders:
    Fx_f   = 0;  
    Fx_r   = 0;

    %% Define states (in the exact order you specified)
    vx    = SX.sym('vx');      % 1
    Xp    = SX.sym('Xp');      % 2
    Yp    = SX.sym('Yp');      % 3
    vy    = SX.sym('vy');      % 4
    yaw   = SX.sym('yaw');     % 5
    r     = SX.sym('r');       % 6
    delta = SX.sym('delta');   % 7

    x = vertcat(vx, Xp, Yp, vy, yaw, r, delta);

    % Time derivatives of states
    xdot = SX.sym('xdot', 7, 1);

    % Input (steering rate)
    d_delta = SX.sym('d_delta');
    u = d_delta;

    % Small regularization to avoid division-by-zero if vx ~ 0
    eps_vx = 1e-3;
    vx_safe = vx + eps_vx;

    %% Equations of motion
    dvx = (Fx_f*cos(delta) - Cf * ( delta - (vy + L_f*r)/vx_safe ) * sin(delta) + Fx_r )/m + vy*r;

    dXp = vx*cos(yaw) - vy*sin(yaw);
    dYp = vx*sin(yaw) + vy*cos(yaw);

    dvy = (Fx_f*sin(delta) + Cf * ( delta - (vy + L_f*r)/vx_safe ) * cos(delta) - Cr * (vy - L_r*r)/vx_safe )/m ...
        - vx*r;

    dyaw = r;

    dr = (( Fx_f*sin(delta) + Cf*( delta - (vy + L_f*r)/vx_safe )*cos(delta) ) * L_f + Cr*(vy - L_r*r)/vx_safe*L_r ) / I_z;
    ddelta = d_delta;

    %% Collect into f_expl in the correct order of states
    % dx(1) = dvx
    % dx(2) = dXp
    % dx(3) = dYp
    % dx(4) = dvy
    % dx(5) = dpsi
    % dx(6) = dr
    % dx(7) = ddelta
    f_expl = vertcat(dvx, dXp, dYp, dvy, dyaw, dr, ddelta);

    %% Build AcadosModel object
    model = AcadosModel();
    model.name          = 'sim_car';
    model.x             = x;
    model.u             = u;
    model.xdot          = xdot;
    model.f_expl_expr   = f_expl;
    model.f_impl_expr   = f_expl - xdot;  % implicit form f_expl - xdot = 0
end
