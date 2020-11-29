#ifndef SAVING_H
#define SAVING_H
#include "Account.h"
#include <string>

using namespace std;

class Saving : public Account
{
public:
    Saving();
    double getOverdraftLimit();
    void setOverdraftLimit(double overdraftLimit);
    void withdraw(double amount);
    string toString();
private:
    double overdraftLimit;
};

#endif