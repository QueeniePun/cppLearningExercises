#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std; 

class Account
{
public:
    Account();
    int getId();
    double getBalance();
    double getAnnualInterestRate();
    void setId(int idNum);
    void setBalance(double amount);
    void setAnnualInterestRate(double rate);
    double getMonthlyInterestRate();
    virtual void withdraw(double amount) = 0;
    void deposit(double amount);

private:
    int id;
    double balance;
    double annualInterestRate;

};

#endif