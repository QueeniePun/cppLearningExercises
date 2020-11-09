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
    char boardKey = board[0][2];
    for (int i = 0; i < 2; i++)
    {
        if (boardKey != board[i + 1][1 - i] && boardKey != ' ')
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

    const int NUMBER_OF_POINTS = 8; 

    // Each row in points represent a point
    double points[NUMBER_OF_POINTS][2] =
    {
        {-1, 3},
        {-1, -1},
        {1, 1},
        {2, 0.5},
        {2, -1},
        {3, 3},
        {4, 2},
        {4, -0.5}
    };

    // p1 and p2 are the indices in the points array
    int p1 = 0, p2 = 1;

    // Initialize shortest distance
    double shortestDistance = GetDistance(points[p1][0], points[p1][1], points[p2][0], points[p2][1]);

    // Compute distance for every two points
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        for (int j = i + 1; j < NUMBER_OF_POINTS; j++)
        {
            double distance = GetDistance(points[i][0], points[i][1], points[j][0], points[j][1]);

            if (shortestDistance > distance)
            {
                p1 = i;
                p2 = j;
                shortestDistance = distance; 
            }
        }
    }

    // now we have the shortest distance, loop through points in array to find the points with this distance 
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        for (int j = i + 1; j < NUMBER_OF_POINTS; j++)
        {
            double distance = GetDistance(points[i][0], points[i][1], points[j][0], points[j][1]);

            if (shortestDistance == distance)
            {
cout << "The closest two points are " << "(" << points[p1][0] << ", " << points[p1][1] << ") and (" <<
        points[p2][0] << ", " << points[p2][1] << ")";                
            }
        }
    }

}

double Chapter8Helper::GetDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void Chapter8Helper::RunExercise11()
{
    // 8.11 Nine coins are placed in 3 x 3. Represent the state of the coins using values 0 for heads, 1 tails
    //      Each state can be represented using a binary number. Total num possibilities 512. Write a program 
    //      that prompts the user to enter a num between 0 and 511 and displays the matrix with H or T 

    // get user input 
    int userInt; 
    cout << "Enter a number between 0 and 511: "; 
    cin >> userInt; 

    // convert integer to binary
    int binaryArray[9];
    int* pBinaryArray = DecimalToBinary(binaryArray, userInt);
    
    // display the binary 
    for (int i = 0; i < 9; i++)
    {
        printf("%d", pBinaryArray[i]);
    }
    cout << endl;

    // fill in the corresponding matrix with H = 0, T = 1; 
    char coinMatrix[3][3];
    int h = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (pBinaryArray[h] == 0)
            {
                coinMatrix[i][j] = 'H';
            }
            else
            {
                coinMatrix[i][j] = 'T';
            }
            h++;
        }
    }

    // display the coin matrix 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("%c \n", coinMatrix[i][j]);
            }
            else
            {
                printf("%c ", coinMatrix[i][j]);
            }
        }
    }
}

int * Chapter8Helper::DecimalToBinary(int * binaryArray, int decimal)
{
    // initialize the binary array and index 
    int i = 8;

    int remainder = decimal;
    while (i >= 0)
    {
        binaryArray[i] = remainder % 2;
        remainder = remainder / 2;
        i--;
    }

    return binaryArray;
}

