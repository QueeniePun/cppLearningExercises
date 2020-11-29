#include "Student.h"

Student::Student()
{
    classStatus = "Senior";
}

Student::Student(const string& classStatus)
{
    this->classStatus = classStatus;
}

string Student::getClassStatus()
{
    return classStatus;
}

void Student::setClassStatus(const string& classStatus)
{
    this->classStatus = classStatus;
}

string Student::toString()
{
    return "Student: " + getName();
}