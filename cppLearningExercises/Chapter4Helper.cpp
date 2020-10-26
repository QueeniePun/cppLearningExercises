#include "Chapter4Helper.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

void Chapter4Helper::RunExercise1(int* values, int size)
{
    // 4.1 Counting positive and negative ints and computing avg

    int positiveInts = 0;
    int negativeInts = 0;
    int numOfValues = size;
    int sum = 0;
    
    for (int i = 0; i < size; i++) 
    {
        if (values[i] < 0)
        {
            negativeInts++;
        }
        if (values[i] > 0)
        {
            positiveInts++;
        }
        sum += values[i];
    }

    double average = static_cast<double>(sum) / static_cast<double>(numOfValues);
    cout << "The number of positives is " << positiveInts << endl;
    cout << "The number of negatives is " << negativeInts << endl;
    cout << "The total is " << sum << endl;
    cout << "The average is " << average << endl;

    // set up stuff to check into the exercise1output struct 
    // Set final actual values to output struct
    Exercise1Output.Actual1 = positiveInts;
    Exercise1Output.Actual2 = negativeInts;
    Exercise1Output.Actual3 = sum;
    Exercise1Output.Actual4 = average;


}
void Chapter4Helper::RunExercise2()
{
    // 4.2 Revise SubtractionQuizLoop to generate 10 random ADDITION questions for 
    //     two integers betewen 1 and 15. 
   
    int correctCount = 0;
    int count = 0;
    long startTime = time(0);
    const int NUMBER_OF_QUESTIONS = 10; 
    while (count < NUMBER_OF_QUESTIONS) 
    {
        // 1. Generate two random integers between 1 and 15;
        srand(time(0));
        int number1 = rand() % 15 + 1; 
        int number2 = rand() % 15 + 1; 

        // 2. Prompt to answer "what is number1 + number2?"
        cout << "What is " << number1 << " + " << number2 << "? ";
        int answer;
        cin >> answer;

        // 3. Grade answer and display result 
        if (number1 + number2 == answer)
        {
            cout << "You are correct. \n";
            correctCount++;
        }
        else
        {
            cout << "Incorrect. The answer should be " << (number1 + number2) << endl;
        }
        count++;
    }
    long endTime = time(0);
    long testTime = endTime - startTime;

    cout << "Your score is " << (correctCount * 10) << "%." << "\nTest time is " <<
        testTime << " seconds.\n";
}

void Chapter4Helper::RunExercise3()
{
    // 4.3 Write a program that displays the a kilograms and pounds table
    const double KILOGRAMS_TO_POUND = 2.2;
    cout << "Kilograms  Pounds\n";
    
    for (int i = 1; i < 200; i += 2) 
    {
        cout << setw(11)<< left << i << (i*KILOGRAMS_TO_POUND) << endl;
    }
}

void Chapter4Helper::RunExercise4()
{
    // 4.4 Display a miles to kilometers table 
    const double MILES_TO_KILOMETER = 1.609;
    cout << "Miles  Kilometers\n";

    for (int i = 1; i < 11; i++)
    {
        cout << setw(7) << left << i << (i * MILES_TO_KILOMETER) << endl;
    }
}

void Chapter4Helper::RunExercise5()
{
    // 4.5 Display 2 tables side by side 
    const double KILOGRAM_TO_POUND = 2.2;
    cout << "Kilograms  Pounds   |   Pounds   Kilograms\n";

    for (int i = 0; i < 100; i++)
    {
        int kilogramsInitial = 1 + (2 * i); 
        int poundsInitial = 20 + (5 * i);
        
        double kgToPounds = static_cast<double>(kilogramsInitial) * KILOGRAM_TO_POUND;
        double poundsToKg = static_cast<double>(poundsInitial) / KILOGRAM_TO_POUND;

        printf("%-10d %-8.1f %-3c %-8d %-.2f \n", kilogramsInitial, kgToPounds, '|', poundsInitial, poundsToKg);

    }
}

