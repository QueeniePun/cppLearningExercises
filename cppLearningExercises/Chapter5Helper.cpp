#include "Chapter5Helper.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

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

void Chapter5Helper::RunExercise9()
{
    // 5.9 use the IsPrime function to find number of primes < 10k 
    int count = 0;
    // start loop at 2 because 1 is not prime
    for (int i = 2; i <= 10000; i++)
    {
        if (IsPrime(i))
        {
            count++;
        }
    }
    printf("%d", count);
}

bool Chapter5Helper::IsPrime(int number)
{
    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
        if (number % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

void Chapter5Helper::RunExercise10()
{
    // 5.10 Write a function that computes comission. Then write test to display table
    cout << "SalesAmount     Commission \n";
    for (int i = 0; i < 19; i++)
    {
        double salesAmount = 10000 + (5000.0 * i);
        double commission = ComputeCommission(salesAmount);
        printf("%-15.2f %.2f \n", salesAmount, commission);
    }

}

double Chapter5Helper::ComputeCommission(double salesAmount)
{
    double commission = 0;
    if (salesAmount <= 5000)
    {
        commission = salesAmount * 0.08;
    }
    if (salesAmount > 5000 && salesAmount <= 10000)
    {
        commission = (5000 * 0.08) + (salesAmount - 5000) * 0.10;
    }
    if (salesAmount > 10000)
    {
        commission = (5000 * 0.08) + (5000 * 0.10) + (salesAmount - 10000) * 0.12;
    }
    return commission;
}

void Chapter5Helper::RunExercise11(char ch1, char ch2, int numberPerLine)
{
    // 5.11 Write a fn that prints 10 chars per line from '1' and 'Z'
    int count = 0;
    for (int i = ch1; i <= ch2; i++)
    {
        if (count == numberPerLine)
        {
            char c = i;
            printf("%c \n", c);
            count = 0;
        }
        else
        {
            char c = i;
            printf("%c ", c);
            count++;
        }
    }
}

void Chapter5Helper::RunExercise12()
{
    // 5.13 Write a function to compute the following series, then display table
    cout << "i    m(i) \n";
    for (int i = 1; i < 21; i++)
    {
        double seriesSum = Exercise12Series(i);
        printf("%-4d %.4f \n", i, seriesSum);
    }

}

double Chapter5Helper::Exercise12Series(double n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        double numerator = i; 
        double denominator = i + 1.0;
        sum += numerator / denominator;
    }
    return sum;
}

void Chapter5Helper::RunExercise13(int num)
{
    // 5.13 Write to compute the series approximation for pi
    double sum = 0;
    int denominator = 0;
    for (int i = 0; i < num; i++)
    {
        denominator = (1.0 + (2.0 * i));
        if (i != 0 && !(i % 2 == 0))
        {
            denominator *= -1;
        }
        sum += 1.0 / denominator;
    }
    double approximation = 4 * sum;
    cout << approximation;
}

void Chapter5Helper::RunExercise14()
{
    // 5.14 Write a function to compute tax, then print a tax table 
    printf("%-10s %-8s %-10s %-10s %-s \n", "taxable", "Single", "Married", "Married", "Head of");
    printf("%-10s %-8s %-10s %-10s %-s \n", "Income", "", "Joint", "Separate", "a House");

    for (int i = 0; i <= 200; i++)
    {
        int taxableIncome = 50000 + (50 * i);
        double single = ComputeTax(0, taxableIncome);
        double marriedJoint = ComputeTax(1, taxableIncome);
        double marriedSeparate = ComputeTax(2, taxableIncome);
        double headOfHouse = ComputeTax(3, taxableIncome);
        printf("%-10.d %-8g %-10g %-10g %-g \n", taxableIncome, round(single), round(marriedJoint), round(marriedSeparate), round(headOfHouse));
    }

}

double Chapter5Helper::ComputeTax(int status, double taxableIncome)
{
    double tax = 0;

    if (status == 0)
    {
        if (taxableIncome <= 6000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 27950)
        {
            tax = 6000 * 0.10 + (taxableIncome - 6000) * 0.15;
        }
        else if (taxableIncome <= 67700)
        {
            tax = 6000 * 0.10 + (27950 -6000) * 0.15 + (taxableIncome - 27950) * 0.27;
        }
        else if (taxableIncome <= 141250)
        {
            tax = 6000 * 0.10 + (27950 - 6000) * 0.15 + (67700 - 27950) * 0.27 + (taxableIncome - 67700) * 0.30;
        }
        else if (taxableIncome <= 307050)
        {
            tax = 6000 * 0.10 + (27950 - 6000) * 0.15 + (67700 - 2795-0) * 0.27 + (141250 - 67700) * 0.30 + (taxableIncome - 141250) * 0.35;
        }
        else
        {
            tax = 6000 * 0.10 + (27950 - 6000) * 0.15 + (67700 - 27950) * 0.27 + (141250 - 67700) * 0.30 + (307050 - 141250) * 0.35 + (taxableIncome - 307050) * 0.386;
        }
    }
    else if (status == 1)
    {

        if (taxableIncome <= 12000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 46700)
        {
            tax = 12000 * 0.10 + (taxableIncome - 12000) * 0.15;
        }
        else if (taxableIncome <= 112850)
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (taxableIncome - 46700) * 0.27;
        }
        else if (taxableIncome <= 171950)
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (112850 - 46700) * 0.27 + (taxableIncome - 112950) * 0.30;
        }
        else if (taxableIncome <= 307050)
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (112850 - 46700) * 0.27 + (171950 - 112850) * 0.30 + (taxableIncome - 171950) * 0.35;
        }
        else
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (112850 - 46700) * 0.27 + (171950 - 112850) * 0.30 + (307050 - 171950) * 0.35 + (taxableIncome - 307050) * 0.386;
        }
    }
    else if (status == 2)
    {
        if (taxableIncome <= 6000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 23350)
        {
            tax = 6000 * 0.10 + (taxableIncome - 6000) * 0.15;
        }
        else if (taxableIncome <= 56425)
        {
            tax = 6000 * 0.10 + (23350 - 6000) * 0.15 + (taxableIncome - 23350) * 0.27;
        }
        else if (taxableIncome <= 85975)
        {
            tax = 6000 * 0.10 + (23350 - 6000) * 0.15 + (56425 - 23350) * 0.27 + (taxableIncome - 56425) * 0.30;
        }
        else if (taxableIncome <= 307050)
        {
            tax = 6000 * 0.10 + (23350 - 6000) * 0.15 + (56425 - 23350) * 0.27 + (85975 - 56425) * 0.30 + (taxableIncome - 153525) * 0.35;
        }
        else
        {
            tax = 6000 * 0.10 + (23350 - 6000) * 0.15 + (56425 - 23350) * 0.27 + (85975 - 56425) * 0.30 + (153525 - 85975) * 0.35 + (taxableIncome - 153526) * 0.386;
        }
    }
    else if (status == 3)
    {

        if (taxableIncome <= 10000)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 37450)
        {
            tax = 10000 * 0.10 + (taxableIncome - 10000) * 0.15;
        }
        else if (taxableIncome <= 96700)
        {
            tax = 10000 * 0.10 + (37450 - 10000) * 0.15 + (taxableIncome - 37450) * 0.27;
        }
        else if (taxableIncome <= 156600)
        {
            tax = 10000 * 0.10 + (37450 - 10000) * 0.15 + (96700 - 37450) * 0.27 + (taxableIncome - 96700) * 0.30;
        }
        else if (taxableIncome <= 307050)
        {
            tax = 10000 * 0.10 + (37450 - 10000) * 0.15 + (96700 - 37450) * 0.27 + (156600 - 96700) * 0.30 + (taxableIncome - 153525) * 0.35;
        }
        else
        {
            tax = 10000 * 0.10 + (37450 - 10000) * 0.15 + (96700 - 37450) * 0.27 + (156600 - 96700) * 0.30 + (307051 - 156600) * 0.35 + (taxableIncome - 307051) * 0.386;
        }
    }
    else
    {
        cout << "Error: invalid status";
    }

    return tax;
}

