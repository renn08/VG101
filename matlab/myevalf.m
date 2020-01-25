function ret =myevalf(str)
str=strrep(str,' ','');
n=length(str);
A=zeros(1,n);
B=zeros(1:n-1);
for i = 1 : n
    A(i) = str2double(str(i));         %把数字输入到一个矩阵中
end
y = 0;
z = 0;
x = find(isnan(A));                    %找到运算符的位置
B=A(2:n);
if length(x)~=1
    x = find(isnan(B))+1;
    n=n-1;
  for j = 1 : x - 2                    %1：1就是 j=1
    y = y + B(1,j) * (10 ^ (x-j-2));
  end
  y=-y;
  for j = x  : n
    z = z + B(1,j) * (10 ^ (n-j));
  end
else
  for j = 1 : x - 1                    %1：1就是 j=1
    y = y + A(1,j) * (10 ^ (x-1-j));
  end
  for j = x + 1 : n
    z = z + A(1,j) * (10 ^ (n-j));
  end
end
if str(x) == '+'
    ret = y + z;
elseif str(x) == '-'
    ret = y - z;
elseif str(x) == '*'
    ret = y * z;
elseif str(x) == '/'
    ret = y / z;
end

