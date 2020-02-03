function a=SeperateSent(long)
%sent(find(~isspace(sent),1):length(sent));%找到第一个非空格的字符位置并截取句子
%sent=[sent,' '];%最后再加一个空格
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