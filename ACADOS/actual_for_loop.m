

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
% lane_MPC    - Lane keeping MPC oid...
method = "local_MPC";

index.icase = icase;
index.method = method;
load TestPath.mat
save output_data scenarios

for j = 1:size(scenarios,2)
    
    index.j = j;
    if index.method == "local_MPC"
        save index index
        
        Plant_4DoF_MPC
    
        load output_data
        scenarios(icase,j).output_loc = [t_sim;x_sim];
        
        save output_data scenarios

    elseif index.method == "global_MPC"
        save index index
        
        Plant_4DoF_glob_MPC % Ik zat dan zoiets te denken
    
        scenarios(icase,j).output_glob = [t_sim;x_sim];
        save output_data scenarios

    elseif index.method == "RRT"
        save index index
        
        Plant_4DoF_RRT % en weer dit 
    
        scenarios(icase,j).output_RRT = [t_sim;x_sim];
        save output_data scenarios
    end


end