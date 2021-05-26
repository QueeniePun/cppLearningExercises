#include "Chapter19Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    printVector(vec, size1);
    cout << "Sorted array : ";
    genericMergeSort(vec, 0, size1 - 1);
    printVector(vec, size1);
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
    printVector(c, size2);
    cout << "Sorted array : "; 
    genericMergeSort(c, 0, size2 - 1);
    printVector(c, size2);
    
    vector<string> str; 
    str.push_back("car");
    str.push_back("dog");
    str.push_back("apple");
    str.push_back("ball");
    str.push_back("tree");
    int size3 = str.size();
    cout << "Entered array : ";
    printVector(str, size3);
    cout << "Sorted array : ";
    genericMergeSort(str, 0, size3 - 1);
    printVector(str, size3);
}

template<typename T>
void Chapter19Helper::printVector(vector<T>& v, int size)
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

void Chapter19Helper::RunExercise3()
{
    // Write a generic function for quick sort 
    
    // Run example
    vector<unsigned> input = { 45, 11, 50, 59, 60, 2, 4, 7, 10 };

    printVector(input, input.size());
    genericQuickSort(input, input.size());
    printVector(input, input.size());
}

template<typename T>
T Chapter19Helper::partition(vector<T>& list, int first, int last)
{
    int pivot = list[first];
    int low = first + 1; 
    int high = last; 

    while (high > low)
    {
        // Search forward from left 
        while (low <= high && list[low] <= pivot)
        {
            low++;
        }

        // Search backward from right
        while (low <= high && list[high] > pivot)
        {
            high--;
        }

        // Swap two elements in the list 
        if (high > low)
        {
            T temp = list[high];
            list[high] = list[low];
            list[low] = temp;

        }
    }

    while (high > first && list[high] >= pivot)
    {
        high--;
    }

    // Swap pivot with list[high]
    if (pivot > list[high])
    {
        list[first] = list[high];
        list[high] = pivot;
        return high; 
    }
    else
    {
        return first; 
    }
}

template<typename T> 
void Chapter19Helper::genericQuickSort(vector<T>& list, int listSize)
{
    genericQuickSort(list, 0, listSize - 1);
}

template<typename T> 
void Chapter19Helper::genericQuickSort(vector<T>& list, int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        genericQuickSort(list, first, pivotIndex - 1);
        genericQuickSort(list, pivotIndex + 1, last);
    }
}

void Chapter19Helper::RunExercise4()
{
    // The quick sort algorithm presented in the book selects
    // the first element in the list as the pivot. Revise it 
    // by selecting the medium among the first, middle, and
    // last elements in the last. 

    // Example: {45, 11, 50, 59, 60, 2, 4, 7, 10}
    // First is 45. Middle is 60. Last is 10. Medium is 10. Use 10 as pivot.
        // Run example
    vector<unsigned> input = { 45, 11, 50, 59, 60, 2, 4, 7, 10 };

    printVector(input, input.size());
    improvedQuickSort(input, input.size());
    printVector(input, input.size());
}

template<typename T> 
void Chapter19Helper::improvedQuickSort(vector<T>& list, int listSize)
{
    improvedQuickSort(list, 0, listSize - 1);
}

template<typename T> 
void Chapter19Helper::improvedQuickSort(vector<T>& list, int first, int last)
{
    if (last > first)
    {
        int pivotIndex = improvedPartition(list, first, last);
        improvedQuickSort(list, first, pivotIndex - 1);
        improvedQuickSort(list, pivotIndex + 1, last);
    }
}


// Return the index 
template<typename T>
int Chapter19Helper::improvedPartition(vector<T>& list, int first, int last)
{

    // Find the medium among the first, middle and last elements to use as pivot 
    int middle = last / 2; 
    int pivotIndex = findMedium(list, first, middle, last);
    T pivot = list[pivotIndex];
    int low = first + 1;
    int high = last;

    while (high > low)
    {
        // Search forward from left 
        while (low <= high && list[low] <= pivot)
        {
            low++;
        }

        // Search backward from right
        while (low <= high && list[high] > pivot)
        {
            high--;
        }

        // Swap two elements in the list 
        if (high > low)
        {
            T temp = list[high];
            list[high] = list[low];
            list[low] = temp;

        }
    }

    while (high > first && list[high] >= pivot)
    {
        high--;
    }

    // Swap pivot with list[high]
    if (pivot > list[high])
    {
        list[first] = list[high];
        list[high] = pivot;
        return high;
    }
    else
    {
        return first;
    }
}

