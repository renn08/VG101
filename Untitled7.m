fid=fopen('hexnumber.txt','r');
while ~feof(fid)
    A = fgetl(fid);
end
fclose(fid);
