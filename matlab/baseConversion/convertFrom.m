function numT = convertFrom(numB, Base)%ʮ���Ƽ����±任
numT=0;
for i=1:floor(log10(numB)+1)%���ĳ��Ȼ���fix()��length(num2str(numB))�������һ�ָ���
 re=mod(numB,10);
 numB=(numB-re)/10;
 numT=re*Base^(i-1)+num10;
end