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
    str[size] = '\0';
}

void Chapter10Helper::MyString1::append(MyString1 s)
{
    
    int strLength = strlen(str);
    for (int i = 0; i < strlen(s.str); i++)
    {
        // Check if there is space to add the '\0'
        if (i + strlen(str) + 1 > 255)
        {
            break;
        }

        // Update the null terminator (so that the strlen(str) is not 255)
        str[i + strLength + 1] = '\0';

        // Append the next char
        str[i + strLength] = s.str[i];
        
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

void Chapter10Helper::RunExercise10()
{
    // 10.10 Write a function that parses a binary string to decimal int
    string s1 = "10001";
    cout << ParseBinary(s1) << endl;
}

int Chapter10Helper::ParseBinary(const string& binaryString)
{
    int decimal = 0; 

    for (int i = 0; i < binaryString.length(); i++)
    {
        decimal += ((binaryString[i] - 48) * pow(2, binaryString.length() - i - 1));
    }

    return decimal;
}

void Chapter10Helper::RunExercise11()
{
    // 10.11 Rewrite the count function in exercise 7.25 using string class
    string s1 = "Welcome to New York!";
    int counts[26] = { 0 };
    CountLetterOccurences(s1, counts, 26);
}

void Chapter10Helper::CountLetterOccurences(const string& s, int counts[], int size)
{

    // find the frequencies of each char 
    for (int i = 0; i < s.length(); i++)
    {

        int countsIndex = s[i] - 97;
        // if s[i] is an uppercase letter
        if (s[i] < 97 && s[i] > 64 && s[i] < 91)
        {
            countsIndex = s[i] - 65;
        }
        counts[countsIndex]++;
    }

    // print all the non zero counts  
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
        {
            int temp = i + 97;
            char c = temp;
            cout << c << ": " << counts[i] << " times" << endl;
        }
    }
}

void Chapter10Helper::RunExercise12()
{
    // 10.12 Write a function that parses a decimal num to hex 
    int value = 165; 
    cout << ConvertDecimalToHex(value);
}

string Chapter10Helper::ConvertDecimalToHex(int value)
{
    int remainder = 0; 
    int quotient = value; 
    string hexString;

    while (quotient != 0)
    {
        remainder = quotient % 16; 
        if (remainder == 10)
        {
            hexString += "A";
        }
        else if (remainder == 11)
        {
            hexString += "B";
        }
        else if (remainder == 12)
        {
            hexString += "C";
        }
        else if (remainder == 13)
        {
            hexString += "D";
        }
        else if (remainder == 14)
        {
            hexString += "E";
        }
        else if (remainder == 15)
        {
            hexString += "F";
        }
        else
        {
            hexString += to_string(remainder);
        }

        quotient = quotient / 16; 
        
    }
    reverse(hexString.begin(), hexString.end());
    return hexString; 
}

void Chapter10Helper::RunExercise13()
{
    // 10.13 Write a function that parses a decimal num to binary string
    int value = 123; 
    cout << ConvertDecimalToBinary(value);
}

string Chapter10Helper::ConvertDecimalToBinary(int value)
{
    int remainder = 0; 
    int quotient = value;
    string binaryString;

    while (quotient != 0)
    {
        remainder = quotient % 2;
        binaryString += to_string(remainder); 
        quotient = quotient / 2; 
    }
    reverse(binaryString.begin(), binaryString.end());
    return binaryString; 
}

void Chapter10Helper::RunExercise14()
{
    // 10.14 Rewrite the prefix function in 7.26
    string s1 = "disgusted";
    string s2 = "disguised";
    cout << FindPrefix(s1, s2);
}

string Chapter10Helper::FindPrefix(const string& s1, const string& s2)
{
    string prefix;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])
        {
            prefix += s1[i];
        }
        else
        {
            break;
        }
    }

    return prefix; 
}

void Chapter10Helper::RunExercise15()
{
    // 10.15 Write a program that repeatedly prompts the user to enter a
    //       capital of a state. 
    srand(time(0));
    CapitalQuiz();
}

