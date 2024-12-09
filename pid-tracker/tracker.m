% This matlab script simulates tracking of arbitrary trajectories
% using PID control and a nonlinear bicycle model.
% ---------------------------------------------------------------
clc; clear; close all;

%% Non-tunable parameters
par.g = 9.81;
par.mass     = 1380;                % vehicle mass, kg      
par.Izz      = 2634.5;              % body inertia around z-axis, kgm^2
par.L        = 2.79;                % wheelbase, m
par.l_f      = 1.384;               % distance from front axle to CoG, m
par.l_r      = par.L - par.l_f;     % distance from rear axle to CoG, m
par.Izz      = 2634.5;              % body inertia around z-axis, kgm^2

% Steering
par.i_steer  = 15.4;                % steering ratio, -

% Additional
par.m_f      = par.mass * par.l_r / par.L;   % front sprung mass, kg
par.m_r      = par.mass * par.l_f / par.L;   % rear sprung mass, kg
par.Caf  = 120000;                           % Front axle cornering stiffness
par.Car = 190000;                            % Rear axle cornering stiffness
par.Kus = par.m_f/par.Caf - par.m_r/par.Car; % understeer gradient
V_ref = 100 /3.6;                            % pre-maneuver speed, km/h

t = linspace(0, 100, 1e6);
delta_t = t(2) - t(1);
x0 = [1; 1; 1; 1; 1; 1];

xref = ones(2, length(t)); % Reference trajectory
x = zeros(6, length(t));
e = zeros(1, length(t));
x(:, 1) = x0;

for k = 1:length(t)-1
    e(k) = error(x(:, k), xref(:, k));
    if k == 1
        u = pid_control_law(e(k), e(k));
    else
        u = pid_control_law(e(k), e(k-1));
    end
    x(:,k+1) = x(:,k) + delta_t*nonlinear_bicycle_model(k*delta_t, x(:,k), [0; u(1)], par);
end

figure;
subplot(3, 2, 1);
plot(t, x(1, :));
title("vx");

subplot(3, 2, 2);
plot(t, x(2, :));
title("vy");

subplot(3, 2, 3);
plot(t, x(3, :));
title("r");

subplot(3, 2, 4);
plot(t, x(4, :));
title("\psi");

subplot(3, 2, 5);
plot(t, x(5, :)); hold on;
plot(t, xref(1, :));
title("Xp");

subplot(3, 2, 6);
plot(t, x(6, :)); hold on;
plot(t, xref(2, :));
title("Yp");


figure;
plot(t, e);
title("Error e(t)");

figure;
plot(x(5,:), x(6,:)); hold on;
scatter(xref(1,1), xref(2,1));

function u = pid_control_law(e, e2)
    kp = 0.1;
    kd = 0.1;
    dt = 1e-4;
    u = kp*e + kd*(e - e2)/dt;
end


function e = error(x, xref)
    % Compute the error based on a desired XY reference trajectory in the global coordinate frame
    Xp = x(5);
    Yp = x(6);

    e = norm([Xp - xref(1); Yp - xref(2)]);
end


function xdot = nonlinear_bicycle_model(t, x, u, par)
    [vx, vy, r, psi, Xp, Yp] = unpack_state(x);
    Fx = u(1);
    delta = u(2);
    
    vxdot = vy*r + Fx/par.mass;
    vydot = -(par.Caf + par.Car)/(par.mass*vx)*vy ...
          + ((par.l_r*par.Car - par.l_f*par.Caf)/(par.mass*vx) - vx)*r ...
          + par.Caf/par.mass*delta;
    rdot = (par.l_r*par.Car - par.l_f*par.Caf)/(par.Izz*vx)*vy ...
         - (par.l_r^2*par.Car + par.l_f^2*par.Caf)/(par.Izz*vx)*r ...
         + (par.l_f*par.Caf)/(par.Izz)*delta;
    psidot = r;
    Xpdot = vx*cos(psi) - vy*sin(psi);
    Ypdot = vx*sin(psi) + vy*cos(psi);

    xdot = [vxdot; vydot; rdot; psidot; Xpdot; Ypdot];
end

function [vx, vy, r, psi, Xp, Yp] = unpack_state(x)
    vx = x(1);
    vy = x(2);
    r = x(3);
    psi = x(4);
    Xp = x(5);
    Yp = x(6);
end
