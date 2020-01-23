function num10 = convertFrom(numB, Base)%暂时无法实现大于十进制的转换（待改进）
num10=0;
for i=1:floor(log10(numB)+1)%数字的长度或用fix()或length(num2str(numB))经过试验第一种更快
 a=mod(numB,10);
 numB=(numB-a)/10;
 num10=a*Base^(i-1)+num10;
 end