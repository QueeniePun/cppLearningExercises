#pragma once
#include "Chapter6Output.h"

class Chapter6Helper
{
public:
    // Supporting data structures
    CHAPTER6::Exercise14Output_s Exercise14Output;


    // Constructor
    Chapter6Helper() :
        Exercise14Output()
    {};

    // Destructor 
    ~Chapter6Helper() {};

    // Method
    void RunExercise1(double &num1, double &num2, double &num3);
    void RunExercise2(double a, double b, double c);
    void RunExercise3(double a, double b, double c, double d, double e, double f);
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();
    int RunExercise7(bool needNewSeed);
    void RunExercise8();
    void RunExercise9();
    void RunExercise10();
    void RunExercise11(int year, int month);
    void RunExercise12(double side);
    void RunExercise13();
    double RunExercise14(double num);
    void RunExercise15(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    // Getters

private:
    void SolveQuadraticEquation(double a, double b, double c, double& discriminant, double& r1, double& r2);
    void SolveLinearEquation(double a, double b, double c, double d,
        double e, double f, double& x, double& y, bool& LinearEquationIsSolvable);
    bool LinearEquationIsSolvable(double a, double b, double c, double d);
    void CurrentTime();
    void CurrentDate(int& day, int& month, int& year);
    bool IsEmirp(int n); 
    bool IsPrime(int n);
    int ReverseInteger(int n);
    bool IsPalindrome(int n);
    int RollDice();
    int RollTwoDice();
    bool CheckSumCraps(int point);
    bool ContinueRollDice(int point);
    int CalculateMersennePrime(int n);
    double AreaRegularPolygon(int n, double side);
    int ZellersAlgorithm(int year, int month, int day);
    void PrintMonth(int year, int month);
    void PrintMonthTitle(int year, int month);
    void PrintMonthBody(int year, int month);
    void PrintMonthName(int month);
    int GetNumberDaysInMonth(int year, int month);
    bool IsLeapYear(int year);
};