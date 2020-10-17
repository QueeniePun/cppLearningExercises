#include "Chapter3Helper.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void Chapter3Helper::RunExercise1()
{
    // 3.1 Solve linear equation
    double a, b, c, d, e, f;
    cout << "Enter a, b, c, d, e, f:" << endl;
    cin >> a >> b >> c >> d >> e >> f;

    if (a * d - b * c == 0)
    {
        cout << "The equation has no solution" << endl;
    }
    else
    {
        double x = (e * d - b * f) / (a * d - b * c);
        double y = (a * f - e * c) / (a * d - b * c);
        cout << "x is " << x << " and y is " << y << endl;
    }
}

void Chapter3Helper::RunExercise2()
{
    // 3.2 Check if integer is even
    int i;
    cout << "Enter an integer: " << endl;
    cin >> i;
    string str = (i % 2 == 0) ? "true" : "false";

    cout << "Is " << i << " an even number? " << str << endl;
}

void Chapter3Helper::RunExercise3()
{
    // 3.3 Solve quadratic equation
    double a, b, c;
    cout << "Enter a, b, c" << endl;
    cin >> a >> b >> c;

    double discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant > 0)
    {
        double r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
        double r2 = (-b - pow(discriminant, 0.5)) / (2 * a);
        cout << "The roots are " << r1 << " and " << r2 << endl;
    }
    else if (discriminant == 0)
    {
        double r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
        cout << "The root is " << r1 << endl;
    }
    else
    {
        cout << "The equation has no real roots." << endl;
    }
}

void Chapter3Helper::RunExercise4()
{
    // 3.4 Modify ComputeChange.cpp
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

    cout << "Your amount " << amount << " consists of  \n" <<
        "\t" << numberOfOnes << ((numberOfOnes == 1) ? " dollar\n" : " dollars\n") <<
        "\t" << numberOfQuarters << ((numberOfQuarters == 1) ? " quarter\n" : " quarters\n") <<
        "\t" << numberOfNickels << ((numberOfNickels == 1) ? " nickel\n" : " nickels\n") <<
        "\t" << numberOfPennies << ((numberOfPennies == 1) ? " penny\n" : " pennies\n");

}

void Chapter3Helper::RunExercise5()
{
    // 3.5 Sorting three integers
    int num1, num2, num3;
    cout << "Enter three integers: " << endl;
    cin >> num1 >> num2 >> num3;

    // find the lowest
    // if num1 is the lowest
    if (num1 <= num2 && num1 <= num3)
    {
        // num1 is the lowest 
        if (!(num2 <= num3))
        {
            // swap num2 and num3
            int temp = num2;
            num2 = num3;
            num3 = temp;
        }
    }
    // if num2 is the lowest 
    else if (num2 <= num1 && num2 <= num3)
    {
        // num2 is the lowest 
        int temp = num1;
        num1 = num2;
        //determine which is num2 and num3
        if (temp <= num3)
        {
            num2 = temp;
        }
        else {
            num2 = num3;
            num3 = temp;
        }
    }
    else
    {
        // then num 3 is the lowest 
        int temp = num1;
        num1 = num3;
        // determine which is num2 and num3
        if (temp <= num2)
        {
            num3 = num2;
            num2 = temp;
        }
        else
        {
            num3 = temp;
        }
    }

    cout << num1 << " " << num2 << " " << num3 << endl;
}

void Chapter3Helper::RunExercise6()
{
    // 3.6 Write a program that displays RandomUppercase
    // Reference: https://www.bitdegree.org/learn/random-number-generator-cpp#where-are-random-numbers-used

    srand((unsigned)time(0));
    int randomValue = (rand() % 25) + 65;
    char c = randomValue;
    cout << c << endl;
}

