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

void Chapter8Helper::RunExercise4()
{
    // 8.4 Weekly hours for all employees are stored in a 2d array, each 
    //     row record an employee's 7day work hour with 7 columns. Write 
    //     a program that displays the employees and their total hours in 
    //     decreasing order of total hours 

    const int NUMBER_OF_EMPLOYEES = 8;
    const int NUMBER_OF_DAYS = 7;
    int workHours[NUMBER_OF_EMPLOYEES][NUMBER_OF_DAYS] =
    {
        {2, 4, 3, 4, 5, 8, 8},
        {7, 3, 4, 3, 3, 4, 4},
        {3, 3, 4, 3, 3, 2, 2},
        {9, 3, 4, 7, 3, 4, 1},
        {3, 5, 4, 3, 6, 3, 8},
        {3, 4, 4, 6, 3, 4, 4},
        {3, 7, 4, 8, 3, 8, 4},
        {6, 3, 5, 9, 2, 7, 9}
    };

    TotalWorkHours(workHours, NUMBER_OF_EMPLOYEES, NUMBER_OF_DAYS);
}

void Chapter8Helper::TotalWorkHours(int workHours[8][7], int NUMBER_OF_EMPLOYEES, int NUMBER_OF_DAYS)
{
    // Find total work hours in decreasing order of the total hours 
    
    // initialize totalHours array 
    int totalHours[8][2];
    for (int row = 0; row < 8; row++)
    {

        totalHours[row][0] = row;
        totalHours[row][1] = 0;
    }

    // find sum for each employee
    for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
    {
        totalHours[i][0] = i;
        totalHours[i][1] = 0;
        for (int j = 0; j < NUMBER_OF_DAYS; j++)
        {
            totalHours[i][1] += workHours[i][j];
        }
        
    }

    // sort totalHours in decreasing order
    for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
    {

        int currMaxEmployee = totalHours[i][0];
        int currMaxHour = totalHours[i][1];
        int currMaxIndex = i;
        for (int j = i + 1; j < NUMBER_OF_EMPLOYEES; j++)
        {
            if (currMaxHour < totalHours[j][1])
            {
                // update the max 
                currMaxEmployee = totalHours[j][0];
                currMaxHour = totalHours[j][1];
                currMaxIndex = j;
            }

            // swap if the currMaxHour is not the current max in the total hours array
            if (currMaxHour != totalHours[i][1])
            {
                totalHours[currMaxIndex][0] = totalHours[i][0];
                totalHours[currMaxIndex][1] = totalHours[i][1];
                totalHours[i][0] = currMaxEmployee;
                totalHours[i][1] = currMaxHour;

            }
        }

    }

    // display results 
    for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++) 
    {
        cout << "Employee " << totalHours[i][0] << "'s total hours: " << totalHours[i][1] << endl;
    }
}

void Chapter8Helper::RunExercise5()
{
    // 8.5 Write a function to add two matrices a and b and save the result in c 

    double matrix1[][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double matrix2[][3] =
    {
        {0, 2, 4},
        {1, 4.5, 2.2},
        {1.1, 4.3, 5.2}
    };

    double matrix3[3][3];

    AddMatrix(matrix1, matrix2, matrix3);

}

void Chapter8Helper::AddMatrix(const double a[][3], const double b[][3], double c[][3])
{
    // add matrices a and b

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }


    // display a + b = c
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << a[i][j] << " " << endl;
            }
            else
            {
                cout << a[i][j] << " ";
            }
        }
    }

    cout << " + \n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << b[i][j] << " " << endl;
            }
            else
            {
                cout << b[i][j] << " ";
            }
        }
    }

    cout << "= \n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << c[i][j] << " " << endl;
            }
            else
            {
                cout << c[i][j] << " ";
            }
        }
    }
}

void Chapter8Helper::RunExercise6()
{
    // 8.6 Rewrite Listing 3.4 ComputeTax using arrays 

    double rates[] = { 0.10, 0.15, 0.27, 0.30, 0.35, 0.386 };
    int brackets[4][5] =
    {
        {6000, 27950, 67700, 141250, 307050}, // single filer 
        {1200, 46700, 112850, 171950, 307050}, // married jointly
        {6000, 23350, 56425, 85975, 153525}, // married separately
        {10000, 37450, 96700, 156600, 307050} // head of household
    };

    int status;
    cout << "Enter filing status: 0 single filer, 1 married jointly, 2 married separately, 3 head:" << endl;
    cin >> status;

    double income;
    cout << "Enter income" << endl;
    cin >> income;

    ComputeTax(status, income, rates, brackets);
}

