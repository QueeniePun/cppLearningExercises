#include "Chapter16Helper.h"
#include "Chapter10Helper.h"
#include "RationalClass.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void Chapter16Helper::RunExercise1()
{
    // 16.1 Exercise 10.9 specifies parseHex(const string &hexString) function.
    //      Implement the parseHex function to throw a runtime error exception 
    //      if the string is not a hex string. 

    Chapter10Helper ch10;
    // Note: The code for this exercise is commented out for exercise 16.5
    // ch10.RunExercise9();
}

void Chapter16Helper::RunExercise2()
{
    // 16.2 Exercise 10.10 specifies parseBinary(const string &binaryString). 
    //      Implement the parseBinary function to throw a runtime error 
    //      exception if the string is not a binaryString. 

    Chapter10Helper ch10;
    // Note: this exercise is commented out to test 16.6
    // ch10.RunExercise10();
}

void Chapter16Helper::RunExercise3()
{
    // 16.3 Define a custom exception called IllegalSubscriptException and
    //      let the function operator throw an IllegalSupscriptException if
    //      the subscript is neither 0 or 1.

    // test program exception
    try
    {
        Rational a;
        cout << "The value at a[0] is " << a[0] << endl;
        cout << "The value at a[2] is " << a[2] << endl;
    }
    catch (IllegalSubscriptException& ex)
    {
        cout << ex.what() << endl;
        cout << "The subscript entered is: " << ex.getSubscript() << endl;
    }
}

void Chapter16Helper::RunExercise4()
{
    // 16.4 For the StackOfIntegers class, define a custom exception class named
    //      EmptyStackException and let the pop function throw the exception if
    //      the stack is empty. Write a test program with a try-catch block.  

    try
    {
        Chapter10Helper::StackOfIntegers stack;
        stack.push(1);
        stack.pop();
        stack.pop();
    }
    catch (EmptyStackException& ex)
    {
        cout << ex.what() << endl;
        cout << "The current size is: " << ex.getSize() << endl;
    }
}

void Chapter16Helper::RunExercise5()
{
    // 16.5 Implement the parseHex function from 16.1 to throw a HexFormatException if
    //      the string is not a hex string. Define the custom class HexFormatException.
    //      Write a test program.

    Chapter10Helper ch10;
    ch10.RunExercise9();
}

void Chapter16Helper::RunExercise6()
{
    // 16.6 Implement 16.2 to throw a BinaryFormatException. 
    Chapter10Helper ch10;
    ch10.RunExercise10();
}