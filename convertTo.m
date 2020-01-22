function numB=convertTo(num10,Base)
 L=floor(log(num10)/log(Base))+1;
 numB=0;
 for i=1:L
     b=mod(num10,Base);
     num10=(num10-b)/Base;
     numB=numB+b*10^(i-1);
end