void Chapter8Helper::RunExercise12()
{
    // 8.12 Revise Listing 8.3 such that hte program finds two points in a three dimensional array closest
    //      to each other. Use a 2-d array to represent the points. 

    const int NUMBER_OF_POINTS = 8;
    double points[][3] =
    {
        {-1, 0, 3},
        {-1, -1, -1},
        {4, 1, 1},
        {2, 0.5, 9},
        {3.5, 2, -1},
        {3, 1.5, 3},
        {-1.5, 4, 2},
        {5.5, 4, -0.5}
    };

    // p1, p2 are the indices in the points array
    int p1 = 0, p2 =1;

    // Initialize shortest distance
    double shortestDistance = GetDistance3Points(points[p1][0], points[p1][1], points[p1][2],
        points[p2][0], points[p2][1], points[p2][2]);

    // Compute distance for every two points
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        for (int j = i + 1; j < NUMBER_OF_POINTS; j++)
        {
            double distance = GetDistance3Points(points[i][0], points[i][1], points[i][2], points[j][0], points[j][1], points[j][2]);

            if (shortestDistance > distance)
            {
                p1 = i;
                p2 = j;
                shortestDistance = distance;
            }
        }
    }

    // Display the two points in the 3-d array that are nearest each other
    cout << "The closest two points are " << "(" << points[p1][0] << ", " << points[p1][1] << ", "
        << points[p1][2] << ") and (" <<
        points[p2][0] << ", " << points[p2][1] << ", " << points[p2][2] << ")";
}

double Chapter8Helper::GetDistance3Points(double x1, double y1, double z1,  double x2, double y2, double z2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

void Chapter8Helper::RunExercise13()
{
    // 8.13 Write a function to sort a 2-d array 
    int numberOfRows = 6;
    int m[6][2] =
    {
        {4, 2},
        {1, 7},
        {4, 5},
        {1, 2},
        {1, 1},
        {4, 1}
    };

    Sort2DArray(m, numberOfRows);
}

void Chapter8Helper::Sort2DArray(int m[][2], int numberOfRows)
{
    // Primary sort on the rows, then a secondary sort on the columns
    int min[2];

    for (int row = 0; row < numberOfRows; row++)
    {
        min[0] = m[row][0];
        min[1] = m[row][1];
        int rowIndex = row;
        for (int i = row + 1; i < numberOfRows; i++)
        {
            // if min is greater than the next (and check the column), then update the min
            if (CompareTwoPoints(min[0], min[1], m[i][0], m[i][1]))
            {
                min[0] = m[i][0];
                min[1] = m[i][1];
                rowIndex = i;
            }
        }

        // swap 
        if (rowIndex != row)
        {
            m[rowIndex][0] = m[row][0];
            m[rowIndex][1] = m[row][1];
            m[row][0] = min[0];
            m[row][1] = min[1];
        }
    }

    // Display the sorted array
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                printf("%d \n", m[i][j]);
            }
            else
            {
                printf("%d ", m[i][j]);
            }
        }
    }
}

bool Chapter8Helper::CompareTwoPoints(double x1, double y1, double x2, double y2)
{
    if (x2 < x1)
    {
        return true;
    }
    else if (x2 == x1)
    {
        // compare the y's
        if (y2 < y1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false; 
    }
}

void Chapter8Helper::RunExercise14()
{
    // 8.14 Write a program that randomly fills 0s and 1s into TicTacBoard, displays the board,
    //      finds the rows/cols/diagonals with all 0s or 1s

    // fill the board
    int TicTacBoard[3][3];
    srand(time(0));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int fill = rand() % 2;
            TicTacBoard[i][j] = fill;
        }
    }

    // display the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("%d \n", TicTacBoard[i][j]);
            }
            else
            {
                printf("%d ", TicTacBoard[i][j]);
            }
        }
    }

    // Check Rows, Cols, Diagonals
    int zeroToken = 0;
    int oneToken = 1;
    int testboard[3][3] =
    {
        {1, 0, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    CheckTicTacRows(TicTacBoard, zeroToken);
    CheckTicTacRows(TicTacBoard, oneToken);
    CheckTicTacCols(TicTacBoard, zeroToken);
    CheckTicTacCols(TicTacBoard, oneToken);
    CheckTicTacMajorDiagonal(TicTacBoard, zeroToken);
    CheckTicTacMajorDiagonal(TicTacBoard, oneToken);
    CheckTicTacSubDiagonal(TicTacBoard, zeroToken);
    CheckTicTacSubDiagonal(TicTacBoard, oneToken);

    // Note: If a row or column is a 'win' the Check functions will return a bool value of true.
    //       Therefore if the filled board has another row or column filled with 0s and 1s, it may not 
    //       display that because the function has already been returned.
    // Example: 101
    //          000     Only displays all 0s on row 1. The function returns, therefore does not detect 
    //          000     the all 0s on row 2.
}

bool Chapter8Helper::CheckTicTacRows(int board[3][3], int token)
{
    // overload function with int board and int tokens for exercise 8.14
    for (int i = 0; i < 3; i++)
    {
        bool isSameAsBoardKey = true;
        int boardKey = token;
        int j = 0;
        if (board[i][0] != boardKey)
        {
            isSameAsBoardKey = false;
        }
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
            cout << "All " << token << "'s on row " << i << endl;
            return true;
        }
    }
    return false;
}

