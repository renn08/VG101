clear all 
clc
m=input('input m');
n=input('input n');
q=input('input q');
A=zeros(m,n);
for i=1:m
  for j=1:n
    A(i,j)=mod(q+i*n+j,m*n);
  end
end
disp('A=')
disp(A)


