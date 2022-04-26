function y = sincfit(beta,f);

f0 = beta(1);
y0 = beta(2);
A  = beta(3);
w = beta(4);

y = A*(sin(w*(f-f0))./(f-f0)).^2+y0;