function gradeAver=produceAver(filename)%filename ��Ҫ��''����ʽ����t.txt��һ��
a=fopen(filename,'r');
A=fscanf(a,'%c');%��%s����һ��
B = A(~isletter(A));%ȡ��A�в����ַ���Ԫ�ص�B��
B=str2num(B);
gradeAver=sum(B)/length(B);
fclose(a);
end
