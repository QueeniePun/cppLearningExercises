#include "Chapter12Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

void Chapter12Helper::RunExercise1()
{
    // 12.1 Design a generic function that returns a max element from an array

    int list1[] = { 3, 5, 1, 0, 2, 8, 7 };
    cout << maxInArray(list1, 7) << endl;

    double list2[] = { 3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7 };
    cout << maxInArray(list2, 7) << endl;

    string list3[] = { "Atlanta", "Denver", "Chicago", "Dallas" };
    cout << maxInArray(list3, 4) << endl;

}

template<typename T>
T Chapter12Helper::maxInArray(T array[], int size)
{
    T max = array[0]; 
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void Chapter12Helper::RunExercise2()
{
    // 12.2 Rerwite the linear search function in Listing 7.8
    int list1[] = { 3, 5, 1, 0, 2, 8, 7 };
    cout << linearSearch(list1, 7, 7) << endl;

    double list2[] = { 3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7 };
    cout << linearSearch(list2, 0.4, 7) << endl;

    string list3[] = { "Atlanta", "Denver", "Chicago", "Dallas" };
    string key = "New York City";
    cout << linearSearch(list3, key, 4) << endl;
}

template<typename T>
int Chapter12Helper::linearSearch(const T list[], T key, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (key == list[i])
        {
            return i;
        }
    }
    return -1;
}

void Chapter12Helper::RunExercise3()
{
    // 12.3 Rewrite Listing 7.9 Binary Search 
    // recall binary sorting requires the array to be presorted
    int list1[] = { 1, 2, 3, 4, 5, 6, 7 };
    cout << binarySearch(list1, 7, 7) << endl;

    double list2[] = {0.5, 1.4, 2.4, 2.5, 2.8, 3.4, 4.7 };
    cout << binarySearch(list2, 2.4, 7) << endl;

    string list3[] = { "Atlanta", "Denver", "Chicago", "Dallas" };
    string key = "New York City";
    cout << binarySearch(list3, key, 4) << endl;
}

template<typename T>
int Chapter12Helper::binarySearch(const T list[], T key, int arraySize)
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
            return mid; 
        }
        else
        {
            low = mid + 1; 
        }
    }

    return -1; 
}

void Chapter12Helper::RunExercise4()
{
    // 12.4 Rewrite Listing 7.11 Insertion Sort
    int list1[] = { 1, 2, 4, 3, 5, 6, 7 };
    insertionSort(list1, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << list1[i] << " ";
    }

    double list2[] = { 0.5, 1.4, 0.4, 3.5, 5.8, 3.4, 4.7 };
    insertionSort(list2, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << list2[i] << " ";
    }

    string list3[] = { "Atlanta", "Denver", "Chicago", "Dallas" };
    insertionSort(list3, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << list3[i] << " ";
    }
}

template<typename T> 
void Chapter12Helper::insertionSort(T list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        T currentElement = list[i];
        int k; 
        for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
        {
            list[k + 1] = list[k];
        }

        list[k + 1] = currentElement;
    }
}

void Chapter12Helper::RunExercise5()
{
    // 12.5 Write a generic function that swaps values in two variables 
    int int1 = 1; 
    int int2 = 2;
    swap(int1, int2);
    cout << "int1 should be 2: " << int1 << " and int 2 should be 1: " << int2 << endl;

    double double1 = 1.0;
    double double2 = 2.0;
    swap(double1, double2);
    cout << "double1: " << double1 << " double 2: " << double2 << endl;

    string string1 = "Hello";
    string string2 = "Bye";
    swap(string1, string2);
    cout << "string1: " << string1 << " string2: " << string2 << endl;
}

template<typename T>
void Chapter12Helper::swap(T &value1, T &value2)
{
    T temp = value1; 
    value1 = value2; 
    value2 = temp; 
}

void Chapter12Helper::RunExercise6()
{
    // 12.6 Add the printStack function into the stack class as an instance
    //      function to display all the elemnts in the stack

    Stack<int> intStack; 
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
    }
    intStack.printStack();
}

template<typename T>
Chapter12Helper::Stack<T>::Stack()
{
    size = 0; 
}

template<typename T>
bool Chapter12Helper::Stack<T>::empty() const
{
    return (size == 0);
}

template<typename T>
T Chapter12Helper::Stack<T>::peek() const
{
    return elements[size - 1];
}

template<typename T>
void Chapter12Helper::Stack<T>::push(T value)
{
    elements[size++] = value;
}

template<typename T>
T Chapter12Helper::Stack<T>::pop()
{
    return elements[--size];
}

template<typename T>
int Chapter12Helper::Stack<T>::getSize() const
{
    return size; 
}

template<typename T> 
void Chapter12Helper::Stack<T>::printStack()
{
    for (int i = 0; i < size; i++)
    {
        cout << elements[i]; 
    }
}

