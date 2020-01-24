function ret=FindDisarium(N)
n=0;
judge=0;
ret(1)=0;
for i=1:N
    L=floor(log(i)/log(10))+1;
    for j=L:-1:1
        dig=mod(floor(i/10^(j-1)),10);
        judge=judge+dig^(L-j+1);
    end
    if judge==i
        ret=[ret,i];
    end
    judge=0;
end
