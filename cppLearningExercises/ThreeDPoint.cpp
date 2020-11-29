#include "ThreeDPoint.h"

ThreeDPoint::ThreeDPoint()
{
    setX(0); 
    setY(0);
    z = 0.0;
}

ThreeDPoint::ThreeDPoint(double x, double y, double z)
{
    setX(x);
    setY(y);
    this->z = z;
}

double ThreeDPoint::getZ()
{
    return z; 
}

double ThreeDPoint::getDistance(double a, double b, double c)
{
    double distance = sqrt(pow(a - getX(), 2) + pow(b -getY(), 2) + pow(c - z, 2));
    return distance;
}

void ThreeDPoint::setZ(double z)
{
    this->z = z; 
}