void Chapter3Helper::RunExercise7()
{
    // 3.7 Computing Taxes
    cout << "Enter the filing stats\n"
        << "0-single filer, 1-married jointly, \n"
        << "2-married separately, 3-head of household): ";
    int status;
    cin >> status;

    cout << "Enter the taxable income: ";
    double income;
    cin >> income;

    double tax = 0;

    if (status == 0)
    {
        if (income <= 6000)
        {
            tax = income * 0.10;
        }
        else if (income <= 27950)
        {
            tax = 6000 * 0.10 + (income - 6000) * 0.15;
        }
        else if (income <= 67700)
        {
            tax = 6000 * 0.10 + (21950) * 0.15 + (income - 27950) * 0.27;
        }
        else if (income <= 141250)
        {
            tax = 6000 * 0.10 + (27950 - 6000) * 0.15 + (67700 - 27950) * 0.27 + (income - 67700) * 0.30;
        }
        else if (income <= 307050)
        {
            tax = 6000 * 0.10 + (27950 - 6000) * 0.15 + (67700 - 27950) * 0.27 + (141250 - 67700) * 0.30 + (income - 141250) * 0.35;
        }
        else
        {
            tax = 6000 * 0.10 + (27950 - 6000) * 0.15 + (67700 - 27950) * 0.27 + (141250 - 67700) * 0.30 + (307050 - 141250) * 0.35 + (income - 307050) * 0.386;
        }
    }
    else if (status == 1)
    {

        if (income <= 12000)
        {
            tax = income * 0.10;
        }
        else if (income <= 46700)
        {
            tax = 12000 * 0.10 + (income - 12000) * 0.15;
        }
        else if (income <= 112850)
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (income - 46700) * 0.27;
        }
        else if (income <= 171950)
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (112850 - 46700) * 0.27 + (income - 112950) * 0.30;
        }
        else if (income <= 307050)
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (112850 - 46700) * 0.27 + (171950 - 112850) * 0.30 + (income - 171950) * 0.35;
        }
        else
        {
            tax = 12000 * 0.10 + (46700 - 12000) * 0.15 + (112850 - 46700) * 0.27 + (171950 - 112850) * 0.30 + (307050 - 171950) * 0.35 + (income - 307050) * 0.386;
        }
    }
    else if (status == 2)
    {
        // edit the ranges accordingly
    }
    else if (status == 3)
    {
        // edit the ranges accordingly
    }
    else
    {
        cout << "Error: invalid status";
    }

    cout << "Tax is " << static_cast<int>(tax * 100) / 100.0 << endl;
}

void Chapter3Helper::RunExercise8()
{
    int year, month, day;
    cout << "Enter year:" << endl;
    cin >> year;
    cout << "Enter month (1-12):" << endl;
    cin >> month;
    cout << "Enter day of month:" << endl;
    cin >> day;

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

    if (h == 0)
    {
        cout << "The day of the week is Saturday." << endl;
    }
    if (h == 1)
    {
        cout << "The day of the week is Sunday." << endl;
    }if (h == 2)
    {
        cout << "The day of the week is Monday." << endl;
    }if (h == 3)
    {
        cout << "The day of the week is Tuesday." << endl;
    }if (h == 4)
    {
        cout << "The day of the week is Wednesday." << endl;
    }if (h == 5)
    {
        cout << "The day of the week is Thursday." << endl;
    }if (h == 6)
    {
        cout << "The day of the week is Friday." << endl;
    }
}

void Chapter3Helper::RunExercise9()
{
    // 3.9 AdditionQuiz
    // 1. Generate two random single-digit integers
    srand(time(0));
    int number1 = rand() % 100;
    int number2 = rand() % 100;

    // 2. Prompt
    cout << "What is " << number1 << " + " << number2 << "? ";
    int answer;
    cin >> answer;

    // 3. Grade
    if (number1 + number2 == answer)
    {
        cout << "You are correct.";
    }
    else
    {
        cout << "Your answer is wrong. It should be " << answer << endl;
    }
}

void Chapter3Helper::RunExercise10()
{
    // 3.10 refer to 3.9, is same answer but plus number3 variable
}

void Chapter3Helper::RunExercise11()
{
    // 3.11 Heads or tails
    srand(time(0));
    int number = rand() % 2;

    cout << "Heads or tails? Input guess as 0 for heads or 1 for tails." << endl;
    int answer;
    cin >> answer;

    cout << ((answer == number) ? "Correct." : "Incorrect.") << endl;
}

void Chapter3Helper::RunExercise12()
{
    // 3.12 Revise ComputeBMI
    cout << "Enter the weight in pounds: ";
    double weight;
    cin >> weight;

    cout << "Enter height in feet and inches: ";
    double heightFeet, heightInches;
    cin >> heightFeet >> heightInches;

    const double KILOGRAMS_PER_POUND = 0.45359327;
    const double METERS_PER_INCH = 0.0254;

    double weightInKilogram = weight * KILOGRAMS_PER_POUND;
    double heightInMeter = ((heightFeet * 12) + (heightInches)) * METERS_PER_INCH;
    double bmi = weightInKilogram / (heightInMeter * heightInMeter);

    cout << "Your BMI is " << bmi << endl;
}

