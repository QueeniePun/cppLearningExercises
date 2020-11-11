#include "Chapter9Helper.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <array>
#include <Windows.h>

using namespace std;

void Chapter9Helper::RunExercise1()
{
    // 9.1 Design a Rectangle class. Create a test program 

    Rectangle rectangle1(4, 40);
    Rectangle rectangle2(3.5, 35.9);

    cout << "rectangle1 width: " << rectangle1.getWidth() << endl; 
    cout << "rectangle1 height: " << rectangle1.getHeight() << endl; 
    cout << "rectangle2 width: " << rectangle2.getWidth() << endl; 
    cout << "rectangle2 height: " << rectangle2.getHeight() << endl; 

    cout << "rectangle1 area: " << rectangle1.getArea() << endl;
    cout << "rectangle1 perimeter: " << rectangle1.getPerimeter() << endl;
    cout << "rectangle2 area: " << rectangle2.getArea() << endl;
    cout << "rectangle2 perimeter: " << rectangle2.getPerimeter() << endl;


}

Chapter9Helper::Rectangle::Rectangle()
{
    width = 1;
    height = 1; 
}

Chapter9Helper::Rectangle::Rectangle(double w, double h)
{
    width = w; 
    height = h; 
}

double Chapter9Helper::Rectangle::getWidth()
{
    return width;
}

double Chapter9Helper::Rectangle::getHeight()
{
    return height;
}

void Chapter9Helper::Rectangle::setWidth(double w)
{
    width = w; 
}

void Chapter9Helper::Rectangle::setHeight(double h)
{
    height = h; 
}

double Chapter9Helper::Rectangle::getArea()
{
    return width * height; 
}

double Chapter9Helper::Rectangle::getPerimeter()
{
    return (2 * width) + (2 * height);
}

void Chapter9Helper::RunExercise2()
{
    // 9.2 Create a Fan class. 

    Fan fan1; 
    fan1.setSpeed(3); 
    fan1.setStatus(true);

    Fan fan2; 
    fan2.setSpeed(2);
    fan2.setRadius(5);
    fan2.setStatus(false);

    cout << "fan1 speed: " << fan1.getSpeed() << endl;
    cout << "fan1 is on? " << fan1.getStatus() << endl;
    cout << "fan1 radius: " << fan1.getRadius() << endl;
    cout << "fan2 speed: " << fan2.getSpeed() << endl;
    cout << "fan2 is on? " << fan2.getStatus() << endl;
    cout << "fan2 radius: " << fan2.getRadius() << endl;
}

Chapter9Helper::Fan::Fan()
{
    speed = 1; 
    on = false;
    radius = 10; 
}

int Chapter9Helper::Fan::getSpeed()
{
    return speed; 
}

bool Chapter9Helper::Fan::getStatus()
{
    return on;
}

double Chapter9Helper::Fan::getRadius()
{
    return radius; 
}

void Chapter9Helper::Fan::setSpeed(int s)
{
    speed = s; 
}

void Chapter9Helper::Fan::setStatus(bool status)
{
    on = status; 
}

void Chapter9Helper::Fan::setRadius(double r)
{
    radius = r; 
}

void Chapter9Helper::RunExercise3()
{
    // 9.3 Design an Account class 
    Account myAccount;
    myAccount.setId(1122);
    myAccount.setBalance(20000);
    myAccount.setAnnualInterestRate(4.5);
    myAccount.withdraw(2500);
    myAccount.deposit(3000);
    cout << "my current balance: " << myAccount.getBalance() << endl;
    cout << "my monthly interest rate: " << myAccount.getMonthlyInterestRate() << endl;

}

Chapter9Helper::Account::Account()
{
    id = 0; 
    balance = 0; 
    annualInterestRate = 0; 
}

int Chapter9Helper::Account::getId()
{
    return id; 
}

double Chapter9Helper::Account::getBalance()
{
    return balance; 
}

double Chapter9Helper::Account::getAnnualInterestRate()
{
    return annualInterestRate;
}

