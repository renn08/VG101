function numT = convertFrom(numB, Base)%十进制及以下变换
numT=0;
for i=1:floor(log10(numB)+1)%数的长度还用fix()或length(num2str(numB))经试验第一种更快
 re=mod(numB,10);
 numB=(numB-re)/10;
 numT=re*Base^(i-1)+num10;
end