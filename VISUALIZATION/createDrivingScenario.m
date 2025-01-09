% Load data
data = load("../ACADOS/output_data.mat");

case_ = 4;
scenario_ = 1;

road_data = data.scenarios(case_, scenario_).roadCenterline;
output_data = data.scenarios(case_, scenario_).output_loc';
obstacle_data = data.scenarios(case_, scenario_).obstacles;

% Define time, position, yaw from output data
t = output_data(:, 1);
Xp = output_data(:, 3);
Yp = output_data(:, 4);
yaw = rad2deg(output_data(:, 6));

trajectory = [Xp Yp yaw t];

% Define driving scenario
scenario = drivingScenario;
roadWidth = 6; % Road width
roadCenterline = road_data;

% Define lane specifications
laneSpecs = lanespec(1, 'Width', roadWidth);

% Add the road to the scenario
road(scenario, roadCenterline, 'Lanes', laneSpecs, 'Name', 'Sinusoidal Road');

% Add the ego vehicle
egoVehicle = vehicle(scenario, 'ClassID', 1, 'Position', [0 0 0.01], 'Name', 'Car');

% Add obstacles dynamically based on obstacle_data
for i = 1:size(obstacle_data, 1)
    % Extract obstacle data for each row
    position = [obstacle_data(i, 1), obstacle_data(i, 2), 0.01];
    yawAngle = rad2deg(obstacle_data(i, 5));
    
    % Add an obstacle (e.g., a truck or pedestrian)
    vehicle(scenario, ClassID=2, Position=position, Yaw=yawAngle, ...
            Name=sprintf('Obstacle%d', i), AssetType="BoxTruck");
end

% Define the custom trajectory (x, y, yaw, time)
customTrajectory = trajectory;

% Initialize array to store path
pathTaken = [];


% Create the 3D simulation plot

plotSim3d(scenario, ActorInFocus=1);
hold on;

% Initialize array to store path
pathTaken = [];

% Main simulation loop
for i = 1:size(customTrajectory, 1)-1
    % Extract current and next waypoints
    currentWaypoint = customTrajectory(i, :);
    nextWaypoint = customTrajectory(i+1, :);

    % Calculate time step and time difference
    dt = nextWaypoint(4) - currentWaypoint(4);

    % Interpolate between the current and next waypoint
    steps = 1; % Number of steps for interpolation
    for j = 1:steps
        t = j / steps;
        egoVehicle.Position = [
            currentWaypoint(1) + t * (nextWaypoint(1) - currentWaypoint(1)), ...
            currentWaypoint(2) + t * (nextWaypoint(2) - currentWaypoint(2)), ...
            0.01
        ];
        egoVehicle.Yaw = currentWaypoint(3) + t * (nextWaypoint(3) - currentWaypoint(3));

        % Store the position in the pathTaken array
        pathTaken = [pathTaken; egoVehicle.Position(1:2)];

        % Adjust camera for bird's-eye view
        camPosition = egoVehicle.Position + [0, 0, 30]; % Position above the vehicle
        camTarget = egoVehicle.Position;               % Target the vehicle
        campos(camPosition);                           % Set camera position
        camtarget(camTarget);                          % Set camera target
        camup([0, 0, 1]);                              % Keep the z-axis up

        % Advance the scenario
        advance(scenario);

        % Pause for visualization (adjust for simulation speed)
        pause(dt / steps);
    end
end

