function num10 = convertFrom(numB, Base)%��ʱ�޷�ʵ�ִ���ʮ���Ƶ�ת�������Ľ���
num10=0;
for i=1:floor(log10(numB)+1)%���ֵĳ��Ȼ���fix()��length(num2str(numB))���������һ�ָ���
 a=mod(numB,10);
 numB=(numB-a)/10;
 num10=a*Base^(i-1)+num10;
 end