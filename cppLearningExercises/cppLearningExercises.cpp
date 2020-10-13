#include <iostream>
/* Note:
#include <iostream> is a preprocessor directive that tells the compiler to include iostream library
*/ 

using namespace std;

void PrintMessage(int num);
void PrintPattern();
void PrintTable();
void PrintSummation(int num);

// Programming Exercises
int main()
{
    // 1.1 Display Welcome to C++, Welcome to CS, and Programming is Fun
    cout << "Welcome to C++!" << endl;
    cout << "Welcome to Computer Science!" << endl;
    cout << "Programming is fun" << endl;

    // 1.2 Display Welcome to C++ 5 times 
    PrintMessage(5);

    // 1.3 Program to Display pattern
    PrintPattern();

    // 1.4 Print a table 
    PrintTable();

    // 1.5 Write a program that displays math result
    cout << (9.5 * 4.5 - 2.5 * 3) / (45.5 - 3.5) << endl;

    // 1.6 summation of 1+2+3+4+5+6+7+8+9
    PrintSummation(9);

    // 1.7 Approximating pi
    cout << 4*(1.0 - 1.0/3.0 + 1.0/5 - 1.0/7 + 1.0/9 - 1.0/11 + 1.0/13) << endl;
    
    return 0;
}

void PrintMessage(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "Welcome to C++!" << endl;
    }
} 

void PrintPattern()
{
    cout << "  CCCC     +        +" << endl;
    cout << " C         +        +" << endl;
    cout << "C       +++++++  +++++++" << endl;
    cout << " C         +        +" << endl;
    cout << "  CCCC     +        +" << endl;
}
void PrintTable()
{
    cout << "a     a^2     a^3" << endl;
    cout << "1     1       1" << endl;
    cout << "2     4       8" << endl;
    cout << "3     9       27" << endl;
    cout << "4     16      64" << endl;
}

void PrintSummation(int num)
{
    int sum = 0;
    for (int i = 1; i <num+1; i++)
    {
        sum = sum + i;
    }
    cout << sum << endl;
}
