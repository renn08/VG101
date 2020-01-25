#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <time.h>


#define MAXCNN 4
#define MAXCN 53
#define MAXPN 11
#define MAXN 51

#define MAX 51//最大值51
#define MIN 0//最小值0
#define N 51//产生52个不同随机数


struct card{
    char cardN[MAXCNN];
};
struct cardlist{
    struct card card[MAXCN];
};
struct player{
    char name[MAXN];
    int initp;
    int addp;
    struct card card[MAXCN];
    int finp;
};
struct playerlist{
    struct player player[MAXPN];
};


void estcardlist(struct cardlist *p);
char* vg101_gets(char *str, int count);
void readplayer(char*p1,char*p2);
void randomcards(int *p);
void addorquit(int n,struct playerlist*p);
void roundend(int n,int m,struct playerlist*P,struct cardlist*p,int*p1);


int main(){
    int n,i=0;
    struct cardlist allcards;
    struct cardlist *p=&allcards;
    estcardlist(p);//构建卡牌库
    printf("Please input the number of players:");
    scanf("%d",&n);
    struct playerlist playerlist;
    struct playerlist *P=&playerlist;
    for(int i=0;i<n;i++){
        playerlist.player[i].addp=0;//addpoint,finalpoint必须初始化为0。
        playerlist.player[i].finp=0;
        }
    getchar();//getchar()函数的作用是从计算机终端（一般为键盘）获取一个无符号字符。getchar()函数只能接收一个字符，其函数值就是从输入设备获取到的字符。
    //这里可以吸收掉上面输入最后的\n，防止出现bug。
    
    while(i<n){
        char temp1[MAXN]={0},temp2[10]={0};
        printf("Please input the data for player%d:",i+1);
        
        readplayer(temp1,temp2);
        strcpy(playerlist.player[i].name,temp1);
        playerlist.player[i].initp=atoi(temp2);
        i=i+1;
        }//读入结束。
        
        getchar();//
        int cards[N];
        randomcards(cards);//随机产生的卡牌从中从头选取。
        for(int i=0;i<n;i++){//对每个玩家生成初始牌。
            printf("%s please see your cards.\n",playerlist.player[i].name);
            char name[MAXN],a[18]="_initial_card.txt";
            strcpy(name,playerlist.player[i].name);
            strcat(name,a);
            FILE *f;
            f=fopen(name,"w");//注意是""
            fprintf(f,"%s, your card is: %s %s",playerlist.player[i].name,allcards.card[cards[2*i]].cardN,allcards.card[cards[2*i+1]].cardN);
            fclose(f);
            strcpy(playerlist.player[i].card[0].cardN,allcards.card[cards[2*i]].cardN);
            strcpy(playerlist.player[i].card[1].cardN,allcards.card[cards[2*i+1]].cardN);//存到每个player structure的卡牌里
        }
        
        getchar();
        //Game Starts and show three public cards:
        printf("Game Starts!\n");
        printf("Public card 1 is: %s\n",allcards.card[cards[2*n]].cardN);
        printf("Public card 2 is: %s\n",allcards.card[cards[2*n+1]].cardN);
        printf("Public card 3 is: %s\n",allcards.card[cards[2*n+2]].cardN);//round1
        
        getchar();//addorquit1
        addorquit(n,P);
        //round end1
        getchar();
        roundend(3,n,P,p,cards);
        getchar();//round2
        //show the forth card:
        printf("Public card 4 is: %s\n",allcards.card[cards[2*n+3]].cardN);

        getchar();//addorquit2
        addorquit(n,P);
        getchar();
        roundend(4,n,P,p,cards);

        getchar();//round3
        printf("Public card 5 is: %s\n",allcards.card[cards[2*n+4]].cardN);
        addorquit(n,P);
        getchar();
        roundend(5,n,P,p,cards);
        printf("Check rank!\nShow your cards, who ranks the first?\n");
        char temp[MAXN];
        scanf("%s",temp);
        int y;
        for(int i=0;i<n;i++){
            if(!strcmp(temp,playerlist.player[i].name)){
               y=i;
               continue;
            }
            playerlist.player[i].finp=playerlist.player[i].initp;
        }
        for(int i=0;i<n;i++){
            playerlist.player[y].finp=playerlist.player[y].finp+playerlist.player[i].addp;
        }
        for(int i=0;i<n;i++){
            printf("%s final point: %d\n",playerlist.player[i].name,playerlist.player[i].finp);
        }
        printf("Game ends!");
        return 0;
}


