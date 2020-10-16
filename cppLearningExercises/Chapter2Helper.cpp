#include "Chapter2Helper.h"
#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

void Chapter2Helper::RunExercise1()
{
    // 2.1 Converting Celsius to Fahrenheit
    double celsius;
    cout << "Enter a degree in Celsius:" << endl;
    cin >> celsius;
    double fahrenheit = (9.0 / 5) * celsius + 32;
    cout << "Fahrenheit degree is " << fahrenheit << endl;
}

void Chapter2Helper::RunExercise2()
{
    // 2.2 Computing the volume of a cylinder
    double radius, length;
    cout << "Enter the radius and length of a cylinder: " << endl;
    cin >> radius >> length;
    double area = radius * radius * PI;
    cout << "The area is " << area << endl;
    double volume = area * length;
    cout << "The volume is " << volume << endl;
}

void Chapter2Helper::RunExercise3()
{
    // 2.3 Converting feet into meters 
    double feet;
    cout << "Enter a value for feet:" << endl;
    cin >> feet;
    double meter = feet * .305;
    cout << "The meter is " << meter << endl;
}

void Chapter2Helper::RunExercise4()
{
    // 2.4 Converting pounds to kg
    double pounds;
    cout << "Enter a number in pounds:" << endl;
    cin >> pounds;
    double kg;
    kg = pounds * 0.454;
    cout << "The kilograms is " << kg << endl;
}

void Chapter2Helper::RunExercise5()
{
    // 2.5 Calculate Tips
    double subtotal, gratuityRate;
    cout << "Enter the subtotal and gratuity rate: " << endl;
    cin >> subtotal >> gratuityRate;
    double gratuity = subtotal * (gratuityRate * 0.01);
    double total = subtotal + gratuity;
    cout << "The gratuity is " << gratuity << " and total is " << total << endl;
}

void Chapter2Helper::RunExercise6()
{
    // 2.6 Summing the digits in an integer 
    int num = 0;
    cout << "Enter a number between 0 and 1000:" << endl;
    cin >> num;
    int numOfOnes = num % 10;
    int numOfTens = (num / 10) % 10;
    int numOfHundreds = num / 100;
    int sum = numOfOnes + numOfTens + numOfHundreds;
    cout << "The sum of the digits is " << sum << endl;

}

void Chapter2Helper::RunExercise7()
{
    // 2.7 Convert to Lower
    char uppercase;
    cout << "Enter an uppercase letter: " << endl;
    cin >> uppercase;
    char lowercase = (char)(uppercase + 32);
    cout << "The lowercase letter is " << lowercase << endl;
}

void Chapter2Helper::RunExercise8()
{
    // 2.8 Finding the character of an ASCII code 
    int asciiCode;
    cout << "Enter an ASCII code: " << endl;
    cin >> asciiCode;
    char character = asciiCode;
    cout << "The character is " << character << endl;
}

void Chapter2Helper::RunExercise9()
{
    // 2.9 Rewrite Listing 2.10 to fix loss of accuracy when converting double to int 
    cout << "Enter an amount in in int, where last 2 digits are cents, (1156 = $11.56): ";
    int amount;
    cin >> amount;

    int remainingAmount = amount;

    int numberOfOnes = remainingAmount / 100;
    remainingAmount = remainingAmount % 100;

    int numberOfQuarters = remainingAmount / 25;
    remainingAmount = remainingAmount % 25;

    int numberOfDimes = remainingAmount / 10;
    remainingAmount = remainingAmount % 10;

    int numberOfNickels = remainingAmount / 5;
    remainingAmount = remainingAmount % 5;

    int numberOfPennies = remainingAmount;

    cout << "Your amount " << amount << "consists of \n" <<
        "\t" << numberOfOnes << "dollars\n"
        "\t" << numberOfQuarters << "quarters\n"
        "\t" << numberOfDimes << "dime\n"
        "\t" << numberOfNickels << "nickels\n"
        "\t" << numberOfPennies << "pennies\n";

}

void Chapter2Helper::RunExercise10()
{
    // 2.10 Calculating interests
    cout << "Enter balance and interest rate (e.g., 3 for 3%): " << endl;
    double balance, annualInterestRate;
    cin >> balance >> annualInterestRate;
    double interest = balance * ((annualInterestRate / 1200));
    cout << "The interest is " << interest << endl;
}

