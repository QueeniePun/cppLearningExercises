#pragma once
#include "Chapter19Output.h"
#include <string>
#include <vector>


class Chapter19Helper
{
public:
    // Supporting data structures
    CHAPTER19::Exercise1Output_s Exercise1Output;


    // Constructor
    Chapter19Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter19Helper() {};

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
    template<typename T>
    void genericBubbleSort(T *items, int arraySize);

    template<typename T> 
    void printArray(std::vector<T>& v, int size);
    
    template<typename T>
    void genericMerge(std::vector<T>& v, int p, int q, int r);

    template<typename T>
    void genericMergeSort(std::vector<T>& v, int p, int r);

};