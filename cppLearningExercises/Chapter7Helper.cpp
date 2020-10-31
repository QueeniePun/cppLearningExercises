#include "Chapter7Helper.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <array>
#include <Windows.h>
#include <algorithm>

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

    //     WHY DOES THIS NOT WORK?
    //     - At compile time, when the program is built, this value (listSize) is unassigned 
    //     const int LIST_SIZE = listSize;
    //     int newArray[LIST_SIZE]

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

void Chapter7Helper::RunExercise8()
{
    // 7.8 Write two overloading functions that return an average of array and write a 
    //     write a test program that promps user to enter 10 double values, invokes fn and 
    //     displays the average value

    double arr[] = { 1.9, 2.5, 3.7, 2, 1.5, 6, 3, 4, 5, 2 };
    double averageValue = Average(arr, 10);
    cout << averageValue << endl;
}

int Chapter7Helper::Average(const int array[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    double average = sum / size;
    return average;
}

double Chapter7Helper::Average(const double array[], int size)
{
    double sum = 0; 
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    double average = sum / size;
    return average; 
}

void Chapter7Helper::RunExercise9()
{
    // 7.9 Write a function that finds the smallest element in an array of integers 
    //     and write a test program that prompts 10 numbers, invokes fn, displays value
    
    double arr[] = { 1.9, 2.5, 3.7, 2, 1.5, 6, 3, 4, 5, 2 };
    double minimumValue = Min(arr, 10);
    cout << minimumValue << endl;
}

double Chapter7Helper::Min(double arr[], int size)
{
    double min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min; 
}

void Chapter7Helper::RunExercise10()
{
    // 7.10 Write a function that returns the index of the smallest element in array of integers
    //      and if there are more elements than one, return smallest index. Write test for array of 10 ints 
    double arr[] = { 1.9, 2.5, 3.7, 2, 1.9, 6, 3, 4, 5, 1.5 };
    double indexOfSmallest = IndexOfSmallestElement(arr, 10);
    cout << indexOfSmallest; 
}

int Chapter7Helper::IndexOfSmallestElement(double array[], int size)
{
    int index = 0; 
    double min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            index = i; 
        }
    }
    return index; 
}

void Chapter7Helper::RunExercise11()
{
    // 7.11 Write functions for mean and deviation, and test program that displays result 
    double arr[] = { 1.9, 2.5, 3.7, 2, 1, 6, 3, 4, 5, 2 };
    double mean = Mean(arr, 10);
    double deviation = Deviation(arr, 10);
    cout << "The mean is: " << mean << endl;
    cout << "The standard deviation is: " << deviation << endl;
}

double Chapter7Helper::Mean(const double x[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += x[i];
    }
    double mean = sum / size; 
    return mean;
}

double Chapter7Helper::Deviation(const double x[], int size)
{
    double mean = Mean(x, size);
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += pow(x[i] - mean, 2);
    }
    double deviation = sqrt(sum / (size - 1.0));
    return deviation; 
}

void Chapter7Helper::RunExercise12()
{
    // 7.12 Write a program that reads student scores, and gets the bes score, then assigns grades 
    //      based on following curve. The progrm prompts user to enter total num students, then prompts user
    //      to enter all of the scores, and concludes by display grades 

    double arr[] = { 40, 55, 70, 58 };
    AssignGrades(arr, 4);
}

void Chapter7Helper::AssignGrades(double arr[], int size)
{
    double max = arr[0]; 
    // loop to find the max score 
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // assign each score to the grades array 
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= max - 10)
        {
            printf("%s %d %s %.f %s \n", "Student", i, "score is", arr[i], "and grade is A");
        }
        else if (arr[i] >= max - 20)
        {
            printf("%s %d %s %.f %s \n", "Student", i, "score is", arr[i], "and grade is B");
        }
        else if (arr[i] >= max - 30)
        {
            printf("%s %d %s %.f %s \n", "Student", i, "score is", arr[i], "and grade is C");
        }
        else if (arr[i] >= max - 40)
        {
            printf("%s %d %s %.f %s \n", "Student", i, "score is", arr[i], "and grade is D");
        }
        else
        {
            printf("%s %d %s %.f %s \n", "Student", i, "score is", arr[i], "and grade is F");

        }
    }
}

