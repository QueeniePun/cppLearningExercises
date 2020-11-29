#ifndef STAFF_H
#define STAFF_H
#include "Employee.h"
#include <string>

using namespace std; 

class Staff : public Employee
{
public: 
    Staff();
    Staff(const string& title);
    string getTitle();
    void setTitle(const string& title);
    string toString();

private:
    string title;
};

#endif