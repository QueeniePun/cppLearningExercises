#ifndef THREEDPOINT_H
#define THREEDPOINT_H
#include "MyPoint.h"
#include <string>
using namespace std; 

class ThreeDPoint : public MyPoint
{
public:
    ThreeDPoint();
    ThreeDPoint(double x, double y, double z);
    double getZ();
    double getDistance(double a, double b, double c);
    void setZ(double z);

private:
    double z; 

};

#endif