void Chapter5Helper::RunExercise15()
{
    // 5.15 Write a function that returns number of days in a year and a test program that 
    //      displays number of days in year 2000 to 2010
    for (int i = 2000; i < 2011; i++)
    {
        printf("%d %d \n", i, NumberOfDaysInAYear(i));
    }

}

int Chapter5Helper::NumberOfDaysInAYear(int year)
{
    // check if it is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 366;
    }
    else 
    {
        return 365;
    }
}

void Chapter5Helper::RunExercise16(int n)
{
    // 5.16 write a function that displays an n by n matrix
    srand(time(0));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            int element = rand() % 2;
            if (j == 2)
            {
                printf("%d \n", element);
            }
            else
            {
                printf("%d ", element);
            }
        }

    }
}

void Chapter5Helper::RunExercise17()
{
    // 5.17 Use the functions defined in Listing 5.12 to print 100 uppercase letters
    //      and then 100 single digits, and print 10 per line 
    const int NUMBER_OF_CHARS = 100;
    const int CHARS_PER_LINE = 10;
    srand(time(0));
    for (int i = 0; i < NUMBER_OF_CHARS; i++)
    {
        char ch = GetRandomUpperCaseLetter();
        if ((i + 1) % CHARS_PER_LINE == 0)
        {
            printf("%c \n", ch);
        }
        else
        {
            printf("%c", ch);
        }
    }
    for (int i = 0; i < NUMBER_OF_CHARS; i++)
    {
        char ch = GetRandomDigitCharacter();
        if ((i + 1) % CHARS_PER_LINE == 0)
        {
            printf("%c \n", ch);
        }
        else
        {
            printf("%c", ch);
        }
    }

}

