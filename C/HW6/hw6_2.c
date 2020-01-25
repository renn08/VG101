#include<stdio.h>
#include<string.h>
void Encode(char *str)
{
    int i;
    int n=strlen(str);
    for(i=0;i<n;i++){
        if((*(str+i)-'A'>=0&&*(str+i)-'Z'<0)||(*(str+i)-'a'>=0&&*(str+i)-'z'<0)){
            *(str+i)=*(str+i)+1;
        }
        else{
            *(str+i)=*(str+i)-25;
        }
    }
}
/* safe version of gets() */
char* vg101_gets(char *str, int count)
{
int i = 0;
char ch = getchar();
while (ch != '\n' && i < count-1)
{
str[i++] = ch;
ch = getchar();
}
str[i] = '\0'; /* add the null character */
return str;
}
int main()
{
char str[256]; /* suppose the length of string is less than 256 */
printf("Please input a string: ");
vg101_gets(str, 256);
Encode(str);
printf("str = %s\n", str);
return 0;
}