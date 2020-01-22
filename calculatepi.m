function pai=calculatepi(n)
m=0;
for i=1:n
    x=rand;
    y=rand;
    if  (x^2+y^2)<=1
        m=m+1;
    end
end
pai=4*m/n;                   %Monte Carlo Methods