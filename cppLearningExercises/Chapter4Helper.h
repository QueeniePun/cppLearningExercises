#pragma once
#include "Chapter4Output.h"

class Chapter4Helper
{
public:
    // Supporting data structures
    CHAPTER4::Exercise1Output_s Exercise1Output;
    CHAPTER4::Exercise7Output_s Exercise7Output;
    CHAPTER4::Exercise8Output_s Exercise8Output;
    CHAPTER4::Exercise9Output_s Exercise9Output;
    CHAPTER4::Exercise15Output_s Exercise15Output;
    // CHAPTER4::Exercise16Output_s Exercise16Output;
    CHAPTER4::Exercise30Output_s Exercise30Output;
    CHAPTER4::Exercise37Output_s Exercise37Output;
    CHAPTER4::Exercise39Output_s Exercise39Output;
    CHAPTER4::Exercise40Output_s Exercise40Output;

    // Constructor
    Chapter4Helper() : 
        Exercise1Output(),
        Exercise7Output(),
        Exercise8Output(),
        Exercise9Output(),
        Exercise15Output(),
        Exercise30Output(),
        Exercise37Output(),
        Exercise39Output(),
        Exercise40Output()
    {};

    // Destructor 
    ~Chapter4Helper() {};

    // Method
    void RunExercise1(int* values, int size);
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();
    void RunExercise7(double initialTuition, double years);
    void RunExercise8(int numStudents, int* studentScores);
    void RunExercise9(int numStudents, int* studentScores);
    void RunExercise10();
    void RunExercise11();
    void RunExercise12();
    void RunExercise13();
    void RunExercise14();
    void RunExercise15(int n1, int n2);
    void RunExercise16(int num);
    void RunExercise17(int numLines);
    void RunExercise18(int numLines);
    void RunExercise19();
    void RunExercise20();
    void RunExercise21(double loan, double years);
    void RunExercise22(double loan, double years, double annualInterest);
    void RunExercise23();
    void RunExercise24();
    void RunExercise25(int n);
    void RunExercise26(int n);
    void RunExercise27();
    void RunExercise28(int year);
    void RunExercise29(int year, int dayIndex);
    void RunExercise30(double amount, double interestRate, int numMonths);
    void RunExercise31(double amount, double percentYield, int numMonths);
    void RunExercise32();
    void RunExercise33(int guess);
    void RunExercise34();
    void RunExercise35();
    void RunExercise36(int arr[9]);
    void RunExercise37(double goalAmount);
    void RunExercise38();
    void RunExercise39(int *arr);
    void RunExercise40(double goalAmount);
    void RunExercise41(int numSeconds);
    void RunExercise42();

    // Getters

private:
};