void Chapter9Helper::Account::setId(int idNum)
{
    id = idNum;
}

void Chapter9Helper::Account::setBalance(double amount)
{
    balance = amount;
}

void Chapter9Helper::Account::setAnnualInterestRate(double rate)
{
    annualInterestRate = rate; 
}

double Chapter9Helper::Account::getMonthlyInterestRate()
{
    return annualInterestRate / 12.0;
}

void Chapter9Helper::Account::withdraw(double amount)
{
    balance -= amount;
}

void Chapter9Helper::Account::deposit(double amount)
{
    balance += amount;
}

void Chapter9Helper::RunExercise4()
{
    // 9.4 Design a MyPoint class
    MyPoint origin; 
    MyPoint myPoint(10, 30.5); 
    cout << "Distance: " << origin.getDistance(myPoint.getX(), myPoint.getY()) << endl;
}

Chapter9Helper::MyPoint::MyPoint()
{
    x = 0;
    y = 0; 
}

Chapter9Helper::MyPoint::MyPoint(double xPoint, double yPoint)
{
    x = xPoint; 
    y = yPoint; 
}

double Chapter9Helper::MyPoint::getX()
{
    return x; 
}

double Chapter9Helper::MyPoint::getY()
{
    return y; 
}

double Chapter9Helper::MyPoint::getDistance(double x2, double y2)
{
    return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

void Chapter9Helper::RunExercise5()
{
    // 9.5 Design a Time Class

    Time currentTime;
    cout << "Current Time is: " << currentTime.getHour() << ":" << currentTime.getMinute() << ":" << currentTime.getSeconds() << endl;

    Time time2(555550);
    cout << time2.getHour()<< ":"  << time2.getMinute() << ":" << time2.getSeconds() << endl;
}

Chapter9Helper::Time::Time()
{
    int totalSeconds = time(0);
    second = totalSeconds % 60;

    int totalMinutes = totalSeconds / 60;
    minute = totalMinutes % 60;

    int totalHours = totalMinutes / 60; 
    hour = totalHours % 24;
}

Chapter9Helper::Time::Time(int seconds)
{
    second = seconds % 60; 
    
    int totalMinutes = seconds / 60;
    minute = totalMinutes % 60; 

    int totalHours = totalMinutes / 60; 
    hour = totalHours % 24;
}

int Chapter9Helper::Time::getHour()
{
    return hour; 
}

int Chapter9Helper::Time::getMinute()
{
    return minute; 
}

int Chapter9Helper::Time::getSeconds()
{
    return second;
}

void Chapter9Helper::RunExercise6()
{
    // 9.6 Design a QuadtraticEquation class 

    QuadraticEquation equation; 

    cout << "Please enter values for a, b, c";
    cin >> equation.a >> equation.b >> equation.c;

    double discriminant = equation.getDiscriminant();
    if (discriminant > 0)
    {
        cout << "Root 1: " << equation.getRoot1() << endl;
        cout << "Root 2: " << equation.getRoot2() << endl;
    }
    else if (discriminant == 0)
    {
        cout << "Root 1: " << equation.getRoot1() << endl;
    }
    else
    {
        cout << "The equation has no real roots." << endl;
    }
}

double Chapter9Helper::QuadraticEquation::getA()
{
    return a; 
}

double Chapter9Helper::QuadraticEquation::getB()
{
    return b;
}

double Chapter9Helper::QuadraticEquation::getC()
{
    return c; 
}

double Chapter9Helper::QuadraticEquation::getDiscriminant()
{
    return (b * b) - (4 * a * c);
}

double Chapter9Helper::QuadraticEquation::getRoot1()
{
    if (getDiscriminant() < 0)
    {
        return 0; 
    }
    else
    {
        double r1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
        return r1;
    }
}
double Chapter9Helper::QuadraticEquation::getRoot2()
{
    if (getDiscriminant() < 0)
    {
        return 0; 
    }
    else
    {
        double r2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
        return r2;
    }
}