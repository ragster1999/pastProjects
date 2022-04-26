%Math Methods Homework 12, Problem 1. Climate Stuff%

%% Part a
dataPre1950 = climData(1:70,2);
dataPost1950 = climData(71:140,2);

muPre = mean(dataPre1950);
muPost = mean(dataPost1950);

stdPre = std(dataPre1950);
stdPost = std(dataPost1950);

SEpre = stdPre/sqrt(2*70-2);
SEpost = stdPost/sqrt(2*70-2);


%These two are the answer to part A%
muDifference = muPost - muPre;
muSEDiff =  sqrt(SEpre^2+SEpost^2);

%% Part b
    % 95 percent confidence interval
    
C = 1.96;

stdDiff = muSEDiff*sqrt(2*2-2);

k = C*stdDiff/sqrt(140);

confmin = muDifference - k;
confmax = muDifference + k;

%% part c
    % Probability of it being an anomaly%
    
    % Lets assume that the mean of Reality is muPre1950, and calculate the
    % probability of the temperature avg after that being as big as it is.
    
    muReal = muPre;
    stdReal = stdPre;
  
    %Evaluated the cumulative distributive fxn in Mathematica, gave this result 
    
    P = 1.11022*10^(-16);
    
%% part d
    % Lets look back to 1980
    % Lets say the error bar guess is .05 degrees

   x = [1:1:40]';
   x1 = climData(101:140,2);
   y1 = 1980:2019;
   
   y1T = transpose(y1);
  
   c = polyfit(y1T,x1,1);
   cest = polyval(c,y1T);
  
   figure(1)
   err = .0960*ones(40,1);
   errorbar(1980:2019,climData(101:140,2),err) 
   hold on
   plot(y1T,cest,'r--')
   hold off
   
   
   %I'd say this guess is a little too small
  [a,da,sig_a2,rchi2] = weightedPoly(1,y1T,x1,err);
  
  % Yeah, too small. Lets guess a uncertainty of .1
  % After guessing around, final error bar we're going with is .096 %
  
  %% Part e
  
  
 
  
  years = climData(1:140,1);
  temp = climData(1:140,2);
 
    %Polynomial of degree 2
  p2 = polyfit(years,temp,2);
  p2est = polyval(p2,years);
  
  %Polynomial of degree 5
  p5 = polyfit(years,temp,5);
  p5est = polyval(p3,years);
  
 %Polynomial of degree 7
  p7 = polyfit(years,temp,7);
  p7est = polyval(p7,years);
  
  %Polynomial of degree 10
  p10 = polyfit(years,temp,10);
  p10est = polyval(p10,years);
  

 
  subplot(2,2,1)

   plot(years,p2est,'r')
  hold on
  plot(years,temp,'b--')
  title('n=2')
  hold off
  
  subplot(2,2,2)

  plot(years,p5est,'k')
  hold on
  plot(years,temp,'b--')
  title('n=5')
  hold off
  
  subplot(2,2,3)
  
  plot(years,p7est,'g')
  hold on
  plot(years,temp,'b--')
  title('n=7')
  hold off
  
  subplot(2,2,4)
 
  plot(years,p10est,'m')
  hold on
  plot(years,temp,'b--')
  title('n=10')
  hold off
  
  
  %n=7 is the lowest # polynomial that effectively conveys the details, in
  %our opinion
    
    
    






