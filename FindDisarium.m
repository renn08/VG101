function ret = FindDisarium(N)
n=0;
for i=1:N
    L=length(num2str(i));
    a=0;
    c=0;
    for j=1:L
        c=mod(i,10);
        a=a+c^(L+1-j);
        c=(i-c)/10;
    end
    if a==i
        n=n+1;
        ret(n)=a;
    end
end
end