bool Chapter8Helper::CheckTicTacCols(int board[3][3], int token)
{
    for (int j = 0; j < 3; j++)
    {
        bool isSameAsBoardKey = true;
        int boardKey = token;
        int i = 0;
        if (board[0][j] != boardKey)
        {
            isSameAsBoardKey = false;
        }
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
            cout << "All " << token << "'s on column " << j << endl;
            return true;
        }
    }
    return false;
}

bool Chapter8Helper::CheckTicTacMajorDiagonal(int board[3][3], int token)
{
    bool isSameAsBoardKey = true;
    int boardKey = token;
    if (board[0][0] != token)
    {
        isSameAsBoardKey = false;
    }
    for (int i = 0; i < 2; i++)
    {
        if (boardKey != board[i + 1][i + 1] && boardKey != ' ')
        {
            isSameAsBoardKey = false;
        }
    }
    if (isSameAsBoardKey && boardKey != ' ')
    {
        cout << "All " << token << "'s on the major diagonal" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Chapter8Helper::CheckTicTacSubDiagonal(int board[3][3], int token)
{
    bool isSameAsBoardKey = true;
    int boardKey = token;
    if (board[0][2] != token)
    {
        isSameAsBoardKey = false;
    }
    for (int i = 0; i < 2; i++)
    {
        if (boardKey != board[i + 1][1 - i] && boardKey != ' ')
        {
            isSameAsBoardKey = false;
        }
    }
    if (isSameAsBoardKey && boardKey != ' ')
    {
        cout << "All " << token << "'s on the sub diagonal" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Chapter8Helper::RunExercise15()
{
    // 8.15 The inverse of a 2x2 matrix A = 1/(ad - bc) times matrix [ {d, -b}, {-c, a}]
    //      Implement the function to obtain an inverse of the matrix 

    double a[2][2] =
    {
        {1, 2},
        {3, 4}
    };

    double inverseOfA[2][2];

    InverseMatrix(a, inverseOfA);
}

void Chapter8Helper::InverseMatrix(const double A[][2], double inverseOfA[][2])
{
    // find a, b, c, d
    double a = A[0][0];
    double b = A[0][1];
    double c = A[1][0];
    double d = A[1][1];

    // calculate the inverse multiplier 
    double multiplier = 1 / (a * d - b * c);
    
    // insert values into the inverse matrix
    inverseOfA[0][0] = d;
    inverseOfA[0][1] = -b;
    inverseOfA[1][0] = -c;
    inverseOfA[1][1] = a;

    // multiply each element in the inverse matrix by the multiplier
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            inverseOfA[i][j] *= multiplier;
        }
    }

    // display the inverse matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                printf("%.2f \n", inverseOfA[i][j]);
            }
            else
            {
                printf("%.2f ", inverseOfA[i][j]);
            }
        }
    }
}

void Chapter8Helper::RunExercise16()
{
    // 8.16 Write a program to check whether all points are on the same line 

    // sets to test with 
    double set1[][2] = { {1, 1}, {2, 2}, {3, 3}, {4, 4} };
    double set2[][2] = { {0, 1}, {1, 2}, {4, 5}, {5, 6} };
    double set3[][2] = { {0, 1}, {1, 2}, {4, 5}, {4.5, 4} };

    CheckSameLine(set3);
}

