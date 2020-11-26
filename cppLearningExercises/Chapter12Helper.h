#pragma once
#include "Chapter12Output.h"
#include <string>
#include <vector>


class Chapter12Helper
{
public:
    // Supporting data structures
    CHAPTER12::Exercise17Output_s Exercise17Output;

    // Exercise 6 and 7
    template<typename T>
    class Stack
    {
    public: 
        Stack(); 
        bool empty() const; 
        T peek() const;
        void push(T value);
        T pop();
        int getSize() const;
        void printStack();
        bool contains(T element);
    private:
        T elements[100];
        int size; 
    };

    // Exercise 8 
    template<typename T> 
    class MyVectorClass
    {
    public:
        MyVectorClass();
        MyVectorClass(int size);
        void pushBack(T element);
        void popBack();
        unsigned int size();
        T at(int index);
        bool empty();
        void clear();
        void swap(MyVectorClass v2);

    private: 
        T *elements; // point to the address of the vector
        int capacity; 
        int current; 
    };

    // Exercise 9 
    template<typename T>
    class StackVector
    {
    public:
        StackVector();
        bool empty() const;
        T peek() const;
        void push(T value);
        T pop();
        int getSize() const;

    private:
        std::vector<T> myVector = std::vector<T>();
    };

    // Exercise 10
    class Course
    {
    public: 
        Course(const std::string& courseName, int capacity);
        Course(Course&);
        std::string getCourseName() const;
        void addStudent(const std::string& name);
        std::vector<std::string> getStudents() const;
        int getNumberOfStudents() const;
    private:
        std::string courseName;
        std::vector<std::string> students;
        int numberOfStudents;
        int capacity; 
    };

    // Constructor
    Chapter12Helper() :
        Exercise17Output()
    {};

    // Destructor 
    ~Chapter12Helper() {};

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

    // Getters

private: 
    template<typename T>
    T maxInArray(T array[], int size);

    template<typename T>
    int linearSearch(const T list[], T key, int arraySize);
    
    template<typename T>
    int binarySearch(const T list[], T key, int arraySize);

    template<typename T>
    void insertionSort(T list[], int listSize);

    template<typename T>
    void swap(T &value1, T &value2);

    int GetCard();
    std::string ShowCard(int card);
    bool CheckSameLine(std::vector< std::vector<double> > set);
    std::vector<std::string> split(const std::string& expression);
    double getDistance(double x1, double y1, double x2, double y2);
    bool hasMatchingSymbols(std::string str, std::vector<char>& symbols);
    double evaluatePostfix(std::string &postfixString);
    std::string infixToPostfix(const std::string& expression);
    bool hasHigherPrecedence(char value1, char value2);
    int getOperatorWeight(char value);
    std::string showCardSuit(int card);
    std::vector<std::string> generateExpressions(std::vector< std::vector<char> > &operatorList, std::vector< std::vector<int> >& digitList);
    std::vector< std::vector<char> > operatorCombos();
    std::vector< std::vector<int> > digitCombos(std::vector<int> cards);
    std::string parsePosition(int position, std::vector<char> operatorList, std::vector<int> digitList, bool& isDigit);
    std::string testExpression(std::vector<std::string> expressions);
    bool sanitizeExpression(std::string expression);
    int showCardRank(int card);
    bool equalsTwentyFour(std::string& expression);
    bool compare_float(double x, double y, double epsilon = 0.01);
};

