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

struct record{//对struct的sort写法//构造bool cmp(两个成员)函数，对想要的的排序方式返回true
    string name;
    double money;
};

bool cmp1(record record1,record record2){
    string n1=record1.name,n2=record2.name;
    int size=n1.size()<n2.size()?n1.size():n2.size();
    for(int i=0;i<size;i++){
        if(n1[i]<n2[i]) return true;
        if(n1[i]>n2[i]) return false;
    } 
    return n1.size()<n2.size(); 
}

void Gp1(){
    record record[1215];//构造struct的数组
    double fee=0;
    int i=0;
    while(fee<12.15){
        cin>>record[i].name>>record[i].money;//“用cin>> 读取 字符数组或者字符串 数据时遇到空白字符（包括空格 tab键和回车）作为终止字符。”
        fee+=record[i++].money;//“流提取符 >> 从流中提取 非字符数组或者字符串 数据时通常跳过流中的空格 tab键换行符等空白字符。”
    }
    sort(record,record+i,cmp1);//结束的地址（最后一个数据的后一个数据的地址）
    ofstream fw("outputgp1.txt");
    for(int j=0;j<i;j++){
        fw<<record[j].name<<' '<<record[j].money<<endl;
    }
}

int main(){
    Gp1();
    return 0;
}