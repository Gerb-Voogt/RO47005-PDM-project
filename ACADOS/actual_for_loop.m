clear all; clc; %close all;

% Set case number
% 1 - straight line no obstacles
% 2 - sine wave no obstacles
% 3 - straight line 1 obstacle
% 4 - sine wave 1 obstacle
% 5 - straight line x obstacles
% 6 - sine wave x obstacles
icase = 4; 

% Deifne method, lijkt mij handig om dan die andere twee scriptjes net een
% beetje aan te passen zodat we dit er zo in kunnen stoppen, denk dat dat
% minder moeite is dan 1 script te maken die ze alle drie kan
% local_MPC   - local MPC 
% global_MPC  - global MPC + local MPC
% RRT         - RRT + local MPC 
% lane_MPC    - Lane keeping MPC oid...
method = "global_MPC";

index.icase = icase;
index.method = method;

if exist('SimData.mat', 'file') == 2
    data = load('SimData.mat');
else
    data = load('..\SETUP\TestPath.mat');
end
    
for j = 1:size(data.scenarios,2)
    
    index.j = j;

    if index.method == "local_MPC"
        save index index
        
        save('SimData.mat','-struct', 'data')
        Plant_4DoF_MPC
   
        u = [zeros(2,1), u_sim];     % because no input at initial timestep
        sol_time = [0, sol_time];    % because no solve time at initial timestep
        sol_stat = [0, sol_stat];    % because no solve status at initial timestep
        data.scenarios(icase,j).outputLocalMPC = [t_sim', x_sim', u', sol_time', sol_stat'];
        save('SimData.mat','-struct', 'data')

    elseif index.method == "global_MPC"
        save index index

        ReferenceOptimization

        scenarios(icase, j).solstatOptimalReference.solver_time = solver_time; % Solver time spent
        scenarios(icase, j).solstatOptimalReference.solver_status = solver_status; % Whether a Path was found or not

        data.scenarios(icase,j).roadOptimalReference = [x_sim(2:3,:)'];
        save('SimData.mat','-struct', 'data')
        
        Plant_4DoF_MPC_Global % Ik zat dan zoiets te denken

        u = [zeros(2,1), u_sim];     % because no input at initial timestep
        sol_time = [0, sol_time];    % because no solve time at initial timestep
        sol_stat = [0, sol_stat];    % because no solve status at initial timestep

        % Hoe willen we de tijd voor het bepalen van global path meenemen? 
        data.scenarios(icase,j).outputGlobalMPC = [t_sim', x_sim', u', sol_time', sol_stat'];
        save('SimData.mat','-struct', 'data')

    elseif index.method == "RRT"
        save index index
        
        Random_MP_scenarios;

        %% Save the scenario data
        scenarios(icase, j).roadMotionPrimitives = [path_resampled(:,1), path_resampled(:,2)]; % X, Y
        scenarios(icase, j).solstatMotionPrimitives.solver_time = solver_time; % Solver time spent
        scenarios(icase, j).solstatMotionPrimitives.path_cost = bestPathCost; % Path Cost
        scenarios(icase, j).solstatMotionPrimitives.best_path_found = bestPathFound; % Whether a Path was found or not

        save('SETUP\TestPath.mat','-struct', 'data')
        
        Plant_4DoF_MPC_MotionPrim

        u = [zeros(2,1), u_sim];     % because no input at initial timestep
        sol_time = [0, sol_time];    % because no solve time at initial timestep
        sol_stat = [0, sol_stat];    % because no solve status at initial timestep
    
        % Hoe willen we de tijd voor het bepalen van global path meenemen? 
        data.scenarios(icase,j).outputMotionPrimitives = [t_sim', x_sim', u', sol_time', sol_stat'];
        save('SETUP\TestPath.mat','-struct', 'data')
    end

end

