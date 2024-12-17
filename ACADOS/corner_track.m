function [sref,xref,yref,psiref,kapparef] = corner_track(R, total_angle)
    % total_angle in radians, e.g. pi/2 for a 90-degree turn
    sref = linspace(0, R*total_angle, 100)'; 
    xref = R * sin(sref / R);
    yref = R * (1 - cos(sref / R));
    psiref = sref / R;       % heading matches the angle of the arc
    kapparef = (1/R) * ones(size(sref));  % constant curvature
end
