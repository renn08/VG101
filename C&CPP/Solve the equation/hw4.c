#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, delta, x1, x2;
    printf("Please enter the coefficients: ");
    scanf("%lf,%lf,%lf", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        if (a != 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Solutions: %g, %g\n", x1, x2); // two solutions
        }
        else
        {
            x1 = -c / b;
            printf("Solution: %g\n", x1); // one solution
        }
    }
    else
    {
        if (delta == 0)
        {
            if (b == 0)
              x1 = 0; 
            else
              x1 = (sqrt(delta) - b) / 2 * a;
            printf("Solution: %g\n", x1); // one solution          //problem:0/a=-0????
        }
        else
        {
            printf("No real solution!\n");
        }
    }
    return 0;
}