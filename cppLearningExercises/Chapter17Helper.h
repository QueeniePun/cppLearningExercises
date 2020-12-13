#pragma once
#include "Chapter17Output.h"
#include <string>
#include <vector>

class Chapter17Helper
{
public:
    // Supporting data structures
    CHAPTER17::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter17Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter17Helper() {};

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
    void RunExercise11();
    void RunExercise12();
    void RunExercise13();
    void RunExercise14();
    void RunExercise15();
    void RunExercise16();
    void RunExercise17();
    void RunExercise18();
    void RunExercise19();
    void RunExercise20();

    // Getters

private:
    int factorial(int n);
    int fib(int index);
    int gcd(int m, int n);
    double sumExercise4(double i);
    double sumExercise5(double i);
    double sumExercise6(double i);
    int computeFibonacci(int index);
    void reverseDisplay(int value);
    void reverseDisplay(const std::string &s);
    int count(const std::string& s, char a);
    int sumDigits(long n);
    void reverseDisplay(const std::string& s, int high);
    int maxArray(int arr[], int n);
    int countUppercase(const std::string& s);
    int count2(const std::string& s, char a);
    int count2(const std::string& s, char a, int high);
    void moveDisks(int n, char fromTower, char toTower, char auxTower);
};