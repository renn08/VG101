function numB=convertTo(numT,Base)
<<<<<<< HEAD
numB=0;
L=floor(log(numT)/log(Base))+1;
=======
L=floor(log(numT)/log(Base))+1;
numB=0;
>>>>>>> 0059a06317a9b1ea769555b2c9146f3145873cb2
for i=1:L
    re=mod(numT,Base);
    numT=(numT-re)/Base;
    numB=numB+re*10^(i-1);
<<<<<<< HEAD
end
=======
end
>>>>>>> 0059a06317a9b1ea769555b2c9146f3145873cb2
