#pragma once
#include "Chapter11Output.h"
#include <string>

class Chapter11Helper
{
public:
    // Supporting data structures
    CHAPTER11::Exercise1Output_s Exercise1Output;

    
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
    
};

