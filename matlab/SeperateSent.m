function a=SeperateSent(long)
%sent(find(~isspace(sent),1):length(sent));%�ҵ���һ���ǿո���ַ�λ�ò���ȡ����
%sent=[sent,' '];%����ټ�һ���ո�
n=1;
while ~isempty(long)
    End=find(~(isspace(long)||isletter(long)),1)-1;
    a{n}=sent(1:End);
    L=length(sent);
    sent=sent(End+1:L);
    sent=sent(find(~isspace(sent),1):length(sent));
    n=n+1;
end
end