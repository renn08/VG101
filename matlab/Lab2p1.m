function myoutput=Lab2p1(filename,a)
fid = fopen(filename,'r');                 %注意输入a，输入输出文件名(带'')        
I = fread(fid,inf, 'uint16');
I=I';
fclose(fid);
Ia = [ones(1, a) * I(1), I];               %将重复a次的首位数与已知数列相连接
S = zeros(1, length(I) + a);               %可以容纳每次的shifted数列
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
