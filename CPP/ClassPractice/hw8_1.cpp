#include<iostream>
#include<math.h>
using namespace std;
class MyPoint{
    int x,y;
public:
    MyPoint(){x=0;y=0;}
    void setdata();
    int getdatax();
    int getdatay();
    int distance(MyPoint a){
        return sqrt(pow((a.x-x),2)+pow((a.y-y),2));
    };
};
void MyPoint::setdata(){cin>>x>>y;}
int MyPoint::getdatax(){return x;}
int MyPoint::getdatay(){return y;}
int main(){
    MyPoint p1,p2;
    p1.setdata();
    p2.setdata();
    cout<<"Input: distance = "<<p1.distance(p2)<<endl;
    return 0;
}

