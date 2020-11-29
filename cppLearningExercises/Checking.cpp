#include "Checking.h"
#include <iostream>

Checking::Checking()
{
    overdraftLimit = 100.00;
}

Checking::Checking(double overdraftLimit)
{
    this->overdraftLimit = overdraftLimit;
}

double Checking::getOverdraftLimit()
{
    return overdraftLimit;
}

void Checking::setOverdraftLimit(double amount)
{
    this->overdraftLimit = amount;
}

void Checking::withdraw(double amount)
{
    if (getBalance() - amount < -overdraftLimit)
    {
        cout << "Cannot withdraw past the overdraftLimit" << endl;
    }
    else
    {
        setBalance(getBalance() - amount);
    }
}

string Checking::toString()
{
    return "Checking balance: " + to_string(getBalance());
}