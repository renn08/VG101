#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void revHex(char* str);
int letTonum(char* letter);
char numTolet(int a);
int main()
{   
    int len1,len2,i;
    int t=0;
    char hex1[256],hex2[256],hexsum[256];
    printf("hexadecimal number 1: "); scanf("%s", hex1); 
    printf("hexadecimal number 2: "); scanf("%s", hex2);
    revHex(hex1);
    revHex(hex2);
    len1=strlen(hex1);
    len2=strlen(hex2);
    if (len1<=len2){
        strcpy(hexsum,hex2);
        for (i=0;hex1[i]!=0;i++){
            hexsum[i]=numTolet((letTonum(hex1+i)+letTonum(hex2+i)+t)%16);
            t=(letTonum(hex1+i)+letTonum(hex2+i)+t)/16;
        }
        revHex(hexsum);
    }
    else {
        strcpy(hexsum,hex1);
        for (i=0;hex2[i]!=0;i++){
            hexsum[i]=numTolet((letTonum(hex1+i)+letTonum(hex2+i)+t)%16);
            t=(letTonum(hex1+i)+letTonum(hex2+i)+t)/16;
        }
        revHex(hexsum);
    }
    printf("Their sum is %s\n", hexsum); // hexsum is the sum of hex1 and hex2
    return 0;
}
void revHex(char* str)
{
    int i, len;
    char temp;
    len = strlen(str);
    for (i = 0; i <= len / 2 - 1; i++) 
    {
        temp = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = temp;
    }
}
int letTonum(char* let)
{
    return *let>='A'?*let-55:*let-48;
}
char numTolet(int a)
{   
    return a<10?'0'+a:'A'+a-10;
}