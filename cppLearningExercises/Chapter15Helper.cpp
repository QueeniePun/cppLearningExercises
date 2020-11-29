#include "Chapter15Helper.h"
#include "Triangle.h"
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "ThreeDPoint.h"
#include "Checking.h"
#include "Saving.h"
#include "GenericStack.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void Chapter15Helper::RunExercise1()
{
    // 15.1 Design a Triangle class that extends GeometricObject 
    //      Write a test program that creates a Triangle with sides 1, 1.5, 1, yellow, filled
    //      and then display the area, perimeter, color, and filled

    Triangle myTriangle(1, 1.5, 1);
    myTriangle.setColor("Yellow");
    myTriangle.setFilled(true);

    cout << "myTriangle" << endl;
    cout << "Area: " << myTriangle.getArea() << endl;
    cout << "Perimeter: " << myTriangle.getPerimeter() << endl;
    cout << "Color: " << myTriangle.getColor() << endl;
    cout << "Is filled: " << myTriangle.isFilled() << endl;

}

void Chapter15Helper::RunExercise2()
{
    // 15.2 Design a class named Person and its two derived classes named Student and Employee
    //      Make Faculty and Staff derived classes of Employee. 

    Person myPerson;
    Student myStudent;
    myStudent.setName("Clover");
    myStudent.setClassStatus("Freshman");
    Employee myEmployee;
    myEmployee.setName("Brrrr");
    Faculty myFaculty;
    myFaculty.setName("Kekw");
    Staff myStaff;
    myStaff.setName("Staff-imnida");

    cout << myPerson.toString() << endl;
    cout << myStudent.toString() << endl;
    cout << myEmployee.toString() << endl;
    cout << myFaculty.toString() << endl;
    cout << myStaff.toString() << endl;
}

void Chapter15Helper::RunExercise3()
{
    // 15.3 Create a class named ThreeDPoint derived from MyPoint; 

    ThreeDPoint point1(0, 0, 0);
    ThreeDPoint point2(10, 30, 25.5);

    cout << point1.getDistance(point2.getX(), point2.getY(), point2.getZ()) << endl;
}

void Chapter15Helper::RunExercise4()
{
    // 15.4 Create two derived accounts Checkings and Savings, derived from Accounts 
    Checking checking;
    Saving saving;
    
    checking.withdraw(120);
    checking.withdraw(100);
    saving.withdraw(110);
    saving.deposit(1000);
    saving.withdraw(40);
    cout << checking.toString() << endl;
    cout << saving.toString() << endl;

}

void Chapter15Helper::RunExercise5()
{
    // 15.5 Create a new stack class that extends vector. 

}