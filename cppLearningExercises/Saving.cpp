#include "Saving.h"
#include <iostream>

Saving::Saving()
{
    overdraftLimit = 100;
}

double Saving::getOverdraftLimit()
{
    return overdraftLimit;
}

void Saving::setOverdraftLimit(double overdraftLimit)
{
    this->overdraftLimit = overdraftLimit;
}

void Saving::withdraw(double amount)
{
    if (getBalance() - amount < 0)
    {
        cout << "Savings account cannot be overdrawn." << endl;
    }
    else
    {
        setBalance(getBalance() - amount);
    }
}

string Saving::toString()
{
    return "Savings balance: " + to_string(getBalance());
}