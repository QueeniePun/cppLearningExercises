#include "Chapter4Helper.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <string>

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

        // Test is current is prime
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

}