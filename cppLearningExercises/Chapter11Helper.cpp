#include "Chapter11Helper.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

void Chapter11Helper::RunExercise1()
{
    // 11.1 Write a program that reads an int for array size,
    //      then reads numbers into array, computes avg,
    //      then finds out how many nums are above avg

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* list = new int[size];
    int count = 0;
    cout << "Enter the numbers of the array: ";

    while (count != size)
    {
        cin >> list[count];
        count++;
    }

    // find average
    double sum = 0.0; 
    for (int i = 0; i < size; i++)
    {
        sum += list[i];
    }
    double average = sum / size; 

    int numAboveAvg = 0; 
    for (int i = 0; i < size; i++)
    {
        if (list[i] > average)
        {
            numAboveAvg++; 
        }
    }

    cout << "Number of elements above average: " << numAboveAvg;
}

void Chapter11Helper::RunExercise2()
{
    // 11.2 Write a program that reads an int for the array size, 
    //      then reads the numbers into array, then displays distinct
    //      numbers 

    int size; 
    cout << "Enter the size of the array: ";
    cin >> size; 

    int* list = new int[size];
    int count = 0; 
    cout << "Enter the numbers of the array: ";
    while (count < size)
    {
        cin >> list[count];
        count++;
    }

    // find distinct the values
    int* tempDistinctList = new int[size];
    for (int i = 0; i < size; i++)
    {
        tempDistinctList[i] = 0; 
    }

    int distinctSize = 0;
    for (int i = 0; i < size; i++)
    {
        bool isInDistinctList = false; 
        for (int j = 0; j < size; j++)
        {
            if (list[i] == tempDistinctList[j])
            {
                isInDistinctList = true; 
            }
        }
        if (!isInDistinctList)
        {
            tempDistinctList[distinctSize] = list[i];
            distinctSize++;
        }
    }

    int* distinctList = new int[distinctSize];
    for (int i = 0; i < distinctSize; i++)
    {
        distinctList[i] = tempDistinctList[i];
    }

    delete[] tempDistinctList;

    // display distinct values
    for (int i = 0; i < distinctSize; i++)
    {
        cout << distinctList[i];
    }
}

void Chapter11Helper::RunExercise3()
{
    // 11.3 Write a function that increases the capacity of an array

    int list[5] = { 1, 2, 3, 4, 5 };
    int *newArray = doubleCapacity(list, 5);
}

int * Chapter11Helper::doubleCapacity(int* list, int size)
{
    int newSize = size * 2;
    int* newArray = new int[newSize];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = list[i];
    }
    for (int i = size; i < newSize; i++)
    {
        newArray[i] = 0; 
    }

    return newArray;

}

void Chapter11Helper::RunExercise4()
{
    // 11.4 Write two overloaded functions that return
    //      the avg of an array

    double array[7] =
    {
        1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7
    };
    cout << average(array, 7) << endl;
}

int Chapter11Helper::average(int* array, int size)
{
    int sum = 0;
    int average;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    average = sum / size;
    return average;
}

double Chapter11Helper::average(double* array, int size)
{
    double sum = 0.0;
    double average; 
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    average = sum / size; 
    return average; 
}

void Chapter11Helper::RunExercise5()
{
    // 11.5 Use pointers to write a function that finds
    //      the smallest elements in an array of integers
    int array[] = { 1, 2, 4, 5, 10, 100, 2, -22 };
    cout << smallestInteger(array, 8);
}

int Chapter11Helper::smallestInteger(int* array, int size)
{
    int min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min; 
}

void Chapter11Helper::RunExercise6()
{
    // 11.6 Write a function counts the occurrences of each digit
    //      in a string 
    
    string s1 = "SSN is 343 43 45 45 and ID is 434 34 4323"; 

    int * ret = count(s1);
    
    for (int i = 0; i < 10; i++)
    {
        cout << ret[i] << endl;
    }

    int ret2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    count2(s1, ret2, 10);
}

int* Chapter11Helper::count(const string& s)
{
    int *counts = new int[10];
    for (int i = 0; i < 10; i++)
    {
        counts[i] = 0; 
    }

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (s[i] > 47 && s[i] < 58)
            {
                int stringIndex = s[i] - 48; 
                if (stringIndex == j)
                {
                    counts[j]++;
                }
            }
        }
    }

    return counts; 
}

void Chapter11Helper::count2(const string& s, int counts[], int size)
{
    // find num occurences
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (s[i] > 47 && s[i] < 58)
            {
                int stringIndex = s[i] - 48;
                if (stringIndex == j)
                {
                    counts[j]++;
                }
            }
        }
    }

    // display results
    for (int i = 0; i < size; i++)
    {
        cout << counts[i];
    }
}