void Chapter10Helper::CapitalQuiz()
{
    string states[10][2] =
    {
        {"Alabama", "Montgomery"},
        {"Alaska", "Juneau"},
        {"Arizona", "Phoenix"},
        {"Arkansas", "Little Rock"},
        {"California", "Sacramento"},
        {"Colorado", "Denver"},
        {"Connecticut", "Hartford"},
        {"Delaware", "Dover"},
        {"Florida", "Tallahassee"},
        {"Georgia", "Atlanta"}
    };

    for (int i = 0; i < 10; i++)
    {
        string answer;
        cout << "What is the capital of " << states[i][0] << "?" << endl;
        cin >> answer; 

        if (CheckCapital(answer, states[i][1]))
        {
            cout << "Your answer is correct." << endl;
        }
        else
        {
            cout << "The capital of " << states[i][0] << " is " << states[i][1] << endl;
        }
    }

}

bool Chapter10Helper::CheckCapital(const string& s, string capital)
{
    return (s == capital);
}

void Chapter10Helper::RunExercise16()
{
    // 10.16 Validate Credit Card number 
    string cardNumber = "4388576018410707";

    if (IsCardValid(cardNumber))
    {
        cout << "Card is valid.";
    }
    else
    {
        cout << "Card is not valid.";
    }

}

bool Chapter10Helper::IsCardValid(const std::string& cardNumber)
{
    int finalSum = SumOfEvenPlace(cardNumber) + SumOfOddPlace(cardNumber);
    finalSum = finalSum % 10; 
    if (finalSum == 0)
    {
        return true; 
    }
    else
    {
        return false; 
    }

}
int Chapter10Helper::SumOfEvenPlace(const std::string& cardNumber)
{
    
    int sum = 0; 
    for (int i = cardNumber.length() - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            string digitString;
            digitString += cardNumber[i];
            int digit = stoi(digitString);
            digit *= 2;
            digit = GetDigit(digit);
            sum += digit;
        }
    }
    return sum; 
}
int Chapter10Helper::GetDigit(int num)
{
    int digit; 
    if (num >= 10)
    {
        int digit1 = num % 10; 
        int digit2 = num / 10;
        digit = digit1 + digit2;
        return digit; 
    }
    else
    {
        return num; 
    }
}
int Chapter10Helper::SumOfOddPlace(const std::string& cardNumber)
{
    string digitString; 
    int sum = 0;  
    for (int i = cardNumber.length() - 1; i > 0; i--)
    {
        if (i % 2 == 1)
        {
            string digitString;
            digitString += cardNumber[i];
            int digit = stoi(digitString);
            sum += digit; 
        }
    }
    return sum; 
}

void Chapter10Helper::RunExercise17()
{
    // 10.17 use string operations to simplify Exercise 3.17 Check ISBN
    string ISBN = "982677324";

    CheckISBN(ISBN);
}

void Chapter10Helper::CheckISBN(const string& s)
{
    string ISBN = s;
    int checksum = 0;
    for (int i = 0; i < s.length();i++)
    {
        string digitString;
        digitString += s[i];
        int digit = stoi(digitString);
        checksum += digit * i; 
    }
    checksum = checksum % 11; 
    if (checksum == 10)
    {
        ISBN += "X";
    }
    else
    {
        ISBN += to_string(checksum);
    }

    cout << ISBN;
}

void Chapter10Helper::RunExercise18()
{
    // 10.18 Design a class named MyInteger 
}

Chapter10Helper::MyInteger::MyInteger(int num)
{
    value = num;
}

int Chapter10Helper::MyInteger::getInt()
{
    return value; 
}

bool Chapter10Helper::MyInteger::isEven()
{
    return (value % 2 == 0);
}

bool Chapter10Helper::MyInteger::isOdd()
{
    return (value % 2 == 1);
}

