#include "Chapter6Helper.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

void Chapter6Helper::RunExercise1(double& num1, double& num2, double& num3)
{
    // 6.1 write a function to sort three numbers in increasing order
    // num 1 = min, num 3 = max
    double temp;

    // find min
    if (num2 < num1 && num2 < num3)
    {
        temp = num2;
        num2 = num1;
        num1 = temp;

    }
    else if (num3 < num1 && num3 < num2)
    {
        temp = num1;
        num1 = num3;
        num3 = temp;


        // find order of num3 and num2
        if (num3 < num2)
        {
            temp = num2;
            num2 = num3;
            num3 = temp;
        }
    }
    cout << num1 << num2 << num3 << endl;
}

void Chapter6Helper::RunExercise2(double a, double b, double c)
{
    // 6.2 write a function solve the quadratic equation
    // 3.3 Solve quadratic equation

    double discriminant = pow(b, 2) - (4 * a * c);
    double r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
    double r2 = (-b - pow(discriminant, 0.5)) / (2 * a);

    SolveQuadraticEquation(a, b, c, discriminant, r1, r2);
}   

void Chapter6Helper::SolveQuadraticEquation(double a, double b, double c, double& discriminant, double& r1, double& r2)
{
    if (discriminant == 0)
    {
        cout << "The root is " << r1;
    }
    else if (discriminant > 0)
    {
        cout << "The roots are " << r1 << " and " << r2 << endl;
    }
    else
    {
        cout << "The equation has no real roots." << endl;
    }
}

void Chapter6Helper::RunExercise3(double a, double b, double c, double d, double e, double f)
{

    double x = (e * d - b * f) / (a * d - b * c);
    double y = (a * f - e * c) / (a * d - b * c);
    bool isSolvable = LinearEquationIsSolvable(a, b, c, d);
    SolveLinearEquation(a, b, c, d, e, f, x, y, isSolvable);
}

void Chapter6Helper::SolveLinearEquation(double a, double b, double c, double d,
    double e, double f, double& x, double& y, bool& LinearEquationIsSolvable)
{
    if (LinearEquationIsSolvable)
    {
        cout << "X is " << x << " and y is " << y << endl;
    }
    else
    {
        cout << "The equation has no solution." << endl;
    }
}

bool Chapter6Helper::LinearEquationIsSolvable(double a, double b, double c, double d)
{
    return !(a * d - b * c == 0);
    
}

void Chapter6Helper::RunExercise4(int day, int month, int year)
{
    // 6.4 Improve listing 2.11 to display current date and time. 
    // getTime function
    // getYear, getMonth, get Day
    // DisplayCurrentDateAndTime
    CurrentTime(); 
    CurrentDate(day, month, year);
}

void Chapter6Helper::CurrentTime()
{
    int totalSeconds = time(0);
    int currentSecond = totalSeconds % 60;
    int totalMinutes = totalSeconds / 60;
    int currentMinute = totalMinutes % 60;
    int totalHours = totalMinutes / 60;
    int currentHour = totalHours % 24; 

    cout << "The current time is: " << currentHour << ":" << currentMinute << ":" << currentSecond << " GMT \n";
}

void Chapter6Helper::CurrentDate(int &day, int &month, int &year)
{
    string monthString = "";
    if (month == 1)
    {
        monthString = "January";
    } 
    if (month == 2)
    {
        monthString = "February";
    } 
    if (month == 3)
    {
        monthString = "March";
    } 
    if (month == 4)
    {
        monthString = "April";
    } 
    if (month == 5)
    {
        monthString = "May";
    }
    if (month == 6)
    {
        monthString = "June";
    } 
    if (month == 7)
    {
        monthString = "July";
    }
    if (month == 8)
    {
        monthString = "August";
    } 
    if (month == 9)
    {
        monthString = "September";
    }
    if (month == 10)
    {
        monthString = "October";
    }
    if (month == 11)
    {
        monthString = "November";
    }
    if (month == 12)
    {
        monthString = "December";
    }
    cout << "The date is: " << monthString << " " << day << ", " << year << endl;
}

