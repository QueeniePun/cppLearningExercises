#pragma once
#include "Chapter5Output.h"

class Chapter5Helper
{
public:
    // Supporting data structures
    CHAPTER5::Exercise2Output_s Exercise2Output;


    // Constructor
    Chapter5Helper() :
        Exercise2Output()
    {};

    // Destructor 
    ~Chapter5Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2(long n);
    void RunExercise3(int number);
    int RunExercise4(int number);
    bool RunExercise5(int number);
    void RunExercise6(int n);
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
    void RunExercise21();
    void RunExercise22();


    // Getters

private:
    int getPentagonalNumber(int n);
    double CelsiusToFahrenheit(double celsius);
    double FahrenheitToCelsius(double fahrenheit);
    double FootToMeter(double foot);
    double MeterToFoot(double meter);



};