void Chapter4Helper::RunExercise6()
{
    // 4.6 Display two tables side by side 
    const double MILE_TO_KILOMETER = 1.609;
    cout << "Miles   Kilometers   |   Kilometers   Miles\n";

    for (int i = 0; i < 10; i++)
    {
        int milesInitial = 1 + i;
        int kilometersInitial = 20 + (5 * i);

        double milesToKm = static_cast<double>(milesInitial) * MILE_TO_KILOMETER;
        double kilometersToMiles = static_cast<double>(kilometersInitial) / MILE_TO_KILOMETER;

        printf("%-7d %-12.3f %-3c %-12d %-.3f \n", milesInitial, milesToKm, '|', kilometersInitial, kilometersToMiles);
    }

}

void Chapter4Helper::RunExercise7(double initialTuition, double years)
{
    // 4.7 Computing future tuition. Supposed 10k + 5% every year
    // Compute tuition in 10 years and total cost of four years' worth of tuition starting 10 years from now 
    
    double futureTuition = initialTuition * pow(1.05, years);
    double totalTuition = futureTuition;

    // totalTuition + totalTuition(1.05) + totalTuition(

    for (int i = 1; i < 4; i++)
    {
        totalTuition += (futureTuition * pow(1.05, i));
    }

    Exercise7Output.Actual1 = futureTuition;
    Exercise7Output.Actual2 = totalTuition;
}

void Chapter4Helper::RunExercise8(int numStudents, int* studentScores)
{
    // 4.8 Prompt user to enter number of student, each student's score, and display highscore
    int highScore = studentScores[0];

    for (int i = 1; i < numStudents; i++)
    {
        if (studentScores[i] > highScore)
        {
            highScore = studentScores[i];
        }
    }
    Exercise8Output.Actual1 = highScore;

}

void Chapter4Helper::RunExercise9(int numStudents, int* studentScores)
{
    // 4.9 Find two highest scores
    int highestScore = studentScores[0];
    int secondHighestScore = studentScores[1];

    if (secondHighestScore > highestScore)
    {
        int temp = secondHighestScore;
        secondHighestScore = highestScore;
        highestScore = temp;
    }

    for (int i = 1; i < numStudents; i++)
    {
        if (studentScores[i] > highestScore)
        {
            highestScore = studentScores[i];
        }
        if (studentScores[i] < highestScore && studentScores[i] > secondHighestScore)
        {
            secondHighestScore = studentScores[i];
        }
    }

    Exercise9Output.Actual1 = highestScore;
    Exercise9Output.Actual2 = secondHighestScore;

}

void Chapter4Helper::RunExercise10()
{
    // 4.10 Display 10 numbers per line, all numbers from 100 to 1000 that are divisible 
    //      by 5 and 6

    int counter = 0;
    for (int i = 100; i < 1000; i++)
    {
        if (i % 5 == 0 && i % 6 == 0)
        {
            cout << i << " ";
            counter++;
        }
        if (counter == 10)
        {
            cout << "\n";
            counter = 0;
        }

    }
}

void Chapter4Helper::RunExercise11()
{
    // 4.11 Finding numbers divisible by 5 or 6, but not both, from 100 to 200
    int counter = 0;
    for (int i = 100; i < 200; i++)
    {
        if ((i % 5 == 0 && !(i % 6 == 0)) || (!(i % 5 == 0) && i % 6 == 0))
        {
            cout << i << " ";
            counter++;
        }
        if (counter == 10)
        {
            cout << "\n";
            counter = 0;
        }
    }
}

void Chapter4Helper::RunExercise12()
{
    // 4.12 Use a while loop to find the smallest int such that n^2 is greater  than 12k

    int n = 0;
    while (pow(n, 2) < 12000)
    {
        n++;
    }
    cout << n;
}

void Chapter4Helper::RunExercise13()
{
    // 4.13 find largest n such that n^3 < 12k using while loop

    int n = 0;

    while (pow(n, 3) < 12000 && pow(n+1, 3) < 12000)
    {
        n++;
    }
    cout << n;
}

void Chapter4Helper::RunExercise14()
{
    // 4.14 Print ASCII table from '!' to '~'. 10 characters per line
    int counter = 0;

    for (int i = 33; i < 127; i++)
    {
        char a = i;
        cout << a;
        counter++;
        if (counter == 10)
        {
            cout << "\n";
            counter = 0;
        }
    }

}