bool Chapter8Helper::CheckSameLine(double set[][2])
{
    // find the slope between the first two points 
    double slope = (set[1][1] - set[0][1]) / (set[1][0] - set[0][0]);

    // compare each point with the first point in row 0 and check if slopes are the same
    for (int i = 2; i < 4; i++)
    {
        double currSlope = (set[i][1] - set[0][1]) / (set[i][0] - set[0][0]);
        if (currSlope != slope)
        {
            cout << "Point " << "(" << set[i][0] << ", " << set[i][1] << ") is not on the same line." << endl;
            return false; 
        }
    }

    cout << "All points are on the same line." << endl;
    return true; 
}

void Chapter8Helper::RunExercise17()
{
    // 8.17 Modify Listing 8.4 to display the total number of solutions for Sudoku. If multiple
    //      solutions exist, display three of them. 

    // read a sudoku puzzle 
    int grid[9][9];
    ReadAPuzzle(grid);

    if (!IsValidPuzzle(grid))
    {
        cout << "Invalid input" << endl;
    }
    else if (SearchPuzzle(grid))
    {
        cout << "The solution is found: " << endl;
        PrintGrid(grid);
    }
    else
    {
        cout << "No solution" << endl;
    }
}

void Chapter8Helper::ReadAPuzzle(int grid[][9])
{
    // Create a scanner
    cout << "Enter a Sudoku puzzle: " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }
}
int Chapter8Helper::GetFreeCellList(const int grid[][9], int freeCellList[][2])
{
    int numberOfFreeCells = 0; 
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                freeCellList[numberOfFreeCells][0] = i;
                freeCellList[numberOfFreeCells][1] = j;
                numberOfFreeCells++;
            }
        }
    }
    return numberOfFreeCells;
}
bool Chapter8Helper::SearchPuzzle(int grid[][9])
{
    // Search for a solution
    int freeCellList[81][2];
    int numberOfFreeCells = GetFreeCellList(grid, freeCellList);
    
    if (numberOfFreeCells == 0)
    {
        return true; 
    }

    int k = 0; 
    while (true)
    {
        int i = freeCellList[k][0];
        int j = freeCellList[k][1];
        if (grid[i][j] == 0)
        {
            grid[i][j] = 1; 
        }
        if (IsValidPuzzle(i, j, grid))
        {
            if (k + 1 == numberOfFreeCells)
            {
                return true; 
            }
            else
            {
                k++;
            }
        }
        else if (grid[i][j] < 9)
        {
            grid[i][j] = grid[i][j] + 1;
        }
        else
        {
            while (grid[i][j] == 9)
            {
                if (k == 0)
                {
                    return false;
                }
                grid[i][j] = 0;
                k--;
                i = freeCellList[k][0];
                j = freeCellList[k][1];
            }
            grid[i][j] = grid[i][j] + 1;
        }
    }
    return true; 
}

void Chapter8Helper::PrintGrid(const int grid[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool Chapter8Helper::IsValidPuzzle(int i, int j, const int grid[][9])
{
    //  Checks whether grid[i][j] is valid in the grid 

    // check the i's row
    for (int column = 0; column < 9; column++)
    {
        if (column != j && grid[i][column] == grid[i][j])
        {
            return false; 
        }
    }

    // check the j's row 
    for (int row = 0; row < 9; row++)
    {
        if (row != i && grid[row][j] == grid[i][j])
        {
            return false; 
        }
    }

    // check if valid in the 3 by 3 box 
    for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
    {
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
        {
            if (row != i && col != j && grid[row][col] == grid[i][j])
            {
                return false;
            }
        }
    }
    
    return true; 
}
bool Chapter8Helper::IsValidPuzzle(const int grid[][9])
{
    // check whether the fixed cells are valid in the grid
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] < 0 || grid[i][j] >> 9 || (grid[i][j] != 0 && !IsValidPuzzle(i, j, grid)))
            {
                return false; 
            }
        }
    }

    return true; // the fixed cells are valid; 
}

