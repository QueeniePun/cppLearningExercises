#pragma once
#include "Chapter15Output.h"
#include <string>
#include <vector>

class Chapter15Helper
{
public:
    // Supporting data structures
    CHAPTER15::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter15Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter15Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    
    // Getters

private:

};

