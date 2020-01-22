function ret =myevall(a)
str=strrep(a,' ','');
n=length(str);
A=zeros(1,n);
for i=1:n
    x=0;
    if str(i)=='+'||'-'||'*'||'/'
       x=i;
    end
    A(i)=str2double(str(i));
end
y=0;
z=0;
for j=1:x-1
y=y+A(1,j)*(10^(j-1))
end
for j=x+1:n
z=z+A(1,j)*(10^(j-x-1))
end
if str(x)=='+'
    ret=y+z;
elseif str(x)=='-'
    ret=y-z;
elseif str(x)=='*'
    ret=y*z;
elseif str(x)=='/'
    ret=y/z;
end




