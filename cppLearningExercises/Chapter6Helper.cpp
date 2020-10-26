#include "Chapter6Helper.h"
#include <iostream>
#include <iomanip>
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

int Chapter6Helper::RunExercise7()
{
    // 6.7 Write a program to play a version of the game Craps
    srand(time(0));
    int point = RollTwoDice();

    bool gameResult = CheckSumCraps(point);
    return gameResult;
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

bool Chapter6Helper::CheckSumCraps(int point)
{
    if (point == 2 || point == 3 || point == 12)
    {
        printf("%s", "You lose \n");
        return 0;
    }
    else if (point == 7 || point == 11)
    {
        printf("%s", "You win \n");
        return 1;
    }
    else
    {
        printf("%s %d \n", "Point is", point);
        ContinueRollDice(point);
    }
}

bool Chapter6Helper::ContinueRollDice(int point)
{
    int newPoint = RollTwoDice();
    
    if (newPoint == 7)
    {
        printf("%s", "You lose\n");
        return 0;

    }
    else if (newPoint == point)
    {
        printf("%s",  "You win \n");
        return 1;
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
    // gameResult function 
    int winCounter = 0;

    for (int i = 0; i < 10000; i++)
    {
        int gameResult = RunExercise7();
        winCounter += gameResult;
    }
    printf("%s %d", "Number of winning games: ", winCounter);
}

void Chapter6Helper::RunExercise10()
{
    // 6.10 Write a program to find all twin primes less than 1000

    for (int i = 2; i < 1000; i++)
    {
        int twin = i + 2;
        if (IsPrime(i) && IsPrime(twin))
        {
            printf("%s%d%s%d%s \n", "(", i, ", ", twin, ")");
        }
    }
}

void Chapter6Helper::RunExercise11(int year, int month)
{
    // 6.11 Simplify Listing 6.11 using Zeller's algorithm to get the start of the day of the month 
    PrintMonth(year, month);
 
}

void Chapter6Helper::PrintMonth(int year, int month)
{
    PrintMonthTitle(year, month);
    PrintMonthBody(year, month);
}

void Chapter6Helper::PrintMonthTitle(int year, int month)
{
    PrintMonthName(month);
    cout << " " << year << endl;
    cout << "-----------------------------" << endl;
    cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
}

void Chapter6Helper::PrintMonthName(int month)
{
    switch (month)
    {
    case 1: cout << "January"; break;
    case 2: cout << "February"; break;
    case 3: cout << "March"; break;
    case 4: cout << "April"; break;
    case 5: cout << "May"; break;
    case 6: cout << "June"; break;
    case 7: cout << "July"; break;
    case 8: cout << "August"; break;
    case 9: cout << "September"; break;
    case 10: cout << "October"; break;
    case 11: cout << "November"; break;
    case 12: cout << setw(16) << "December"; break;
    }
}
void Chapter6Helper::PrintMonthBody(int year, int month)
{
    int startDay = ZellersAlgorithm(year, month, 1);

    int numberOfDaysInMonth = GetNumberDaysInMonth(year, month);

    int i = 0; 
    for (i = 0; i < startDay - 1; i++)
    {
        cout << "    ";
    }

    for (i = 1; i <= numberOfDaysInMonth; i++)
    {
        cout << setw(4) << i;
        if ((i + startDay - 1) % 7 == 0)
        {
            cout << endl;
        }
    }
}

int Chapter6Helper::GetNumberDaysInMonth(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 11;
    }
    if (month == 2) return IsLeapYear(year) ? 29 : 28;
}
int Chapter6Helper::ZellersAlgorithm(int year, int month, int day)
{
    // Calculates the day of the week 
    if (month == 1) {
        month = 13;
        year = year - 1;
    }
    if (month == 2) {
        month = 14;
        year = year - 1;
    }
    int q = day;
    int m = month;
    int j = year / 100;
    int k = year % 100;

    int a = static_cast<int>((26 * (m + 1) / 10));
    int b = static_cast<int>((k / 4));
    int c = static_cast<int>((j / 4));

    int h = (q + a + k + b + c + (5 * j)) % 7;

    return h;
}

bool Chapter6Helper::IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Chapter6Helper::RunExercise12(double side)
{
    const double PI = 3.14159;
    double pentagonArea = (5 * pow(side, 2)) / (4 * tan(PI / 5));
    printf("%s %f", "The area of the pentagon is: ", pentagonArea);
}

void Chapter6Helper::RunExercise13()
{
    // 6.13 Write a function that returns area of regular polygon, then a main function that 
    //      prompts the user to enter the number of sides and the side of regular polygon and 
    //      displays area 

    int n;
    double side; 
    cout << "Enter number of sides of the regular polygon: \n";
    cin >> n; 
    cout << "Enter the side of the regular polygon: \n";
    cin >> side;

    double areaPolygon = AreaRegularPolygon(n, side);
    cout << areaPolygon;
}

double Chapter6Helper::AreaRegularPolygon(int n, double side) 
{
    const double PI = 3.14159;
    double area = (n * pow(side, 2)) / (4 * tan(PI / n));
    return area; 
}

double Chapter6Helper::RunExercise14(double num)
{
    // 6.14 Implement the sqrt function by repeatedly performing a calculation with some formula
    //      initial guess can be any positive value. This value will be starting value for Last guess
    //      If the difference between nextGuess and lastGuess is < 0.0001, then nextGuess is sqrt

    double lastGuess = 1; 
    double nextGuess = (lastGuess + (num / lastGuess)) / 2;

    while (nextGuess - lastGuess > 0.0001)
    {
        lastGuess = nextGuess;
        nextGuess = (lastGuess + (num / lastGuess)) / 2;

    }
    lastGuess = nextGuess;
    nextGuess = (lastGuess + (num / lastGuess)) / 2;

    Exercise14Output.Actual1 = nextGuess;
    return nextGuess;
}

void Chapter6Helper::RunExercise15(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    // 6.15 Write a program that prompts the user to enter four endpoints and displays the intersecting point
    //      Hint: use the function for solving 2x2 linear equations

    // Calculate a, b, c, d, e, f to use Cramer's rule to find the intersecting point 
    double a = y1 - y2;
    double b = -x1 + x2;
    double c = y3 - y4;
    double d = -x3 + x4;
    double e = -y1 * (x1 - x2) + (y1 - y2) * x1;
    double f = -y3 * (x3 - x4) + (y3 - y4) * x3;

    RunExercise3(a, b, c, d, e, f);

}