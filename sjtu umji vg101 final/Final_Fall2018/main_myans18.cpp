// g++ -std=c++11
// Jigang's note: please change the above to your compiler if needed
// (e.g., Visual Studio, Code::blocks, Xcode, etc.)

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
//
// Jigang's note: add additional header files if needed
//

using namespace std;

int isprime(int n){
    int i;
    double limit = sqrt(n) + 1;
    if (n == 1){
        return 0;
    }
    if (n==2){
        return 1;
    }
    for (i=2;i<limit;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

int isin(int n,int*p){
    for(int i=0;p[i]!=0;i++){
        if(n==p[i]){
            return 1;
        }
    } 
    return 0;
}

void removespace(char*p){
    int i,j=0;
    for(i=0;i<strlen(p);i++){
        if(p[i]!=' '){
            p[j++] = p[i];
            }
    }     
    p[j] = '\0';
}

int judgesign(char*p,int i){
    if(p[i]=='+'){
        return 1;
    }
    if(p[i]=='-'){
        return 2;
    }
    if(p[i]=='i'){
        return 3;
    }
    return 0;
}

int wordsnum(string p){
    int count=0;
    for(int i=0;i<p.length();i++){
        if(p[i]==' '){
            count++;
        }
    }
    count++;
    return count;
}

double max(double x,double y){
    if(x<y) return y;
    else return x; 
}
double min(double x,double y){
    if(x>y) return y;
    else return x;
}

///////////////////////////////
// Jigang's note: please fill in the codes
// in each function below according to
// instruction in each problem

// problem 1 - please fill in the codes
void P1()
{
    int prime[101]={0};
    int semiprime[101]={0};
    int n=0,m=0;
    for(int i=1;i<101;i++){
        if(!isprime(i)){
            cout<<i<<endl;
        }
    }
    
    for(int i=1;i<101;i++){
        if(isprime(i)){
            prime[n]=i;
            n=n+1;
            }
    }
    
    for(int i=0;prime[i]!=0;i++){
        int temp;
        for(int j=i;prime[j]!=0;j++){
            temp=prime[i]*prime[j];
            semiprime[m]=temp;
            if(semiprime[m]>100){
                break;
            }
            m++;
            }
        
    }
    
    for(int i=1;i<=100;i++){
        if(isin(i,semiprime)){
            continue;
        }
        else{
            cout<<i<<endl;
        }
    }
}

// problem 2 - please fill in the codes
void P2()
{
    char c1[20]={'\0'};
    char c2[20]={'\0'};
    int poss1=0,posi1=-1,poss2=0,posi2=-1;
    char re1[20]={'\0'},re2[20]={'\0'};
    char im1[20]={'\0'},im2[20]={'\0'};
    gets(c1);
    gets(c2);
    removespace(c1);
    removespace(c2);
    for(int i=0;i<strlen(c1);i++){
        if(i){
            if((judgesign(c1,i)==1)||(judgesign(c1,i)==2)){
            poss1=i;
        }}
        if(judgesign(c1,i)==3){
            posi1=i;
        }
    }
    for(int i=0;i<strlen(c2);i++){
        if(i){
            if((judgesign(c2,i)==1)||(judgesign(c2,i)==2)){
            poss2=i;
        }}
        if(judgesign(c2,i)==3){
            posi2=i;
        }
    }
    if(poss1==0){
        if(posi1==-1){
            strcpy(re1,c1);
            im1[0]='0';
        }
        else{
              if(strlen(c1)>2||isdigit(c1[0])){
                 re1[0]='0';
                 for(int i=0;i<(strlen(c1)-1);i++){
                 im1[i]=c1[i];
                 }
              }
              else{
                re1[0]='0';
                c1[strlen(c1)-1]='1';
                for(int i=0;i<strlen(c1);i++){
                    im1[i]=c1[i];
                }
              }
            }
    }
    else{
       for(int i=0;i<poss1;i++){
           re1[i]=c1[i];
       }
       for(int i=poss1;i<posi1;i++){
           im1[i-poss1]=c1[i];
       }
       if((poss1+1)==posi1){
           im1[1]='1';
       }
    }
    if(poss2==0){
        if(posi2==-1){
            strcpy(re2,c2);
            im2[0]='0';
        }
        else{
              if(strlen(c2)>2||isdigit(c2[0])){
                 re2[0]='0';
                 for(int i=0;i<(strlen(c2)-1);i++){
                 im2[i]=c2[i];
                 }
              }
              else{
                re2[0]='0';
                c2[strlen(c2)-1]='1';
                for(int i=0;i<strlen(c2);i++){
                    im2[i]=c2[i];
                }
              }
            }
    }
    else{
       for(int i=0;i<poss2;i++){
           re2[i]=c2[i];
       }
       for(int i=poss2;i<posi2;i++){
           im2[i-poss2]=c2[i];
       }
       if((poss2+1)==posi2){
           im2[1]='1';
       }
    }
    double r1,r2,i1,i2;
    double re,im;
    r1=atof(re1);
    i1=atof(im1);
    r2=atof(re2);
    i2=atof(im2);
    re=-(r1*r2+i1*i2)/(r1*r1+i1*i1);
    im=(r2*i1-r1*i2)/(r1*r1+i1*i1);
    
    if(re!=0){
    if(im!=1&&im>0){cout<<re<<'+'<<im<<'i'<<endl;}
    if(im!=-1&&im<0){cout<<re<<im<<'i'<<endl;}
    if(im==1){cout<<re<<"+i"<<endl;}
    if(im==-1){cout<<re<<"-i"<<endl;}
    }
    if(re==0){
    if(im!=1&&im!=-1&&im!=0){cout<<re<<endl;}
    if(im==1){cout<<"i"<<endl;}
    if(im==-1){cout<<"-i"<<endl;}
    }
    if(im==0){
    if(re!=0){cout<<re<<endl;}
    if(re==0){cout<<'0'<<endl;}
    }
}

// problem 3 - please fill in the codes
void P3()
{
   string filename;
   string str;
   cin>>filename;
   ifstream in(filename.c_str());
   if(in.is_open()){
      while(!in.eof()){
          string str1;
          string temp;
          getline(in,temp);
          temp[temp.size()-1]=' ';
          int wordnum=wordsnum(temp);
          str1=' '+temp.substr(0,temp.find(" ",0))+'.';
          for(int i=temp.find(" ",0);i<temp.size()-1;i++){
              if(isspace(temp[i])){
                 string temp1=temp.substr(i,temp.find(" ",i+1)-i);
                 str1=temp1+str1;
                }
          }
          str1.erase(0,1);
          str=str1+str;
      }
   }
    ofstream out("P3_result.txt");  
    if (out.is_open()){ 
        out<<str.substr(0,str.find(".",0)+1)<<endl; 
        for(int i=str.find(".",0);i<str.size()-1;i++){
            if(str[i]=='.'){
                out<<str.substr(i+1,str.find(".",i+1)-i)<<endl;
            }
        }
    }  
}

// problem 4 - please fill in the codes
class P4
{
    double lx,rx,ly,ry;
public:
    P4()
    {
        lx=0;rx=0;ly=0;ry=0;
    }
    P4(double x1, double y1, double x2, double y2)
    {
        lx=min(x1,x2);
        rx=max(x1,x2);
        ly=min(y1,y2);
        ry=max(y1,y2);
    } 
    
    double lx1(){return lx;}
    double rx1(){return rx;}
    double ly1(){return ly;}
    double ry1(){return ry;}
    
    double OverlapArea(P4& rt)
    {
        double area;
        
        double width,bwidth,width1=rx-lx,width2=rt.rx1()-rt.lx1();
        double height,bheight,height1=ry-ly,height2=rt.ry1()-rt.ly1();
        
        bwidth=max(rx,rt.rx1())-min(lx,rt.lx1());
        bheight=max(ry,rt.ry1())-min(ly,rt.ly1());
        
        width=width1+width2-bwidth;
        height=height1+height2-bheight;
        
        if(width<=0||height<=0) area=0;
        else area=width*height;
        
        return area;
    }
};

// problem 5 - please fill in the codes
void P5()
{
}

////////////////////////////////////////////////
// Jigang's note:
// YOU DON'T NEED TO CHANGE THE FOLLOWING CODES
/////////////////////////////
void preP1() // problem 1
{
    cout << "Run Problem 1" << endl;
    P1();
}

void preP2() // problem 2
{
    cout << "Run Problem 2" << endl;
    P2();
}

void preP3() // problem 3
{
    cout << "Run Problem 3" << endl;
    P3();
}

void preP4() // problem 4
{
    cout << "Run Problem 4" << endl;
    double x1, y1, x2, y2;
    cout << "Input x1, y1, x2, y2 (separate by spaces): ";
    cin >> x1 >> y1 >> x2 >> y2;
    P4 rt1, rt2(0, 0, 2, 4), rt3(x1, y1, x2, y2);
    cout << "Overlapped area of rt1 and rt2 = " << rt1.OverlapArea(rt2) << endl;
    cout << "Overlapped area of rt2 and rt3 = " << rt2.OverlapArea(rt3) << endl;
}

void preP5() // problem 5
{
    cout << "Run Problem 5" << endl;
    P5();
}

// Jigang's note: you don't need to change the main function
// to test your program, run the file and input the problem number
// as instructed
int main(int argc, char** argv)
{
    int n = 0; // problem number
    if (argc == 1)
    {
        cout << "Input problem number (1-5): ";
        cin >> n;
        cin.ignore(); // ignore the rest of stdin buffer
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "1") == 0) n = 1;
        else if (strcmp(argv[1], "2") == 0) n = 2;
        else if (strcmp(argv[1], "3") == 0) n = 3;
        else if (strcmp(argv[1], "4") == 0) n = 4;
        else if (strcmp(argv[1], "5") == 0) n = 5;
        else {cout << "Invalid argument!" << endl; return -1;}
    }
    if (n == 1) preP1();
    else if (n == 2) preP2();
    else if (n == 3) preP3();
    else if (n == 4) preP4();
    else if (n == 5) preP5();
    return 0;
}