void Chapter8Helper::ComputeTax(int status, double income, double rates[], int brackets[4][5])
{
    double tax = 0;

    if (income < brackets[status][0])
    {
        tax = income * rates[0];
    }
    else if (income <= brackets[status][1])
    {
        tax = brackets[status][0] * rates[0] + ((income - brackets[status][0]) * rates[1]);
    }
    else if (income <= brackets[status][2])
    {
        tax = brackets[status][0] * rates[0] + (brackets[status][1] - brackets[status][0]) * rates[1]
            + ((income - brackets[status][1]) * rates[2]);
    }
    else if (income <= brackets[status][3])
    {
        tax = brackets[status][0] * rates[0] + (brackets[status][1] - brackets[status][0]) * rates[1]
            + (brackets[status][2] - brackets[status][1]) * rates[2] + ((income - brackets[status][2]) * rates[3]);
    }
    else if (income <= brackets[status][4])
    {
        tax = brackets[status][0] * rates[0] + (brackets[status][1] - brackets[status][0]) * rates[1]
            + (brackets[status][2] - brackets[status][1]) * rates[2]
            + (brackets[status][3] - brackets[status][2]) * rates[3]
            + ((income - brackets[status][3]) * rates[4]);
    }
    else
    {
        tax = brackets[status][0] * rates[0] 
            + (brackets[status][1] - brackets[status][0]) * rates[1]
            + (brackets[status][2] - brackets[status][1]) * rates[2]
            + (brackets[status][3] - brackets[status][2]) * rates[3]
            + (brackets[status][4] - brackets[status][3]) * rates[4]
            + ((income - brackets[status][4]) * rates[5]);
    }

    cout << tax; 
}

void Chapter8Helper::RunExercise7()
{
    // 8.7 Write a program that randomly fills 0's and 1's into an 8 x8 checker board 
    //     display the board, find the rows, columns, or diagonals with all 0s or 1s 
    //     use a 2d array to represent a checkerboard 

    int checkerboard[8][8];

    // fill in the board with 0's and 1's randomly
    srand(time(0));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            checkerboard[i][j] = rand() % 2;
        }
    }

    // display the board 
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 7) 
            {
                cout << checkerboard[i][j] << endl;
            }
            else
            {
                cout << checkerboard[i][j];
            }
        }
    }



    int test[8][8] =
    {
        {1, 0, 0, 0, 0, 0, 1, 1},

        {1, 1, 1, 1, 1, 1, 1, 1},

        {0, 0, 1, 1, 0, 1, 1, 0},

        {0, 0, 0, 1, 1, 0, 1, 0},

        {0, 0, 0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 1, 1, 1, 1}
    }; 
    CheckCheckerboardRows(test);
    CheckCheckerboardColumns(test);
    CheckCheckerboardMajorDiagonal(test);
    CheckCheckerboardSubDiagonal(test);

}

void Chapter8Helper::CheckCheckerboardRows(int checkerboard[8][8])
{
    // find the rows with all 0s or 1s 
    for (int i = 0; i < 8; i++)
    {
        bool isSameAsBoardKey = true;
        int boardKey = checkerboard[i][0];
        int j = 0;
        while (isSameAsBoardKey && j != 7)
        {
            if (boardKey != checkerboard[i][j + 1])
            {
                isSameAsBoardKey = false;
            }
            j++;
        }
        if (isSameAsBoardKey) 
        {
            cout << "Row " << i << " has the same " << boardKey << "s" << endl;
        }
    }
}

void Chapter8Helper::CheckCheckerboardColumns(int checkerboard[8][8])
{
    for (int j = 0; j < 8; j++)
    {
        bool isSameAsBoardKey = true;
        int boardKey = checkerboard[0][j];
        int i = 0;
        while (isSameAsBoardKey && i != 7)
        {
            if (boardKey != checkerboard[i+1][j])
            {
                isSameAsBoardKey = false;
            }
            i++;
        }
        if (isSameAsBoardKey)
        {
            cout << "Column " << j << " has the same " << boardKey << "s" << endl;
        }
    }
}
void  Chapter8Helper::CheckCheckerboardMajorDiagonal(int checkerboard[8][8])
{
    // top left diagonal to bottom right 
    
    bool isSameAsBoardKey = true;
    int boardKey = checkerboard[0][0];
    for (int i = 0; i < 7; i++)
    {
        if (boardKey != checkerboard[i + 1][i + 1])
        {
            isSameAsBoardKey = false; 
        }
    }
    if (isSameAsBoardKey)
    {
        cout << "Top left diagonal to bottom right has all " << boardKey << "s" << endl;
    }
}

void Chapter8Helper::CheckCheckerboardSubDiagonal(int checkerboard[8][8])
{
    // top right to bottom left diagonal
    bool isSameAsBoardKey = true; 
    int boardKey = checkerboard[7][7];
    for (int i = 7; i > 0; i--)
    {
        if (boardKey != checkerboard[i - 1][i - 1])
        {
            isSameAsBoardKey = false;
        }
    }
    if (isSameAsBoardKey)
    {
        cout << "Top right to bottom left diagonal has all " << boardKey << "s" << endl;
    }
}