bool Chapter10Helper::MyInteger::isPrime()
{
    for (int divisor = 2; divisor <= value / 2; divisor++)
    {
        if (value % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

bool Chapter10Helper::MyInteger::isEven(int num)
{
    return (num % 2 == 0);
}

bool Chapter10Helper::MyInteger::isOdd(int num)
{
    return (num % 2 == 1);
}

bool Chapter10Helper::MyInteger::isPrime(int num)
{
    for (int divisor = 2; divisor <= num / 2; divisor++)
    {
        if (num % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

bool Chapter10Helper::MyInteger::isEven(MyInteger myInt)
{
    return (myInt.value % 2 == 0);
}

bool Chapter10Helper::MyInteger::isOdd(MyInteger myInt)
{
    return (myInt.value % 2 == 1);
}

bool Chapter10Helper::MyInteger::isPrime(MyInteger myInt)
{
    for (int divisor = 2; divisor <= myInt.value / 2; divisor++)
    {
        if (myInt.value % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

bool Chapter10Helper::MyInteger::equals(int num)
{
    return (value == num);
}

bool Chapter10Helper::MyInteger::equals(MyInteger myInt)
{
    return (value == myInt.value);
}

int Chapter10Helper::MyInteger::ParseInt(string stringInt)
{
    int newInt = stoi(stringInt);
    return newInt;
}

void Chapter10Helper::RunExercise19()
{
    // 10.19 Rewrite the Loan class to add two static functions for computing
    //       monthly payment and total payment 
}

Chapter10Helper::Loan::Loan()
{
    annualInterestRate = 9.5;
    numberOfYears = 30; 
    loanAmount = 100000;
}

double Chapter10Helper::Loan::getLoan()
{
    return loanAmount;
}

double Chapter10Helper::Loan::getMonthlyPayment(double annualInterestRate, int numberOfYears, double loanAmount)
{
    double monthlyInterestRate = annualInterestRate / 1200; 
    return loanAmount * monthlyInterestRate / (1 - (pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
}

double Chapter10Helper::Loan::getTotalPayment(double annualInterestRate, int numberOfYears, double loanAmount)
{
    return getMonthlyPayment(annualInterestRate, numberOfYears, loanAmount) * numberOfYears * 12;
}

void Chapter10Helper::RunExercise20()
{
    // 10.20 Design a class named stock 
    Stock myStock("MSFT", "Microsoft Corporation");
    myStock.setCurrentPrice(17.6);
    myStock.setPreviousClosingPrice(17.5);
    cout << myStock.changePercent() << endl;
}

Chapter10Helper::Stock::Stock(string stockSymbol, string stockName)
{
    symbol = stockSymbol;
    name = stockName; 
}

string Chapter10Helper::Stock::getSymbol()
{
    return symbol; 
}

string Chapter10Helper::Stock::getName()
{
    return name; 
}

double Chapter10Helper::Stock::getPreviousClosingPrice()
{
    return previousClosingPrice;
}

double Chapter10Helper::Stock::getCurrentPrice()
{
    return currentPrice;
}

void Chapter10Helper::Stock::setPreviousClosingPrice(double newPreviousClosingPrice)
{
    previousClosingPrice = newPreviousClosingPrice;
}

void Chapter10Helper::Stock::setCurrentPrice(double newCurrentPrice)
{
    currentPrice = newCurrentPrice;
}

double Chapter10Helper::Stock::changePercent()
{
    double percentChange = ((currentPrice - previousClosingPrice) / previousClosingPrice) * 100;
    return percentChange; 
}

void Chapter10Helper::RunExercise21()
{
    // 10.21 Design a class named RegularPolygon

    RegularPolygon test1;
    RegularPolygon test2(6, 4);
    RegularPolygon test3(10, 4, 5.6, 7.8);

    cout << "Perimeter: " << test1.getPerimeter() << endl;
    cout << "Area: " << test1.getArea() << endl;
    cout << "Perimeter: " << test2.getPerimeter() << endl;
    cout << "Area: " << test2.getArea() << endl;
    cout << "Perimeter: " << test3.getPerimeter() << endl;
    cout << "Area: " << test3.getArea() << endl;
}

Chapter10Helper::RegularPolygon::RegularPolygon()
{
    n = 3;
    side = 1; 
    x = 0; 
    y = 0;
}

Chapter10Helper::RegularPolygon::RegularPolygon(int numSides, double sideLength)
{
    n = numSides;
    side = sideLength;
    x = 0;
    y = 0; 
}

Chapter10Helper::RegularPolygon::RegularPolygon(int numSides, double sideLength, double xCoord, double yCoord)
{
    n = numSides; 
    side = sideLength;
    x = xCoord;
    y = yCoord;
}

int Chapter10Helper::RegularPolygon::getNumSides()
{
    return n;
}

double Chapter10Helper::RegularPolygon::getSideLength()
{
    return side;
}

double Chapter10Helper::RegularPolygon::getX()
{
    return x; 
}

double Chapter10Helper::RegularPolygon::getY()
{
    return y; 
}

void Chapter10Helper::RegularPolygon::setNumSides(int numSides)
{
    n = numSides;
}

void Chapter10Helper::RegularPolygon::setSideLength(double sideLength)
{
    side = sideLength;
}

void Chapter10Helper::RegularPolygon::setX(double xCoord)
{
    x = xCoord;
}

void Chapter10Helper::RegularPolygon::setY(double yCoord)
{
    y = yCoord; 
}

double Chapter10Helper::RegularPolygon::getPerimeter()
{
    return (n * side);
}

double Chapter10Helper::RegularPolygon::getArea()
{
    const double PI = 3.14159;
    double area = (n * pow(side, 2)) / (4 * tan(PI / n));
    return area; 
}

void Chapter10Helper::RunExercise22()
{
    // 10.22 Write a program that receives a positive integer and 
    //       displays all of its smallest factors in decreasing order

    StackOfIntegers stack;
    int num = 120; 
    int factor = 2;
    while (num / factor != 1)
    {
        if (num % factor == 0)
        {
            stack.push(factor);
            num /= factor; 
        }
        else
        {
            factor++;
        }
    }
    stack.push(num);

    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
}

Chapter10Helper::StackOfIntegers::StackOfIntegers()
{
    size = 0; 
}

bool Chapter10Helper::StackOfIntegers::isEmpty() const
{
    return (size == 0);
}

int Chapter10Helper::StackOfIntegers::peek() const
{
    return elements[size - 1];
}

void Chapter10Helper::StackOfIntegers::push(int value)
{
    elements[size++] = value;
}

int Chapter10Helper::StackOfIntegers::pop()
{
    return elements[--size];
}
int Chapter10Helper::StackOfIntegers::getSize() const
{
    return size; 
}

void Chapter10Helper::RunExercise23()
{
    // 10.23 Write a hangman game 

    Hangman game;

    StartHangmanGame(game);

}

void Chapter10Helper::StartHangmanGame(Hangman game)
{
    while (!game.isGuessFinished())
    {
        char ch;
        cout << "(Guess) Enter a letter in word " << game.getGuess() << endl;
        cin >> ch;
        game.updateGuess(ch);
    }

    cout << "The word is " << game.getGuess() << ". You missed "
         << game.getWrongGuessCount() << " time(s)" << endl;

    char response;
    cout << "Do you want to guess for another word? Enter y or n";
    cin >> response;

    if (response == 'y')
    {
        Hangman newGame;
        StartHangmanGame(newGame);
    }
    else
    {
        return;
    }
}

Chapter10Helper::Hangman::Hangman()
{
    srand(time(0));
    int getGuess = rand() % 4; 
    word = words[getGuess];
    wrongGuessCount = 0;
    for (int i = 0; i < word.length(); i++)
    {
        guess += "*";
    }

}

string Chapter10Helper::Hangman::getGuess()
{
    return guess; 
}

int Chapter10Helper::Hangman::getWrongGuessCount()
{
    return wrongGuessCount;
}

string Chapter10Helper::Hangman::updateGuess(char ch)
{
    if (!isLetterValid(ch))
    {
        cout << ch << " is not in the word " << getGuess() << endl;
        wrongGuessCount++;
        return guess; 
    }
    else if (isLetterValid(ch) && guess.find(ch) != string::npos)
    {
        cout << ch << " is already in the word" << endl;
        return guess;
    }
    else
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ch)
            {
                guess[i] = ch;
            }
        }
        return guess; 
    }


}

bool Chapter10Helper::Hangman::isLetterValid(char ch)
{
    if (word.find(ch) == string::npos)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Chapter10Helper::Hangman::isGuessFinished()
{
    return (guess == word);
}

void Chapter10Helper::RunExercise24()
{
    // 10.24 Write a program that displays all the prime numbers less
    //       120 in decreasing order. Use the StackOfIntegers class to
    //       store the prime numbers, display in reverse

    StackOfIntegers stack;

    for (int i = 2; i < 120; i++)
    {
        if (IsPrime(i))
        {
            stack.push(i);
        }
    }

    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
}

bool Chapter10Helper::IsPrime(int num)
{
    for (int divisor = 2; divisor <= num / 2; divisor++)
    {
        if (num % divisor == 0)
        {
            return false;
        }
    }
    return true;
}
