// g++ -std=c++11
// Jigang's note: please change the above to your compiler if needed

// Jigang's note: add additional header files if needed
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int wordsnum(string &p){//return the word number of a sentence.
    int count=0;
    for(int i=0;i<p.length();i++){
        if(p[i]==' '){
            count++;
        }
    }
    count++;
    return count;
}

///////////////////////////////
// Jigang's note: please fill in the codes in each
// function below according to instructions

// problem 1 - please fill in the codes
void P1()
{
    string A;
    getline(cin,A);
    //cout<<endl;
    cout<<"Hello "+A+'!';
}

// problem 2 - please fill in the codes
int P2(int N, int k, int m)
{// feel free to change the following codes in the function
    int S = 0;
    int top=N/k;
    for(int n=1;n<=top;n++){
        S+=pow(n*k,m);
    }
    return S;
}

// problem 3 - please fill in the codes
// you need to add necessary member variables and fill in the provided member functions
class P3
{
    double a,b,c;
    //double x1,y1;
public:
    P3() // constructor with no input arguments. By default, the coefficients (a, b, c) = (1, 0, 0);
    {
        a=1;b=0;c=0;
    }
    P3(double aa, double bb, double cc) // constructor with 3 numbers to initialize the coefficients (a, b, c)
    {
        a=aa;b=bb;c=cc;
    }
    // get solutions of the quadratic function in x and y, return value is the number of solutions
    // if number of solutions = 0, set x = y = 0;
    // if number of solutions = 1, both values of x and y are the solution
    // if number of solutions = 2, x and y are the two solutions where x < y
    int GetSolutions(double &x, double &y)
    {// feel free to change the following codes in the function
        int num = 0; // number of solutions
        double delta=0;
        delta=b*b-4*a*c;
        if(delta<0){
            num=0;
            x = y = 0;
        }
        else if(delta==0){
            num=1;
            if(b/(2*a)==0) x=y=0;
            else x=y=-b/(2*a);

        }
        else{
            num=2;
            x=(sqrt(delta) - b) / 2 * a;
            y=(-sqrt(delta) - b) / 2 * a;
        }
        return num;
    }
};

// problem 4 - please fill in the codes
struct sentence{
    string word;
};

bool cmp1(sentence sentence1,sentence sentence2){
    string n1=sentence1.word,n2=sentence2.word;
        if(n1[0]<n2[0]) return true;
        return false;    
}

void P4()
{
    ifstream in("P4.txt");
    while(!in.eof()){
          sentence sentence[1000];
          string temp;
          string x;
          int i=0;
          getline(in,temp);
          stringstream ss(temp);
          while(ss>>x)
          {
              sentence[i++].word=x;   
    }
    sort(sentence,sentence+i,cmp1);
    for(int j=0;j<i-1;j++){
        cout<<sentence[j].word<<' ';
    }
    cout<<sentence[i-1].word<<endl;
    }
}

// problem 5 - please fill in the codes

void P5()
{
    ifstream In("P5.txt");
    sentence Sentence[1000];
    string Temp;
    string X;
    int i=0;
    getline(In,Temp);
    stringstream SS(Temp);
    while(SS>>X)
          {
              Sentence[i++].word=X;   
    }
    i=wordsnum(Temp);
    vector<int>v;
    vector<int>::iterator it;
    int remain=0;
    int j;
    for(j=1;j<=sqrt(2*i);j++){
        if((j*(j+1))/2<i){
           v.insert(v.begin(),j);
        }
        else break;
    }

    remain=i-((j-1)*(j))/2;
    v.insert(v.begin(),remain);
    
    it=v.begin();
    int record=0;
    for(it=v.begin();it!=v.end();it++){
        for(int m=0;m<*it-1;m++){
           cout<<Sentence[m+record].word<<' ';
        }
        cout<<Sentence[record+*it-1].word<<endl;
        record=*it+record;
    }
}

////////////////////////////////////////////////
// Jigang's note: YOU DON'T NEED TO CHANGE THE FOLLOWING CODES
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
        if (argv[1][1] != '\0') {cout << "Invalid argument!" << endl; return -1;}
        switch(argv[1][0])
        {
            case '1': n = 1; break;
            case '2': n = 2; break;
            case '3': n = 3; break;
            case '4': n = 4; break;
            case '5': n = 5; break;
            default: cout << "Invalid argument!" << endl; return -1;
        }
    }
    cout << "Run problem " << n << endl;
    if (n == 1) P1();
    else if (n == 2)
    {
        // testing codes
        cout << "P2(10, 3, 2) = " << P2(10, 3, 2) << endl;
        cout << "P2(100, 4, 3) = " << P2(100, 4, 3) << endl;
        cout << "P2(50, 6, 4) = " << P2(50, 6, 4) << endl;
        cout << "P2(123, 9, 1) = " << P2(123, 9, 1) << endl;
        cout << "P2(1000, 11, 2) = " << P2(1000, 11, 2) << endl;
    }
    else if (n == 3)
    {
        // testing codes
        P3 eq1, eq2(1, 2, 1), eq3(1, 0, -2), eq4(1, 1, 1);
        double x, y;
        int n;
        n = eq1.GetSolutions(x, y);
        cout << "Equation 1: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
        n = eq2.GetSolutions(x, y);
        cout << "Equation 2: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
        n = eq3.GetSolutions(x, y);
        cout << "Equation 3: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
        n = eq4.GetSolutions(x, y);
        cout << "Equation 4: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
    }
    else if (n == 4) P4();
    else if (n == 5) P5();
    return 0;
}
