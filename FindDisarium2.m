function ret = FindDisarium2(N)
c=0;
for i=1:N
    a=num2str(i);
    b=0;
    for j=1:length(a)
        b=b+str2num(a(j))^j;
    end
    if b==i
        c=c+1;
        ret(c)=b;
    end
end
end