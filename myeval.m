function ret =myeval(str)
str=strrep(str,' ','');
n=length(str);
for i=2:n
    if str(i)=='+'||...
       str(i)=='-'||...
       str(i)=='*'||...
       str(i)=='/'
        x=i;               %找到运算符的真实位置，从2开始以避免计入负数前的负号                         
    break
    end
end
y=str2double(str(1:x-1));
z=str2double(str(x+1:n));
if str(x) == '+'
    ret = y + z;
elseif str(x) == '-'
    ret = y - z;
elseif str(x) == '*'
    ret = y * z;
elseif str(x) == '/'
    ret = y / z;
end                       %此函数可进行对所有整数（包括负数）、小数的加减乘除运算