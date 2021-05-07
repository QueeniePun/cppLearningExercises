#pragma once
#include "Chapter18Output.h"
#include <string>
#include <vector>


class Chapter18Helper
{
public:
    // Supporting data structures
    CHAPTER18::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter18Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter18Helper() {};

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

    void findMaxSortedSubstring(std::string str); 

private:;
};