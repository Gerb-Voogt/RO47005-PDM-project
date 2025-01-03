function model= car_PDM_model(par)
    
    import casadi.*
    veh_parameters

    % Parameters from par
    mass = par.mass;
    Izz = par.Izz;
    l_f = par.l_f;
    l_r = par.l_r;
    Calpha_front = par.Calpha_front;
    Calpha_rear  = par.Calpha_rear;
    L = par.L;  
    g = par.g;

    nx = 7;
    nu = 1;


    % States
    vx    = SX.sym('vx');
    Xp    = SX.sym('Xp');
    Yp    = SX.sym('Yp');
    vy    = SX.sym('vy');
    yaw   = SX.sym('yaw');
    r     = SX.sym('r');
    delta = SX.sym('delta');

    x = vertcat(vx, Xp, Yp, vy, yaw, r, delta);
    xdot = SX.sym('xdot', nx, 1);

    % Input
    d_delta = SX.sym('d_delta');
    u = d_delta;

    % Equations of motion
    dvx = vy * r;
    dXp = vx*cos(yaw) - vy*sin(yaw);
    dYp = vx*sin(yaw) + vy*cos(yaw);
    dvy = -((Calpha_front + Calpha_rear)/(mass*vx))*vy ...
          + (((l_r*Calpha_rear - l_f*Calpha_front)/(mass*vx)) - vx)*r ...
          + (Calpha_front*delta)/mass;
    dyaw = r;
    dr = ((l_r*Calpha_rear - l_f*Calpha_front)/(Izz*vx))*vy ...
         - ((l_r^2*Calpha_rear + l_f^2*Calpha_front)/(Izz*vx))*r ...
         + (l_f*Calpha_front*delta)/Izz;
    ddelta = d_delta;

    f_expl = vertcat(dvx, dXp, dYp, dvy, dyaw, dr, ddelta);

    % Create model struct
    model = AcadosModel();
    model.x = x;
    model.u = u;
    model.xdot = xdot;
    model.f_expl_expr = f_expl;
    model.f_impl_expr = f_expl - xdot;
    model.name = 'car_PDM';

end
