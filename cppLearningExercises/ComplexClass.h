#ifndef COMPLEXCLASS_H
#define COMPLEXCLASS_H
#include <string> 
#include <iostream>

using namespace std;

class Complex
{
public:
    Complex();
    Complex(double a);
    Complex(double a, double b);
    double getA() const;
    double getB() const;
    Complex add(const Complex& secondComplex) const;
    Complex subtract(const Complex& secondComplex) const;
    Complex multiply(const Complex& secondComplex) const;
    Complex divide(const Complex& secondComplex) const;
    string toString() const;
    int compareTo(const Complex& secondComplex) const;
    bool equals(const Complex& secondComplex) const; 

    Complex& operator+=(const Complex & secondComplex);
    Complex& operator-=(const Complex & secondComplex);
    Complex& operator*=(const Complex & secondComplex);
    Complex& operator/=(const Complex & secondComplex);

    int& operator[](int index);

    Complex& operator++();
    Complex& operator--();

    Complex operator++(int dummy);
    Complex operator--(int dummy);

    Complex operator+();
    Complex operator-();

    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, const Complex&);

private:
    int c[2];
    double a; 
    double b; 
};

bool operator<(const Complex& c1, const Complex& c2);
bool operator<=(const Complex& c1, const Complex& c2);
bool operator>(const Complex& c1, const Complex& c2);
bool operator>=(const Complex& c1, const Complex& c2);
bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);

#endif