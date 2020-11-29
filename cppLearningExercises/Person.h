#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(const string &name, const string &address, const string &phoneNumber, const string &email);
    string getName() const;
    string getAddress() const;
    string getPhoneNumber() const;
    string getEmail() const;
    void setName(const string& name);
    void setAddress(const string& address);
    void setPhoneNumber(const string& phoneNumber);
    void setEmail(const string& email);
    string toString() const;

private:
    string name;
    string address;
    string phoneNumber;
    string email;
};

#endif