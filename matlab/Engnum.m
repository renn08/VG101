%According to the tradition of English usage.One-digit number can be
%replaced by English number.Deximals and Multiple-digit number remain the same.
function Engnum(filename)
a=fopen(filename,'r');
while ~feof(a)
    A=fgetl(a);
    L=length(A);
    record=[];
    %���ײ��ð��������֣���ĩҪ���������ð��������֡�
    %�Ƚ�����ı�������ã�Ȼ����ٴ�����ġ�
    for j=1:L
        if (j=1)
            
        end
        record=
    end
    B=[];
    for i=1:L
        B=[B,' ',Corres(str2num(A(i)))];
    end
    L=length(B);
    C=B(2:L);
    b=fopen(['German_',filename],'a');
    fprintf(b,'%s\n',C);
    fclose(b);
end
fclose(a);
end