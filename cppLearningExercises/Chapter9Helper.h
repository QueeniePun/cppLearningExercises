#pragma once
#include <string>
#include "Chapter9Output.h"

class Chapter9Helper
{
public:
    // Supporting data structures
    CHAPTER9::Exercise1Output_s Exercise1Output;

    // Exercise 1
    class Rectangle
    {
    public:
        Rectangle(); // no arg constructor
        Rectangle(double w, double h); // constructor;
        double getWidth();
        double getHeight();
        void setWidth(double w);
        void setHeight(double h);
        double getArea();
        double getPerimeter();
    private:
        double width;
        double height;
    };

    // Exercise 2
    class Fan
    {
    public:
        Fan(); 
        int getSpeed();
        bool getStatus();
        double getRadius();
        void setSpeed(int s);
        void setStatus(bool status);
        void setRadius(double r);

    private: 
        int speed; 
        bool on; 
        double radius;

    };

    // Exercise 3
    class Account
    {
    public:
        Account();
        int getId();
        double getBalance();
        double getAnnualInterestRate();
        void setId(int idNum);
        void setBalance(double amount);
        void setAnnualInterestRate(double rate);
        double getMonthlyInterestRate();
        void withdraw(double amount);
        void deposit(double amount);

    private:
        int id; 
        double balance; 
        double annualInterestRate; 

    };

    // Exercise 4 
    class MyPoint
    {
    public:
        MyPoint();
        MyPoint(double xPoint, double yPoint);
        double getX();
        double getY();
        double getDistance(double x2, double y2);

    private:
        double x; 
        double y; 

    };

    // Exercise 5
    class Time
    {
    public:
        Time();
        Time(int seconds);
        int getHour();
        int getMinute();
        int getSeconds();

    private:
        int hour;
        int minute; 
        int second; 
    };

    // Exercise 6 
    class QuadraticEquation
    {
    public:

        double a = 0;
        double b = 0; 
        double c = 0; 

        // Getters
        double getA();
        double getB();
        double getC();
        double getDiscriminant();
        double getRoot1();
        double getRoot2();

        // Constructor
        QuadraticEquation() {};

        // Destructor 
        ~QuadraticEquation() {};
    private:

    };

    // Constructor
    Chapter9Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter9Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();

    // Getters

private:


};