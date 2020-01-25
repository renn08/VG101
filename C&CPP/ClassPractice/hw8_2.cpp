#include<iostream>
#include<math.h>
using namespace std;

class MyPoint{
    int x,y;
public:
    MyPoint(){x=0;y=0;}
    void setdata();
    void setdata1(int tempx,int tempy);
    int getdatax();
    int getdatay();
    double distance(MyPoint a){
        return sqrt(pow((a.x-x),2)+pow((a.y-y),2));
    };
};
void MyPoint::setdata(){cin>>x>>y;}
void MyPoint::setdata1(int tempx,int tempy){x=tempx;y=tempy;}
int MyPoint::getdatax(){return x;}
int MyPoint::getdatay(){return y;}

class Triangle{
    MyPoint point1,point2,point3;
public:
    Triangle(){
        point1.setdata1(0,0);
        point2.setdata1(1,0);
        point3.setdata1(0,1);
        };
    Triangle(MyPoint p1,MyPoint p2,MyPoint p3){
        point1.setdata1(p1.getdatax(),p1.getdatay());
        point2.setdata1(p2.getdatax(),p2.getdatay());
        point3.setdata1(p3.getdatax(),p3.getdatay());
    }
    int getArea(){
        double Area;
        Area=((point1.getdatax())*(point2.getdatay())
             +(point2.getdatax())*(point3.getdatay())
             +(point3.getdatax())*(point1.getdatay())
             -(point1.getdatax())*(point3.getdatay())
             -(point2.getdatax())*(point1.getdatay())
             -(point3.getdatax())*(point2.getdatay()))/2;
        return fabs(Area);
    }
    int getPerimeter(){
        double Perimeter;
        Perimeter=point1.distance(point2)+point2.distance(point3)+point3.distance(point1);
        return Perimeter;
    }
};

int main(){
    MyPoint p1,p2,p3;
    p1.setdata();
    p2.setdata();
    p3.setdata();
    Triangle Triangle(p1,p2,p3);
    cout<<"Input: area = "<<Triangle.getArea()<<endl;
    cout<<"perimeter = "<<Triangle.getPerimeter()<<endl;
    return 0;
}
