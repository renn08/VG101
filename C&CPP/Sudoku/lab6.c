#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int* n(){
    FILE *O;
    O=fopen("input.txt","r");
    char n[5];
    fgets(n,5,O);
    fclose(O);
    int x=*n-48;
    int *y=&x;
    return y;
}

void remove_space(char line[]) {
	int num[30], len = strlen(line) , tmp = 0;
	for(int i = 0;i < len; ++i)
		if(line[i] != ' ')
			num[tmp++] = i;
	for(int i = 0;i < tmp; ++i)
		line[i] = line[num[i]];
	line[tmp] = '\0';
	for(int i = tmp+1;i <= len; ++i )  
		line[i] = 0;                                  
}

int find_next_empty(char temp[9][9],int startrow,int* row, int* col){
    int i,j;
    int z=3;

    for(i=startrow;i<9;i++){
        for(j=0;j<9;j++){
            if(temp[i][j]=='-'){
                *row=i;
                *col=j;
                return 1;
            }
        }  
        }
    return 0;
}

int resolve(char temp[9][9],int row,int col){
    int i,j;
    char N;
    int Z=3;
    int next_row,next_col;
    N='A'-1;
    while(1){
        next_num:
        ++N;
        if(N-'A'>=9) break;

        for(j=0;j<9;j++){
            if(temp[row][j]==N){
                goto next_num;
            }
        }

        for(i=0;i<9;i++){
            if(temp[i][col]==N){
                goto next_num;
            }
        }
        
        int x=(row/3)*3;
        int y=(col/3)*3;
        for(i=x;i<x+3;i++){
            for(j=y;j<y+3;j++){
                if(temp[i][j]==N){
                    goto next_num;
                }
            }

        }
        temp[row][col]=N;
        //puts(temp[0]);
        if(!find_next_empty(temp,row,&next_row,&next_col)){
            return 1;
        }
        if(!resolve(temp,next_row,next_col)){
            temp[row][col]='-';
            continue;
        }else{
            return 1; 
        }
}
return 0;
}

void resolve_sudoku(char temp[9][9]){
    int row,col;

    find_next_empty(temp,0,&row,&col);
    resolve(temp,row,col);
}

int main(){
    FILE *O;
    char line[100];
    int i =0;
    int z=3;
    char temp[9][9];
    O = fopen("input.txt", "r");
    while (fgets(line, 100, O)){
    if (line[0] == '\n' || line[0] == '\r'){
      continue;
    }
    else{
      remove_space(line);
      if (!isdigit(*line)){
        for (int j = 0; j < 9; j++){
          temp[i][j] = line[j];
        }
        i++;
        }
    }
    }
  fclose(O);
  resolve_sudoku(temp);
  FILE *o;
    o=fopen("output.txt","w");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            fprintf(o,"%c",temp[i][j]);
        }
        fprintf(o,"\n");
    }
    fclose(o);
  return 0;
}