void Chapter2Helper::RunExercise11()
{
    // 2.11 Calculate investment 
    double investmentAmount;
    cout << "Enter investment amount: " << endl;
    cin >> investmentAmount;

    double monthlyInterestRate;
    cout << "Enter monthly interest rate: " << endl;
    cin >> monthlyInterestRate;
    monthlyInterestRate = monthlyInterestRate / 1200;


    double numberOfYears;
    cout << "Enter number of years: " << endl;
    cin >> numberOfYears;


    double accumulatedValue = investmentAmount * pow(1 + monthlyInterestRate, numberOfYears * 12);
    cout << "Accumulated value is :" << accumulatedValue << endl;

}

void Chapter2Helper::RunExercise12()
{
    // 2.12 CompoundValue 
    double initialValue = 100;
    double compoundValue = 0;
    for (int i = 0; i < 6; i++)
    {
        compoundValue = (initialValue + compoundValue) * 1.004177;
    }
    cout << compoundValue << endl;
}

void Chapter2Helper::RunExercise13()
{
    // 2.13 Calculate BMI
    double weightPounds;
    cout << "Enter your weight in pounds: " << endl;
    cin >> weightPounds;
    double weightKilos = weightPounds * 0.45359237;

    double heightInches;
    cout << "Enter your height in inches: " << endl;
    cin >> heightInches;
    double heightMeters = heightInches * 0.0254;

    double bmi = weightKilos / pow(heightMeters, 2);
    cout << bmi << endl;
}

void Chapter2Helper::RunExercise14()
{
    // 2.14 Calculate Energy 
    double M;
    cout << "Enter the amount of water in kilograms: " << endl;
    cin >> M;

    double initialTemp;
    cout << "Enter the intial temperature in Celsius: " << endl;
    cin >> initialTemp;

    double finalTemp;
    cout << "Enter the final temperature in Celsius: " << endl;
    cin >> finalTemp;

    double Q = M * (finalTemp - initialTemp) * 4184;

    cout << Q << endl;
}

void Chapter2Helper::RunExercise15()
{
    // 2.15 Calculate Wind Chill
    double temp, windSpeedMPH;
    cout << "Enter the temperature in Fahrenheit: " << endl;
    cin >> temp;
    cout << "Enter the wind speed in miles per hour: " << endl;
    cin >> windSpeedMPH;

    double windChill = 35.74 + 0.6215 * temp - 35.75 * pow(windSpeedMPH, 0.16) + 0.4275 * temp * pow(windSpeedMPH, 0.16);
    cout << "The wind-chill index is " << windChill << endl;
}

void Chapter2Helper::RunExercise16()
{
    // 2.16 Print a Table

}

void Chapter2Helper::RunExercise17()
{
    // 2.17 Calculate distance
    double x1, y1, x2, y2;
    cout << "Enter x1, y1, x2, y2: " << endl;
    cin >> x1 >> y1 >> x2 >> y2;

    double distance = pow((pow(x2 - x1, 2) + pow(y2 - y1, 2)), 0.5);
    cout << "The distance of the two points is: " << distance << endl;
}

void Chapter2Helper::RunExercise18()
{

    // 2.18 Calculate Area of Hexagon 
    double side;
    cout << "Enter the side: " << endl;
    cin >> side;

    double area = ((3 * 1.732) / 2) * pow(side, 2);

    cout << "The area of a hexagon is " << area << endl;

}

void Chapter2Helper::RunExercise19()
{
    // 2.19 Calculate Area of Triangle 
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter three points for a triangle: " << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double area = 0.5 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
    cout << "The area of the triangle is: " << area << endl;
}

void Chapter2Helper::RunExercise20()
{
    // 2.20 Calculate Acceleration
    double v0, v1, t;
    cout << "Enter v0, v1, t: " << endl;
    cin >> v0 >> v1 >> t;

    double acceleration = (v1 - v0) / t;
    cout << "The average acceleration is: " << acceleration << endl;
}

void Chapter2Helper::RunExercise21()
{
    // 2.21 Calculate Runway Length
    double v, a;
    cout << "Enter v and a: " << endl;
    cin >> v >> a;

    double length = (pow(v, 2)) / (2 * a);
    cout << "The minimum runway length for this airplane is " << length << endl;
}
