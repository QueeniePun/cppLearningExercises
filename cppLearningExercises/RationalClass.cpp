#include "RationalClass.h"
#include <sstream>

Rational::Rational()
{
    numerator = 0; 
    denominator = 1; 
    r[0] = numerator; 
    r[1] = denominator;
}

Rational::Rational(int numerator, int denominator)
{
    int factor = gcd(numerator, denominator);
    r[0] = (denominator > 0 ? 1: -1) * numerator / factor;
    r[1] = abs(denominator) / factor;
}

int Rational::getNumerator() const
{
    return r[0];
}

int Rational::getDenominator() const
{
    return r[1];
}

int Rational::gcd(int n, int d)
{
    int n1 = abs(n);
    int n2 = abs(d);
    int gcd = 1; 
    for (int k = 1; k <= n1 && k <= n2; k++)
    {
        if (n1 % k == 0 && n2 % k == 0)
        {
            gcd = k;
        }
    }
    return gcd;
}

Rational Rational::add(const Rational& secondRational) const
{
    int n = r[0] * secondRational.getDenominator() 
        + r[1] * secondRational.getNumerator();
    int d = r[1] * secondRational.getDenominator();
    return Rational(n, d);
}

Rational Rational::subtract(const Rational& secondRational) const
{
    int n = r[0] * secondRational.getDenominator() - r[1] *
        secondRational.getNumerator();
    int d = r[1] * secondRational.getDenominator();
    return Rational(n, d);
}

Rational Rational::multiply(const Rational& secondRational) const
{
    int n = r[0] * secondRational.getNumerator();
    int d = r[1] * secondRational.getDenominator();
    return Rational(n, d);
}

Rational Rational::divide(const Rational& secondRational) const
{
    int n = r[0] * secondRational.getDenominator();
    int d = r[1] * secondRational.getNumerator();
    return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const
{
    Rational temp = subtract(secondRational);
    if (temp.getNumerator() < 0)
    {
        return -1;
    }
    else if (temp.getNumerator() == 0)
    {
        return 0; 
    }
    else
    {
        return 1;
    }
}

bool Rational::equals(const Rational& secondRational) const
{
    if (compareTo(secondRational) == 0)
    {
        return true; 
    }
    else
    {
        return false;
    }
}

int Rational::intValue() const
{
    return getNumerator() / getDenominator();
}

double Rational::doubleValue() const
{
    return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString() const
{
    stringstream ss1, ss2; 
    ss1 << r[0];
    ss2 << r[1];

    if (r[1] == 1)
    {
        return ss1.str() + "";
    }
    else
    {
        return ss1.str() + "/" + ss2.str();
    }
}

Rational::Rational(int numerator)
{
    r[0] = numerator;
    r[1] = 1; 
}

Rational& Rational::operator+=(const Rational& secondRational)
{
    *this = add(secondRational);
    return *this;
}

Rational& Rational::operator-=(const Rational& secondRational)
{
    *this = subtract(secondRational);
    return *this; 
}

Rational& Rational::operator*=(const Rational& secondRational)
{
    *this = multiply(secondRational);
    return *this;
}

Rational& Rational::operator/=(const Rational& secondRational)
{
    *this = divide(secondRational);
    return *this;
}

int& Rational::operator[](int index)
{
    if (index == 0)
    {
        return r[0];
    }
    else if (index == 1)
    {
        return r[1]; 
    }
    else
    {
        throw runtime_error("subscript out of range");
    }
}

Rational& Rational::operator++()
{
    r[0] += r[1];
    return *this;
}

Rational& Rational::operator--()
{
    r[0] -= r[1];
    return *this;
}

Rational Rational::operator++(int dummy)
{
    Rational temp(numerator, denominator);
    r[0] += r[1];
    return temp;
}

Rational Rational::operator--(int dummy)
{
    Rational temp(numerator, denominator);
    r[0] -= r[1];
    return temp;
}

Rational Rational::operator+()
{
    return *this;
}

Rational Rational::operator-()
{
    return Rational(-numerator, denominator);
}

ostream& operator<<(ostream& out, const Rational& rational)
{
    if (rational.denominator == 1)
    {
        out << rational.numerator;
    }
    else
    {
        out << rational.numerator << "/" << rational.denominator;
    }
    return out; 
}

istream& operator>>(istream& in, Rational& rational)
{
    cout << "Enter numerator: ";
    in >> rational.numerator; 
    cout << "Enter denmoinator: ";
    in >> rational.denominator; 
    return in;
}

bool operator<(const Rational& r1, const Rational& r2)
{
    return (r1.compareTo(r2) < 0);
}

bool operator<=(const Rational& r1, const Rational& r2)
{
    return (r1.compareTo(r2) <= 0);
}

bool operator>(const Rational& r1, const Rational& r2)
{
    return (r1.compareTo(r2) > 0);
}

bool operator>=(const Rational& r1, const Rational& r2)
{
    return (r1.compareTo(r2) >= 0);
}

bool operator==(const Rational& r1, const Rational& r2)
{
    return (r1.compareTo(r2) == 0);
}

bool operator!=(const Rational& r1, const Rational& r2)
{
    return (r1.compareTo(r2) != 0);
}

Rational operator+(const Rational& r1, const Rational& r2)
{
    return r1.add(r2);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    return r1.subtract(r2);
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    return r1.multiply(r2);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    return r1.divide(r2);
}