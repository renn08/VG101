#include <stdio.h>
#include <math.h>
int isprime(int n);
int main()
{ 
    int a;
    int i;
    int sum=0;
    scanf("%d",&a);
    if (a==1)
    {
        printf("%d",0);
        return 0;
    }
    for (i=2;i<a+1;i++)
    {
        if (isprime(i))
        {
            printf("%d ",i);
            sum=sum+i;
        }
    }
    printf("\n%d",sum);
    return 0;

}
int isprime(int n)
{
    int i;
    double limit = sqrt(n) + 1;
    if (n == 1)
    {
        return 0;
    }
    if (n==2)
    {
        return 1;
    }
    for (i=2;i<limit;i++)
    {
        if (n%i==0)
        {
            return 0;
        }
    }
    return 1;
}