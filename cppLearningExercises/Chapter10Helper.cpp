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

    MyString1 myStringTest; 
    MyString1 myStringTest2; 
    char chars[20] = "Welcome";
    char chars2[20] = "Dallas";
    myStringTest.assign(chars);
    myStringTest2.assign(chars2);
    myStringTest.append(myStringTest2);

    cout << myStringTest.str << endl;
    for (int i = 0; i < strlen(myStringTest.str); i++)
    {
        Exercise2Output.Actual1[i] = myStringTest.str[i];
    }
}

Chapter10Helper::MyString1::MyString1()
{
    for (int i = 0; i < 255; i++)
    {
        str[i] = ' ';
        if (i == 254)
        {
            str[i] = '\0';
        }
    }
}

Chapter10Helper::MyString1::MyString1(char chars[], int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = chars[i];
    }
}

void Chapter10Helper::MyString1::append(MyString1 s)
{
    
    for (int i = 0; i < strlen(s.str); i++)
    {
        if (i + strlen(str) > 255)
        {
            break;
        }

        str[i + strlen(str)] = s.str[i];
    }
}

void Chapter10Helper::MyString1::append(MyString1 s, int index, int n)
{
    for (int i = 0; i < n; i++)
    {
        str[strlen(str) + i] += s.str[i + index];
    }
}

void Chapter10Helper::MyString1::assign(char chars[])
{

    clear(); 

    for (int i = 0; i < strlen(chars); i++)
    {
        str[i] = chars[i];
    }

    str[strlen(chars)] = '\0';
}

void Chapter10Helper::MyString1::assign(MyString1 s, int index, int n)
{
    clear(); 

    for (int i = 0; i < n; i++)
    {
        str[i] = s.str[i];
    }

    str[n] = '\0';
}

char Chapter10Helper::MyString1::at(int index)
{
    if (index < 0 || index > strlen(str))
    {
        return ' ';
    }

    return str[index];
}

int Chapter10Helper::MyString1::length()
{
    return strlen(str);
}

void Chapter10Helper::MyString1::clear()
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            str[i] = ' ';
        }
    }
}

void Chapter10Helper::MyString1::erase(int index, int n)
{
    for (int i = 0; i < n; i++)
    {
        str[i + index] = ' ';
    }

    int strIndex = index + n;
    for (int i = 0; i < (strlen(str) - index - n); i++)
    {
        str[index + i] = str[strIndex + i];
        str[strIndex + i] = ' ';
    }
}

bool Chapter10Helper::MyString1::empty()
{
    return strlen(str) == 0;
}

int Chapter10Helper::MyString1::compare(MyString1 s)
{
    return strcmp(str, s.str);
}

void Chapter10Helper::MyString1::copy(char s[], int index, int n)
{
    clear();
    for (int i = 0; i < n; i++)
    {
        str[i] = s[i + index];
    }
}

void Chapter10Helper::MyString1::substr(int index, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << str[i + index];
    }
}

int Chapter10Helper::MyString1::find(char ch)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            return i;
        }
    }

    return -1;
}

void Chapter10Helper::RunExercise3()
{
    // 10.3 Implement MyString2 class with several functions
}

Chapter10Helper::MyString2::MyString2(char chars[], int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = chars[i];
    }
}

void Chapter10Helper::MyString2::append(int n, char ch)
{
    for (int i = 0; i < n; i++)
    {
        str[strlen(str) + i] = ch;
    }
}

void Chapter10Helper::MyString2::assign(MyString2 s, int n)
{
    clear();
    for (int i = 0; i < n; i++)
    {
        str[i] = s.str[i];
    }
}

void Chapter10Helper::MyString2::assign(int n, char ch)
{
    clear();
    for (int i = 0; i < n; i++)
    {
        str[i] = ch; 
    }
}

void Chapter10Helper::MyString2::clear()
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            str[i] = ' ';
        }
    }
}

int Chapter10Helper::MyString2::compare(int index, int n, MyString2 s)
{
    char temp[255];
    for (int i = index; i < index + n; i++)
    {
        temp[i] = s.str[i];
    }
    temp[n] = '\0';
    return strcmp(str, temp);
}

void Chapter10Helper::MyString2::copy(char s[], int index, int n)
{
    clear();
    for (int i = 0; i < n; i++)
    {
        str[i] = s[i + index];
    }
}

void Chapter10Helper::MyString2::substr(int index)
{
    for (int i = 0; i < strlen(str); i++)
    {
        cout << str[i + index];
    }
}

