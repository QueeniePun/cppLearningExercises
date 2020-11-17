#pragma once
#include "Chapter11Output.h"
#include "Chapter9Helper.h"
#include <string>

class Chapter11Helper
{
public:
    // Supporting data structures
    CHAPTER11::Exercise1Output_s Exercise1Output;

    // Exercise 8
    class Circle2D
    {
    public:
        Circle2D();
        Circle2D(double x, double y, double radius);
        double getX();
        double getY();
        double getRadius();
        double getArea();
        double getPerimeter();
        bool contains(double x, double y);
        bool contains(Circle2D& circle);
        bool overlaps(Circle2D& circle);

    private:
        double x;
        double y;
        double radius;
    };

    // Exercise 9
    class Rectangle2D
    {
    public:
        Rectangle2D();
        Rectangle2D(double x, double y, double width, double height);
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
        double getWidth();
        double getHeight();
        void setWidth(double width);
        void setHeight(double height);
        double getArea();
        double getPerimeter();
        bool contains(double x, double y);
        bool contains(Rectangle2D& r);
        bool overlaps(Rectangle2D& r);
    private:
        double x;
        double y;
        double width;
        double height;
    };

    // Constructor
    Chapter11Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter11Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();
    void RunExercise7();
    void RunExercise8();
    void RunExercise9();
    void RunExercise10();

    // Getters

private:
    int* doubleCapacity(int* list, int size);
    int average(int* array, int size);
    double average(double* array, int size);
    int smallestInteger(int* array, int size);
    int* count(const std::string& s);
    void count2(const std::string& s, int counts[], int size);
    bool isTransaction(int choice);
    bool isValidID(int id, Chapter9Helper::Account* account);
    void displayMainMenu();
    void executeTransaction(int choice, Chapter9Helper::Account* account, int id);
    int* countLetters(const std::string& s);
    void countLetters2(const std::string& s, int* counts, int size);
};

