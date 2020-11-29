#include "Triangle.h"

Triangle::Triangle()
{
    side1 = 1.0;
    side2 = 1.0;
    side3 = 1.0;
}

Triangle::Triangle(double side1, double side2, double side3)
{
    this->side1 = side1; 
    this->side2 = side2;
    this->side3 = side3;
}

double Triangle::getSide1()
{
    return side1; 
}

double Triangle::getSide2()
{
    return side2;
}

double Triangle::getSide3()
{
    return side3;
}

double Triangle::getArea()
{
    double p = getPerimeter() / 2.0;
    double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return area; 
}

double Triangle::getPerimeter()
{
    double perimeter = side1 + side2 + side3;
    return perimeter;
}

