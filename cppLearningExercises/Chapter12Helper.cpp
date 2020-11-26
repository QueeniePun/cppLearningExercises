#include "Chapter12Helper.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>


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
    // 12.11 Rewrite exercise 7.21 using vectors to represent arrays 
    srand(time(0));
    bool spades = false;
    bool hearts = false;
    bool diamond = false;
    bool clubs = false;
    
    vector<string> picks(4);

    int index = 0;
    int pickCount = 0;

    while (!spades || !hearts || !diamond || !clubs)
    {
        string card = ShowCard(GetCard());
        pickCount++;
        if (card.find("Spades") != string::npos && !spades) {
            picks[index++] = card;
            spades = true;
        }
        else if (card.find("Hearts") != string::npos && !hearts) {
            picks[index++] = card;
            hearts = true;
        }
        else if (card.find("Diamond") != string::npos && !diamond) {
            picks[index++] = card;
            diamond = true;
        }
        else if (card.find("Clubs") != string::npos && !clubs) {
            picks[index++] = card;
            clubs = true;
        }

    }

    for (int i = 0; i < 4; i++)
    {
        printf("%s \n", picks[i].c_str());
    }
    printf("%s %d", "Pick count = ", pickCount);
}


int Chapter12Helper::GetCard()
{
    int card = rand() % 52 + 1;
    return card;
}

string Chapter12Helper::ShowCard(int card)
{
    vector<string> suit = { "Spades", "Hearts", "Diamonds", "Clubs", };
    vector<string> ranks = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

    int suitNum = card / 13;
    int rankNum = card % 13;

    return ranks[rankNum] + " of " + suit[suitNum];
}

void Chapter12Helper::RunExercise12()
{
    // 12.12 Rewrite exercise 8.16 using vectors to represent strings
    
    // sets to test with 
    vector< vector<double> > set1 = { {1, 1}, {2, 2}, {3, 3}, {4, 4} };
    vector< vector<double> > set2 = { {0, 1}, {1, 2}, {4, 5}, {5, 6} };
    vector< vector<double> > set3 = { {0, 1}, {1, 2}, {4, 5}, {4.5, 4} };
 
    CheckSameLine(set3);
}

bool Chapter12Helper::CheckSameLine(vector< vector<double> > set)
{
    // find the slope between first two points 
    double slope = (set[1][1] - set[0][1]) / (set[1][0] - set[0][0]);

    // compare each point and check if slopes are same
    for (int i = 2; i < set.size(); i++)
    {
        double currSlope = (set[i][1] - set[0][1]) / (set[i][0] - set[0][0]);
        if (currSlope != slope)
        {
            cout << "Point " << "(" << set[i][0] << ", " << set[i][1] <<
                ") is not on the same line" << endl;
            return false;
        }
    }
    cout << "All points are on the same line." << endl;
    return true; 
}

void Chapter12Helper::RunExercise13()
{
    // 12.13 Write a function that splits the expression into numbers, operators,
    //       and parentheses, and displays split items in reverse order
    string s = "4 + 50";
    vector<string> v = split(s);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << endl;
    }
}

vector<string> Chapter12Helper::split(const string& expression)
{
    vector<string> v; 
    string numberString; 

    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            numberString.append(1, expression[i]);
        }
        else
        {
            if (numberString.size() > 0)
            {
                v.push_back(numberString); // store the numeric string 
                numberString.erase(); // empty the numeric string 
            }

            if (!isspace(expression[i]))
            {
                string s;
                s.append(1, expression[i]);
                v.push_back(s); // store operator or parenthese
            }
        }
    }

    if (numberString.size() > 0)
    {
        v.push_back(numberString);
    }

    return v; 
}

