#pragma once
#include "Chapter20Output.h"
#include <string>
#include <vector>


class Chapter20Helper
{
public:
    // Supporting data structures
    CHAPTER20::Exercise1Output_s Exercise1Output;


    // Constructor
    Chapter20Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter20Helper() {};

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

    // Getters

private:
};