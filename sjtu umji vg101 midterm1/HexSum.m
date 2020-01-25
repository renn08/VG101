function ret=HexSum(str)%str format:'1A 2B 3C' 
ret=0;
spArr=find(isspace(str));
spNum=length(spArr);
b=[0,spArr,length(str)+1];
for i=1:spNum+1
    ret=ret+hex2dec(str((b(i)+1):b(i+1)-1));
end
ret=dec2hex(ret);
end