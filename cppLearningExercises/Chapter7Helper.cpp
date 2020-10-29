#include "Chapter7Helper.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <array>

using namespace std;

void Chapter7Helper::RunExercise1(double list[], int listSize)
{
    // 7.1 Write a program that reads ten numbers, computes their average, and finds out
    //     how many numbers are above the average 
    double sum = 0.0; 
    for (int i = 0; i < listSize; i++)
    {
        sum += list[i];
    }
    double average = sum / listSize; 
    Exercise1Output.Actual1 = average;

    cout << "Average: " << average << endl;

    int count = 0;
    for (int i = 0; i < listSize; i++)
    {
        if (list[i] > average)
        {
            count++;
        }
    }
    cout << "The number of values greater than average: " << count << endl;
    Exercise1Output.Actual2 = count;
}

void Chapter7Helper::RunExercise2(int list[], int listSize)
{
    // 7.2 Write a program that reads 10 integers and displays them 
    //     in the reverse order in which they were read

    // WHY THIS NOT WORK? 
    /* const int LIST_SIZE = listSize;
    int newArray[LIST_SIZE]; */

    for (int i = 0; i < listSize / 2; i++)
    {
        int temp = list[i];
        list[i] = list[listSize - 1 - i];
        list[listSize - 1 - i] = temp;
    }

    for (int i = 0; i < listSize; i++)
    {
        cout << list[i] << " ";
    }
}

void Chapter7Helper::RunExercise3(int list[], int listSize) 
{
    // 7.3 Write a program that reads the integers between 1 and 100 and counts the occurrence of each number

    // initialize counter array for integers 1 to 100 
    int integers[100];
    for (int i = 0; i < 100; i++)
    {
        integers[i] = 0;
    }

    // count occurrences 
    for (int i = 0; i < listSize; i++)
    {
        integers[list[i]]++;
    }

    // display result
    for (int i = 0; i < 100; i++)
    {
        if (integers[i] != 0)
        {
            cout << i << " occurs " << integers[i] << " times" << endl;
        }
    }
}

void Chapter7Helper::RunExercise4()
{
    // 7.4 Write a program that reads an unspecified num of scores and determines how many 
    //     are above or equal to the avg & how many are below. enter neg num to signify end of inputs
    //     assume max scores is 100

    int arr[100];
    int numScores = 0; 
    double sum = 0;

    cout << "Enter score: "; 
    double newInput;
    for (int i = 0; i < 100; i++)
    {
        cin >> newInput;
        if ( newInput < 0)
        {
            break;
        }
        arr[i] = newInput;
        sum += arr[i];
        numScores++;
    }

    double average = sum / numScores;

    // find how many above or below average
    int above = 0;
    int below = 0;
    for (int i = 0; i < numScores; i++)
    {
        if (arr[i] >= average)
        {
            above++;
        }
        else
        {
            below++;
        }
    }
    
    cout << average << endl;
    cout << "above: " << above << "\n" << "below: " << below << endl;
}

void Chapter7Helper::RunExercise5(int list[], int listSize)
{
    // 7.5 Write a program that reads in ten numbers and displays distinct numbers
    
    // initialize new array 
    int distinctList[10];
    for (int i = 0; i < 10; i++)
    {
        distinctList[i] = 0;
    }

    // loop through given list[] and loop through distinctList[] and see if distinct
    int currentDistinctIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < 10; j++)
        {
            if (list[i] == distinctList[j])
            {
                isDuplicate = true;
                break;
            }             
        }
        if (!(isDuplicate))
        {
            distinctList[currentDistinctIndex] = list[i];
            currentDistinctIndex++;
        }
    }

    // display array 
    for (int i = 0; i < currentDistinctIndex; i++)
    {
        cout << distinctList[i] << " ";
    }
}

void Chapter7Helper::RunExercise6()
{
    // 7.6 Revise Listing 4.14 

    // initialize array of primes 
    int primesList[50];
    int index = 0;
    for (int i = 2; index < 50; i++)
    {
        if (IsPrime(i))
        {
            primesList[index] = i;
            index++;
        }
    }

    // display array
    int count = 1;
    for (int i = 0; i < index; i++)
    {
        if (count % 10 == 0) {

            printf("%5d \n", primesList[i]);
            count = 1;
        }
        else
        {
            printf("%5d ", primesList[i]);
            count++;
        }
    }
}

bool Chapter7Helper::IsPrime(int number)
{
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

void Chapter7Helper::RunExercise7()
{
    // 7.7 Write a program that generates one hundred random ints between 0 and 9 and displays count for each
    srand(time(0));
    // initialize count array 
    int counts[10];
    for (int i = 0; i < 10; i++)
    {
        counts[i] = 0;
    }

    // generate 100 random integers
    for (int i = 0; i < 100; i++)
    {
        int randomInt = rand() % 10;

        // loop through counts array to account for the random generated integer
        for (int j = 0; j < 10; j++)
        {
            if (j == randomInt)
            {
                counts[j]++;
            }
        }
    }

    // display results of array 
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d \n", i, counts[i]);
    }
}