void Chapter12Helper::RunExercise7()
{
    // 12.7 Add the contains(T element) into the stack class  
    Stack<int> intStack;
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
    }
    cout << "should be true: " << intStack.contains(2);
    cout << "should be false: " <<intStack.contains(18);

}

template<typename T>
bool Chapter12Helper::Stack<T>::contains(T element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == elements[i])
        {
            return true; 
        }
    }

    return false; 
}

void Chapter12Helper::RunExercise8()
{
    // 12.8 Implement the vector class as an exercise
    //      implement the functions defined in figure 12.2

    MyVectorClass<int> vector1(10); 
    for (int i = 0; i < vector1.size(); i++)
    {
        vector1.pushBack(i); 
    }

    MyVectorClass<int> vector2(10);
    for (int i = 0; i < vector2.size(); i++)
    {
        vector2.pushBack(i * 2);
    }

    swap(vector1, vector2);

    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1.at(i);
    }
}

template<typename T>
Chapter12Helper::MyVectorClass<T>::MyVectorClass()
{
    elements = new T[1];
    capacity = 1; 
    current = 0; 
}

template<typename T>
Chapter12Helper::MyVectorClass<T>::MyVectorClass(int size)
{
    elements = new T[size];
    capacity = size;
    current = 0; 
}

template<typename T>
void Chapter12Helper::MyVectorClass<T>::pushBack(T element)
{
    if (current == capacity)
    {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = elements[i];
        }

        delete[] elements; 
        capacity *= 2; 
        elements = temp; 
    }

    elements[current] = element;
    current++; 
}

template<typename T>
void Chapter12Helper::MyVectorClass<T>::popBack()
{
    current--; 
}

template<typename T> 
unsigned int Chapter12Helper::MyVectorClass<T>::size()
{
    return capacity; 
}

template<typename T> 
T Chapter12Helper::MyVectorClass<T>::at(int index)
{
    return elements[index];
}

template<typename T> 
bool Chapter12Helper::MyVectorClass<T>::empty()
{
    return (current == 0);
}

template<typename T> 
void Chapter12Helper::MyVectorClass<T>::clear()
{
    current = 0; 
}

template<typename T> 
void Chapter12Helper::MyVectorClass<T>::swap(MyVectorClass v2)
{
    T *temp = elements;
    elements = v2.elements;
    v2.elements = temp; 
}

void Chapter12Helper::RunExercise9()
{
    // 12.9 Listing 12.4 is implemented using arrays. Implement using vectors 

    // Note: declaring the vector in the StackVector class syntax from reference 
    // Reference: https://stackoverflow.com/questions/39765112/error-c2039-vector-is-not-a-member-of-std

    StackVector<int> myVector;
    myVector.push(7);
    myVector.push(7);
    myVector.push(7);
    myVector.push(8);
    cout << myVector.peek() << endl;
}

template<typename T> 
Chapter12Helper::StackVector<T>::StackVector()
{
    vector<T> myVector(1);
}

template<typename T> 
bool Chapter12Helper::StackVector<T>::empty() const
{
    return myVector.empty();
}

template<typename T> 
T Chapter12Helper::StackVector<T>::peek() const
{
    int size = myVector.size();
    T last = size - 1; 
    return myVector[last];
}

template<typename T> 
void Chapter12Helper::StackVector<T>::push(T value)
{
    myVector.push_back(value);
}

template<typename T> 
T Chapter12Helper::StackVector<T>::pop()
{
    myVector.pop_back();
}

template<typename T> 
int Chapter12Helper::StackVector<T>::getSize() const
{
    return myVector.size();
}

void Chapter12Helper::RunExercise10()
{
    // 12.10 Rewrite the Course class in Listing 11.17, use a vector 
    Course Course1("CPP", 2);
    Course1.addStudent("Queenie");
    Course1.addStudent("AI Queenie");
    vector<string> students = Course1.getStudents();
    for (int i = 0; i < Course1.getNumberOfStudents(); i++)
    {
        cout << students[i] << " ";
    }
}

Chapter12Helper::Course::Course(const string &courseName, int capacity)
{
    numberOfStudents = 0; 
    this->courseName = courseName;
    this->capacity = capacity;
    students.resize(capacity);
}

Chapter12Helper::Course::Course(Course& course)
{
    courseName = course.courseName;
    numberOfStudents = course.numberOfStudents;
    capacity = course.capacity; 
    students.resize(capacity);
}

string Chapter12Helper::Course::getCourseName() const
{
    return courseName;
}

void Chapter12Helper::Course::addStudent(const string& name)
{
    if (numberOfStudents >= capacity)
    {
        cout << "Class full" << endl;
    }
    else
    {
        students[numberOfStudents] = name; 
        numberOfStudents++;
    }
}

vector<string> Chapter12Helper::Course::getStudents() const
{
    return students; 
}

int Chapter12Helper::Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

void Chapter12Helper::RunExercise11()
{
    // 12.11 
}