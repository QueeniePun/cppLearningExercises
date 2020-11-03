#pragma once
#include "Chapter8Output.h"
#include <string>

class Chapter8Helper
{
public:
    // Supporting data structures
    CHAPTER8::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter8Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter8Helper() {};

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
 
    // Getters

private:
    double SumMatrix(const double m[][4], int RowSize, int columnSize);
    double SumMajorDiagonal(const double m[][4]);
};