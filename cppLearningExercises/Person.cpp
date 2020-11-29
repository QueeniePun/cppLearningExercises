#include "Person.h"

Person::Person()
{
    name = "Queenie";
    address = "The Rose City";
    phoneNumber = "(*88) 123-4567";
    email = "queeniep@bu.edu";
}

Person::Person(const string& name, const string& address, const string& phoneNumber, const string& email)
{
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

string Person::getName() const
{
    return name;
}

string Person::getAddress() const
{
    return address;
}

string Person::getPhoneNumber() const
{
    return phoneNumber;
}

string Person::getEmail() const
{
    return email;
}

void Person::setName(const string& name)
{
    this->name = name;
}

void Person::setAddress(const string& address)
{
    this->address = address;
}

void Person::setPhoneNumber(const string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Person::setEmail(const string& email)
{
    this->email = email;
}

string Person::toString() const
{
    return "Person: " + name;
}

