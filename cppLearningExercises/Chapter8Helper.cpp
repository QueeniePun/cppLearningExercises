#include "Chapter8Helper.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <array>
#include <Windows.h>
#include <algorithm>


using namespace std;

void Chapter8Helper::RunExercise1()
{
    // 8.1 Write a function that sums all the integers in a matric of integers
    const int SIZE = 4;
    double m[4][4];
 
    // ReadTheMatrixInputs
    cout << "Enter 4 by 4 matrix row by row:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> m[i][j];
        }
    }

    int sum = SumMatrix(m, SIZE, SIZE);
    cout << sum;
}

double Chapter8Helper::SumMatrix(const double m[][4], int rowSize, int columnSize)
{
    int sum = 0;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            sum += m[i][j];
        }
    }
    return sum;
}

void Chapter8Helper::RunExercise2()
{
    // 8.2 Write a function that sums all the integers in the major diagonal in an 
    //     n x n matrix of integers. The main diagonal of a matrix consists of 
    //     those elements that lie on the diagonal that runs from top left to
    //     bottom right.
    const int SIZE = 4;
    double m[4][4];

    // ReadTheMatrixInputs
    cout << "Enter 4 by 4 matrix row by row:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> m[i][j];
        }
    }

    int sum = SumMajorDiagonal(m);
    cout << sum;
}

double Chapter8Helper::SumMajorDiagonal(const double m[][4])
{
    int sumDiagonal = 0;
    for (int i = 0; i < 4; i++)
    {
        sumDiagonal += m[i][i];
    }
    return sumDiagonal;
}

void Chapter8Helper::RunExercise3()
{
    // 8.3 Rewrite Listing 8.2 Grade Exam to display the students in 
    //     increasing order of the correct answers
    const int NUMBER_OF_STUDENTS = 8;
    const int NUMBER_OF_QUESTIONS = 10;

    char answers[NUMBER_OF_STUDENTS][NUMBER_OF_QUESTIONS] =
    {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    char answerKey[] = { 'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D' };


    int correctCount[NUMBER_OF_STUDENTS][2];
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        int correctCountTemp = 0;
        for (int j = 0; j < NUMBER_OF_QUESTIONS; j++)
        {
            if (answers[i][j] == answerKey[j])
            {
                correctCountTemp++;
            }
        }
        correctCount[i][1] = correctCountTemp;
        correctCount[i][0] = i;
    }

    // sort correctCount[][] in ascending order 

  
    for (int i = 0; i < NUMBER_OF_STUDENTS - 1; i++)
    {
       int currStudent = correctCount[i][0];
        int currGrade = correctCount[i][1];
        int currIndex = i;

        for (int j = i+ 1; j < NUMBER_OF_STUDENTS; j++)
        {
            if (currGrade > correctCount[j][1])
            {
                // update minStudent, minGrade, and minIndex
                currStudent = correctCount[j][0];
                currGrade = correctCount[j][1];
                currIndex = j;
            }
        }

        // swap
        if (currIndex != i)
        {
            correctCount[currIndex][0] = correctCount[i][0];
            correctCount[currIndex][1] = correctCount[i][1];
            correctCount[i][0] = currStudent;
            correctCount[i][1] = currGrade;
        }
    }

    // display the sorted correctCount
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        cout << "Student " << correctCount[i][0] << "'s correct count is " << correctCount[i][1] << endl;
    }
}

