#ifndef MYPOINT_H
#define MYPOINT_H
#include <string>
using namespace std; 

class MyPoint
{
public:
    MyPoint();
    MyPoint(double xPoint, double yPoint);
    double getX();
    double getY();
    double getDistance(double x2, double y2);
    void setX(double x);
    void setY(double y);

private:
    double x;
    double y;

};

#endif