#include "Chapter5Helper.h"
#include <iostream>
#include <string>

using namespace std;

void Chapter5Helper::RunExercise1()
{
    // 5.1 create function int getPentagonalNumber(int n) and create
    //     a test program that displays first 100 pentagonal nums, 10 each line
    int count = 1;

    for (int i = 1; i < 101; i++)
    {
        int pentagonalNumber = getPentagonalNumber(i);
        if (count == 10)
        {
            printf("%6d \n", pentagonalNumber);
            count = 1;
        }
        else
        {
            printf("%6d ", pentagonalNumber);
            count++;
        }
    }
}

int Chapter5Helper::getPentagonalNumber(int n)
{
    int pentagonalNumber = (n * (3 * n - 1)) / 2;
    return pentagonalNumber;
}

void Chapter5Helper::RunExercise2(long n)
{
    // 5.2 create fn sumDigits and display sum of its digits
    int loopLimit = to_string(n).length();
    int sum = 0;
    int currentDigit = n;
    for (int i = 0; i < loopLimit; i++)
    {
        int digit = currentDigit % 10;
        sum += digit;
        currentDigit = currentDigit / 10;
    }
    printf("%d", sum);

    Exercise2Output.Actual1 = sum;
}

void Chapter5Helper::RunExercise3(int number)
{
    // 5.3 Prompts an integer input and displays its reversal

    int loopLimit = to_string(number).length();
    int currentDigit = number;

    for (int i = 0; i < loopLimit; i++)
    {
        int digit = currentDigit % 10;
        cout << digit;
        currentDigit = currentDigit / 10;
    }
}

int Chapter5Helper::RunExercise4(int number)
{
    // 5.4 Return an integer reversed

    int loopLimit = to_string(number).length();
    int currentDigit = number;
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

bool Chapter5Helper::RunExercise5(int number)
{
    // 5.5 Write a function isPalindrome to check whether an integer is palindrome

    return (number == RunExercise4(number));
}

void Chapter5Helper::RunExercise6(int n)
{
    // 5.6 Write a function to display a pattern 

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i; j <= n - 1; j++)
        {
            printf("%s", " ");
        }
        for (int k = i; k >= 1; k--)
        {
            printf("%d", k);
        }
        printf("\n");
    }
}

void Chapter5Helper::RunExercise7()
{
    // 5.7 create two functions to convert celsius and fahrenheit
    //     then write test program that invokes these fns to display table

    cout << "Celsius   Fahrenheit   |   Fahrenheit   Celsius \n";
    for (int i = 0; i < 10; i++)
    {
        double celsiusInitial = 40.0 + (1 * -i);
        double fahrenheitInitial = 120.0 + (10.0 * -i);

        double celsiusToFahrenheitValue = CelsiusToFahrenheit(celsiusInitial);
        double fahrenheitToCelsiusValue = FahrenheitToCelsius(fahrenheitInitial);

        printf("%-9.1f %-12.1f %-3s %-12.1f %.2f \n", celsiusInitial, celsiusToFahrenheitValue, "|",
             fahrenheitInitial, fahrenheitToCelsiusValue);
    }
}

double Chapter5Helper::CelsiusToFahrenheit(double celsius)
{
    double fahrenheit = celsius * (9.0 / 5) + 32;
    return fahrenheit;
}

double Chapter5Helper::FahrenheitToCelsius(double fahrenheit)
{
    double celsius = (fahrenheit - 32) * (5.0 / 9);
    return celsius;
}

void Chapter5Helper::RunExercise8()
{
    // 5.8 create two functions to convert feet and meters
    //     then write test program that invokes these fns to display table

    cout << "Feet   Meters   |   Feet   Meters \n";
    for (int i = 0; i < 10; i++)
    {
        double feetInitial = 1.0 + i;
        double meterInitial = 20.0 + (5.0 * i);

        double feetToMeterValue = FootToMeter(feetInitial);
        double meterToFeetValue = MeterToFoot(meterInitial);

        printf("%-6.1f %-8.3f %-3s %-6.1f %.3f \n", feetInitial, feetToMeterValue, "|",
            meterInitial, meterToFeetValue);
    }
}

double Chapter5Helper::FootToMeter(double foot)
{
    double meter = 0.305 * foot;
    return meter;
}

double Chapter5Helper::MeterToFoot(double meter)
{
    double foot = meter / 0.305;
    return foot;
}