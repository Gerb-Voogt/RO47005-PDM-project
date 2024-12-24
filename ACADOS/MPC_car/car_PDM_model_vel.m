function [model, constraint] = car_PDM_model_vel(par)
    
    import casadi.*

    % Parameters from par
    mass = par.mass;
    Izz = par.Izz;
    l_f = par.l_f;
    l_r = par.l_r;
    Calpha_front = par.Calpha_front;
    Calpha_rear  = par.Calpha_rear;
    L = par.L;  
    g = par.g;

    nx = 5;
    nu = 2;


    % States
    v     = SX.sym('v');
    Xp    = SX.sym('Xp');
    Yp    = SX.sym('Yp');
    yaw   = SX.sym('yaw');
    delta = SX.sym('delta');

    x = vertcat(v, Xp, Yp, yaw, delta);
    xdot = SX.sym('xdot', nx, 1);

    % Input
    a = SX.sym('a'); 
    d_delta = SX.sym('d_delta');
    u = vertcat(a,d_delta);

    % Equations of motion (from ACADO code)
    dv = a;
    dXp = v*cos(yaw);
    dYp = v*sin(yaw);
    dyaw = v/par.L*tan(delta);
    ddelta = d_delta;

    f_expl = vertcat(dv, dXp, dYp, dyaw, ddelta);

    % Create model struct
    model = AcadosModel();
    model.x = x;
    model.u = u;
    model.xdot = xdot;
    model.f_expl_expr = f_expl;
    model.f_impl_expr = f_expl - xdot;
    model.name = 'car_PDM';

    %% Nonlinear constraints
    
    Xobs = 50;%114;    % Obstacle's X-position
    Yobs = 0;%120;     % Obstacle's Y-position
    R = 1;%20;        % Minimum radius from the obstacle

    h = [...
        (Xp-Xobs)^2+(Yp-Yobs)^2-R^2;...
        ];


    constraint = h;
end
