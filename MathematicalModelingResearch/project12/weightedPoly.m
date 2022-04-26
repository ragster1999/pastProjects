function [a,da,sig_a2,rchi2] = weightedPoly(n,x,y,sig_y)


Beta = zeros(1,n+1);
Alpha = zeros(n+1,n+1);

for i = 0:n
Beta(i+1) = sum((1./sig_y.^2).*y.*x.^(i));
for j = 0:n
    Alpha(i+1,j+1) = sum((1./sig_y.^2).*x.^(i).*x.^(j));
end
end

sig_a2 = inv(Alpha);

for j = 1:(n+1)
    da(j) = sqrt(sig_a2(j,j));
end

a = Beta*sig_a2;
f = 0*x;
for i = 1:length(a);
    f = f + a(i).*x.^(i-1);
end
rchi2 = sum(1./sig_y.^2.*(y - f).^2)/(length(x)- n - 1);

