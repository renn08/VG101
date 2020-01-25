function d= hex2dec(h)
L=length(h);
d=0;
for i=1:L
    if (h(L-i+1)>=65)&&(h(L-i+1)<=70)
        d=d+(h(L-i+1)-65+10)*16^(i-1);
    elseif (h(L-i+1)>=48)&&(h(L-i+1)<=57)
        d=d+(h(L-i+1)-48)*16^(i-1);
    elseif (h(L-i+1)>=97)&&(h(L-i+1)<=102)
        d=d+(h(L-i+1)-97+10)*16^(i-1);
    else 
        fprintf(2,'error\n');
        break;
    end
end