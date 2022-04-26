% matlabProject.m
% Alex Gonzalez, Ben Harker, Kyle Wahlberg
% Due: 5.14.19

%% Set some Variables
% Tempretures
specificHeatCapacity = 0.56; % beef btu/(lb F)

tempInitial = 70;   % degrees C
timeCut = 200;      % How long the program will run in seconds
rare = 120;
medRare = 130;
med = 140;
medWell = 150;
burnt = 160;

% For FTCS umerical Method
N = 50;                 % Number of grid points = 51
kappa = 1;              % Diffusion constant
L = 1.0;                % Length of domain
h = L/N;                % Space grid size
x = (0:N)*h - L/2;      % Space coordinate
%tau = h^2/(2*kappa);   % Stability limit
tau=0.0001;

T = zeros(N+1,1);       % Numerical solution vector
ii = 2:N;               % Index counters
ip = 3:N+1;
im = 1:N-1;

% Define initial condition
T(N/2) = 1;
T(x:-(L/4)-1) = 1;
T(-L/4:x) = 1;


%% Do some Equations
hold on
for i=1:timeCut % Loopoing through using the FTCS Method to update
    T(ii) = T(ii)+(kappa*tau/h^2)*(T(ip)-2*T(ii)+T(im));
    
    plot(x,T,'-o'); 
    
end
%% Other stuff

title('A Graph'); xlabel('Time (s)'); ylabel('Heat? Or % cooked?');


%% Plot some plots