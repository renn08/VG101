function ret=CountGaussianPrime(N)
c1=(floor((N-3)/4)+1)*2;
m=zeros(N);
for a=1:N
    for b=1:N
        m(a,b)=a^2+b^2;
    end
end
n=isprime(m);
c2=length(m(n));
ret=c1+c2;
end