template<typename T> 
int Chapter19Helper::findMedium(vector<T>& list, int first, int middle, int last)
{
    // Returns the element that is the medium between the first, middle, and 
    // last elements 

    vector<T> temp = { list[first], list[middle], list[last] };
    
    // Dereference the values since max/min_element only returns iterators 
    T max = *max_element(begin(temp), end(temp));
    T min = *min_element(begin(temp), end(temp));
    
    if (list[first] != max || list[first] != min)
    {
        return first; 
    }
    if (list[middle] != max || list[middle] != min)
    {
        return middle;
    }
    if (list[last] != max || list[last] != min)
    {
        return last; 
    }
    
}

void Chapter19Helper::RunExercise5()
{
    // Write a test program that invokes the generic sort function to sort 
    // and array of int values, and array of doubles values, and array of string 

    // assuming heap sort 
        // Run example
    vector<unsigned> intTest = { 45, 11, 50, 59, 60, 2, 4, 7, 10 };
    vector<double> doubleTest = { 4.5, 1.1, 5.0, 5.9, 6.0, .2, 4, 7, 1.0 };
    vector<string> stringTest = { "hello", "this", "is", "a", "test", "Queenie", "zzz", "123", "yes" };

    printVector(intTest, intTest.size());
    improvedQuickSort(intTest, intTest.size());
    printVector(intTest, intTest.size());

    printVector(doubleTest, doubleTest.size());
    improvedQuickSort(doubleTest, doubleTest.size());
    printVector(doubleTest, doubleTest.size());

    printVector(stringTest, stringTest.size());
    improvedQuickSort(stringTest, stringTest.size());
    printVector(stringTest, stringTest.size());
}


void Chapter19Helper::RunExercise6()
{
    // Write the following overloaded functions that check whether an array is 
    // ordered in ascending order or descending order. By default, the function
    // checks ascending order. To check descending order, pass false to the 
    // ascending argument in the function 

    // bool ordered(T list[], int size)
    // bool ordered(T list[], int size, bool ascending)
    int intTest[] = { 45, 11, 50, 59, 60, 2, 4, 7, 10 };
    cout << ordered(intTest, 9) << endl;
    
    int intTest2[] = { 2, 4, 7, 10, 11, 45, 50, 59, 60 };
    cout << ordered(intTest2, 9) << endl;

    int intTest3[] = { 2, 4, 7, 10, 2, 45, 50, 59, 60 };
    cout << ordered(intTest3, 9) << endl;
    
    int intTest4[] = { 60, 59 ,50, 45, 12, 10, 7, 4, 2 };
    cout << ordered(intTest4, 9) << endl;
}

template<typename T> 
bool Chapter19Helper::ascending(T list[], int size)
{
    // Checks whether an array is in ascending order 
    // Assume the list is ascending
    bool isAscending = true; 

    // Compare if the current element is greater than the next element
    // If it is, then isAscending is false
    int i = 0;
    while (i < size - 1 && isAscending)
    {
        // If the current is greater than the next element, it's not ascending
        if (list[i] > list[i + 1])
        {
            isAscending = false;
        }
        i++;
    }

    // Return the value of isAscending
    return isAscending;
}

template <typename T> 
bool Chapter19Helper::ordered(T list[], int size)
{
    // Returns true if the array is ordered in ascending order
    bool isAscending = ascending(list, size);
    
    if (isAscending)
    {
        return true; 
    }
    // If not ascending order, check if it is descending 
    else
    {
        bool isDescending = ordered(list, size, false);
        return isDescending; 
    }

}

template <typename T>
bool Chapter19Helper::ordered(T list[], int size, bool ascending)
{
    // Returns true if the array is ordered (checks for descending)
    if (ascending)
    {
        return true;
    }
    else
    {
        // Check if list is descending 
        bool isDescending = true; 
        int i = 0; 
        while (i < size - 1 && isDescending)
        {
            // If the current is less than the next element, it's not descending
            if (list[i] < list[i + 1])
            {
                isDescending = false; 
            }
            i++;
        }
        return isDescending;
    }
}

