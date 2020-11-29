#include "MyPoint.h"

MyPoint::MyPoint()
{
    x = 0;
    y = 0;
}

MyPoint::MyPoint(double xPoint, double yPoint)
{
    x = xPoint;
    y = yPoint;
}

double MyPoint::getX()
{
    return x;
}

double MyPoint::getY()
{
    return y;
}

double MyPoint::getDistance(double x2, double y2)
{
    return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

void MyPoint::setX(double x)
{
    this->x = x;
}

void MyPoint::setY(double y)
{
    this->y = y;
}