void Chapter4Helper::RunExercise15(int n1, int n2)
{
    // 4.15 Compute greatest common divisor 
    int gcd = 1;
    int d = n1 - n2;
    if (d < 0)
    {
        d = d * -1;
    }
    for (d; d >= 1; d--)
    {
        if (n1 % d == 0 && n2 % d == 0 && d > gcd) 
        {
            gcd = d;
            break;
        }
    }
    Exercise15Output.Actual1 = gcd;
}

void Chapter4Helper::RunExercise16(int num)
{
    // 4.16 Finding the factors of an integer 
    // reads an integer and displays all its smallest factors 
    int currentNum = num;
    string primeFactors = "";
    int divisor = 2;

    while (divisor != currentNum)
    {
        if (currentNum % divisor == 0)
        {
            primeFactors += to_string(divisor) + " ";
            currentNum = currentNum / divisor;
            divisor = 2;
        }
        else
        {
            divisor++;
        }
        
    }
    primeFactors += to_string(divisor);
    
    cout << primeFactors;
}

void Chapter4Helper::RunExercise17(int numLines)
{
    // 4.17 Write a program the user will enter integer from 1 to 15 and display a pyramid
    for (int i = 1; i < numLines + 1; i++)
    {
        // Print 4.18 Pattern III with these two loops  
        for (int j = i; j <= numLines - 1; j++)
        {
            printf("%s", "  ");
        }
        for (int k = i; k >= 2; k--)
        {
            printf("%d ", k);
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        // Print 4.18 Pattern I 
    
     printf("\n");
    }
}

void Chapter4Helper::RunExercise18(int numLines)
{
    // 4.18 Printing 3 different patterns 

    // Pattern I 
    for (int i = 1; i < numLines + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    cout << endl;

    // Pattern II
    for (int i = 1; i < numLines + 1; i++)
    {
        for (int j = i; j <= numLines; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    cout << endl;

    // Pattern III
    for (int i = 1; i < numLines + 1; i++)
    {
        // Print Pattern 2 but with spaces 
        for (int j = i; j <= numLines - 1; j++)
        {
            printf("%s", "  ");
        }
        for (int k = i; k >= 1; k--) 
        {
            printf("%d ", k);
        }
        printf("\n");
    }
    cout << endl;

    // Pattern IV
    for (int i = 1; i < numLines + 1; i++)
    {
        // Print Pattern 1 but with spaces 
        for (int j = 2; j <= i; j++)
        {
            printf("%s", "  ");
        }
        for (int k = 1; k <= numLines + 1 - i; k++)
        {
            printf("%d ", k);
        }
        printf("\n");
    }
}

void Chapter4Helper::RunExercise19()
{
    // 4.19 Write a nested for loop that prints a pyramid
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            printf("%s", "     ");
        }
        for (int k = 0; k < i; k++)
        {
            int num = pow(2, k);
            int numLength = to_string(num).length();
            if (numLength == 1) 
            {
                printf("    %d", num);
            }
            if (numLength == 2) 
            {
                printf("   %d", num);
            }
            if (numLength == 3) 
            {
                printf("  %d", num);
            }
        }
        for (int l = i; l >= 0; l--)
        {
            int num = pow(2, l);
            int numLength = to_string(num).length();
            if (numLength == 1)
            {
                printf("    %d", num);
            }
            if (numLength == 2)
            {
                printf("   %d", num);
            }
            if (numLength == 3)
            {
                printf("  %d", num);
            }
        }
        printf("\n");
    }
}

void Chapter4Helper::RunExercise20()
{
    // 4.20 Modiy Listing 14 to print all prime numbers between 2 and 1000
    //      Display 8 prime numbers per line
    const int NUMBER_OF_PRIMES_PER_LINE = 8;
    int counter = 0;

    for (int i = 2; i <= 1000; i++)
    {
        // assume i is true
        bool isPrime = true;

        // Test if current is prime
        for (int divisor = 2; divisor <= i / 2 && isPrime; divisor++)
        {
            // if the if statement below is true, then i is not Prime
            if (i % divisor == 0)
            {
                isPrime = false;
            }
        }

        if (isPrime)
        {
            counter++; 
            if (counter % NUMBER_OF_PRIMES_PER_LINE == 0)
            {
                printf("%4d \n", i);
            }
            else
            {
                printf("%4d ", i);
            }
        }
    }
}

void Chapter4Helper::RunExercise21(double loan, double years)
{
    // 4.21 Input loan amount and loan period in years and display monthly and 
    //      total payments for each interest rate starting from 5% to 8%, at 1/8 
    //      increments.

    cout << "Interest Rate      Monthly Payment       Total Payment" << endl;
    for (double i = 5; i <= 8; i = i + 0.125)
    {
        double monthlyInterestRate = i / 1200;
        double monthlyPayment = loan * monthlyInterestRate /
            (1 - 1 / pow(1 + monthlyInterestRate, years * 12));
        double totalPayment = monthlyPayment * years * 12;
        printf("%-5.3f%-13c %-21.2f %.2f \n", i, '%', monthlyPayment, totalPayment);
    }
}
void Chapter4Helper::RunExercise22(double loan, double years, double annualInterest)
{
    // 4.22 Loan amortization schedule

    double monthlyInterestRate = annualInterest / 1200; 
    double monthlyPayment = loan * monthlyInterestRate /
        (1 - 1 / pow(1 + monthlyInterestRate, years * 12));
    double totalPayment = monthlyPayment * years * 12;

    cout << "Monthly payment: " << monthlyPayment << endl;
    cout << "Total payment: " << totalPayment << endl << endl;

    cout << "Payment#     Interest     Principal     Balance" << endl;

    double balance = loan;

    for (int i = 1; i <= totalPayment / monthlyPayment; i++)
    {
        double monthlyInterest = monthlyInterestRate * balance;
        double principal = monthlyPayment - monthlyInterest;
        balance = balance - principal;
        
        printf("%-12d %-12.2f %-13.2f %.2f \n", i, monthlyInterest, principal, balance);
    }

}

void Chapter4Helper::RunExercise23()
{
    //4.23 Demonstrate cancellation errors. Write a prgram that compares the results
    //     of the summation of the preceding series, computing from left to right then 
    //     right to left with n = 50000
    double sumLeftToRight = 0.0;
    for (double i = 1.0; i <= 50000.0; i++)
    {
        sumLeftToRight += 1.0 / i;
    }


    double sumRightToLeft = 0.0;
    for (double i = 50000.0; i > 0.0; i--)
    {
        sumRightToLeft += 1.0 / i;
    }

    printf("Sum from left to right is %f. Sum from right to left is %f. \n", sumLeftToRight, sumRightToLeft);
    double difference = sumLeftToRight - sumRightToLeft;
    printf("The difference is %f.", difference);
}

void Chapter4Helper::RunExercise24()
{
    // 4.24 Write a program to sum the series 1/3 + 3/5 + 5/7 + 9/11

    double numerator = 0;
    double denominator = 0;
    double sum = 0;

    for (int i = 0; i < 49; i++)
    {
        numerator = 1.0 + (2.0 * i);
        denominator = 3.0 + (2.0 * i);
        sum += numerator / denominator;
    }
    cout << sum;
}

void Chapter4Helper::RunExercise25(int n)
{
    // 4.25 Write a program that displays the pi value for i = 10k, 20k .. 100k
    double sum = 0;
    int denominator = 0;
    for (int i = 0; i < n; i++)
    {
        denominator = (1.0 + (2.0 * i));
        if (i != 0 && !(i%2 ==0))
        {
            denominator *= -1;
        }
        sum += 1.0 / denominator;
    }
    double approximation = 4 * sum;
    cout << approximation;
}

void Chapter4Helper::RunExercise26(int n)
{
    // 4.26 computing e, write a program that displays e value for i = 10k, .. 100k
    double e = 1;
    double numLoops = n;
    
    for (double i = 1; i <= numLoops; i++) 
    {
        double denominator = i;
        for (double j = i - 1; j >= 1; j--)
        {
            denominator *= j;
        }
        e += 1 / denominator;
    }

    cout << setprecision(15) << e;
}

void Chapter4Helper::RunExercise27()
{
    // 4.27 Write a program, 10 per line, the leap years from 2001 to 2100

    // from Chapter 3;
    // bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    
    int counter = 0;

    for (int i = 2001; i < 2101; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
        {
            printf("%d ", i);
            counter++;
        }
        if (counter == 10)
        {
            printf("\n");
            counter = 0;
        }
    }
}

void Chapter4Helper::RunExercise28(int year)
{
    // 4.28 Display first day of each month when given Year and First day of the year
    int month = 0;
    string day = "";
    string monthString = "";
    
    // loop through the months 
    for (int i = 1; i < 13; i++)
    {
        int y = year;
        month = i;
        if (month == 1)
        {
            monthString = "January 1, ";
            month = 13; 
            y = year - 1;
        }
        if (month == 2)
        {
            monthString = "February 1, ";
            month = 14;
            y = year - 1;
        }
        if (month == 3)
        {
            monthString = "March 1, ";
        }
        if (month == 4)
        {
            monthString = "April 1, ";
        }
        if (month == 5)
        {
            monthString = "May 1, ";
        }
        if (month == 6)
        {
            monthString = "June 1, ";
        }
        if (month == 7)
        {
            monthString = "July 1, ";
        }
        if (month == 8)
        {
            monthString = "August 1, ";
        }
        if (month == 9)
        {
            monthString = "September 1, ";
        }
        if (month == 10)
        {
            monthString = "October 1, ";
        }
        if (month == 11)
        {
            monthString = "November 1, ";
        }
        if (month == 12)
        {
            monthString = "December 1, ";
        }
        int q = 1;
        int m = month;
        int j = y / 100;
        int k = y % 100;

        int a = static_cast<int>((26 * (m + 1) / 10));
        int b = static_cast<int>((k / 4));
        int c = static_cast<int>((j / 4));


        int h = (q + a + k + b + c + (5 * j)) % 7;
        if (h == 0)
        {
            day = "Saturday";
        }
        if (h == 1)
        {
            day = "Sunday";
        }if (h == 2)
        {
            day = "Monday";
        }if (h == 3)
        {
            day = "Tuesday";
        }if (h == 4)
        {
            day = "Wednesday";
        }if (h == 5)
        {
            day = "Thursday";
        }if (h == 6)
        {
            day = "Friday";
        }
        cout << monthString << year << " is " << day << endl;
    }
}

void Chapter4Helper::RunExercise29(int year, int dayIndex)
{
    // 4.29 Display calendar 
    string title = "";
    int daysInMonth = 0;

    for (int i = 1; i < 13; i++)
    {
        switch (i)
        {
        case 1: title = "January "; break;
        case 2: title = "February "; break;
        case 3: title = "March "; break;
        case 4: title = "April "; break;
        case 5: title = "May "; break;
        case 6: title = "June "; break;
        case 7: title = "July "; break;
        case 8: title = "August "; break;
        case 9: title = "September "; break;
        case 10: title = "October "; break;
        case 11: title = "November "; break;
        case 12: title = "December "; break;
        }

        title += to_string(year);

        cout << title << "\n" << "-----------------------------------" << endl; 
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << endl;


        // print spaces 
        for (int i = 0; i < dayIndex; i++)
        {
            cout << "     ";
        }
        // loop days of the month (find how many days to print)
        if (i == 1)
        {
            daysInMonth = 31;
        }
        if (i == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                daysInMonth = 29;
            }
            else
            {
                daysInMonth = 28;
            }
        }
        if (i == 3)
        {
            daysInMonth = 31;
        }
        if (i == 4)
        {
            daysInMonth = 30;
        }
        if (i == 5)
        {
            daysInMonth = 31;
        }
        if (i == 6)
        {
            daysInMonth = 30;
        }
        if (i == 7)
        {
            daysInMonth = 31;
        }
        if (i == 8)
        {
            daysInMonth = 31;
        }
        if (i == 9)
        {
            daysInMonth = 30;
        }
        if (i == 10)
        {
            daysInMonth = 31;
        }
        if (i == 11)
        {
            daysInMonth = 30;
        }
        if (i == 12)
        {
            daysInMonth = 31;
        }
        for (int i = 1; i <= daysInMonth; i++)
        {
            printf("%5d", i);
            if (++dayIndex >6)
            {
                dayIndex = 0;
                printf("\n");
            }
            if (i == daysInMonth)
            {
                printf("\n \n");
            }
        }

    }
}

void Chapter4Helper::RunExercise30(double amount, double annualInterestRate, int numMonths)
{
    // 4.30 Enter amount, annual interest rate, and number months 
    //      Display the amount in savings account after the given month
    double monthlyInterest = annualInterestRate / 1200;

    double currentValue = 0;
    for (int i = 1; i <= numMonths; i++)
    {
        currentValue = (currentValue + amount) * (1.0 + monthlyInterest);
    }

    Exercise30Output.Actual1 = currentValue;
}

void Chapter4Helper::RunExercise31(double amount, double annualPercentYield, int numMonths)
{
    double monthlyPercentYield = annualPercentYield / 1200;
    double value = amount;
    for (int i = 1; i <= numMonths; i++)
    {
        value = value + (value * monthlyPercentYield);
        printf("%d %.2f \n", i, value);
    }

}

void Chapter4Helper::RunExercise32()
{
    // 4.32 Find 4 perfect numbers less than 10000
    //      A perfect number if it is equal to the sum of all its positive divisors
    //       excluding itself
    
    for (int i = 1; i <= 10000; i++)
    {
        int sum = 0;
        // find factors of each num
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("%d \n", i);
        }
    }
}

