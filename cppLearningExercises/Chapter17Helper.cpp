#include "Chapter17Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void Chapter17Helper::RunExercise1()
{
    // 17.1 Rewrite the factorial function in Listing 17.1 using iterations
    // Note: Using iterations means loops 
    int n = 5; 
    cout << "Factorial of " << n << " is " << factorial(n);
}

int Chapter17Helper::factorial(int n)
{
    while (!(n == 0))
    {
        return n * factorial(n - 1);
    }
    
    return 1; 
}

void Chapter17Helper::RunExercise2()
{
    // 17.2 Rewrite the fib function in Listing 17.2 using iterations
    int index = 7; 
    cout << "Fibonacci number at index " << index << " is " << fib(index);
}

int Chapter17Helper::fib(int index)
{
    int f0 = 0;
    int f1 = 1;
    if (index == 0)
    {
        return f0;
    }
    if (index == 1)
    {
        return f1; 
    }

    int currentFib = 1; 

    for (int i = 1; i < index; i++)
    {
        currentFib = f0 + f1; 
        f0 = f1; 
        f1 = currentFib;
    }
    
    return currentFib;
}

void Chapter17Helper::RunExercise3()
{
    // 17.3 Compute the gcd using recursion 

    int m = 24;
    int n = 16;
    int a = 255; 
    int b = 25;

    cout << "The gcd of " << m << " and " << n << " is " << gcd(m, n) << endl;
    cout << "The gcd of " << a << " and " << b << " is " << gcd(a, b) << endl;

}

int Chapter17Helper::gcd(int m, int n)
{
    if (m % n == 0)
    {
        return n;
    }
    else
    {
        return gcd(n, m % n);
    }
}

void Chapter17Helper::RunExercise4()
{
    // 17.4 Write a recursive function for the following series:
    //      1 + 1/2 + 1/3 + ... + 1/i
    cout << "The sum is " << sumExercise4(3.0) << endl;
}

double Chapter17Helper::sumExercise4(double i)
{
    if (i == 1)
    {
        return 1.0; 
    }
    else
    {
        return (1.0 / i) + sumExercise4(i - 1);
    }
}

void Chapter17Helper::RunExercise5()
{
    // 17.5 Write a recursive function for the following series:
    //      1/3 + 2/5 + 3/7 + 4/9 + 5/11 +6/13 + ... + (i / 2i + 1)
    cout << "The sum is " << sumExercise5(3.0) << endl;
}

double Chapter17Helper::sumExercise5(double i)
{
    if (i == 1)
    {
        return 1.0 / 3.0;
    }
    else
    {
        return (i / (2 * i + 1)) + sumExercise5(i - 1);
    }
}

void Chapter17Helper::RunExercise6()
{
    // 17.6 Write a recursive function for the following series: 
    //      1/2 + 2/3 + ... + (i/i+1)
    cout << "The sum is " << sumExercise6(3.0) << endl;
}

double Chapter17Helper::sumExercise6(double i)
{
    if (i == 1)
    {
        return 1.0 / 2.0;
    }

    else
    {
        return (i / (i + 1)) + sumExercise6(i - 1);
    }
}

int g_fibCount = 0;

void Chapter17Helper::RunExercise7()
{
    // 17.7 Modify Listing 17.2 so that the program finds the number of times 
    //      the fib function is called. (Hint: use a global variable and increment
    //      every time the function is called)
    
    int index = 7;
    computeFibonacci(index);
    cout << "The computeFibonacci function was called " << g_fibCount << " times.";
}

int Chapter17Helper::computeFibonacci(int index)
{
    g_fibCount++;
    if (index == 0)
    {
        return 0;
    }
    else if (index == 1)
    {
        return 1;
    }
    else
    {
        return computeFibonacci(index - 1) + computeFibonacci(index - 2);
    }
}

void Chapter17Helper::RunExercise8()
{
    // 17.8 Write a recursive function that displays an int value reversely
    //      on the console using the following header: reverseDisplay(int value)
    reverseDisplay(54321);
}

void Chapter17Helper::reverseDisplay(int value)
{
    if (value / 10 == 0)
    {
        cout << value; 
    }
    else
    {
        cout << (value % 10); 
        reverseDisplay(value / 10);
    }
}

void Chapter17Helper::RunExercise9()
{
    // 17.9 Write a recursive function that displays a string reversely. 
    reverseDisplay("abcd");
}

