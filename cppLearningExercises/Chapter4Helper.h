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
 
    // Constructor
    Chapter4Helper() : 
        Exercise1Output(),
        Exercise7Output(),
        Exercise8Output(),
        Exercise9Output(),
        Exercise15Output()
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
    void RunExercise25();

    // Getters

private:
};