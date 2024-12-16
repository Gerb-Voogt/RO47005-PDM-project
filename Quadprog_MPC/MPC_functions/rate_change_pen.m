function [A,B1,B2,C,Q,R,M,P,x0] = rate_change_pen(A,B1,B2,Q,R,L,x0)
    % Augment the state with the previous control action
    % This allows us to formulate it as a standard LQR problem with cross
    % terms.

    n_x = size(A,1);
    n_u = size(B1,2);

    % Calculate terminal cost
    [P,~,~] = dare(A, B1, Q, R);

    % Extend the system matrices
    A = [A, zeros(n_x,n_u);
         zeros(n_u,n_x), zeros(n_u,n_u)];
    B1 = [B1; eye(n_u)];
    B2 = [B2; zeros(n_u)];
    C = eye(n_x+n_u);

    % Extend the weighing matrices
    Q = [Q,zeros(n_x,n_u);
         zeros(n_u,n_x),L];
    R = R+L;
    M = -[zeros(n_x,n_u);L];
    P = [P,zeros(n_x,n_u);
         zeros(n_u,n_x),zeros(n_u,n_u)];

    % Extend the initial state
    x0 = [x0; zeros(n_u,1)];
end
