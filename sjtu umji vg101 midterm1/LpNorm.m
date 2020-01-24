function ret = LpNorm(x, p)
x=abs(x);
for i=1:length(x)
    c(1,i)=(x(1,i))^p;
end
ret=(sum(c))^(1/p);
end