void estcardlist(struct cardlist *p){
    for(int i=0;i<52;i++){
        
        if(i<13){
            (*p).card[i].cardN[0]='D';
            if(i<9){
                (*p).card[i].cardN[1]='1'+i;
                (*p).card[i].cardN[2]='\0';//确保安全都在末尾加'\0'。
                }
            else{
                (*p).card[i].cardN[1]='1';
                (*p).card[i].cardN[2]='0'+i-9;
                (*p).card[i].cardN[3]='\0';
                }
                continue;
        }
        if(i<26){
            (*p).card[i].cardN[0]='S';
            if((i-13)<9){
                (*p).card[i].cardN[1]='1'+i-13;
                (*p).card[i].cardN[2]='\0';
            }
            else{
                (*p).card[i].cardN[1]='1';
                (*p).card[i].cardN[2]='0'+i-22;
                (*p).card[i].cardN[3]='\0';
            }
            continue;
        }
        if(i<39){
            (*p).card[i].cardN[0]='C';
            if((i-26)<9){
                (*p).card[i].cardN[1]='1'+i-26;
                (*p).card[i].cardN[2]='\0';
            }
            else{
                (*p).card[i].cardN[1]='1';
                (*p).card[i].cardN[2]='0'+i-35;
                (*p).card[i].cardN[3]='\0';
            }
            continue;
        }
        if(i<52){
            (*p).card[i].cardN[0]='H';
            if((i-39)<9){
                (*p).card[i].cardN[1]='1'+i-39;
                (*p).card[i].cardN[2]='\0';
            }
            else{
                (*p).card[i].cardN[1]='1';
                (*p).card[i].cardN[2]='0'+i-48;
                (*p).card[i].cardN[3]='\0';
            }
            continue;
        }
}
}

char* vg101_gets(char *str, int count){
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
    
void readplayer(char*p1,char*p2){
    char temp1[MAXN]={0},temp2[10]={0};
    int x;
    char temp[MAXN+10];
        vg101_gets(temp,MAXN+10);
    
    for(int i=0;i<strlen(temp);i++){if(isspace(temp[i])){x=i;}}
    strncpy(temp1,temp,x);
    for(int i=x+1;i<strlen(temp);i++){
        temp2[i-x-1]=temp[i];
    }
    strcpy(p1,temp1);
    strcpy(p2,temp2);
    }
    
void randomcards(int *p){
    srand(time(NULL));
    int RandNum;
    int i, j, flag = 0, t=0;
    while(1)
    {
    	flag = 0;
    	if(t == N)
    		break;
    		
		RandNum = (rand()%(MAX - MIN)) + MIN;
		for(i = 0; i < t; i++)
		{
			if(p[i] == RandNum)
				flag = 1;
		}
		if(flag != 1)
		{
			p[t] = RandNum;
			t++;
		}	
	}
}

void addorquit(int n,struct playerlist*p){
        for(int i=0;i<n;i++){
        char temp[2];
        printf("%s, do you want to add?",(*p).player[i].name);
        scanf("%s",temp);
        if(!strcmp(temp,"N")){continue;}
        char temp1[MAXN]={0},temp2[10]={0};
        readplayer(temp1,temp2);
        if(!strcmp(temp,"Y")){
            (*p).player[i].addp=atoi(temp2)+(*p).player[i].addp;
        }          
    }
}

void roundend(int n,int m,struct playerlist*P,struct cardlist*p,int*p1){
        printf("Round end!\n");
        for(int i=0;i<n;i++){
            printf("Public card %d is: %s\n",i+1,(*p).card[p1[2*n+i]].cardN);
        }
        for(int i=0;i<m;i++){
            printf("%s initial point: %d\n",(*P).player[i].name,(*P).player[i].initp);
            printf("%s added point: %d\n",(*P).player[i].name,(*P).player[i].addp);
        }
}