void Chapter7Helper::RunExercise13(double COMMISSION_SOUGHT)
{
    // 7.13 Rewrite Exercise 4.37 using the binary search approach since the sales amount is between
    //      1 and COMMISSION_SOUGHT/0.08, you can use binary search to improve solution

    double low = 1; 
    double high = COMMISSION_SOUGHT / 0.08;

    while (high >= low)
    {

        double totalPay = 0;
        double mid = ((low + high) / 2);
        // Find the total pay at this bound 
        if (mid <= 5000)
        {
            totalPay = mid * 0.08 + 5000; 
        }
        else if (mid > 5000 && mid <= 10000)
        {
            totalPay = mid * 0.10 + 5000;
        }
        else
        {
            totalPay = mid * 0.12 + 5000;
        }

        // compare the total pay and commission sought
        if (totalPay < COMMISSION_SOUGHT)
        {
            low = mid + 0.01; 
        }
        else if (totalPay - COMMISSION_SOUGHT <= 0.002)
        {
            Exercise13Output.Actual1 = mid;
            return;
        }
        else
        {
            high = mid - 0.01;
        }
    }
}

void Chapter7Helper::RunExercise14()
{
    // 7.14 Write a program that randomly generates array of 100000 integers and a key. 
    //      Estimate the execution time of invoking the linearSearch fn. Sort the array, then 
    //      use binarySearch to get the execution time. 
    srand(time(0));
    int key = rand();
    cout << key << endl;
    int arr[100000];
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = i;
    }

    const int NANOSECONDS_PER_SECOND = 1000000;
    long startTimeLinear = time(0);
    for (int i = 0; i < 1000000; i++) 
    {
        LinearSearch(arr, key, 100000);
    }
    long endTimeLinear = time(0);
    long ExecutionTimeLinear = (endTimeLinear - startTimeLinear) * NANOSECONDS_PER_SECOND;
    printf("%s %ld \n", "LinearSearch execution time (ns):", ExecutionTimeLinear);

    long startTimeBinary = time(0);
    for (int i = 0; i < 1000000; i++)
    {
        BinarySearch(arr, key, 100000);
    }
    long endTimeBinary = time(0);
    long ExecutionTimeBinary = (endTimeBinary - startTimeBinary) * NANOSECONDS_PER_SECOND;
    printf("%s %ld \n", "BinarySearch execution time (ns):", ExecutionTimeBinary);
}

int Chapter7Helper::LinearSearch(const int list[], int key, int arraySize)
{
    
    for (int i = 0; i < arraySize; i++)
    {
        if (key == list[i])
        {
            // cout << "Found linear" << endl;
            return i;
        }
    }
    return -1;
}

int Chapter7Helper::BinarySearch(const int list[], int key, int arraySize)
{

    int low = 0;
    int high = arraySize - 1; 
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (key < list[mid])
        {
            high = mid - 1; 
        }
        else if (key == list[mid])
        {
            // cout << "Found binary" << endl;
            return mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1; 
}

void Chapter7Helper::RunExercise15()
{
    // 7.15 Locker puzzle. A school has 100 students and 100 lockers. The doors opened should be n^2 from for
    //      integers of n: 1 to 10
    
    // initialize lockers 
    int locker[101];
    for (int i = 1; i < 101; i++)
    {
        locker[i] = 0;
    }

    // loop through each student and account their actions
    for (int i = 1; i < 101; i++)
    {
        for (int j = i; j < 101; j += i)
        {
            locker[j]++;
        }
    }

    // loop through each locker and see if open or closed 
    for (int i = 1; i < 101 ; i++)
    {
        if (locker[i] % 2 == 1)
        {
            printf("%s %d %s \n", "Locker", i, "is opened");
        }
    }
}

void Chapter7Helper::RunExercise16()
{
    // 7.16 Bubble sort: Write a sort function that uses the bubble sort algorithm 
    //      Write a test program that reads in an array of ten double numbers, invokes fn, displays result

    double arr[] = { 3.2, 4, 9, 1, 6, 5.3, 8, 7, 5, 2 };
    BubbleSort(arr, 10);
}

void Chapter7Helper::BubbleSort(double list[], int listSize)
{
    bool changed = true; 
    do 
    {
        changed = false; 
        for (int j = 0; j < listSize - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                double temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                changed = true; 
            }
        }
    } while (changed);

    // display the list 
    for (int i = 0; i < listSize; i++)
    {
        printf("%.2f ", list[i]);
    }
}

