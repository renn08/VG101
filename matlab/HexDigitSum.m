function ret = HexDigitSum(str)
a=length(str);
b=isletter(str);
letarr=str(b);
numarr=str(~b);
dec=0;
for i=1:length(numarr)
    dec=dec+str2double(numarr(i));
end
for i=1:length(letarr)
    dec=dec+hex2dec(letarr(i));
end
ret=dec2hex(dec);
end