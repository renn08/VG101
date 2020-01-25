#include <stdio.h> 
#include <string.h>
char* strshift(char *str, int shift) 
{ 
  int i,j;
  int n=strlen(str);
  if(shift>0){
      for(i=0;i<shift;i++){
          char temp=*(str+n-1);
          for(j=0;j<n-1;j++){
              *(str+n-1-j)=*(str+n-2-j);
            }
            *str=temp;
      }
  }
  if(shift<0){
      for(i=0;i<-shift;i++){
          char temp=*str;
          for(j=0;j<n-1;j++){
              *(str+j)=*(str+j+1);//注意不要在两个for嵌套时使用同一个i。
            }
            *(str+n-1)=temp;
      }
  }
  return str; 
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
int shift;
char str[256]; /* suppose the length of string is less than 256 */
char *pstr;

printf("Please input a string: ");
vg101_gets(str, 256);
printf("Please input the shift: ");
scanf("%d", &shift);
pstr = strshift(str, shift);
printf("str = %s\n", str);
printf("*pstr = %s\n", pstr);
return 0;
}