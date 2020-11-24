#ifndef CIRCLE_H
#define CIRCLE_H 

class Circle
{
public:
    Circle();
    Circle(double);
    double getArea();
    double getRadius();
    void setRadius(double);
private:
    double radius;
};


bool operator<(Circle &c1, Circle &c2);
bool operator<=(Circle &c1, Circle &c2);
bool operator>(Circle &c1, Circle &c2);
bool operator>=(Circle &c1, Circle &c2);
bool operator==(Circle &c1, Circle &c2);
bool operator!=(Circle &c1, Circle &c2);

#endif