int Chapter10Helper::MyString2::find(char ch, int index)
{
    for (int i = index; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            return i; 
        }
    }

    return -1; 
}

void Chapter10Helper::RunExercise4()
{
    // 10.4 Write a function that returns a sorted string
    string s = "";
    cout << "Enter a string: ";
    cin >> s;
    
    cout << Sort(s) << endl;

}

string Chapter10Helper::Sort(string &s)
{
    string sorted = s;

    for (int i = 0; i < sorted.length()-1; i++)
    {
        char min = sorted[i];
        int minIndex = i;
        
        for (int j = i + 1; j < sorted.length(); j++)
        {
            if (min > sorted[j])
            {
                min = sorted[j];
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            sorted[minIndex] = sorted[i];
            sorted[i] = min;
        }
    }

    return sorted; 
}

void Chapter10Helper::RunExercise5()
{
    // 10.5 Revise listing 10.3 to check whether string is 
    //      Palindrome assuming not case sensitive
    cout << "Enter a string: ";
    string s; 
    cin >> s; 

    if (IsPalindrome(s))
    {
        cout << s << " is a palindrome" << endl;
    }
    else
    {
        cout << s << " is not a palindrome" << endl;
    }
}

bool Chapter10Helper::IsPalindrome(const string& s)
{
    // create a temp string that is entirely lowercase
    string temp = s;
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            temp[i] = s[i] + 32;
        }
        else
        {
            temp[i] = s[i];
        }
    }

    // Initialize indices
    int low = 0; 
    int high = s.length() - 1;

    while (low < high)
    {
        if (temp[low] != temp[high])
        {
            return false; 
        }
        low++;
        high--; 
    }

    return true;
}

void Chapter10Helper::RunExercise6()
{
    // 10.6 Rewrite the indexOf function in 7.22 but pass by 
    //      reference 
    string s1 = "welcome";
    string s2 = "We welcome you!";
    string s3 = "We invite you!";

    cout << IndexOf(s1, s3);
}

int Chapter10Helper::IndexOf(const string& s1, const string& s2)
{
    for (int i = 0; i < s2.length() - s1.length(); i++)
    {
        for (int j = 0; j <= s1.length(); j++)
        {
            if (s2[i + j] != s1[j])
            {
                break; // not found, keep search
            }
            if (j + 1.0 == s1.length())
            {
                return i;
            }
        }
    }
    // none found
    return -1;
}

void Chapter10Helper::RunExercise7()
{
    // 10.7 Rewrite the count function in 7.23
    string s = "Welcome to C++";
    char a = 'o';

    int count = CountCharacters(s, a);
    printf("%d", count);
}

int Chapter10Helper::CountCharacters(const string& s, char a)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == a)
        {
            count++;
        }
    }
    return count;
}

void Chapter10Helper::RunExercise8()
{
    // 10.8 Rewrite the CountLetters function in 7.24
   string s = "2020 is coming";

    int count = CountLetters(s);
    printf("%d", count);
}

int Chapter10Helper::CountLetters(const string& s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
        {
            count++;
        }
    }
    return count;
}

void Chapter10Helper::RunExercise9()
{
    // 10.9 Write a function that parses a hex num to decimal int
    string s1 = "FAA";
    cout << ParseHex(s1) << endl;

}

int Chapter10Helper::ParseHex(const string& hexString)
{
    int decimal = 0;

    for (int i = 0; i < hexString.length(); i++)
    {
        if (hexString[i] == 'A')
        {
            decimal += (10 * pow(16, hexString.length() - i - 1));
        }
        else if (hexString[i] == 'B')
        {
            decimal += (11 * pow(16, hexString.length() - i - 1));
        }
        else if (hexString[i] == 'C')
        {
            decimal += (12 * pow(16, hexString.length() - i - 1));
        }
        else if (hexString[i] == 'D')
        {
            decimal += (13 * pow(16, hexString.length() - i - 1));
        }
        else if (hexString[i] == 'E')
        {
            decimal += (14 * pow(16, hexString.length() - i - 1));
        }
        else if (hexString[i] == 'F')
        {
            decimal += (15 * pow(16, hexString.length() - i - 1));
        }
        else
        {
            // hexstring[i] needs to be an integer 
            decimal += ((hexString[i] - 48) * pow(16, hexString.length() - i - 1));
        }

    }

    return decimal;
}