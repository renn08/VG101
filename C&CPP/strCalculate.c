#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int judge(char a[51], int i);
float calculateTD(int poS, int pos, char a[51]);
int main()
{
    char a[51];
    int i, j = 0;
    double x = 0;
    int poS = -1;
    float n[51];
    int t = 0;
    int p[51];
    int pos;
    gets(a);
    for (i = 0; i < strlen(a); i++) //为什么printf用%s不能输出//字符数组不使用&
    {
        if (a[i] != ' ')
        {
            a[j++] = a[i]; //先a[j],然后j=j+1
        }
    }
    a[j] = '\0';
    for (i = 0; i < strlen(a); i++)
    {
        if ((judge(a, i) == 2) || (judge(a, i) == 3))
        {
            pos = i;
            t = t + 1;
            n[t - 1] = calculateTD(poS, pos, a);
            p[t - 1] = judge(a, i);
            poS = pos;
        }
    }
    if (t == 0)
    {
        x = calculateTD(-1, strlen(a), a);
        printf("%lf", x);
    }
    else
    {
        pos = strlen(a);
        n[t] = calculateTD(poS, pos, a);
        x = n[0];
        for (i = 0; i < t; i++)
        {
            if (p[i] == 2)
            {
                x = x + n[i + 1];
            }
            if (p[i] == 3)
            {
                x = x - n[i + 1];
            }
        }
        printf("%lf", x);
    }
}
float calculateTD(int poS, int pos, char a[51])
{

    int i, j = 0;
    double x = 0;
    int poS2 = poS;
    float n[51];
    int t = 0;
    int p[51];
    int pos2;
    for (i = poS + 1; i < pos; i++)
    {
        if ((judge(a, i) == 4) || (judge(a, i) == 5))
        {
            char g[51] = {'\0'};
            pos2 = i;
            t = t + 1;
            for (j = poS2 + 1; j < i; j++)
            {
                g[j - 1 - poS2] = a[j];
            }
            n[t - 1] = atof(g);
            p[t - 1] = judge(a, i);
            poS2 = pos2;
        }
    }
    pos2 = pos;
    char f[51] = {'\0'}; //将g全部重设为空元素
    for (j = poS2 + 1; j < pos2; j++)
    {
        f[j - 1 - poS2] = a[j];
    }
    n[t] = atof(f);
    x = n[0];
    for (i = 0; i < t; i++)
    {
        if (p[i] == 4)
        {
            x = x * n[i + 1];
        }
        if (p[i] == 5)
        {
            x = x / n[i + 1];
        }
    }
    return x;
}
int judge(char a[51], int i)
{
    if (a[i] == '.')
    {
        return 1;
    }
    else
    {
        if (isdigit(a[i]))
        {
            return 1;
        }
        if (a[i] == '+')
        {
            return 2;
        }
        if (a[i] == '-')
        {
            return 3;
        }
        if (a[i] == '*')
        {
            return 4;
        }
        if (a[i] == '/')
        {
            return 5;
        }
    }
}