void Chapter11Helper::RunExercise7()
{
    // 11.7 Use the Account class in 9.3 to simulate an ATM machine
    //      Create 10 accounts in array with ID 0 to 9 and initial 
    //      balance 100.
    
    // Create 10 accounts in array 
    Chapter9Helper::Account *accounts = new Chapter9Helper::Account[10];

    // Initialize accounts 
    int initialBalance = 100; 
    for (int i = 0; i < 10; i++)
    {
        accounts[i].setId(i);
        accounts[i].setBalance(100);
    }

    // Start the ATM Machine
    do
    {
        // Prompt ID 
        int id;
        cout << "Enter an id: ";
        cin >> id; 

        if (isValidID(id, accounts))
        {
            int choice; 
            do
            {
                // Get user choice
                displayMainMenu();
                cin >> choice; 
                if (isTransaction(choice))
                {
                    executeTransaction(choice, accounts, id);
                }

            } while (choice != 4);
        }

    } while (true);
}


bool Chapter11Helper::isValidID(int id, Chapter9Helper::Account* account)
{
    for (int i = 0; i < 10; i++)
    {
        if (id == account[i].getId())
        {
            return true; 
        }
    }
    return false;
}

bool Chapter11Helper::isTransaction(int choice)
{
    return (choice > 0 && choice < 4);
}
void Chapter11Helper::displayMainMenu()
{
    cout << "Main Menu \n" 
         << "1: check balance \n"
         << "2: withdraw \n"
         << "3: deposit \n"
         << "4: exit \n"
         << "Enter a choice: ";

}
void Chapter11Helper::executeTransaction(int choice, Chapter9Helper::Account* account, int id)
{
    switch (choice)
    {
    case 1:
        cout << "The balance is " << account[id].getBalance() << endl;
        break;
    case 2:
        cout << "Enter an amount to withdraw: " << endl;
        int withdrawalAmount;
        cin >> withdrawalAmount;
        account[id].withdraw(withdrawalAmount);
        break;
    case 3:
        cout << "Enter an amount to deposit: " << endl;
        int depositAmount; 
        cin >> depositAmount; 
        account[id].deposit(depositAmount);
        break;
    }
}

void Chapter11Helper::RunExercise8()
{
    // 11.8 Define the Circle2D class

    Circle2D c1(2, 2, 5.5);
    Circle2D c2(2, 2, 5.5);
    Circle2D c3(4, 5, 10.5);
    cout << "C1 area and perimeter" << c1.getArea() << "\n" << c1.getPerimeter() << endl;
    cout << c1.contains(3, 3) << " should be 1" << endl;
    cout << c1.contains(c2) << " should be 1" << endl;
    cout << c1.contains(c3) << " should be 0" << endl;
}

Chapter11Helper::Circle2D::Circle2D()
{
    x = 0;
    y = 0;
    radius = 1;
}

Chapter11Helper::Circle2D::Circle2D(double x, double y, double radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

double Chapter11Helper::Circle2D::getX()
{
    return x;
}

double Chapter11Helper::Circle2D::getY()
{
    return y; 
}

double Chapter11Helper::Circle2D::getRadius()
{
    return radius;
}

double Chapter11Helper::Circle2D::getArea()
{
    const double PI = 3.14159;
    double area = (PI * pow(radius, 2));
    return area; 
}

double Chapter11Helper::Circle2D::getPerimeter()
{
    const double PI = 3.14159;
    double perimeter = (2 * PI * radius);
    return perimeter;
}

bool Chapter11Helper::Circle2D::contains(double x, double y)
{
    /* the point is inside the circle if the distance between 
       the point and the center of the circle is <= radius 
    */

    double distance = sqrt((pow(x - this->x, 2) + pow(y - this->y, 2)));
    if (distance > this->radius)
    {
        return false;
    }
    return true; 
}

bool Chapter11Helper::Circle2D::contains(Circle2D& circle)
{
    // The circle is inside the circle if the distance from the two 
    // centers and the smaller radius is <= the bigger radius

    double distance = sqrt(((this->x - circle.x) * (this->x - circle.x))
        + ((this->y - circle.y) * (this->y - circle.y)));

    if (distance + circle.radius > this->radius)
    {
        return false; 
    }
    else
    {
        return true; 
    }
}

bool Chapter11Helper::Circle2D::overlaps(Circle2D& circle)
{
    // if the sum of the distance between the centers and the smaller
    // radius is <= the sum of the two radiuses 
    double distance = sqrt(((this->x - circle.x) * (this->x - circle.x))
        + ((this->y - circle.y) * (this->y - circle.y)));
    double sumRadii = circle.radius + this->radius;

    if (distance + circle.radius <= sumRadii)
    {
        return true; 
    }
    else
    {
        return false;
    }
    
}

void Chapter11Helper::RunExercise9()
{
    // 11.9 Define the Rectangle2D class 

    Rectangle2D r1(2, 2, 5.5, 4.9);
    Rectangle2D r2(4, 5, 10.5, 3.2);
    Rectangle2D r3(3, 5, 2.3, 5.4);

    cout << "r1 area and perimeter: " << r1.getArea() << " " << r1.getPerimeter() << endl;
    cout << r1.contains(3, 3) << " should be 1" << endl;
    cout << r1.contains(r2) << " should be 0" << endl;
    cout << r1.overlaps(r3) << " should be 1" << endl;
}

Chapter11Helper::Rectangle2D::Rectangle2D()
{
    x = 0; 
    y = 0; 
    width = 1; 
    height = 1; 
}

Chapter11Helper::Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
    this->x = x; 
    this->y = y; 
    this->width = width;
    this->height = height; 
}

