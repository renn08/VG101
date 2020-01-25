N=1000;
A=zeros(N,N);
tic;%显示程序运行多久
for ii=1:N
    for jj=1:N
        A(ii,jj)=8;
    end
end
toc;