void Chapter4Helper::RunExercise33(int guess)
{
    // 4.33 Revise Listing 3.8 Lottery to generate lottery of 2 digit num
    //      The two digits in the number are distinct
    srand(time(0));
    int lotteryDigit1 = rand() % 10; // ones
    int lotteryDigit2 = rand() % 10; // tens

    string lotteryString = to_string(lotteryDigit1) + to_string(lotteryDigit2);
    int lottery = stoi(lotteryString);

    while (lotteryDigit1 == lotteryDigit2)
    {
        lotteryDigit2 = rand() % 10;
    }

    int guessDigit1 = guess / 10;
    int guessDigit2 = guess % 10;


    cout << "The lottery number is " << lotteryDigit1 << lotteryDigit2 << endl;

    if (guess == lottery)
    {
        cout << "Exact match: you win $10,000" << endl;
    }
    else if (guessDigit2 == lotteryDigit1 && guessDigit1 == lotteryDigit2)
    {
        cout << "Match all digits, you win $3000" << endl;
    }
    else if (guessDigit1 == lotteryDigit1
        || guessDigit1 == lotteryDigit2
        || guessDigit2 == lotteryDigit1
        || guessDigit2 == lotteryDigit2)
    {
        cout << "Match one digit, you win $1000" << endl;
    }
    else
    {
        cout << "You lose." << endl;
    }
}

