#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>
using namespace std;

class Student : public Person
{
public: 
    Student();
    Student(const string& classStatus);
    string getClassStatus();
    void setClassStatus(const string& classStatus);
    string toString();

private:
    string classStatus; 
};

#endif