void Chapter6Helper::RunExercise5()
{
    // 6.5 Write a program that displays the first 100 emirps, 10 per line 

    // IsEmirp  function
    // IsPrime function
    // Reverse function 
    const int NUMBER_OF_EMIRPS_PER_LINE = 10;
    int n = 2;
    int counterEmirpsPerLine = 0;
    int counterNumOfEmirps = 0;
    while (counterNumOfEmirps < 100) {
        if (IsEmirp(n))
        {
            counterNumOfEmirps++;
            counterEmirpsPerLine++;
            if (counterEmirpsPerLine % NUMBER_OF_EMIRPS_PER_LINE == 0)
            {
                printf("%4d \n", n);
            }
            else
            {
                printf("%4d ", n);
            }
        }
        n++;
    }
}

bool Chapter6Helper::IsEmirp(int i)
{
    return IsPrime(i) && IsPrime(ReverseInteger(i));

}

bool Chapter6Helper::IsPrime(int n)
{
    // assume i is true
    bool isPrime = true;

    // Test if b is prime
    for (int divisor = 2; divisor <= n / 2 && isPrime; divisor++)
    {
        // if the if statement below is true, then n is not Prime
        if (n % divisor == 0)
        {
            isPrime = false;
        }
    }
    return isPrime;
}

int Chapter6Helper::ReverseInteger(int n)
{
    int loopLimit = to_string(n).length();
    int currentDigit = n;
    string reverseString = "";

    for (int i = 0; i < loopLimit; i++)
    {
        int digit = currentDigit % 10;

        reverseString += to_string(digit);
        currentDigit = currentDigit / 10;

    }
    int reverse = stoi(reverseString);
    return reverse;
}

void Chapter6Helper::RunExercise6()
{
    // 6.6  Write a program that displays the first 100 palindromic prime numbers 

    // IsPrime function 
    // IsPalindrome function -> use Reverse function
    const int NUMBER_OF_PALINDROMIC_PRIMES_PER_LINE = 10;
    int n = 2;
    int counterPrimesPerLine = 0;
    int counterNumOfPrimes = 0;
    while (counterNumOfPrimes < 100) {
        if (IsPrime(n) && IsPalindrome(n))
        {
            counterNumOfPrimes++;
            counterPrimesPerLine++;
            if (counterPrimesPerLine % NUMBER_OF_PALINDROMIC_PRIMES_PER_LINE == 0)
            {
                printf("%7d \n", n);
            }
            else
            {
                printf("%7d ", n);
            }
        }
        n++;
    }
}

bool Chapter6Helper::IsPalindrome(int n)
{
    return n == ReverseInteger(n);
}

void Chapter6Helper::RunExercise7()
{
    // 6.7 Write a program to play a version of the game Craps
    srand(time(0));
    int point = RollTwoDice();

    CheckSumCraps(point);
}

int Chapter6Helper::RollDice()
{
    int dice = rand() % 6 + 1;
    return dice;
}

int Chapter6Helper::RollTwoDice()
{
    int dice1 = RollDice();
    int dice2 = RollDice();
    int sum = dice1 + dice2;
    printf("%s %d %s %d %s %d \n", "You rolled ", dice1, "+", dice2, "=", sum);
    return sum;
}

void Chapter6Helper::CheckSumCraps(int point)
{
    if (point == 2 || point == 3 || point == 12)
    {
        printf("%s", "You lose \n");
    }
    else if (point == 7 || point == 11)
    {
        printf("%s", "You win \n");
    }
    else
    {
        printf("%s %d \n", "Point is", point);
        ContinueRollDice(point);
    }
}

void Chapter6Helper::ContinueRollDice(int point)
{
    int newPoint = RollTwoDice();
    
    if (newPoint == 7)
    {
        printf("%s", "You lose\n");
    }
    else if (newPoint == point)
    {
        printf("%s",  "You win \n");
    }
    else
    {
        ContinueRollDice(point);
    }
}

void Chapter6Helper::RunExercise8()
{
    // 6.8 Write a program that finds all Mersenne primes with p <= 31 
    // Check IsPrime
    // Check IsMersenne 
    printf("%s", "p     2^p-1 \n");
    for (int p = 2; p <= 31; p++)
    {
        int mersennePrime = CalculateMersennePrime(p);
        if (IsPrime(p) && IsPrime(mersennePrime))
        {
            printf("%-5d %-d \n", p, mersennePrime);
        }
    }
}

int Chapter6Helper::CalculateMersennePrime(int n)
{
    int mersennePrime = pow(2, n) - 1;
    return mersennePrime;
}

void Chapter6Helper::RunExercise9()
{
    // 6.9 Revise 6.7 to run 10000 times and display number of winning games
    // keep a reference variable to keep track of wins 
    for (int i = 0; i < 10000; i++)
    {

    }
}