void Chapter17Helper::reverseDisplay(const string& s)
{
    if (s.length() == 1)
    {
        cout << s; 
    }
    else
    {
        string a = s;
        cout << a.back();
        a.pop_back();
        reverseDisplay(a);
    }
}

void Chapter17Helper::RunExercise10()
{
    // 17.10 Write a recursive function that finds the number of 
    //       occurences of a specified letter in a string 
    cout << count("Welcome, Queenie", 'e');
}

int Chapter17Helper::count(const string& s, char a)
{
    int counter = 0;

    while (s.length() != 0)
    {
        if (s.back() == a)
        {
            counter++;
        }
        string b = s;
        b.pop_back();
        return counter + count(b, a);
    }

    return counter; 
}

void Chapter17Helper::RunExercise11()
{
    // 17.11 Write a recursive function that computes the sum of 
    //       digits in an integer. For ex, 234 sum is 9.
    cout << sumDigits(234);
}

int Chapter17Helper::sumDigits(long n)
{
    if (n / 10 == 0)
    {
        return n; 
    }
    else
    {
        return (n % 10) + sumDigits(n / 10);
    }
}

void Chapter17Helper::RunExercise12()
{
    // 17.12 Rewrite exercise 17.9 using a helper function 
    //       to pass the substring high index to the function
    //       header is void reverseDisplay(const string &s, int high)
    reverseDisplay("Queenie", 6);
}

void Chapter17Helper::reverseDisplay(const string& s, int high)
{
    if (high >= 0)
    {
        cout << s[high];
        reverseDisplay(s, high - 1);
    }
}

void Chapter17Helper::RunExercise13()
{
    // 17.13 Write a recursive function that returns the largest
    //       integer in an array 
    int arr[] = { 0, 1, 2, 13, 4, 5 ,6};
    cout << maxArray(arr, 7);
}

int Chapter17Helper::maxArray(int arr[], int n)
{
    // base case: let user know array is empty 
    if (n == 0)
    {
        cout << "array is empty" << endl;
    }

    // base case: array length of 1 -> return the only element arr[0]
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int temp = maxArray(arr, n - 1);
        if (temp > arr[n])
        {
            return temp;
        }
        else
        {
            return arr[n];
        }
    }
}

void Chapter17Helper::RunExercise14()
{
    // 17.14 Write a recursive function to return the number of uppercase
    //       letters in a string 
    string s = "Queenie Pun";
    cout << countUppercase(s);
}

int Chapter17Helper::countUppercase(const string& s)
{
    int counter = 0;

    while (s.length() != 0)
    {
        if (s.back() > 64 && s.back() < 91)
        {
            counter++;
        }
        string b = s;
        b.pop_back();
        return counter + countUppercase(b);
    }

    return counter;
}

void Chapter17Helper::RunExercise15()
{
    // 17.15 Rewrite 17.10 using a helper function to pass a substring
    //       high index to the function 
    string s = "Welcome Queenie";
    char a = 'e';
    cout << count2(s, a);
}

int Chapter17Helper::count2(const string& s, char a)
{
    int counter = 0;
    int high = s.length();

    while (high > 0)
    {
        high--;
        counter += count2(s, a, high);
    }
    return counter;
}

int Chapter17Helper::count2(const string& s, char a, int high)
{
    if (s[high] == a)
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}

int g_moveDisksCount = 0; 

void Chapter17Helper::RunExercise16()
{
    // 17.16 Modify Listing 17.7 TowersOfHanoi.cpp so that the 
    //       program finds the num of moves needed to move n
    //       disks from tower A to tower B. (Hint: Use a global
    //       variable and increment it every time the fn is called)
    moveDisks(3, 'A', 'B', 'C');
    cout << g_moveDisksCount;
}

void Chapter17Helper::moveDisks(int n, char fromTower, char toTower, char auxTower)
{
    g_moveDisksCount++;

    if (n == 1)
    {
        cout << "Move disk " << n << " from " << fromTower
 << " to " << toTower << endl;
    }
    else
    {
        moveDisks(n - 1, fromTower, auxTower, toTower);
        cout << "Move disk " << n << " from " << fromTower <<
            " to " << toTower << endl;
        moveDisks(n - 1, auxTower, toTower, fromTower);
    }
}

