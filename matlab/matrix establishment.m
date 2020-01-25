n=6;
A=zeros(n);
prearr=[1:n,1:n];
for ii=1:n
    A(:,ii)=prearr(ii:ii+n-1);
end