void Chapter3Helper::RunExercise13()
{
    // 3.13 Revise Lottery.cpp 
    srand(time(0));
    int lottery = rand() % 100 + 100;

    cout << "Enter your lottery pick (three digits): ";
    int guess;
    cin >> guess;

    int lotteryDigit1 = lottery % 10; // ones
    int lotteryDigit2 = (lottery / 10) % 10; // tens
    int lotteryDigit3 = (lottery / 100) % 10; // hundreds

    int guessDigit1 = guess % 10;
    int guessDigit2 = (guess / 10) % 10;
    int guessDigit3 = (guess / 100) % 100;

    cout << "The lottery number is " << lottery << endl;

    if (guess == lottery)
    {
        cout << "Exact match: you win $10,000" << endl;
    }
    else if (guessDigit1 == lotteryDigit1 && guessDigit2 == lotteryDigit3 && guessDigit3 == lotteryDigit2
        || guessDigit1 == lotteryDigit2 && guessDigit2 == lotteryDigit1 && guessDigit3 == lotteryDigit3
        || guessDigit1 == lotteryDigit3 && guessDigit2 == lotteryDigit1 && guessDigit3 == lotteryDigit2
        || guessDigit1 == lotteryDigit2 && guessDigit2 == lotteryDigit3 && guessDigit3 == lotteryDigit1
        || guessDigit1 == lotteryDigit3 && guessDigit2 == lotteryDigit2 && guessDigit3 == lotteryDigit3)

    {
        cout << "Match all digits: you win $3,000." << endl;
    }
    else if (guessDigit1 == lotteryDigit1 || guessDigit1 == lotteryDigit2 || guessDigit1 == lotteryDigit3
        || guessDigit2 == lotteryDigit1 || guessDigit2 == lotteryDigit2 || guessDigit2 == lotteryDigit3
        || guessDigit3 == lotteryDigit1 || guessDigit3 == lotteryDigit2 || guessDigit3 == lotteryDigit3)
    {
        cout << "Match one digit: you win $1,000." << endl;
    }
    else
    {
        cout << "Sorry, no match." << endl;
    }
}

void Chapter3Helper::RunExercise14()
{
    // 3.14 Wind chill is valid 
    double temperatureF, windSpeed;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> temperatureF;
    cout << "Enter wind speed: ";
    cin >> windSpeed;

    if (!(temperatureF >= -58 && temperatureF <= 41))
    {
        cout << "Temperature input is invalid.";
    }
    if (!(windSpeed >= 2))
    {
        cout << " Wind speeds must be greater than or equal to 2.";
    }

    if (temperatureF >= -58 && temperatureF <= 41 && windSpeed >= 2)
    {
        // CalculateWindChill();
        cout << "Will now calculate wind chill..." << endl;
    }
}

void Chapter3Helper::RunExercise15()
{
    // 3.15 RockPaperScissor
    srand(time(0));
    int computerHand = rand() % 3;
    cout << computerHand << endl;

    cout << "Enter Scissor (0), Rock (1), or Paper (2): ";
    int playerHand;
    cin >> playerHand;

    if (computerHand == 0)
    {
        if (playerHand == 0) {
            cout << "Computer and player both play scissors. Draw." << endl;
        }
        if (playerHand == 1) {
            cout << "Computer plays scissor. Player plays rock. Player wins." << endl;
        }
        if (playerHand == 2) {
            cout << "Computer plays scissor. Player plays paper. wins" << endl;
        }
    }
    else if (computerHand == 1)
    {
        if (playerHand == 0) {
            cout << "Computer plays rock. Player plays scissor. Computer wins." << endl;
        }
        if (playerHand == 1) {
            cout << "Computer and player both play rock. Draw." << endl;
        }
        if (playerHand == 2) {
            cout << "Computer plays rock. Player plays paper. Player wins." << endl;
        }
    }
    else
    {
        if (playerHand == 0) {
            cout << "Computer plays paper. Player plays scissor. Player wins." << endl;
        }
        if (playerHand == 1) {
            cout << "Computer players paper. Player plays rock. Computer wins." << endl;
        }
        if (playerHand == 2) {
            cout << "Computer and player both play paper. Draw." << endl;
        }
    }
}