double Chapter11Helper::Rectangle2D::getX()
{
    return x; 
}

double Chapter11Helper::Rectangle2D::getY()
{
    return y; 
}

void Chapter11Helper::Rectangle2D::setX(double x)
{
    this->x = x;
}

void Chapter11Helper::Rectangle2D::setY(double y)
{
    this->y = y; 
}

double Chapter11Helper::Rectangle2D::getWidth()
{
    return width; 
}

double Chapter11Helper::Rectangle2D::getHeight()
{
    return height; 
}

void Chapter11Helper::Rectangle2D::setWidth(double width)
{
    this->width = width;
}

void Chapter11Helper::Rectangle2D::setHeight(double height)
{
    this->height = height;
}

double Chapter11Helper::Rectangle2D::getArea()
{
    double area = width * height; 
    return area; 
}

double Chapter11Helper::Rectangle2D::getPerimeter()
{
    double perimeter = (height * 2) + (width * 2);
    return perimeter;
}

bool Chapter11Helper::Rectangle2D::contains(double x, double y)
{
    return ((x <= this->x + (width / 2) && x >= this->x - (width / 2))
        && (y <= this->y + (height / 2) && y >= this->y - height / 2));
}

bool Chapter11Helper::Rectangle2D::contains(Rectangle2D& r)
{
    double rLowerXBound = r.x - (r.width / 2);
    double rUpperXBound = r.x + (r.width / 2);
    double rLowerYBound = r.y - (r.height / 2);
    double rUpperYBound = r.y + (r.height / 2);

    if ((rLowerXBound >= this->x - (width /2) && rUpperXBound <= this->x + (width /2))
        && (rLowerYBound >= this->y - (height / 2) && rUpperYBound <= this->y + (height / 2)))
    {
        return true; 
    }
    else
    {
        return false;
    }
}

bool Chapter11Helper::Rectangle2D::overlaps(Rectangle2D& r)
{
    // find top left coordinates of the rectangles and bottom right coords 
    double l1[1][2];
    l1[0][0] = this->x - (width / 2);
    l1[0][1] = this->y + (height / 2);
    double r1[1][2];
    r1[0][0] = this->x + (width / 2);
    r1[0][1] = this->y - (height / 2);
    double l2[1][2];
    l2[0][0] = r.x - (width / 2);
    l2[0][1] = r.y + (height / 2);
    double r2[1][2];
    r2[0][0] = r.x + (width / 2);
    r2[0][1] = r.y - (height / 2);

    // if rectangle is on the left side of other
    if (l1[0][0] >= r2[0][0] || l2[0][0] >= r1[0][0])
    {
        return false;
    }

    // if rectangle is above the other
    if (l1[0][1] <= r2[0][1] || l2[0][1] <= r1[0][1])
    {
        return false;
    }

    return true; 
}

void Chapter11Helper::RunExercise10()
{
    // 11.10 Count occurences of each letter in a string 
    string s1 = "ABcaBQ";

    int* ret = countLetters(s1);

    for (int i = 0; i < 26; i++)
    {
        cout << ret[i] << endl;
    }

    int ret2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0};
    countLetters2(s1, ret2, 26);

}

int* Chapter11Helper::countLetters(const string& s)
{

    int* counts = new int[26];
    for (int i = 0; i < 26; i++)
    {
        counts[i] = 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            // if letter is a capital 
            if (s[i] > 64 && s[i] < 91)
            {
                int stringIndex = s[i] - 65;
                if (stringIndex == j)
                {
                    counts[j]++;
                }
            }
            
            // if letter is a lowercase
            if (s[i] > 96 && s[i] < 123)
            {
                int stringIndex = s[i] - 96;
                if (stringIndex == j)
                {
                    counts[j]++;
                }
            }
        }
    }

    return counts;
}

void Chapter11Helper::countLetters2(const std::string& s, int* counts, int size)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            // if letter is a capital 
            if (s[i] > 64 && s[i] < 91)
            {
                int stringIndex = s[i] - 65;
                if (stringIndex == j)
                {
                    *(counts + j) += 1;
                }
            }

            // if letter is a lowercase
            if (s[i] > 96 && s[i] < 123)
            {
                int stringIndex = s[i] - 96;
                if (stringIndex == j)
                {
                    *(counts + j) += 1;
                }
            }
        }
    }

    // display results
    for (int i = 0; i < size; i++)
    {
        cout << counts[i];
    }
}