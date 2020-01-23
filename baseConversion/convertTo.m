function numB=convertTo(numT,Base)
L=floor(log(numT)/log(Base))+1;
numB=0;
for i=1:L
    re=mod(numT,Base);
    numT=(numT-re)/Base;
    numB=numB+re*10^(i-1);
end
