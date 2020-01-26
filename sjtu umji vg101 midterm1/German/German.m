function German(filename)%worked for only one number a line
a=fopen(filename,'r');
while ~feof(a)
    A=fgetl(a);
    L=length(A);
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