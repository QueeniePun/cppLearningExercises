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
    void RunExercise11(char ch1, char ch2, int numberPerLine);
    void RunExercise12();
    void RunExercise13(int num);
    void RunExercise14();
    void RunExercise15();
    void RunExercise16(int n);
    void RunExercise17();
    void RunExercise18();
    void RunExercise19(double side1, double side2, double side3);
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
    bool IsPrime(int number);
    double ComputeCommission(double salesAmount);
    double Exercise12Series(double i);
    double ComputeTax(int status, double taxableIncome);
    int NumberOfDaysInAYear(int year);
    char GetRandomCharacter(char ch1, char ch2);
    char GetRandomUpperCaseLetter();
    char GetRandomDigitCharacter();
    bool TriangleIsValid(double side1, double side2, double side3);
    double TriangleArea(double side1, double side2, double side3);
    double FutureInvestmentValue(double investmentAmount, double monthlyINterestRate, int years);
};