#include "Chapter4Helper.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

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
    const double KILOGRAMS_TO_POUND = 2.2;
    cout << "Kilograms  Pounds   |   Pounds   Kilograms\n";

    for (int i = 0; i < 100; i++)
    {
        int kilogramsInitial = 1 + (2 * i); 
        int poundsInitial = 20 + (5 * i);
        
        double kgToPounds = static_cast<double>(kilogramsInitial) * KILOGRAMS_TO_POUND;
        double poundsToKg = static_cast<double>(poundsInitial) / KILOGRAMS_TO_POUND;

        printf("%-10d %-8.1f %-3c %-8d %-.2f \n", kilogramsInitial, kgToPounds, '|', poundsInitial, poundsToKg);

    }
}