void Chapter4Helper::RunExercise34()
{
    // 4.34 Revise exercise 3.15 to let the user play until either player or AI 
    //      wins more than two times 

    srand(time(0));

    int playerScore = 0;
    int computerScore = 0;

    while (playerScore <= 2 && computerScore <= 2) {

        int computerHand = rand() % 3;

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
                playerScore++;
            }
            if (playerHand == 2) {
                cout << "Computer plays scissor. Player plays paper. Computer wins" << endl;
                computerScore++;
            }
        }
        else if (computerHand == 1)
        {
            if (playerHand == 0) {
                cout << "Computer plays rock. Player plays scissor. Computer wins." << endl;
                computerScore++;
            }
            if (playerHand == 1) {
                cout << "Computer and player both play rock. Draw." << endl;
            }
            if (playerHand == 2) {
                cout << "Computer plays rock. Player plays paper. Player wins." << endl;
                playerScore++;
            }
        }
        else
        {
            if (playerHand == 0) {
                cout << "Computer plays paper. Player plays scissor. Player wins." << endl;
                playerScore++;
            }
            if (playerHand == 1) {
                cout << "Computer players paper. Player plays rock. Computer wins." << endl;
                computerScore++;
            }
            if (playerHand == 2) {
                cout << "Computer and player both play paper. Draw." << endl;
            }
        }
    }
    if (playerScore > computerScore)
    {
        cout << "Player wins." << endl;
    }
    else {
        cout << "Computer wins." << endl;
    }
}

