function d = hex2dec(h)
a=isletter(h);
b=isstrprop(h,'digit');
c=[a+b,0];%�ҳ��ո񲿷ֺ��0
B=(c==0);
n=sum(B);%���ֵĸ���
t=1;
for i=1:length(c)
    if c(i)~=0
        A(t,i)=h(i);
    elseif i==length(c)
        break
    elseif c(i)==0
        t=t+1;
        A(t,i)=h(i);%��16�����������һ�������У����пո�
    end
end
for j=1:n
    d(j,:)=strrep(A(1,:));
end
d=hex2dec(d);
sum(d)

end