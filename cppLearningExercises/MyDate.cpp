#include "MyDate.h"

MyDate::MyDate()
{
    year = 2020;
    month = 11;
    day = 28;
}

MyDate::MyDate(int year, int month, int day)
{
    this->year = year; 
    this->month = month;
    this->day = day;
}

int MyDate::getYear()
{
    return year;
}

int MyDate::getMonth()
{
    return month;
}

int MyDate::getDay()
{
    return day; 
}

void MyDate::setYear(int year)
{
    this->year = year; 
}

void MyDate::setMonth(int month)
{
    this->month = month;
}

void MyDate::setDay(int day)
{
    this->day = day; 
}

string MyDate::toString()
{
    string date = to_string(year) + "-" + to_string(month) + "-" + "-" + to_string(day); 
    return date;
}