void Chapter3Helper::RunExercise16()
{
    // 3.16 TrianglePerimeter
    double side1, side2, side3;
    cout << "Enter 3 sides of a triangle" << endl;
    cin >> side1 >> side2 >> side3;

    if (side1 + side2 > side3 || side1 + side3 > side2 || side2 + side3 > side1)
    {
        cout << "The input is valid. ";
    }
    else
    {
        cout << "The input is invalid. ";
    }
}

void Chapter3Helper::RunExercise17()
{
    // 3.17 Check ISBN
    int d1, d2, d3, d4, d5, d6, d7, d8, d9;
    cout << "Enter the first 9 digits: " << endl;
    cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7 >> d8 >> d9;

    int d10 = (d1 * 1 + d2 * 2 + d3 * 3 + d4 * 4 + d5 * 5 + d6 * 6 + d7 * 7 + d8 * 8 + d9 * 9) % 11;
    cout << "checkout sum is " << d10 << endl;

    // Output must include the leading zeros 
    // Reference: https://www.tutorialspoint.com/print-leading-zeros-with-cplusplus-output-operator

    if (d10 == 10)
    {
        cout << setw(2) << setfill('0') << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << d9 << 'X' << endl;
    }
    else
    {
        cout << setw(2) << setfill('0') << d1
            << setw(2) << setfill('0') << d2
            << setw(2) << setfill('0') << d3
            << setw(2) << setfill('0') << d4
            << setw(2) << setfill('0') << d5
            << setw(2) << setfill('0') << d6
            << setw(2) << setfill('0') << d7
            << setw(2) << setfill('0') << d8
            << setw(2) << setfill('0') << d9
            << setw(2) << setfill('0') << d10 << endl;
    }
}

void Chapter3Helper::RunExercise18()
{
    // 3.18 Find the number of days in a month
    int month, year;
    cout << "Enter month and year (1 for January, 2 for February, etc):" << endl;
    cin >> month >> year;

    // Account for Leap Year
    if (IsLeapYear(year) && month == 2)
    {
        cout << "February " << year << " has 29 days." << endl;
    }

    // Normal Year
    if (month == 1)
    {
        cout << "January " << year << " has 31 days." << endl;
    }
    else if (month == 2 && !IsLeapYear(year))
    {
        cout << "February " << year << " has 28 days." << endl;
    }
    else if (month == 3)
    {
        cout << "March " << year << " has 31 days." << endl;
    }
    else if (month == 4)
    {
        cout << "April " << year << " has 30 days." << endl;
    }
    else if (month == 5)
    {
        cout << "May " << year << " has 31 days." << endl;
    }
    else if (month == 6)
    {
        cout << "June " << year << " has 30 days." << endl;
    }
    else if (month == 7)
    {
        cout << "July " << year << " has 31 days." << endl;
    }
    else if (month == 8)
    {
        cout << "August " << year << " has 31 days." << endl;
    }
    else if (month == 9)
    {
        cout << "September " << year << " has 30 days." << endl;
    }
    else if (month == 10)
    {
        cout << "October " << year << " has 31 days." << endl;
    }
    else if (month == 11)
    {
        cout << "November " << year << " has 30 days." << endl;
    }
    else if (month == 12)
    {
        cout << "December " << year << " has 31 days." << endl;
    }
}


void Chapter3Helper::RunExercise19()
{
    // 3.19 Check whether the point is within the circle centered at (0,0) with radius 10
    double x, y;
    cout << "Enter a point with two coordinates: ";
    cin >> x >> y;

    double radius = 10;
    // a point is in a circle if its distance from center <= radius
    double distance = pow((pow(x, 2) + (pow(y, 2))), 0.5);

    string inCircle = (distance <= radius) ? "Point is in circle." : "Point is not in circle.";
    cout << inCircle << endl;
}

void Chapter3Helper::RunExercise20()
{
    // 3.20 Check if point is in rectangle centered at (0,0) with width 10 and height 5
    double x, y;
    cout << "Enter a point with two coordinates: ";
    cin >> x >> y;

    double width = 10;
    double height = 5;

    if (x < 0) {
        x = x * -1;
    }
    if (y < 0) {
        y = y * -1;
    }
    // a point is in a circle if horizontal distance to (0,0) <= width / 2
    // and if vertical distance to (0,0) is <= height / 2;

    if (x <= 5 && y <= 2.5)
    {
        cout << "Point is in rectangle." << endl;
    }
    else
    {
        cout << "Point is not in rectangle." << endl;
    }
}

