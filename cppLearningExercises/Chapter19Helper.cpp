#include "Chapter19Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void Chapter19Helper::RunExercise1()
{
    // Write a generic function for bubble sort 
    int a[7] = { 7, 5, 4, 3, 9, 8, 6 };
    double b[5] = { 4.3, 2.5, -0.9, 10.2, 3.0 };
    char c[] = { 'a', 'b', 'd', 'c', 'e', 'f', 'g' };

    cout << "Here is unsorted integer array: ";
    for (int i = 0; i < 7; i++)
        cout << a[i] << ' ';
    cout << endl;

    genericBubbleSort(a, 7);

    cout << "Here is sorted integer array: ";
    for (int i = 0; i < 7; i++)
        cout << a[i] << ' ';
    cout << endl;

    cout << "Here is unsorted double array: ";
    for (int i = 0; i < 5; i++)
        cout << b[i] << ' ';
    cout << endl;

    genericBubbleSort(b, 5);

    cout << "Here is sorted double array: ";
    for (int i = 0; i < 5; i++)
        cout << b[i] << ' ';
    cout << endl; 
    
    cout << "Here is unsorted char array: ";
    for (int i = 0; i < 7; i++)
        cout << c[i] << ' ';
    cout << endl;

    genericBubbleSort(c, 7);

    cout << "Here is sorted char array: ";
    for (int i = 0; i < 7; i++)
        cout << c[i] << ' ';
    cout << endl;
}

template<typename T>
void Chapter19Helper::genericBubbleSort(T *items, int arraySize)
{
    // Initialize a temporary template temp
    T temp;
    bool needNextPass = true;
    for (int k = 1; k < arraySize && needNextPass; k++)
    {
        // Array may be sorted and next pass is not needed
        needNextPass = false;
        for (int i = 0; i < arraySize - k; i++)
        {
            if (items[i] > items[i + 1])
            {
                // Swap items[i] with items[i+1]
                temp = items[i];
                items[i] = items[i + 1];
                items[i + 1] = temp; 

                // Next pass is still needed
                needNextPass = true;
            }
        }
    }
}

void Chapter19Helper::RunExercise2()
{
    // Write a generic function for merge sort 
    // Reference: https://www.geeksforgeeks.org/merge-sort/

    vector<int> vec;
    vec.push_back(13);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(10);
    int size1 = vec.size();
    cout << "Entered array : ";
    printArray(vec, size1);
    cout << "Sorted array : ";
    genericMergeSort(vec, 0, size1 - 1);
    printArray(vec, size1);
    cout << "\n";

    vector<char> c;
    c.push_back('d');
    c.push_back('y');
    c.push_back('h');
    c.push_back('l');
    c.push_back('e');
    c.push_back('a');
    int size2 = c.size();
    cout << "Entered array : ";
    printArray(c, size2);
    cout << "Sorted array : "; 
    genericMergeSort(c, 0, size2 - 1);
    printArray(c, size2);
    
    vector<string> str; 
    str.push_back("car");
    str.push_back("dog");
    str.push_back("apple");
    str.push_back("ball");
    str.push_back("tree");
    int size3 = str.size();
    cout << "Entered array : ";
    printArray(str, size3);
    cout << "Sorted array : ";
    genericMergeSort(str, 0, size3 - 1);
    printArray(str, size3);
}

template<typename T>
void Chapter19Helper::printArray(vector<T>& v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

template<typename T>
void Chapter19Helper::genericMerge(vector<T>& v, int p, int q, int r)
{
    // Find the size of the two sub arrays 
    int size1 = q - p + 1;
    int size2 = r - q;

    // Create temp vectors 
    vector<T> L(size1);
    vector<T> R(size2);

    // Copy data to temp vectors L and R 
    for (int i = 0; i < size1; i++)
    {
        L[i] = v[p + i];
    }
    for (int j = 0; j < size2; j++)
    {
        R[j] = v[q + j + 1];
    }

    // Merge the temp vectors back into v[p...r]

    // Initial index of first subarray 
    int i = 0; 
    
    // Initial index of second subarray 
    int j = 0;

    // Initial index of merged subarray 
    int k = p;

    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < size1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < size2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void Chapter19Helper::genericMergeSort(vector<T>& v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        genericMergeSort(v, p, q);
        genericMergeSort(v, q+1, r);
        genericMerge(v, p, q, r);
    }
}

