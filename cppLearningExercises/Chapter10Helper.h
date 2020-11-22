#pragma once
#include "Chapter10Output.h"
#include <string>

class Chapter10Helper
{
public:
    // Supporting data structures
    CHAPTER10::Exercise2Output_s Exercise2Output;

    // Exercise 2
    class MyString1
    {
    public:
        char str[255];
        MyString1();
        MyString1(char chars[], int size);
        void append(MyString1 s);
        void append(MyString1 s, int index, int n);
        void assign(char chars[]);
        void assign(MyString1 s, int index, int n);
        char at(int index);
        int length();
        void clear();
        void erase(int index, int n);
        bool empty();
        int compare(MyString1 s);
        void copy(char s[], int index, int n);
        void substr(int index, int n);
        int find(char ch);

    private:
        
    };

    // Exercise 3
    class MyString2
    {
    public:
        char str[255];
        MyString2(char chars[], int size);
        void append(int n, char ch);
        void assign(MyString2 s, int n);
        void assign(int n, char ch);
        int compare(int index, int n, MyString2 s);
        void copy(char s[], int index, int n);
        void substr(int index);
        int find(char ch, int index);
        void clear();
    private:

    };

    // Exercise 18
    class MyInteger
    {
    public:
        int value;
        MyInteger(int num);
        int getInt();
        bool isEven();
        bool isOdd();
        bool isPrime();
        static bool isEven(int num);
        static bool isOdd(int num);
        static bool isPrime(int num);
        static bool isEven(MyInteger myInt);
        static bool isOdd(MyInteger myInt);
        static bool isPrime(MyInteger myInt);
        bool equals(int num);
        bool equals(MyInteger myInt);
        static int ParseInt(std::string stringInt);
    private:
    };


    // Exercise 19 
    class Loan
    {
    public:
        Loan();
        double getLoan();
        static double getMonthlyPayment(double annualInterestRate, int numberOfYears, double loanAmount);
        static double getTotalPayment(double annualInterestRate, int numberOfYears, double loanAmount);
    private:
        double annualInterestRate; 
        int numberOfYears;
        double loanAmount;
    };

    // Exercise 20
    class Stock
    {
    public: 
        Stock(std::string stockSymbol, std::string stockName);
        std::string getSymbol();
        std::string getName();
        double getPreviousClosingPrice(); 
        double getCurrentPrice();
        void setPreviousClosingPrice(double newPreviousClosingPrice);
        void setCurrentPrice(double newCurrentPrice);
        double changePercent();

    private:
        std::string symbol; 
        std::string name; 
        double previousClosingPrice; 
        double currentPrice; 

    };


    // Exercise 21
    class RegularPolygon
    {
    public:
        RegularPolygon();
        RegularPolygon(int numSides, double sideLength);
        RegularPolygon(int numSides, double sideLength, double xCoord, double yCoord);
        int getNumSides();
        double getSideLength();
        double getX();
        double getY();
        void setNumSides(int numSides);
        void setSideLength(double sideLength);
        void setX(double xCoord);
        void setY(double yCoord);
        double getPerimeter();
        double getArea();

    private:
        int n; 
        double side; 
        double x; 
        double y; 

    };

    // Exercise 22
    class StackOfIntegers
    {
    public: 
        StackOfIntegers();
        bool isEmpty() const;
        int peek() const;
        void push(int value);
        int pop();
        int getSize() const;
        
    private:
        int elements[100];
        int size; 
    };


    // Exercise 23
    class Hangman
    {
    public:
        Hangman();
        std::string getGuess();
        int getWrongGuessCount();
        std::string updateGuess(char ch);
        bool isLetterValid(char ch);
        bool isGuessFinished();

    private:
        std::string words[4] =
        {
            "write", "that", "program", "queenie"
        };
        std::string word;
        std::string guess; 
        int wrongGuessCount; 

    };
    // Constructor
    Chapter10Helper() :
        Exercise2Output()
    {};

    // Destructor 
    ~Chapter10Helper() {};

    // Method
    void RunExercise1();
    void RunExercise2();
    void RunExercise3();
    void RunExercise4();
    void RunExercise5();
    void RunExercise6();
    void RunExercise7();
    void RunExercise8();
    void RunExercise9();
    void RunExercise10();
    void RunExercise11();
    void RunExercise12();
    void RunExercise13();
    void RunExercise14();
    void RunExercise15();
    void RunExercise16();
    void RunExercise17();
    void RunExercise18();
    void RunExercise19();
    void RunExercise20();
    void RunExercise21();
    void RunExercise22();
    void RunExercise23();
    void RunExercise24();

    // Getters

private:
    bool IsAnagram(std::string s1, std::string s2);
    std::string Sort(std::string& s);
    bool IsPalindrome(const std::string& s);
    int IndexOf(const std::string& s1, const std::string& s2);
    int CountCharacters(const std::string& s, char a);
    int CountLetters(const std::string& s);
    int ParseHex(const std::string& hexString);
    int ParseBinary(const std::string& binaryString);
    void CountLetterOccurences(const std::string& s, int counts[], int size);
    std::string ConvertDecimalToHex(int value);
    std::string ConvertDecimalToBinary(int value);
    std::string FindPrefix(const std::string& s1, const std::string& s2);
    void CapitalQuiz();
    bool CheckCapital(const std::string& s, std::string capital);
    bool IsCardValid(const std::string& cardNumber);
    int SumOfEvenPlace(const std::string& cardNumber);
    int GetDigit(int num);
    int SumOfOddPlace(const std::string& cardNumber);
    void CheckISBN(const std::string& s);
    bool IsPrime(int num);
    void StartHangmanGame(Hangman game);
}; 

