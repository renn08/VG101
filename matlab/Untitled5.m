len=length(a);
k=1;
p=1;
b=[];
while k<=len
if a(k)==' '
b=[b;a(p:k-1)];
p=k+1;
end
k=k+1;
end
len = length(b);
a2=[];
for k=2:2:len
a2=[a2;[b(k,:),b(k-1,:)]];
end%转换成十进制整型
a3=hex2dec(a2)