void Chapter4Helper::RunExercise35()
{
    // 4.35 Prove that the summation is 24 
    double sum = 0;
    
    double numerator = 1;
    double denominator = 1;
    for (int i = 1; i < 625; i++)
    {
        denominator = pow(i, 0.5) + pow(i + 1, 0.5);
        sum += 1 / denominator;
    }
    cout << sum;
}

void Chapter4Helper::RunExercise36(int arr[9])
{
    // 4.36 Use loops to simplify Exercise 3.17
    // 3.17 Check ISBN

    // Calculate d10
    int d10 = 0;
    for (int i = 0; i < 9; i++)
    {
        d10 += arr[i] * (1 + i);
    }
    d10 = d10 % 11;

    // Display the ISBN
    for (int i = 0; i < 9; i++) {
        cout << arr[i];
    }
    if (d10 == 10)
    {
        cout << "X";
    }
    else
    {
        cout << d10;
    }
}

void Chapter4Helper::RunExercise37(double goalAmount)
{
    // 4.37 Find the minimum sales needed in order to make goal amount

    double totalPay = 0;
    double sales = 0.0;
    do {
        sales += 0.01;
        if (sales > 0.01 && sales <= 5000)
        {
            totalPay = 5000 + sales * 0.08;
        }
        else if (sales > 5000 && sales <= 10000)
        {
            totalPay = 5000 + sales * 0.10;
        }
        else
        {
            totalPay = 5000 + sales * 0.12;
        }

    } while (totalPay < goalAmount);

    Exercise37Output.Actual1 = sales;
}

