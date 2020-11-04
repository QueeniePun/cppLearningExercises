#pragma once
#include "Chapter8Output.h"
#include <string>

class Chapter8Helper
{
public:
    // Supporting data structures
    CHAPTER8::Exercise1Output_s Exercise1Output;

    // Constructor
    Chapter8Helper() :
        Exercise1Output()
    {};

    // Destructor 
    ~Chapter8Helper() {};

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
 
    // Getters

private:
    double SumMatrix(const double m[][4], int RowSize, int columnSize);
    double SumMajorDiagonal(const double m[][4]);
    void TotalWorkHours(int workHours[8][7], int NUMBER_OF_EMPLOYEES, int NUMBER_OF_DAYS);
    void AddMatrix(const double a[][3], const double b[][3], double c[][3]);
    void ComputeTax(int status, double income, double rates[], int brackets[4][5]);
    void CheckCheckerboardRows(int checkerboard[8][8]);
    void CheckCheckerboardColumns(int checkerboard[8][8]);
    void CheckCheckerboardMajorDiagonal(int checkerboard[8][8]);
    void CheckCheckerboardSubDiagonal(int checkerboard[8][8]);
    void PlaceTicTacToken(char board[3][3], char token, int row, int col);
    int CheckTicTacBoardStatus(char board[3][3], char token);
    bool CheckTicTacDraw(char board[3][3], char token);
    bool CheckTicTacWin(char board[3][3], char token);
    bool CheckTicTacBoardFilled(char board[3][3]);
    bool CheckTicTacRows(char board[3][3], char token);
    bool CheckTicTacCols(char board[3][3], char token);
    bool CheckTicTacMajorDiagonal(char board[3][3], char token);
    bool CheckTicTacSubDiagonal(char board[3][3], char token);
    void DisplayTicTacBoard(char board[3][3]);
    void MultiplyMatrix(const double a[][3], const double b[][3], double c[][3]);
};