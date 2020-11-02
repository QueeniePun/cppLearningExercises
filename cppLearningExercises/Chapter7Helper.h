#pragma once
#include "Chapter7Output.h"
#include <string>

class Chapter7Helper
{
public:
    // Supporting data structures
    CHAPTER7::Exercise1Output_s Exercise1Output;
    CHAPTER7::Exercise13Output_s Exercise13Output;


    // Constructor
    Chapter7Helper() :
        Exercise1Output(),
        Exercise13Output()
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
    void RunExercise13(double COMMISSION_SOUGHT);
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
    void RunExercise25();
    void RunExercise26();
    void RunExercise27();

    // Getters

private:
    bool IsPrime(int number);
    int Average(const int array[], int size);
    double Average(const double array[], int size);
    double Min(double array[], int size);
    int IndexOfSmallestElement(double array[], int size);
    double Mean(const double x[], int size);
    double Deviation(const double x[], int size);
    void AssignGrades(double arr[], int size);
    int LinearSearch(const int list[], int key, int arraySize);
    int BinarySearch(const int list[], int key, int arraySize);
    void BubbleSort(double list[], int listSize);
    std::string DropBall(int slots[], int numOfSlots);
    int GetBallPosition(std::string ballPath);
    void PrintHistogram(int array[], int arraySize);
    void SelectionSortDescending(double list[], int listSize);
    void PrintQueensBoard(char queens[], int NUMBER_OF_QUEENS);
    void PlaceQueens(char queens[], int numQueens);
    int PlaceQueensLocation();
    bool IsOccupied(char x);
    bool IsAttacking(char board[]);
    bool IsSameColumn(char board[]);
    bool IsSameRow(char board[]);
    bool IsSameDiagonal(char board[]);
    int GetColumn(int index);
    int GetRow(int index);
    int GetCard();
    std::string ShowCard(int card);
    int IndexOf(const char s1[], const char s2[]);
    int CountCharacters(const char s[], char a);
    int CountLetters(const char s[]);
    void FindPrefix(const char s1[], const char s2[], char commonPrefix[]);
    int GetNumber(char letter);
    void PrintPhoneNumber(const char s[]);

};