void Chapter8Helper::RunExercise8()
{
    // 8.8 Create a program for playing TicTacToe as follows
    //     1. The program prompts first player to enter an X token. Then 2nd player to 
    //        enter an O token. Whenever a token is entered, the program refreshes the
    //        the board and determines the status of game (win, draw, unfinished)
    //     2. To place a token, prompt user to enter the row and column for the token

    char board[3][3] = 
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };


    // get user input
    // update board (place the token)
    // get board status
    // continue playing if unfinished
    char token;
    int row; 
    int col;
    int status = 2;
    while (status == 2)
    {
        cout << "Please enter your token ";
        cin >> token;
        cout << "Please enter the row ";
        cin >> row;
        cout << "Please enter the column ";
        cin >> col;

        PlaceTicTacToken(board, token, row, col);
        DisplayTicTacBoard(board); 

        if (CheckTicTacBoardStatus(board, token) == 1)
        {
            cout << token << "s win" << endl;
            status = 1;
        }
        if (CheckTicTacBoardStatus(board, token) == 0)
        {
            cout << "draw" << endl;
            status = 0;
        }
        
    }
}

void Chapter8Helper::DisplayTicTacBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << board[i][j] << endl;
            }
            else
            {
                cout << board[i][j];
            }
        }
    }
}
void Chapter8Helper::PlaceTicTacToken(char board[3][3], char token, int row, int col)
{
    board[row][col] = token;
}

int Chapter8Helper::CheckTicTacBoardStatus(char board[3][3], char token)
{
    int status; 
    if (CheckTicTacWin(board, token))
    {
        status = 1;
    }
    else if (CheckTicTacDraw(board, token))
    {
        status = 0; 
    }
    else // game is unfinished
    {
        status = 2; 
    }

    return status; 
}

bool Chapter8Helper::CheckTicTacDraw(char board[3][3], char token)
{
    // check if board is filled
    if (CheckTicTacBoardFilled(board) && !(CheckTicTacWin(board, token)))
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

bool Chapter8Helper::CheckTicTacBoardFilled(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool Chapter8Helper::CheckTicTacWin(char board[3][3], char token)
{
    // win if there are 3 in a row, 3 in col, 3 on the diagonals 
    if (CheckTicTacRows(board, token) || CheckTicTacCols(board, token) || CheckTicTacMajorDiagonal(board, token)
        || CheckTicTacSubDiagonal(board, token))
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

bool Chapter8Helper::CheckTicTacRows(char board[3][3], char token)
{
    for (int i = 0; i < 3; i++)
    {
        bool isSameAsBoardKey = true;
        char boardKey = board[i][0];
        int j = 0;
        while (isSameAsBoardKey && j != 2 && boardKey != ' ')
        {
            if (boardKey != board[i][j + 1])
            {
                isSameAsBoardKey = false;
            }
            j++;
        }
        if (isSameAsBoardKey && boardKey != ' ')
        {
            return true;
        }
    }
    return false; 
}


bool Chapter8Helper::CheckTicTacCols(char board[3][3], char token)
{
    for (int j = 0; j < 3; j++)
    {
        bool isSameAsBoardKey = true;
        char boardKey = board[0][j];
        int i = 0;
        while (isSameAsBoardKey && i != 2 && boardKey != ' ')
        {
            if (boardKey != board[i + 1][j])
            {
                isSameAsBoardKey = false;
            }
            i++;
        }
        if (isSameAsBoardKey && boardKey != ' ')
        {
            return true; 
        }
    }
    return false; 
}

bool Chapter8Helper::CheckTicTacMajorDiagonal(char board[3][3], char token)
{
    bool isSameAsBoardKey = true;
    char boardKey = board[0][0];
    for (int i = 0; i < 2; i++)
    {
        if (boardKey != board[i + 1][i + 1] && boardKey != ' ')
        {
            isSameAsBoardKey = false;
        }
    }
    if (isSameAsBoardKey && boardKey != ' ')
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

bool Chapter8Helper::CheckTicTacSubDiagonal(char board[3][3], char token)
{
    bool isSameAsBoardKey = true;
    char boardKey = board[2][2];
    for (int i = 2; i > 0; i--)
    {
        if (boardKey != board[i - 1][i - 1] && boardKey != ' ')
        {
            isSameAsBoardKey = false;
        }
    }
    if (isSameAsBoardKey && boardKey != ' ')
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

void Chapter8Helper::RunExercise9()
{
    double matrix1[][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double matrix2[][3] =
    {
        {0, 2, 4},
        {1, 4.5, 2.2},
        {1.1, 4.3, 5.2}
    };

    double matrix3[3][3] =
    {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    MultiplyMatrix(matrix1, matrix2, matrix3);
}

void Chapter8Helper::MultiplyMatrix(const double a[][3], const double b[][3], double c[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int h = 0; h < 3; h++)
            {
                c[i][j] += a[i][h] *  b[h][j];
            }
        }
    }


    // display a * b = c
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << a[i][j] << " " << endl;
            }
            else
            {
                cout << a[i][j] << " ";
            }
        }
    }

    cout << " * \n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << b[i][j] << " " << endl;
            }
            else
            {
                cout << b[i][j] << " ";
            }
        }
    }

    cout << "= \n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << c[i][j] << " " << endl;
            }
            else
            {
                cout << c[i][j] << " ";
            }
        }
    }
}

void Chapter8Helper::RunExercise10()
{
    // 8.10 Listing 8.3 finds one closest pair. Revise the program to find all closest pairs if 
    //      multiple closest pairs exist. 
}