%clc; close all;

% Set case number
% 1 - straight line no obstacles
% 2 - sine wave no obstacles
% 3 - straight line 1 obstacle
% 4 - sine wave 1 obstacle
% 5 - straight line x obstacles
% 6 - sine wave x obstacles

number_of_scenarios = 1;


if number_of_scenarios == 0
    disp("Number of scenarios per case must be > 1!");
    exit;
end


for icase = 6:6
    for j = 1
        Random_MP_scenarios;

        %% Save the scenario data
        scenarios(icase, j).roadMotionPrimitives = [path_resampled(:,1), path_resampled(:,2)]; % X, Y
        scenarios(icase, j).solstatMotionPrimitives.solver_time = solver_time; % Solver time spent
        scenarios(icase, j).solstatMotionPrimitives.path_cost = bestPathCost; % Path Cost
        scenarios(icase, j).solstatMotionPrimitives.best_path_found = bestPathFound; % Whether a Path was found or not
    end
end

save output_data_rrt scenarios