void Chapter12Helper::RunExercise14()
{
    // 12.14 Rewrite listing 8.3. First prompt the user to enter the num points
    //       then prompt the user to enter all the points

    int numPoints;
    cout << "Enter the number of points: " << endl;
    cin >> numPoints;

    vector< vector<double> > points(numPoints);
    for (int i = 0; i < numPoints; i++)
    {
        points[i] = vector<double>(3);
    }

    cout << "Enter the points: ";
    for (int i = 0; i < numPoints; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    int p1 = 0, p2 = 1;
    double shortestDistance = getDistance(points[p1][0], points[p1][1],
        points[p2][0], points[p2][1]);

    for (int i = 0; i < numPoints; i++)
    {
        for (int j = i + 1; j < numPoints; j++)
        {
            double distance = getDistance(points[i][0], points[i][1],
                points[j][0], points[j][1]);

            if (shortestDistance > distance)
            {
                p1 = i; 
                p2 = j;
                shortestDistance = distance; 
            }
        }
    }

    cout << "The closest two points are " <<
        "(" << points[p1][0] << ", " << points[p1][1] << ") and (" <<
        points[p2][0] << ", " << points[p2][1] << ")";
}

double Chapter12Helper::getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void Chapter12Helper::RunExercise15()
{
    // 12.5 Write a program that prompts the user to enter a c++ source-code
    //      filename and check whether the file has correct pairs of grouping
    //      symbols () [] and {}

    // read a file line by line and check 
    ifstream file("test.txt");
    string str;
    vector<char> symbols;
    bool isMatching = true;

    while (getline(file, str))
    {
        isMatching = hasMatchingSymbols(str, symbols);
        if (!isMatching)
        {
            cout << "no matching symbols" << endl;
            break;
        }
    }

    if (isMatching)
    {
       // check if there are dangling symbols
        if (symbols.empty())
        {
            cout << "Grouping symbols match";
        }
        else
        {
            cout << "No matching symbols";
        }
    }
    
}

bool Chapter12Helper::hasMatchingSymbols(string str, vector<char> &symbols)
{
    for (int i = 0; i < str.size(); i++)
    {
        char current = str[i];
        if (current == '{' || current == '[' || current == '(')
        {
            symbols.push_back(current);
            continue; 
        }
        if (current == '}' || current == ']' || current == ')')
        {
            if (symbols.empty())
            {
                return false; // there is no matching opening symbol
            }
            else
            {
                // compare the pair
                char last = symbols[symbols.size() - 1];
                bool matching = false; 

                switch (last)
                {
                case '{': 
                    if (current == '}')
                    {
                        matching = true; 
                        break;
                    }
                case '[': 
                    if (current == ']')
                    {
                        matching = true; 
                        break;
                    }
                case '(': 
                    if (current == ')')
                    {
                        matching = true; 
                        break;
                    }
                default: // if no case match is found
                    break;
                }
                if (matching)
                {
                    symbols.pop_back();
                }
                else
                {
                    return false; 
                }
            }
        }
    }
}

void Chapter12Helper::RunExercise16()
{
    // 12.16 Write a program that prompts the user to enter a post fix expression
    //       and evaluates it 

    string postfixString; 
    cout << "Enter a postfix expression: ";
    getline(cin, postfixString);

    cout << evaluatePostfix(postfixString);
}

double Chapter12Helper::evaluatePostfix(string& postfixString)
{
    vector<double> stack;
    // scan all the characters in the string 
    for (int i = 0; i < postfixString.length(); i++)
    {
        if (postfixString[i] == ' ')
        {
            continue; 
        }
        // if it is a digit, push to stack
        if (isdigit(postfixString[i]))
        {
            int num = 0; 
            while (isdigit(postfixString[i]))
            {
                num = num * 10 + (postfixString[i] - 48);
                i++;
            }
            i--; 
            stack.push_back(num);
        }
        // check if it is an operator 
        if (postfixString[i] == '+' || postfixString[i] == '-' ||
            postfixString[i] == '*' || postfixString[i] == '/')
        {
            double val1 = stack.back();
            stack.pop_back();
            double val2 = stack.back();
            stack.pop_back();
            switch (postfixString[i])
            {
            case '+': stack.push_back(val2 + val1); break;
            case '-': stack.push_back(val2 - val1); break;
            case '*': stack.push_back(val2 * val1); break;
            case '/': stack.push_back(val2 / val1); break;
            }
        }
    }
    return stack.back();
}

void Chapter12Helper::RunExercise17()
{
    // 12.17 Write a program for the 24 point card game. 

    srand(time(0));

    vector<string> ranks = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

    // Generate 4 Random Cards
    vector<int> cards(4);

    for (int i = 0; i < 4; i++)
    {
        int card = GetCard();
        cards[i] = showCardRank(card) + 1;

        cout << "Card: " << card << endl;
        cout << "Rank: " << showCardRank(card) << endl;

        // Display the card
        string suitString = showCardSuit(card);
        string rankString = ranks[showCardRank(card)];
        cout << rankString << " of " << suitString << endl;
    }


    vector< vector<char> > operatorList = operatorCombos(); 
    vector< vector<int> > digitList = digitCombos(cards); 

    /*string infixString; 
    cout << "Enter an infix expression: ";
    getline(cin, infixString);
    string postfixString = infixToPostfix(infixString);
    cout << evaluatePostfix(postfixString);*/

    vector<string> expList = generateExpressions(operatorList, digitList);
    testExpression(expList);
    /*Exercise17Output.Actual = expList;*/
}

vector< vector<int> > Chapter12Helper::digitCombos(vector<int> cards)
{
    int intList[4];
    for (int i = 0; i < 4; i++)
    {
        intList[i] = cards[i];
    }

    sort(intList, intList + 4);
    
    // create a vector matrix that holds all digit combinations 
    vector< vector<int> > digitCombos(24);
    for (int i = 0; i < 24; i++)
    { 
        digitCombos[i] = vector<int>(4);
    }

    // generate combinations 
    int count = 0;
    do {
        digitCombos[count][0] = intList[0];
        digitCombos[count][1] = intList[1];
        digitCombos[count][2] = intList[2];
        digitCombos[count][3] = intList[3];
        count++;

        cout << intList[0] << ' ' << intList[1] << ' ' << intList[2] << ' '
            << intList[3] << endl;
    } while (next_permutation(intList, intList + 4));

    cout << count << endl;

    while (digitCombos.size() != count)
    {
        digitCombos.pop_back();
    }

    return digitCombos; 
}

vector< vector<char> > Chapter12Helper::operatorCombos()
{
    vector< vector<char> > operatorList(64); // There are 4x4x4 = 64 operator combos
    for (int i = 0; i < 64; i++)
    {
        operatorList[i] = vector<char>(3); // Each combo has 3 operators
    }

    char ops[4] = { '+', '-', '*', '/' };

    int index = 0; 
    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            for (int c = 0; c < 4; c++)
            {
                operatorList[index][0] = ops[a];
                operatorList[index][1] = ops[b];
                operatorList[index][2] = ops[c];
                index++;
            }
        }
    }
    return operatorList; 
}

