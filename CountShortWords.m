function ret=CountShortWords(N,str)
A=isstrprop(str,'digit');
a=isletter(str);
judge=A+a;
j=0;
for i=1:length(judge)
if judge(i)==0
    j=j+1;
    b(j)=i;
end
end
b=[0,b];
for i=2:length(b)
    d=b(i)-b(i-1)-1;
    n(i-1)=d;
end
t=n<=N&n>=1;
out=n(t);
ret=length(out);
end
