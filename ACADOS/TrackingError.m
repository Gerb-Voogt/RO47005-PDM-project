clear all; close all;

% Load your data
data = load('../METRICS/metrics_data.mat');

icase = 6;        % Fixed scenario index
allRuns = 1:10;   % All runs 1 to 10
runsToUse = setdiff(allRuns, 3);   % Exclude run 3 because of instability

nRuns = numel(runsToUse);

% Pre-allocate arrays for storing computed areas for each run
areas_local   = zeros(nRuns,1);
areas_global  = zeros(nRuns,1);
areas_rrt     = zeros(nRuns,1);

% Loop over the selected runs
for idx = 1:nRuns
    j = runsToUse(idx);
    
    % Extract the road centerline points for current run
    x_center = data.scenarios(icase,j).roadCenterline(:,1);
    y_center = data.scenarios(icase,j).roadCenterline(:,2);
    
    % --- Method 1: Local MPC ---
    x_actual_local = data.scenarios(icase,j).outputLocalMPC(:,3);
    y_actual_local = data.scenarios(icase,j).outputLocalMPC(:,4);
    y_interp_local = interp1(x_actual_local, y_actual_local, x_center, 'linear', 'extrap');
    diff_local = abs(y_center - y_interp_local);
    areas_local(idx) = trapz(x_center, diff_local);
    
    % --- Method 2: Global MPC ---
    x_actual_global = data.scenarios(icase,j).outputGlobalMPC(:,3);
    y_actual_global = data.scenarios(icase,j).outputGlobalMPC(:,4);
    y_interp_global = interp1(x_actual_global, y_actual_global, x_center, 'linear', 'extrap');
    diff_global = abs(y_center - y_interp_global);
    areas_global(idx) = trapz(x_center, diff_global);
    
    % --- Method 3: Motion Primitives (RRT) ---
    x_actual_rrt = data.scenarios(icase,j).outputMotionPrimitives(:,3);
    y_actual_rrt = data.scenarios(icase,j).outputMotionPrimitives(:,4);
    y_interp_rrt = interp1(x_actual_rrt, y_actual_rrt, x_center, 'linear', 'extrap');
    diff_rrt = abs(y_center - y_interp_rrt);
    areas_rrt(idx) = trapz(x_center, diff_rrt);
end

% Pre-allocate arrays for normalized areas for each run
norm_local  = zeros(nRuns,1);
norm_global = zeros(nRuns,1);
norm_rrt    = zeros(nRuns,1);

% Normalize areas for each run relative to the maximum area of the three methods.
for idx = 1:nRuns
    currentAreas = [areas_local(idx), areas_global(idx), areas_rrt(idx)];
    maxArea = min(currentAreas);
    
    if maxArea > 0
        norm_local(idx)  = areas_local(idx)  / maxArea;
        norm_global(idx) = areas_global(idx) / maxArea;
        norm_rrt(idx)    = areas_rrt(idx)    / maxArea;
    else
        norm_local(idx)  = 0;
        norm_global(idx) = 0;
        norm_rrt(idx)    = 0;
    end
end

% Compute the average normalized areas over all selected runs for each method
avg_norm_local  = mean(norm_local);
avg_norm_global = mean(norm_global);
avg_norm_rrt    = mean(norm_rrt);

% Display the average results
fprintf('Average Normalized Area for Scenario %d (over runs: %s):\n', icase, mat2str(runsToUse));
fprintf('Local MPC:         %f\n', avg_norm_local);
fprintf('Global MPC:        %f\n', avg_norm_global);
fprintf('Motion Primitives: %f\n', avg_norm_rrt);
