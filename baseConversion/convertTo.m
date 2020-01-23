function numB=convertTo(numT,Base)
numB=0;
L=floor(log(numT)/log(Base))+1;
for i=1:L
    re=mod(numT,Base);
    numT=(numT-re)/Base;
    numB=numB+re*10^(i-1);
end