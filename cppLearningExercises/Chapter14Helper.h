#pragma once
#include "Chapter14Output.h"
#include <string>
#include <vector>


class Chapter14Helper
{
public:
    // Supporting data structures
    CHAPTER14::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter14Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter14Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();
    void RunExercise7();

    // Getters

private:

};

