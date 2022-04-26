% matlabProject.m
% Alex Gonzalez, Ben Harker, Kyle Wahlberg
% Due: 5.14.19

%% Set some Variables
% Tempretures
clear all;
specificHeatCapacity = 0.56; % beef btu/(lb F)
density = .033; %beef lbs/ci
thermalcond = .185 / 12; % beef btu/(hr F ft) / 12 in/ft
thermaldiff = thermalcond/(density*specificHeatCapacity);

tempInitial = 42; % degrees F
rare = 120;
medRare = 130;
med = 140;
medWell = 150;
burnt = 160;

weight = input('How much meat (lbs) are you cooking? ');
thick = input('How thick (in) is your steak? ');
done = menu('How would you like your steak cooked?','Rare','Medium Rare','Medium','Medium Well','Burnt');
method = menu('How are you cooking?','Cast Iron','Grill');

% For FTCS Numerical Method
N = 100;                       
L = sqrt((weight / density) / thick);
hx = L/N;        % Space grid size
hy = thick/(2*N);
x = (0:N)*hx;     % Space coordinate
time=0;
tau = 0.00001;

T = zeros(N+1,N+1);     % Numerical solution vector
T=T+42;
ii = 2:N;               % Index counters
ip = 3:N+1;
im = 1:N-1;
ji=2:N;
jp=3:N+1;
jm=1:N-1;

if done==1
    CookTemp=rare;
elseif done==2
    CookTemp=medRare;
elseif done==3;
    CookTemp=med;
elseif done==4
    CookTemp=medWell;
else
    CookTemp=burnt;
end;

if method==1
    T(:,1)=450;
else
    T(:,1)=400;
    for i=1:4;
        T(round(i*N/4))=450;
    end;
end;

while T(:,N/2)< CookTemp
    T(ii,ji) = T(ii,ji) + thermaldiff*tau*( ((T(im,ji)-2*T(ii,ji)+T(ip,ji))/hx^2) + ((T(ii,jm)-2*T(ii,ji)+T(ii,jp))/hy^2) );
    T(:,2)=T(:,1);
    T(1,:)=T(2,:);
    T(N+1,:)=T(N,:);
    T(:,N+1)=T(:,N);
    
    plot(x,T(:,N/2),'k.',[0,L],[rare,rare],'r-',[0,L],[medRare,medRare],'r-',[0,L],[med,med],'y-',[0,L],[medWell,medWell],'y-',[0,L],[burnt,burnt],'k-');
    xlim([-1,L+1]); ylim([40,burnt]);
    xlabel('Steak (in)'); ylabel('Temperature (F)');
    pause(0.000001);

end;


  
    