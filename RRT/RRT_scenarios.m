clc; clear; close all;

% Set case number
% 1 - straight line no obstacles
% 2 - sine wave no obstacles
% 3 - straight line 1 obstacle
% 4 - sine wave 1 obstacle
% 5 - straight line x obstacles
% 6 - sine wave x obstacles
icase = 4; 
number_of_scenarios = 10;


if number_of_scenarios == 0
    disp("Number of scenarios per case must be > 1!");
    exit;
end


for icase = 1:6
    for scenario_idx = 1:number_of_scenarios
        Random_MP_scenarios;

        %% Save the scenario data
        scenarios(icase, scenario_idx).roadCenterLine = [roadCenterlineX', roadCenterlineY']; % road centerline x, road centerline y
        scenarios(icase, scenario_idx).obstacles = obstacles; % Obstacles used for scenario
        scenarios(icase, scenario_idx).output_rrt = [bestDubins(:,1), bestDubins(:,2), bestDubins(:,3)]; % X, Y, Yaw
        scenarios(icase, scenario_idx).statistics.solver_time = solver_time; % Solver time spent
        scenarios(icase, scenario_idx).statistics.path_cost = bestPathCost; % Path Cost
        scenarios(icase, scenario_idx).statistics.best_path_found = bestPathFound; % Whether a Path was found or not
    end
end

save output_data_rrt scenarios
