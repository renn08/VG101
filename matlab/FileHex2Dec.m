function FileHex2Dec(filename)
a=fopen(filename,'r');
while ~feof(a)
    A=fgetl(a);
    B=hex2dec(A);
    b=fopen(['dec_',filename],'a');
    fprintf(b,'%d\n',B);
    fclose(b);
end
fclose(a);
end
