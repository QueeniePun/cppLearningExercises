#include "Account.h"

Account::Account()
{
    id = 0;
    balance = 0;
    annualInterestRate = 0;
}

int Account::getId()
{
    return id;
}

double Account::getBalance()
{
    return balance;
}

double Account::getAnnualInterestRate()
{
    return annualInterestRate;
}

void Account::setId(int idNum)
{
    id = idNum;
}

void Account::setBalance(double amount)
{
    balance = amount;
}

void Account::setAnnualInterestRate(double rate)
{
    annualInterestRate = rate;
}

double Account::getMonthlyInterestRate()
{
    return annualInterestRate / 12.0;
}

void Account::withdraw(double amount)
{
    balance -= amount;
}

void Account::deposit(double amount)
{
    balance += amount;
}

