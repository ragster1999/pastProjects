function y = gaussfit(beta,f);

f0 = beta(1);
y0 = beta(2);
A  = beta(3);
FWHM = beta(4);

y = A*exp(-4*log(2)*(f-f0).^2/FWHM^2)+y0;
