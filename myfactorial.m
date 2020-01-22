function output = myfactorial(n)
if n==0
    output=1;
else
    output = n*myfactorial(n-1);
end