void Chapter7Helper::RunExercise17()
{
    // 7.17 Write a program that simulates the bean machine. The number of R's is the position of the slot of the ball
    int numOfBalls = 5;
    int numOfSlots = 7; // max of 50 in the machine 

    string ballPaths[5];
    int slots[7]; // each element in slots stores the number of balls in a slot 
     
    for (int i = 0; i < 7; i++)
    {
        slots[i] = 0;
    }
    
    srand(time(0));

    // display the path of the balls
    for (int i = 0; i < numOfBalls; i++)
    {
        // find the path of ball by dropping the ball numOfSlots times
        ballPaths[i] = DropBall(slots, numOfSlots);
        printf("%s \n", ballPaths[i].c_str());
    } 

    for (int i = 0; i < numOfSlots; i++)
    {
        cout << slots[i] ;
    }

    cout << endl;
    // display the final buildup of the balls in the slots in a histogram 
    PrintHistogram(slots, numOfSlots);

}

string Chapter7Helper::DropBall(int slots[], int numOfSlots)
{
    string ballPath = "";
    
    // loop through numOfSlots
    for (int i = 0; i < numOfSlots; i++)
    {
        int randomPath = rand() % 2;
        if (randomPath == 0)
        {
            ballPath.append("R");
        }
        else
        {
            ballPath.append("L");
        }
    }

    // find final position of ball
    int position = GetBallPosition(ballPath);
    slots[position]++;
    return ballPath;
}

int Chapter7Helper::GetBallPosition(string ballPath)
{
    char r = 'R';
    int numOfR = 0;
    for (int i = 0; i < ballPath.length(); i++)
    {
        if (ballPath.at(i) == r)
        {
            numOfR++;
        }
    }
    return numOfR;
}

bool comp(int a, int b)
{
    return (a < b);
}

void Chapter7Helper::PrintHistogram(int slots[], int slotsSize)
{
    // find the max of the array 

    // max_element returns an iterator (pointer), use * to dereference pointer
    // Reference: http://www.cplusplus.com/reference/algorithm/max_element/
    // Reference: https://www.w3schools.com/cpp/cpp_pointers_dereference.asp
    
    int maxHeight = *(std::max_element(slots, slots + slotsSize));
    int currentHeight = maxHeight;

    for (int h = maxHeight; h > 0; h--) {
        for (int i = 0; i < slotsSize; i++)
        {
            if (slots[i] == h)
            {
                printf("%c", 'O');
                slots[i]--;
            }
            else
            {
                printf("%c", ' ');
            }
        }
        cout << endl;
    }
}

void Chapter7Helper::RunExercise18()
{
    // 7.18 Rewrite 7.9.1 selection sort by finding the largest num
    //      and swapping with it the last number in array. Write a 
    //      test program that reads in an array of 10 double nums, invokes fn,
    //      and displays the sorted 

    double nums[] = { 2.0, 6.0, 3, 7.8, 3.4, 7.0, 9, 8, 4, 8.7 };
    SelectionSortDescending(nums, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", nums[i]);
    }
}

void Chapter7Helper::SelectionSortDescending(double list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        double currentMax = list[i];
        int currentMaxIndex = i;

        for (int j = i + 1; j < listSize; j++)
        {
            if (currentMax < list[j])
            {
                currentMax = list[j];
                currentMaxIndex = j;
            }
        }


        if (currentMaxIndex != i)
        {
            list[currentMaxIndex] = list[i];
            list[i] = currentMax;
        }
    }
}

void Chapter7Helper::RunExercise19()
{
    // 7.19 The classic Eight Queens puzzle 
}