vector<string> Chapter12Helper::generateExpressions(vector< vector<char> >& operatorList, vector< vector<int> > &digitList)
{
    vector<string> expressions;

    for (int i = 0; i < digitList.size(); i++)
    {
        for (int j = 0; j < operatorList.size(); j++)
        {
            // generate temp digits
            vector<int> digitTemp; 
            for (int k = 0; k < 4; k++)
            {
                digitTemp.push_back(digitList[i][k]);
            }

            // generate operator
            vector<char> operatorTemp;
            for (int l = 0; l < 3; l++)
            {
                operatorTemp.push_back(operatorList[j][l]);
            }

            // find the expression
            int expPositions[] = { 0, 1, 2, 3, 4, 5, 6 };
            do
            {
                string temp = "";
                int digitCount = 0; 
                int operatorCount = 0; 
                bool isDigit = false;
                bool isValid = true;
                for (int i = 0; i < 7; i++)
                {
                    temp += parsePosition(expPositions[i], operatorTemp, digitTemp, isDigit);
                    temp += " ";
                    isDigit ? digitCount++ : operatorCount++;
                    if (operatorCount >= digitCount)
                    {
                        isValid = false;
                        break;
                    }
                }
                if (isValid)
                {
                    expressions.push_back(temp);
                }
            } while (next_permutation(expPositions + 2, expPositions + 6));

        }
    }
    return expressions;
}