void Chapter3Helper::RunExercise21()
{
    // 3.21 Pick a Card from Deck of 52
    srand(time(0));
    int randRank = rand() % 13 + 1;

    int randSuit = rand() % 4 + 1;

    string rank;
    string suit;

    if (randRank == 2 || randRank == 3 || randRank == 4 || randRank == 5 || randRank == 6
        || randRank == 7 || randRank == 8 || randRank == 9 || randRank == 10)
    {
        rank = to_string(randRank);
    }
    if (randRank == 1)
    {
        rank = "Ace";
    }
    if (randRank == 11)
    {
        rank = "Jack";
    }
    if (randRank == 12)
    {
        rank = "Queen";
    }
    if (randRank == 13)
    {
        rank = "King";
    }

    if (randSuit == 1)
    {
        suit = "Clubs";
    }
    if (randSuit == 2)
    {
        suit = "Diamonds";
    }
    if (randSuit == 3)
    {
        suit = "Hearts";
    }
    if (randSuit == 4)
    {
        suit = "Spades";
    }
    cout << "The card you have picked is " << rank << " of " << suit << "." << endl;
}

void Chapter3Helper::RunExercise22()
{
    // 3.22 Using && and || operators
    int value;
    cout << "Enter an integer:";
    cin >> value;

    bool isDivisibleBy5 = (value % 5 == 0);
    bool isDivisibleBy6 = (value % 6 == 0);

    cout << "Is " << value << " divisible by 5 and 6? " << boolalpha << (isDivisibleBy5 && isDivisibleBy6) << endl;
    cout << "Is " << value << " divisible by 5 or 6? " << boolalpha << (isDivisibleBy5 || isDivisibleBy6) << endl;
    cout << "Is " << value << " divisible by 5 or 6 but not both? " << boolalpha << (!(isDivisibleBy5 && isDivisibleBy6) &&
        (isDivisibleBy5 || isDivisibleBy6)) << endl;

}

void Chapter3Helper::RunExercise23()
{
    // 3.23 Validate Triangle
    double x, y, z;
    cout << "Enter three edges:";
    cin >> x >> y >> z;

    bool isValid = (x + y > z && x + z > y && z + y > x);

    cout << "Can edges " << x << ", " << y << ", and " << z << " form a triangle? " << boolalpha << isValid << endl;


}
void Chapter3Helper::RunExercise24()
{
    // 3.24 Phone Key Pads
    char value;
    cout << "Enter an uppercase letter: ";
    cin >> value;

    int correspondingNum = 0;
    if (!isupper(value)) {
        cout << "Invalid input.";
    }
    else
    {
        if (value == 'A' || value == 'B' || value == 'C')
        {
            correspondingNum = 2;
        }
        if (value == 'D' || value == 'E' || value == 'F')
        {
            correspondingNum = 3;
        }
        if (value == 'G' || value == 'H' || value == 'I')
        {
            correspondingNum = 4;
        }
        if (value == 'J' || value == 'K' || value == 'L')
        {
            correspondingNum = 5;
        }
        if (value == 'M' || value == 'N' || value == 'O')
        {
            correspondingNum = 6;
        }
        if (value == 'P' || value == 'Q' || value == 'R' || value == 'S')
        {
            correspondingNum = 7;
        }
        if (value == 'T' || value == 'U' || value == 'V')
        {
            correspondingNum = 8;
        }
        if (value == 'W' || value == 'X' || value == 'Y' || value == 'Z')
        {
            correspondingNum = 9;
        }
    }
    cout << "The corresponding number is: " << correspondingNum << endl;
}
void Chapter3Helper::RunExercise25()
{
    // 3.25 Point In Triangle
    double x, y;
    cout << "Enter a point's x- and y- coordinates: " << endl;
    cin >> x >> y;

    // right triangle with points (0,0), (0, 100), and (200, 0)
    // x must be >= 0, <= 200
    // y must be <= than the hypotenuse 

    double yBoundary = 100 - (x / 2);
    if (x >= 0 && x <= 200)
    {
        if (y <= yBoundary)
        {
            cout << "The point is in the triangle." << endl;
        }
        else
        {
            cout << "The point is not in the triangle." << endl;
        }
    }
    else
    {
        cout << "The point is not in the triangle." << endl;
    }
}

bool Chapter3Helper::IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}