void Chapter4Helper::RunExercise38()
{
    // 4.38 Simulate flipping a coin one million times and displays num heads and tails
    srand(time(0));

    int numHeads = 0;
    int numTails = 0;

    for (int i = 0; i < 1000000; i++) {
        int coinFlip = rand() % 2;
        if (coinFlip == 0)
        {
            numHeads++;
        }
        if (coinFlip == 1)
        {
            numTails++;
        }
    }

    cout << "Number of heads: " << numHeads << "\n" << "Number of tails: " << numTails;
}

void Chapter4Helper::RunExercise39(int *arr)
{
    // 4.39 Input an array of integers, find the max, and count max's occurences
    int max = arr[0];
    int count = 1;
    
    for (int i = 1; i < sizeof(arr); i++)
    {
        if (arr[i] > max) 
        {
            max = arr[i];
            count = 1;
        }
        else if (arr[i] == max)
        {
            count++;
        }
    }
    Exercise39Output.Actual1 = max;
    Exercise39Output.Actual2 = count;
}

void Chapter4Helper::RunExercise40(double goalAmount)
{
    // 4.40 Write 4.37 as follows: use a for loop instead of do-while
    //      let user enter COMMISSION_SOUGHT instead of fixing as constant
    // *note: goalAmount = COMMISSION_SOUGHT

    double totalPay = 0;
    double sales = 0.0;
    
    for (double i = 0; i >= 0; i = i + 0.01)
    {
        sales = i;
        if (sales <= 5000)
        {
            totalPay = 5000 + sales * 0.08;
        }
        else if (sales > 5000 && sales <= 10000)
        {
            totalPay = 5000 + sales * 0.10;
        }
        else
        {
            totalPay = 5000 + sales * 0.12;
        }
        if (totalPay >= goalAmount) 
        {
            break;
        }
    }
    Exercise40Output.Actual1 = sales;
}

void Chapter4Helper::RunExercise41(int numSeconds)
{
    // 4.41 Clock countdown, prompt user to enter num seconds, then display
    //      every second and terminates when time expires
    
    // Reference: https://stackoverflow.com/questions/36879367/how-to-print-a-word-every-second
    
    for (int i = numSeconds; i > 0; i--)
    {
        cout << i << " seconds remaining" << endl;
        Sleep(1000);
    }
    cout << "Stopped" << endl;

}

void Chapter4Helper::RunExercise42()
{
    // 4.42 Monte Carlo Simulation 

    const int NUMBER_OF_TRIALS = 1000000;
    double numberOfHits = 0.0;
    srand(time(0));
    
    for (int i = 0; i < NUMBER_OF_TRIALS; i++)
    {
        double x = rand() * 2.0 / RAND_MAX - 1; 
        double y = rand() * 2.0 / RAND_MAX - 1; 

        if (x < 0)
        {
            numberOfHits++;
        }
        else if (y > 0 && x + y < 1)
        {
            numberOfHits++;
        }
    }
    double probability = numberOfHits / NUMBER_OF_TRIALS;

    cout << "The probability for a stone to fall in this region is: " << probability << endl;
}
