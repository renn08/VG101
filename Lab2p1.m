function myoutput=Lab2p1(filename,a)
fid = fopen(filename,'r');                 %ע������a����������ļ���(��'')        
I = fread(fid,inf, 'uint16');
I=I';
fclose(fid);
Ia = [ones(1, a) * I(1), I];               %���ظ�a�ε���λ������֪����������
S = zeros(1, length(I) + a);               %��������ÿ�ε�shifted����
for i = 1 : (2* a + 1)
	S = S + Ia; 
	Ia = [Ia(2:length(Ia)),Ia(length(Ia))]; 
end
initial = S(1:length(I)) / (2 * a + 1);    %Sliding Average Filter
myoutput=initial(1:2:length(I));           %compress
fid = fopen('output.dat','w');
fwrite(fid,myoutput,'uint16');
fclose(fid);
end
