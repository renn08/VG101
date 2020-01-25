// g++ -std=c++11
// Jigang's note: please change the above to your compiler if needed
// (e.g., Visual Studio, Code::blocks, Xcode, etc.)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
//
// Jigang's note: add additional header files if needed
//

using namespace std;

///////////////////////////////
// Jigang's note: please fill in the codes
// in each function below according to
// instruction in each problem

// problem 1 - please fill in the codes
void P1()
{
}

// problem 2 - please fill in the codes
void P2()
{
}

// problem 3 - please fill in the codes
void P3()
{
}

// problem 4 - please fill in the codes
class P4
{
public:
    P4()
    {
    }
    P4(double x1, double y1, double x2, double y2)
    {
    }
    double OverlapArea(P4& rt)
    {
        double area;
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
