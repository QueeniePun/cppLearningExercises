#ifndef FACULTY_H
#define FACULTY_H
#include "Employee.h"
#include <string>

using namespace std;

class Faculty : public Employee
{
public: 
    Faculty();
    Faculty(string officeHours, int rank);
    string getOfficeHours();
    int getRank();
    void setOfficeHours(string officeHours);
    void setRank(int rank);
    string toString();

private:
    string officeHours;
    int rank;
};

#endif