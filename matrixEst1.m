function A=matrixEst1(n)
arr=[1:n,1:n];
for i=1:n
A(i,:)=arr(i:i+n-1);
end
end