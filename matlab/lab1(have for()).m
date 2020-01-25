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
order_number=input('order number');
if order_number==2             %注意=和==
    a=input('input a');
    i=input('input i');
    j=input('input j');
  if     a==1
           x=A(:,i);
           A(:,i)=A(:,j);
           A(:,j)=x;
           disp('B=')
           disp(B)
  else                          %注意换行
           x=A(i,:);
           A(i,:)=A(j,:);
           A(j,:)=x;
           disp('B=')
           disp(B)
  end
elseif  order_number==3
           B=zeros(n,m);
           for i=1:m
               for j=1:n
                   B(j,m-i+1)=A(i,j);
               end
           end
           disp('B=')
           disp(B)
end


    
   