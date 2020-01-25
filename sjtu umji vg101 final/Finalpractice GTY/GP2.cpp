#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct numlist{
    int num;
};

int main(){
    numlist numlist[1000];
    int num;
    int i=0;
    int p=0;
    cin>>numlist[i].num;
    while(numlist[i].num!=0){
        cin>>numlist[++i].num;
    }
    for(int j=0;j<i;j++){
        for(int m=0;m<i;m++){
            if(j==m) continue;
            if(numlist[j].num==numlist[m].num){
                numlist[j].num=0;
                numlist[m].num=0;
            } 
        }
    }
    for(int n=0;n<i;n++){
        if(numlist[n].num!=0){
            cout<<numlist[n].num<<endl;
            break;
        }
    }
    return 0;
}