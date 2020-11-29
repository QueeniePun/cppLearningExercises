#ifndef CHECKING_H
#define CHECKING_H
#include "Account.h"

class Checking : public Account
{
public: 
    Checking();
    Checking(double overdraftLimit);
    double getOverdraftLimit();
    void setOverdraftLimit(double amount);
    void withdraw(double amount);
    string toString();

private: 
    double overdraftLimit;
};

#endif