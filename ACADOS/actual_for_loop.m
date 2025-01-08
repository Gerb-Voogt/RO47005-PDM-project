addpath('D:\TU_Delft\Master\PDM\RO47005-PDM-project\SETUP\')

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
method = "local_MPC";

index.icase = icase;
index.method = method;

data = load('TestPath.mat')

for j = 1:4 %size(scenarios,2)
    
    index.j = j;

    if index.method == "local_MPC"
        save index index
        
        Plant_4DoF_MPC
   
        u = [zeros(2,1), u_sim];     % because no input at initial timestep
        sol_time = [0, sol_time];    % because no solve time at initial timestep
        sol_stat = [0, sol_stat];    % because no solve status at initial timestep
        data.scenarios(icase,j).outputLocalMPC = [t_sim', x_sim', u', sol_time', sol_stat'];
        save('TestPath.mat',data)

    elseif index.method == "global_MPC"
        save index index

        ReferenceOptimization

        data.scenarios(icase,j).roadOptimalReference = [x_sim(2:3,:)'];
        save('TestPath.mat',data)
        
        Plant_4DoF_glob_MPC % Ik zat dan zoiets te denken

        u = [zeros(2,1), u_sim];     % because no input at initial timestep
        sol_time = [0, sol_time];    % because no solve time at initial timestep
        sol_stat = [0, sol_stat];    % because no solve status at initial timestep

        % Hoe willen we de tijd voor het bepalen van global path meenemen? 
        data.scenarios(icase,j).outputGlobalMPC = [t_sim', x_sim', u', sol_time', sol_stat'];
        save('TestPath.mat',data)

    elseif index.method == "RRT"
        save index index
        
        RRT bestand

        data.scenarios(icase,j).roadMotionPrimitives = [x_sim(2:3,:)'];
        save('TestPath.mat',data)
        
        Plant_4DoF_MPC_MotionPrim

        u = [zeros(2,1), u_sim];     % because no input at initial timestep
        sol_time = [0, sol_time];    % because no solve time at initial timestep
        sol_stat = [0, sol_stat];    % because no solve status at initial timestep
    
        % Hoe willen we de tijd voor het bepalen van global path meenemen? 
        data.scenarios(icase,j).outputMotionPrimitives = [t_sim', x_sim', u', sol_time', sol_stat'];
        save('TestPath.mat',data)
    end

end