char Chapter5Helper::GetRandomCharacter(char ch1, char ch2)
{
    return static_cast<char>(ch1 + rand() % (ch2 - ch1 + 1));
}

char Chapter5Helper::GetRandomUpperCaseLetter()
{
    return GetRandomCharacter('A', 'Z');
}

char Chapter5Helper::GetRandomDigitCharacter()
{
    return GetRandomCharacter('0', '9');
}

void Chapter5Helper::RunExercise18()
{
    // 5.18 Write a program that prints following table using sqrt function
    printf("Number    SquareRoot \n");
    for (int i = 0; i <= 10; i++)
    {
        int number = (i * 2);
        double square = sqrt(number);
        printf("%-9d %.4f \n", number, square);
    }
}

void Chapter5Helper::RunExercise19(double side1, double side2, double side3)
{
    // 5.19 Write functions for isValid triangle and area, and test program that reads
    //      3 sides and computes area if input is valid, otherwise display invalid 
    if (TriangleIsValid(side1, side2, side3))
    {
        double area = TriangleArea(side1, side2, side3);
        printf("%s %f", "Area of triangle is", area);
    }
    else
    {
        printf("%s", "Input is invalid");
    }
}

bool Chapter5Helper::TriangleIsValid(double side1, double side2, double side3)
{
    return (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1);
}

double Chapter5Helper::TriangleArea(double side1, double side2, double side3)
{
    double s = (side1 + side2 + side3) / 2;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}

void Chapter5Helper::RunExercise20()
{
    // 5.20 Print the following table to display sin and cos values of degrees from 0 to 360, increments of 10
    const double PI = 3.1415926535897;
    printf("%s", "Degree     Sin        Cos\n");

    for (double i = 0; i < 37; i++)
    {
        double degree = i * 10;
        double radians = degree * (PI) / 180;
        double sinValue = sin(radians);
        double cosValue = cos(radians);
        printf("%-10g %-10.4f %-10.4f \n", degree, sinValue, cosValue);
    }
}

void Chapter5Helper::RunExercise21()
{
    // 5.21 Write a program, that prompts 10 numbers and computes mean and standard dev 
    double a, b, c, d, e, f, g, h, i, j;
    cout << "Enter 10 numbers ";
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

    double sumNums = (a + b + c + d + e + f + g + h + i + j);

    double mean =  sumNums / 10;
    cout << "The mean is " << mean << endl;
    
    double deviation = sqrt(
        (pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2) +
            pow(f, 2) + pow(g, 2) + pow(h, 2) + pow(i, 2) + pow(j, 2) - (pow(sumNums, 2) / 10)) / 9);

    cout << "The standard deviation is " << deviation;
}

void Chapter5Helper::RunExercise22()
{
    // 5.22 Write a function that computres future investment value (exercise 2.11) and write a test program
    //      that prompts the user to enter the investment amountand interest rateand prints
    //      a table that displays future value from years 1 to 30
    double amountInvested, annualInterestRate;
    
    cout << "The amount invested: ";
    cin >> amountInvested;
    cout << "Annual interest rate: ";
    cin >> annualInterestRate;

    double monthlyInterestRate = annualInterestRate / 1200;

    printf("%s", "Years    Future Value \n");
    for (int i = 1; i < 31; i++)
    {
        double futureValue = FutureInvestmentValue(amountInvested, monthlyInterestRate, i);
        printf("%-8d %.2f \n", i, futureValue);
    }

}

double Chapter5Helper::FutureInvestmentValue(double investmentAmount, double monthlyInterestRate, int years)
{
    double futureValue = investmentAmount * pow(1 + monthlyInterestRate, 12 * years);
    return futureValue;
}