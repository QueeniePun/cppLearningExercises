#pragma once
#include "Chapter10Output.h"
#include <string>

class Chapter10Helper
{
public:
    // Supporting data structures
    CHAPTER10::Exercise1Output_s Exercise1Output;

    // Exercise 2
    class MyString1
    {
    public:
        MyString1();
        MyString1(char chars[], int size);
        void append(MyString1 s2);
        void append(MyString1 s, int index, int n);
        void assign(char chars[]);
        void assign(MyString1 s, int index, int n);
        char at(int index);
        int length();
        void clear();
        void erase(int index, int n);
        bool empty();
        int compare(MyString1 s);
        void copy(char s[], int index, int n);
        void substr(int index, int n);
        int find(char ch);

    private:
        std::string s1; 
    };


    // Constructor
    Chapter10Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter10Helper() {};

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
    void RunExercise20();
    void RunExercise21();
    void RunExercise22();
    void RunExercise23();
    void RunExercise24();

    // Getters

private:
    bool IsAnagram(std::string s1, std::string s2);

}; 
