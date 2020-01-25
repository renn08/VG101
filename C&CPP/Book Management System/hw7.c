#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXT 101
#define MAXBN 1001
#define MAXC 101
#define MAXN 101
#define MAXID 101
char* vg101_gets(char *str, int count) 
{ 
    int i = 0; 
    char ch = getchar();
    
    while (ch != '\n' && i < count-1) 
    { 
        str[i++] = ch; 
        ch = getchar(); 
    } 
    str[i] = '\0'; 
    return str; 
}
struct book{
    char title[MAXT];
    char id[MAXID];
    int isborrow;//初始为0。
};
struct library{
    struct book booklist[MAXBN];
}library;
struct borrowid{
    char id[MAXID];
};
struct customer{
    char name[MAXN];
    char id[MAXID];
    struct borrowid borrowlist[MAXBN];//struct borrowid{char}[MAXBN];//初始设为0
};
struct customerlist{
    struct customer customerlist[MAXC];
}customerlist;
int main(){
    for(int i=0;i<MAXBN;i++){
        memset(library.booklist[i].id,0,sizeof(char)*MAXID);
        library.booklist[i].isborrow=0;//初始全部未借出。
    }
    for(int i=0;i<MAXC;i++){
        memset(customerlist.customerlist[i].id,0,sizeof(char)*MAXID);
        for(int j=0;j<MAXBN;j++){
            for(int z=0;z<MAXID;z++){
                customerlist.customerlist[i].borrowlist[j].id[z]=0;
                }
            
        }
        
    }
    char res[256];
    char RES[256];
    printf("Welcome to the library management system, please type your commands.\n");
    while(1){
        printf("> ");
        memset(res,0,sizeof(char)*256);
        memset(RES,0,sizeof(char)*256);
        vg101_gets(res, 256);
        for(int i=0;i<(int)strlen(res);i++){
            if(res[i]==32){
                break;
            }
            RES[i]=res[i];
        }//void *memset(void *s, int ch, size_t n);函数解释将s中当前位置后面的n个字节用ch替换并返回s。
        if(!strcmp(RES,"exit")){
            break;
        }
        else if(!strcmp(RES,"addbook")){
            int i,j=0,n=0;
            int m=0;
            
            struct book addbook;
            memset(addbook.id,0,sizeof(char)*MAXID);
            memset(addbook.title,0,sizeof(char)*MAXT);
            char bookname[100]={0};
            char temp[10]={0};
            for(i=8;i<(int)strlen(res);i++){
                if(res[i]==32){
                    j=i;
                    break;
                }
                temp[i-8]=res[i];
            }
            for(i=j+1;i<(int)strlen(res);i++){
               bookname[i-j-1]=res[i];
            }
            strcpy(addbook.title,bookname);
            for(int i=0;i<(int)strlen(temp);i++){
                addbook.id[i]=temp[i];
                }
                
                addbook.isborrow=0;
            for(i=0;i<MAXBN;i++){
                if(!strcmp(library.booklist[i].id,temp)){
                   m=1;
                   break;
                }
            }
            if(m==1){
                printf("The book ID already exists.\n");
                continue;
                }
                
            for(i=0;i<MAXBN;i++){//检索可放的序号
                if(library.booklist[i].id[0]==0){
                    n=i;
                    break;
                }
            }
            library.booklist[n]=addbook;
            printf("%s added to the system.\n",bookname);
        }
        else if(!strcmp(RES,"addcustomer")){
            int i,j=0,n=0;
            int m=0;
            struct customer addcustomer;
            memset(addcustomer.id,0,sizeof(char)*MAXID);
            
            memset(addcustomer.name,0,sizeof(char)*MAXN);
            char customername[100]={0};
            char temp[10]={0};
            for(i=12;i<(int)strlen(res);i++){
                if(res[i]==32){
                    j=i;
                    break;
                }
                temp[i-12]=res[i];
            }
            //int id=atoi(temp);
            for(i=j+1;i<(int)strlen(res);i++){
               customername[i-j-1]=res[i];
            }
            strcpy(addcustomer.name,customername);//
            for(int i=0;i<(int)strlen(temp);i++){
                addcustomer.id[i]=temp[i];
                }
                
            for(int j=0;j<MAXBN;j++){
                for(int z=0;z<MAXID;z++){
                    addcustomer.borrowlist[j].id[z]=0;}
                
            }
            for(i=0;i<MAXC;i++){
                if(!strcmp(customerlist.customerlist[i].id,temp)){
                   m=1;
                   break;
                }
            }
            if(m==1){
                printf("The customer ID already exists.\n");
                continue;
                }
            for(i=0;i<MAXC;i++){//检索可放的序号
                if(customerlist.customerlist[i].id[0]==0){
                    n=i;
                    break;
                }
            }
            customerlist.customerlist[n]=addcustomer;
            printf("%s added to the system.\n",customername);
        }
        else if(!strcmp(RES,"checkb1")){
            int i,n;
            char temp[10]={0};
            for(i=8;i<(int)strlen(res);i++){
                temp[i-8]=res[i];
            }
            //id=atoi(temp);
            for(i=0;i<MAXBN;i++){//不满足条件也会+1
                if(!strcmp(library.booklist[i].id,temp)){
                    n=i;
                    break;
                }
            }
            if(i!=MAXBN){
                if(library.booklist[n].isborrow){
                    printf("%s %s borrowed\n",library.booklist[n].id,library.booklist[n].title);
                    }
                else{
                    printf("%s %s on shelf\n",library.booklist[n].id,library.booklist[n].title);
                    }
            }
            else{
                printf("\n");
                }
        }
        else if(!strcmp(RES,"checkb2")){
            int i;
            int m=0;
            char title[101]={0};
            for(i=8;i<(int)strlen(res);i++){
                title[i-8]=res[i];
            }
            for(i=0;i<MAXBN;i++){//不满足条件也会+1
                if(!strcmp(title,library.booklist[i].title)){
                    m=1;
                    if(library.booklist[i].isborrow){
                        printf("%s %s borrowed\n",library.booklist[i].id,library.booklist[i].title);
                    }
                    else{
                        printf("%s %s on shelf\n",library.booklist[i].id,library.booklist[i].title);
                    }
                }
            }
            if(m==0){
                printf("\n");
            }
        }
        else if(!strcmp(RES,"checkc")){
            int i,n=0,j,m=0;
            char temp[10]={0};
            for(i=7;i<(int)strlen(res);i++){
                temp[i-7]=res[i];
            }
            //cid=atoi(temp);
            for(i=0;i<MAXC;i++){//不满足条件也会+1
                if(!strcmp(customerlist.customerlist[i].id,temp)){
                    n=i;
                    break;
                }
            }//找到此顾客位置
            printf("Book borrowed by %s:\n",customerlist.customerlist[n].name);
            for(i=0;i<MAXBN;i++){
                if(customerlist.customerlist[n].borrowlist[i].id[0]!='\0'){
                    //customerlist.customerlist[n].borrowlist[i].id;
                     for(j=0;j<MAXBN;j++){//不满足条件也会+1
                            if(!strcmp(library.booklist[j].id,customerlist.customerlist[n].borrowlist[i].id)){
                             m=j;
                    break;
                }
            }//找到此书位置
                    printf("%s %s\n",library.booklist[j].id,library.booklist[m].title);
                }
                
            }
        }
        else if(!strcmp(RES,"borrow")){
            //int bid,cid;
            int i,j=0,n1=0,n2=0;
            char temp1[10]={0};
            char temp2[10]={0};
            for(i=7;i<(int)strlen(res);i++){
                if(res[i]==32){
                    j=i;
                    break;
                }
                temp1[i-7]=res[i];
            }
            //bid=atoi(temp1);
            for(i=j+1;i<(int)strlen(res);i++){
               temp2[i-j-1]=res[i];
            }
            //cid=atoi(temp2);
            for(i=0;i<MAXBN;i++){//不满足条件也会+1
                if(!strcmp(library.booklist[i].id,temp1)){
                    n1=i;
                    break;
                }
            }//找到此书位置
            for(i=0;i<MAXC;i++){//不满足条件也会+1
                if(!strcmp(customerlist.customerlist[i].id,temp2)){
                    n2=i;
                    break;
                }
            }//找到此顾客位置
            if(library.booklist[n1].isborrow){//假如不能借出
                printf("Fail! The book was borrowed by another customer.\n");
                continue;
            }
            else{//能借出
                library.booklist[n1].isborrow=1;
                     for(i=0;i<MAXBN;i++){//检索可放的序号
                     if(customerlist.customerlist[n2].borrowlist[i].id[0]=='\0'){
                     strcpy(customerlist.customerlist[n2].borrowlist[i].id,temp1);
                     break;
                }
                }
                printf("Success! %s is borrowed by %s.\n",library.booklist[n1].title,customerlist.customerlist[n2].name);
            }
        }
        else if(!strcmp(RES,"return")){
            //int bid;
            int i,n1=0,j;
            char temp[10]={0};
            for(i=7;i<(int)strlen(res);i++){
               temp[i-7]=res[i];
            }
            //bid=atoi(temp);
            for(i=0;i<MAXBN;i++){//不满足条件也会+1
                if(!strcmp(library.booklist[i].id,temp)){
                    n1=i;
                    break;
                }
            }//找到此书位置
            if(library.booklist[n1].isborrow==0){
                printf("Fail! The book has not been borrowed.\n");
                continue;
            }
            library.booklist[n1].isborrow=0;
            for(i=0;i<MAXC;i++){
                for(j=0;j<MAXBN;j++)
                if(!strcmp(customerlist.customerlist[i].borrowlist[j].id,temp)){
                    memset(customerlist.customerlist[i].borrowlist[j].id,0,sizeof(char)*MAXID);
                    break;
                }
            }//找到还书顾客位置并将借书记录删去。
            printf("Success! The following book has been returned:\n%s %s\n",temp,library.booklist[n1].title);
        }
        else if(!strcmp(RES,"listbook")){
            int n=0;
            for(int i=0;i<MAXBN;i++){
                if(library.booklist[i].id[0]!=0){
                    printf("%s %s",library.booklist[i].id,library.booklist[i].title);
                    if(library.booklist[i].isborrow){
                        printf(" borrowed\n");
                    }
                    else{
                        printf(" on shelf\n");
                    }

                }
                else{n=n+1;}           
            }
            if(n==MAXBN){printf("There is no book in the system.\n");}
        }
        else if(!strcmp(RES,"listcustomer")){
            int n=0;
            for(int i=0;i<MAXC;i++){
                if(customerlist.customerlist[i].id[0]!=0){
                    printf("%s %s\n",customerlist.customerlist[i].id,customerlist.customerlist[i].name);
                    }
                else{n=n+1;}
            }
            if(n==MAXC){printf("There is no customer in the system.\n");}
        }
        
        else{
            printf("Unknown command!\n");
        }
    }
    printf("Exit the system!");
    return 0;
}
