clear; clc;

% Define the range of cases to iterate over:
% 1 - straight line no obstacles
% 2 - sine wave no obstacles
% 3 - straight line 1 obstacle
% 4 - sine wave 1 obstacle
% 5 - straight line x obstacles
% 6 - sine wave x obstacles
caseNumbers = 1:6;

% Define the method:
% local_MPC   - local MPC 
% global_MPC  - global MPC + local MPC
% RRT         - RRT + local MPC 
method = "RRT";
index.method = method;

% Load data
if exist('SimDataFinal.mat', 'file') == 2
    data = load('SimDataFinal.mat');
else
    data = load('../SETUP/TestPathFixed.mat');
end

% Outer loop: Loop over all cases
for icase = caseNumbers
    
    index.icase = icase;
    
    save index index

    % Inner loop: Loop over multiple runs for a given case (skip run 1 if desired)
    for j = 1:10  %[3,4,6]  % Adjust run indices if needed
        
        % Save current case and run index
        index.j = j;
        
        % Save index structure (if needed by subsequent scripts)
        save index index
        
        if index.method == "local_MPC"
            % Save simulation data for local MPC
            save('SimDataFinal.mat','-struct', 'data')
            
            % Run local MPC simulation (script should be in your path)
            Plant_4DoF_MPC
            
            % Add dummy initial input, solution time and status (for initial time step)
            u = [zeros(2,1), u_sim];     % because no input at initial timestep
            sol_time = [0, sol_time];      % because no solve time at initial timestep
            sol_stat = [0, sol_stat];      % because no solve status at initial timestep
            
            % Store output in the data structure
            data.scenarios(icase, j).outputLocalMPC = [t_sim', x_sim', u', sol_time', sol_stat'];
            
            % Save the updated data structure back to disk
            save('SimDataFinal.mat','-struct', 'data')
        
        elseif index.method == "global_MPC"
            % Run the reference optimization part
            ReferenceOptimization
            
            % Store the optimization solver outputs in the data structure
            data.scenarios(icase, j).solstatOptimalReference.solver_time = solver_time; % Solver time spent
            data.scenarios(icase, j).solstatOptimalReference.solver_status = solver_status; % Path found status
            
            % Store the reference road/path data
            data.scenarios(icase, j).roadOptimalReference = [x_sim(2:3,:)'];
            save('SimDataFinal.mat','-struct', 'data')
            
            % Run the global MPC simulation using the previous reference results
            Plant_4DoF_MPC_Global
            
            % Add dummy initial input, solution time and status (for initial time step)
            u = [zeros(2,1), u_sim];     % because no input at initial timestep
            sol_time = [0, sol_time];      % because no solve time at initial timestep
            sol_stat = [0, sol_stat];      % because no solve status at initial timestep
            
            % Store output in the data structure
            data.scenarios(icase, j).outputGlobalMPC = [t_sim', x_sim', u', sol_time', sol_stat'];
            save('SimDataFinal.mat','-struct', 'data')
        
        elseif index.method == "RRT"
            % Run RRT-based path planning script
            run('../RRT/Random_MP_scenarios.m');
            
            % Define a run number for later use in plots or saving (if required)
            run_number = 14;
            
            % If a path is found, then process the output
            if bestPathFound
                % Save the raw RRT planning data into the data structure
                data.scenarios(icase, j).roadMotionPrimitives = [path_resampled(:,1), path_resampled(:,2)]; % X, Y
                data.scenarios(icase, j).solstatMotionPrimitives.solver_time = solver_time; % Solver time spent
                data.scenarios(icase, j).solstatMotionPrimitives.path_cost = bestPathCost;   % Path Cost
                data.scenarios(icase, j).solstatMotionPrimitives.best_path_found = bestPathFound; % Path found flag
                
                save('SimDataFinal.mat','-struct', 'data')
                
                % Run MPC on the motion primitives path
                Plant_4DoF_MPC_MotionPrim
                
                % Add dummy initial input, solution time and status (for initial time step)
                u = [zeros(2,1), u_sim];     % because no input at initial timestep
                sol_time = [0, sol_time];      % because no solve time at initial timestep
                sol_stat = [0, sol_stat];      % because no solve status at initial timestep
                
                % Save the MPC output corresponding to the motion primitives into the data structure
                data.scenarios(icase, j).outputMotionPrimitives = [t_sim', x_sim', u', sol_time', sol_stat'];
                save('SimDataFinal.mat','-struct', 'data')
            end
        end
    end
end
