#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "GeometricObject.h"

class Triangle : public GeometricObject
{
public: 
    Triangle();
    Triangle(double side1, double side2, double side3);
    double getSide1();
    double getSide2();
    double getSide3();
    double getArea();
    double getPerimeter();
private:
    double side1;
    double side2;
    double side3;
};

#endif