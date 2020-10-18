#pragma once
#include "Chapter4Output.h"

class Chapter4Helper
{
public:
    // Supporting data structures
    CHAPTER4::Exercise1Output_s Exercise1Output;
    CHAPTER4::Exercise2Output_s Exercise2Output;
 
    // Constructor
    Chapter4Helper() : 
        Exercise1Output(),
        Exercise2Output()
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
    void RunExercise23();
    void RunExercise24();
    void RunExercise25();

    // Getters

private:
};