#include "Employee.h"

Employee::Employee()
{
    office = "Home";
    salary = 200000.00;
    dateHired.setYear(1996);
    dateHired.setMonth(05);
    dateHired.setDay(28);
}

Employee::Employee(string office, double salary, MyDate &dateHired)
{
    this->office = office; 
    this->salary = salary; 
    this->dateHired = dateHired; 
}

string Employee::getOffice()
{
    return office; 
}

double Employee::getSalary()
{
    return salary;
}

string Employee::getDateHired()
{
    return dateHired.toString();
}

string Employee::toString()
{
    return "Employee: " + getName();
}