string Chapter12Helper::parsePosition(int position, vector<char> operatorList, vector<int> digitList, bool &isDigit)
{
    // if position is 0, 1, 2, 3, get digit
    if (position <= 3)
    {
        isDigit = true;
        return to_string(digitList[position]);
    }
    else
    {
        isDigit = false;
        string temp = "";
        int posTemp = position - 4; 
        temp += operatorList[posTemp];
        return temp;
    }
}


string Chapter12Helper::testExpression(vector<string> expressions)
{
    bool solutionFound = false; 
    string solution = "No solution"; 
    for (int i = 0; i < expressions.size(); i++)
    {
        // test expression
        if (compare_float(evaluatePostfix(expressions[i]), 24, 0.1))
        {
            solution = expressions[i];
            double temp = evaluatePostfix(expressions[i]);
            cout << setw(5) << setprecision(4) << expressions[i] << "=" <<  temp << endl;
            solutionFound = true;
        }
        
    }

    cout << solution << endl;
    return solution;
}

bool Chapter12Helper::compare_float(double x, double y, double epsilon)
{
    return (abs(x - y) < epsilon);
   
}

string Chapter12Helper::showCardSuit(int card)
{
    vector<string> suit = { "Spades", "Hearts", "Diamonds", "Clubs", };

    int suitNum = card / 13;

    // Check for the multiples of 13
    if (card % 13 == 0)
    {
        suitNum--;
    }

    return suit[suitNum];
}

int Chapter12Helper::showCardRank(int card)
{
    int rankNum = card % 13;
    return rankNum;
}

bool Chapter12Helper::equalsTwentyFour(string& expression)
{
    return true;
}

void Chapter12Helper::RunExercise18()
{
    // 12.18 Write a function that converts an infix expression into a postfix

     string s = "(1 + 2) * 3";
     cout << infixToPostfix(s) << endl;

    string s2 = "2 * (1 + 3)";
    cout << infixToPostfix(s2) << endl;
}

string Chapter12Helper::infixToPostfix(const string& expression)
{
   string postfixString; 
   vector<char> charStack;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ')
        {
            continue; 
        }
        else if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/')
        {
            while (!charStack.empty() && charStack.back() != '('
                && hasHigherPrecedence(charStack.back(), expression[i]))
            {
                postfixString += charStack.back();
                postfixString += " ";
                charStack.pop_back();
            }
            charStack.push_back(expression[i]);
        }
        else if (isdigit(expression[i]))
        {
            int num = 0; 
            while (isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - 48);
                i++;
            }
            i--;
            postfixString += to_string(num);
            postfixString += " ";
        }
        else if (expression[i] == '(')
        {
            charStack.push_back(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!charStack.empty() && charStack.back() != '(')
            {
                postfixString += charStack.back();
                postfixString += " ";
                charStack.pop_back();
            }
            charStack.pop_back();
        }
    }

    while (!charStack.empty())
    {
        postfixString += charStack.back();
        postfixString += " ";
        charStack.pop_back();
    }

    return postfixString; 
}

bool Chapter12Helper::hasHigherPrecedence(char value1, char value2)
{
    int value1Weight = getOperatorWeight(value1);
    int value2Weight = getOperatorWeight(value1);
     
    if (value1Weight == value2Weight)
    {
        return true; 
    }
    return value1Weight > value2Weight ? true : false; 
}

int Chapter12Helper::getOperatorWeight(char value)
{
    int weight = -1; 
    switch (value)
    {
    case '+': weight = 1; break;
    case '-': weight = 1; break;
    case '*': weight = 2; break;
    case '/': weight = 2; break;
    }
    return weight; 
}