void Chapter19Helper::RunExercise7()
{
    // Write a program that randomly generates 1,000,000 integers and sorts 
    // using radix sort. 
  /*  int *list = generateIntegers();
    int n = 10;

    for (int i = 0; i < 10; i++)
    {
        cout << list[i] << " ";
    }
    cout << "\n"; */
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    printArray(arr, n);
 
}

int* Chapter19Helper::generateIntegers()
{
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        int key = rand() % 999 + 1;
        cout << key << endl;
        arr[i] = key;
    }

    return arr;
}

// A utility function to get maximum value in arr[]
int Chapter19Helper::getMax(int arr[], int size)
{
    int mx = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];

        }
    }
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void Chapter19Helper::countSort(int arr[], int n, int exp)
{
    // Create dynamic output array
    int *output = new int[n]; 
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
}

// A utility function to print an array
void Chapter19Helper::printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void Chapter19Helper::radixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
} 

void Chapter19Helper::RunExercise8()
{
    // Write a program that obtains the execution time of selection, 
    // bubble, quick sort and merge for size inputs of 50k, 100k, 150k, 200k, 
    // 250k, 300k.

    cout << "Array Size    |Selection Sort| Bubble Sort  | Merge  Sort | Quick    Sort |" << endl;
    for (int i = 50000; i <= 300000; i += 50000)
    {
        printValue(i);
    }
   
}

void Chapter19Helper::printValue(int arraySize)
{
    int strWidth = 14; 
    int* list = new int[arraySize];

    srand(time(0));

    for (int i = 0; i < arraySize; i++)
    {
        list[i] = rand() % 999 + 1;
    }
    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < strWidth; j++)
        {
            cout << "-";
        }
        cout << "|";
    }

    printf("\n %-11d  |", arraySize);
    
    int* list2 = new int[arraySize];
    list2 = list;
    long startTime = time(0);
    selectionSort(list2, arraySize);
    long endTime = time(0);
    long executionTime = endTime - startTime; 
    printf("%-13d |", executionTime);

    list2 = new int[arraySize];
    list2 = list;
    startTime = time(0);
    genericBubbleSort(list2, arraySize);
    endTime = time(0);
    executionTime = endTime - startTime;
    printf("%-13d |", executionTime);

    list2 = new int[arraySize];
    list2 = list;
    vector<int> vec(list2, list2 + arraySize);
    startTime = time(0);
    genericMergeSort(vec, 0, arraySize-1);
    endTime = time(0);
    executionTime = endTime - startTime;
    printf("%-13d |", executionTime);

    //list2 = new int[arraySize];
    //list2 = list;
    //startTime = time(0);
    //quickSort(list2, arraySize);
    //endTime = time(0);
    //executionTime = endTime - startTime;
    //printf("%-13d |", executionTime);


}

void Chapter19Helper::selectionSort(int list[], int arraySize)
{
    for (int i = 0; i < arraySize -1; i++)
    {
        int currentMin = list[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < arraySize; j++)
        {
            if (currentMin > list[j])
            {
                currentMin = list[j];
                currentMinIndex = j; 
            }
        }
        if (currentMinIndex != i)
        {
            list[currentMinIndex] = list[i];
            list[i] = currentMin;
        }
    }
}

void Chapter19Helper::quickSort(int list[], int arraySize)
{
    quickSort(list, 0, arraySize - 1);
}

void Chapter19Helper::quickSort(int list[], int first, int last)
{
    if (last > first)
    {
        int pivotIndex = partition(list, first, last);
        quickSort(list, first, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, last);
    
    }

}

int Chapter19Helper::partition(int list[], int first, int last)
{
    int pivot = list[first];
    int low = first + 1; 
    int high = last; 

    while (high > low)
    {
        while (low <= high && list[low] <= pivot)
        {
            low++;
        }
        while (low <= high && list[high] > pivot)
        {
            high--; 
        }
        if (high > low)

        {
            int temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }
    
    while (high > first && list[high] >= pivot)
    {
        high--; 
    }

    if (pivot > list[high])
    {
        list[first] = list[high];
        list[high] = pivot; 
        return high;
    }
    else
    {
        return first; 
    }
} 