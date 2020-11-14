#pragma once
#include "Chapter10Output.h"
#include <string>

class Chapter10Helper
{
public:
    // Supporting data structures
    CHAPTER10::Exercise2Output_s Exercise2Output;

    // Exercise 2
    class MyString1
    {
    public:
        char str[255];
        MyString1();
        MyString1(char chars[], int size);
        void append(MyString1 s);
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
        
    };

    // Exercise 3
    class MyString2
    {
    public:
        char str[255];
        MyString2(char chars[], int size);
        void append(int n, char ch);
        void assign(MyString2 s, int n);
        void assign(int n, char ch);
        int compare(int index, int n, MyString2 s);
        void copy(char s[], int index, int n);
        void substr(int index);
        int find(char ch, int index);
        void clear();
    private:

    };

    // Constructor
    Chapter10Helper() :
        Exercise2Output()
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
    std::string Sort(std::string& s);
    bool IsPalindrome(const std::string& s);
    int IndexOf(const std::string& s1, const std::string& s2);
    int CountCharacters(const std::string& s, char a);
    int CountLetters(const std::string& s);
    int ParseHex(const std::string& hexString);
}; 

