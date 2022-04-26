function y = lorentzfit(beta,f);

f0 = beta(1);
y0 = beta(2);
A  = beta(3);
FWHM = beta(4);

y = A*(FWHM/2)^2./((f-f0).^2+(FWHM/2)^2)+y0;