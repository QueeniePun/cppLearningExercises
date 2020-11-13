#include "Chapter10Helper.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <array>
#include <Windows.h>

using namespace std;

void Chapter10Helper::RunExercise1()
{
    // 10.1 Write a function that checks whether two words are anagrams. 
    //      Two words are anagrams if they contain the same letters in any order.
    //      Write a test program that prompts the user to enter two strings and checks 

    string s1; 
    string s2; 
    cout << "Enter a string: ";
    cin >> s1; 
    cout << "Enter a second string: ";
    cin >> s2; 

    if (IsAnagram(s1, s2))
    {
        cout << s1 << " and " << s2 << " are anagrams" << endl;
    }
    else
    {
        cout << s1 << " and " << s2 << " are not anagrams" << endl;
    }

}

bool Chapter10Helper::IsAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    // Sort the strings and compare sort function needs to include algorithm
    string test1 = s1; 
    string test2 = s2; 
    sort(test1.begin(), test1.end());
    sort(test2.begin(), test2.end());

    for (int i = 0; i < test1.length(); i++)
    {
        if (test1[i] != test2[i])
        {
            return false;
        }
    }

    return true; 
}

void Chapter10Helper::RunExercise2()
{
    // 10.2 Provide your own implementation of the string class MyString1 
}

Chapter10Helper::MyString1::MyString1()
{
    s1 = "";
}

Chapter10Helper::MyString1::MyString1(char chars[], int size)
{
    for (int i = 0; i < size; i++)
    {
        s1 += chars[i];
    }
}

void Chapter10Helper::MyString1::append(MyString1 s2)
{
    s1 += s2.s1;
}

void Chapter10Helper::MyString1::append(MyString1 s, int index, int n)
{
    for (int i = index; i < (index + n); i++)
    {
        s1 += s.s1[i];
    }
}

void Chapter10Helper::MyString1::assign(char chars[])
{

}