void Chapter8Helper::RunExercise18()
{
    // 8.18 inverse 3 x 3 matrix
    double a[3][3] =
    {
        {1, 4, 2},
        {2, 5, 8},
        {2, 1, 8}
    };

    double inverseOfA[3][3];
    InverseMatrix(a, inverseOfA);
}

void Chapter8Helper::InverseMatrix(const double A[][3], double inverseOfA[][3])
{
    // find a11, a12, a13, a21, a22, a23, a31, a32, a33
    double a11 = A[0][0];
    double a12 = A[0][1];
    double a13 = A[0][2];
    double a21 = A[1][0];
    double a22 = A[1][1];
    double a23 = A[1][2];
    double a31 = A[2][0];
    double a32 = A[2][1];
    double a33 = A[2][2];

    // calculate the inverse multiplier 
    double absA = (a11 * a22 * a33) + (a31 * a12 * a23) + (a13 * a21 * a32)
        - (a13 * a22 * a31) - (a11 * a23 * a32) - (a33 * a21 * a12);
    if (absA == 0)
    {
        cout << "The inverse of a 3 x 3 matrix A cannot be obtained";
    }
    double multiplier = 1 / absA;

    // insert values into the inverse matrix
    inverseOfA[0][0] = a22 * a33 - a23 * a32;
    inverseOfA[0][1] = a13 * a32 - a12 * a33;
    inverseOfA[0][2] = a12 * a23 - a13 * a22;
    inverseOfA[1][0] = a23 * a31 - a21 * a33;
    inverseOfA[1][1] = a11 * a33 - a13 * a31;
    inverseOfA[1][2] = a13 * a21 - a11 * a23;
    inverseOfA[2][0] = a21 * a32 - a22 * a31;
    inverseOfA[2][1] = a12 * a31 - a11 * a32;
    inverseOfA[2][2] = a11 * a22 - a12 * a21;

    // multiply each element in the inverse matrix by the multiplier
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverseOfA[i][j] *= multiplier;
        }
    }

    // display the inverse matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("%.2f \n", inverseOfA[i][j]);
            }
            else
            {
                printf("%.2f ", inverseOfA[i][j]);
            }
        }
    }
}

void Chapter8Helper::RunExercise19()
{
    // 8.19 Implement bank balances and loans tracker

    const int NUMBER_OF_BANKS = 5;
    const int LIMIT = 201;

    double balance[5] = {25, 125, 175, 75, 81};
    double borrowers[5][5];
    boolean unsafe[5];

    for (int i = 0; i < NUMBER_OF_BANKS; i++) {
        // current bank's balance
        
        // number of banks that borrow money from current bank
        
        for (int j = 0; j < 5; j++) {
            // input the borrowers array
        }
    }

    // Check for unsafe banks
    boolean unsafeFound = false;
    do {
        unsafeFound = false;
        for (int i = 0; i < NUMBER_OF_BANKS; i++) {
            // calculate bank i's asset
            double asset = balance[i];
            for (int j = 0; j < 5; j++) {
                asset += borrowers[i][j];
            }

            if (asset < LIMIT) {
                unsafe[i] = true;
                // reset debt of the unsafe bank to zero
                for (int j = 0; j < 5; j++) {
                    if (borrowers[j][i] != 0) {
                        borrowers[j][i] = 0;
                        // go trough all the banks again if some debt go
                        // default
                        unsafeFound = true;
                    }
                }
            }

        }

    } while (unsafeFound);

    // Print the result out

    cout << "The unsafe banks are:" << endl;
    for (int i = 0; i < 5; i++) {
        if (unsafe[i] == true) {
            cout << i <<  " ";
        }


}