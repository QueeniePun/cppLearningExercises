#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;

class MyDate
{
public:
    MyDate();
    MyDate(int year, int month, int day);
    int getYear();
    int getMonth();
    int getDay();
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    string toString();

private:
    int year; 
    int month; 
    int day;
};

#endif