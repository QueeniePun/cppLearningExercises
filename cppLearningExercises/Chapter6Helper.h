#pragma once
#include "Chapter6Output.h"

class Chapter6Helper
{
public:
    // Supporting data structures
    CHAPTER6::Exercise1Output_s Exercise1Output;


    // Constructor
    Chapter6Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter6Helper() {};

    // Method
    void RunExercise1(double &num1, double &num2, double &num3);
    void RunExercise2(double a, double b, double c);
    void RunExercise3(double a, double b, double c, double d, double e, double f);
    void RunExercise4(int day, int month, int year);
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
    void CheckSumCraps(int point);
    void ContinueRollDice(int point);
    int CalculateMersennePrime(int n);
};