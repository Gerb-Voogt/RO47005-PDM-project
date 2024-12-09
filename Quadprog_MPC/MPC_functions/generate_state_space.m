% Linearizes the model with a few assumptions and generates continuous and
% discrete state space A,B matrices

veh_parameters;
vx = V_ref;

syms Xp Yp vy yaw r delta

% System equations
Xp_dot  = vx * cos(yaw) - vy * sin(yaw);
Yp_dot  = vx * sin(yaw) + vy*cos(yaw);
vy_dot  = -((par.Calpha_front + par.Calpha_rear)/(par.mass*vx))*vy + (((par.l_r*par.Calpha_rear - par.l_f*par.Calpha_front)/(par.mass*vx)) - vx)*r + (par.Calpha_front*delta)/par.mass;
yaw_dot = r;
r_dot   = ((par.l_r*par.Calpha_rear - par.l_f*par.Calpha_front)/(par.Izz*vx))*vy - ((par.l_r^2*par.Calpha_rear + par.l_f^2*par.Calpha_front)/(par.Izz*vx))*r + (par.l_f*par.Calpha_front*delta)/par.Izz;

dx = [Xp_dot; Yp_dot; vy_dot; yaw_dot; r_dot];

% Derive A and B matrices
A = jacobian(dx,[Xp,Yp,vy,yaw,r]);
B = jacobian(dx,delta);

A = double(subs(A,[Xp,Yp,vy,yaw,r],linearization_point'));
B = double(B);

% Generate state-space models
sysc = ss(A,B,eye(size(A,1)),[]);
sysd = c2d(sysc,Ts);

if model_continuous
    sys = sysc;
else
    sys = sysd;
end
