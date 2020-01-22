function gradeAver=produceAver(filename)%filename 需要加''，格式需像t.txt中一样
a=fopen(filename,'r');
A=fscanf(a,'%c');%用%s会变成一行
B = A(~isletter(A));%取出A中不是字符的元素到B中
B=str2num(B);
gradeAver=sum(B)/length(B);
fclose(a);
end
