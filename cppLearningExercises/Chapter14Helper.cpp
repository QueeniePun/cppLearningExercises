#include "Chapter14Helper.h"
#include "RationalClass.h"
#include "Circle2.h"
#include "StackOfIntegers.h"
#include "Chapter10Helper.h"
#include "ComplexClass.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void Chapter14Helper::RunExercise1()
{
    // 14.1 Write a program that computes the following summation series using
    //      the Rational class (calculation takes too long for 100 loops)

    Rational num;

    for (int n = 0; n < 10; n++)
    {

        Rational temp(n + 1 , n+2);
        num += temp;
    }
    cout << num.toString();

}

void Chapter14Helper::RunExercise2()
{
    // 14.2 Rewrite Rational Class using a new internal representation for the 
    //      numerator and denominator. Declare an array of two integers as follows

    Rational rational1(4, 10);
    Rational rational2(2, 4);
    rational1 = rational1.multiply(rational2);
    cout << rational1.toString();

}

void Chapter14Helper::RunExercise3()
{
    // 14.3 Implement the relational operators in the Circle class 
    //      order according to their radii

    Circle c1(2);
    Circle c2(3);

    cout << (c1 > c2) << endl;
    cout << (c1 >= c2) << endl;
    cout << (c1 < c2) << endl;
    cout << (c1 <= c2) << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;

}

void Chapter14Helper::RunExercise4()
{
    // 14.4 Exercise 10.14 define the StackOfIntegers class. Implement the 
    //      subscript operator [] to access the elements via [] operator

    StackOfIntegers stack;
    stack.push(5);

    cout << stack[0] << endl;

    stack.push(7);

    cout << stack[1] << endl;
}

void Chapter14Helper::RunExercise5()
{
    // 14.5 Implement the following operators: [], +, <<, <, <=  in the
    //      MyString1 class in Exercise 10.2

    Chapter10Helper::MyString1 s1;
    Chapter10Helper::MyString1 s2;
    char chars[20] = "Queenie";
    char chars2[20] = "Pun";
    s1.assign(chars);
    s2.assign(chars2);
    cout << s1[0] << endl;
    s1 = s1 + s2;
    cout << s1 << endl;
    // cout << (s1 + s2) << endl;
    cout << (s1 < s2) << endl;
    cout << (s1 <= s2) << endl;
}

void Chapter14Helper::RunExercise6()
{
    // 14.6 Implement +=, >>, ==, !=, >, >= in MyString1 class

    Chapter10Helper::MyString1 s1;
    Chapter10Helper::MyString1 s2;
    char chars[20] = "Queenie";
    char chars2[20] = "Pun";
    s1.assign(chars);
    s2.assign(chars2);
    s1 += s1;
    cout << s1 << endl;
    cin >> s1;
    cout << s1;
    cout << (s1 == s2) << endl;
    cout << (s1 != s2) << endl;
    cout << (s1 >= s2) << endl;
    cout << (s1 > s2) << endl;
}

void Chapter14Helper::RunExercise7()
{
    // 14.7 Design a class named Complex to represent complex numbers and functions
    //      add, subtract, multiply, divide, and toString 

    Complex c1(4, 3);
    Complex c2(1, 2);
    c1 = c1 * c2;
    cout << c1 << endl;
}