clear; clc;

% Set case number
% 1 - straight line no obstacles
% 2 - sine wave no obstacles
% 3 - straight line 1 obstacle
% 4 - sine wave 1 obstacle
% 5 - straight line x obstacles
% 6 - sine wave x obstacles
icase = 6; 

% Deifne method, lijkt mij handig om dan die andere twee scriptjes net een
% beetje aan te passen zodat we dit er zo in kunnen stoppen, denk dat dat
% minder moeite is dan 1 script te maken die ze alle drie kan
% local_MPC   - local MPC 
% global_MPC  - global MPC + local MPC
% RRT         - RRT + local MPC 

method = "RRT";

index.icase = icase;
index.method = method;

if exist('SimData.mat', 'file') == 2
    data = load('SimData.mat');
else
    data = load('../SETUP/TestPathFixed.mat');
end
    
% Skip run 1 because RRT fails to find a path
for j = 1:10 %[3,4,6]
    
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
        
        run('../RRT/Random_MP_scenarios.m');
        run_number = 14;
        % figname = "images/" + run_number + "_" + icase + "-" + j + "-RRT-Path.png";
        % saveas(gcf, figname);


        if bestPathFound
            %% Save the scenario data
            data.scenarios(icase, j).roadMotionPrimitives = [path_resampled(:,1), path_resampled(:,2)]; % X, Y
            data.scenarios(icase, j).solstatMotionPrimitives.solver_time = solver_time; % Solver time spent
            data.scenarios(icase, j).solstatMotionPrimitives.path_cost = bestPathCost; % Path Cost
            data.scenarios(icase, j).solstatMotionPrimitives.best_path_found = bestPathFound; % Whether a Path was found or not

            save('SimData.mat','-struct', 'data')

            Plant_4DoF_MPC_MotionPrim

            run_number = 14;
            % figname = "images/" + run_number + "_" + icase + "-" + j + "-RRT-MPC-Solution.png";
            % saveas(gcf, figname)

            figure;
            subplot(2,1,1);
            plot(t_sim,x_sim(1,:), "LineWidth", 1.5)
            xlabel('Time [s]');
            ylabel('Velocity [m/s]');
            title('vx', j);
            grid on;
            subplot(2,1,2);
            plot(t_sim,x_sim(4,:), "LineWidth", 1.5)
            xlabel('Time [s]');
            ylabel('Velocity [m/s]');
            title('vy', j);
            grid on;

            u = [zeros(2,1), u_sim];     % because no input at initial timestep
            sol_time = [0, sol_time];    % because no solve time at initial timestep
            sol_stat = [0, sol_stat];    % because no solve status at initial timestep

            % Hoe willen we de tijd voor het bepalen van global path meenemen? 
            data.scenarios(icase,j).outputMotionPrimitives = [t_sim', x_sim', u', sol_time', sol_stat'];
            save('SimData.mat','-struct', 'data')
        end
    end

end

