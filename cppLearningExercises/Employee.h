#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include "MyDate.h"
#include <string>
using namespace std;

class Employee : public Person, public MyDate
{
public: 
    Employee();
    Employee(string office, double salary, MyDate& dateHired);
    string getOffice();
    double getSalary();
    string getDateHired();
    string toString();
private:
    string office;
    double salary;
    MyDate dateHired;
};

#endif