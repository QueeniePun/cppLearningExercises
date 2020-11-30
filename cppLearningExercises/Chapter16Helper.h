#pragma once
#include "Chapter16Output.h"
#include <string>
#include <vector>

class Chapter16Helper
{
public:
    // Supporting data structures
    CHAPTER16::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter16Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter16Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();

    // Getters

private:

};

