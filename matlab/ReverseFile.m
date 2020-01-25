function ReverseFile(filename)
a=fopen(filename,'r');
while ~feof(a)
    A = fgetl(a);
    B=A(length(A):-1:1);
    b=fopen('reverse.txt','a');
    fprintf(b,'%s\n',B);
    fclose(b);
end
fclose(a);
end