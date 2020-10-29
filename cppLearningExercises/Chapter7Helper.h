#pragma once
#include "Chapter7Output.h"

class Chapter7Helper
{
public:
    // Supporting data structures
    CHAPTER7::Exercise1Output_s Exercise1Output;


    // Constructor
    Chapter7Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter7Helper() {};

    // Method
    void RunExercise1(double list[], int listSize);
    void RunExercise2(int list[], int listSize);
    void RunExercise3(int list[], int listSize);
    void RunExercise4();
    void RunExercise5(int list[], int listSize);
    void RunExercise6();
    void RunExercise7();
    void RunExercise8();
    void RunExercise9();
    void RunExercise10();
    void RunExercise11();
    void RunExercise12();
    void RunExercise13();
    double RunExercise14();
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
    void RunExercise26();
    void RunExercise27();

    // Getters

private:
    bool IsPrime(int number);

};