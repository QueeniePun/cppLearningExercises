#include "ComplexClass.h"
#include <sstream>

Complex::Complex()
{
    a = 0; 
    b = 0; 
    c[0] = a;
    c[1] = b;
}

Complex::Complex(double a)
{
    this->a = a; 
    this->b = 0; 
    c[0] = a; 
    c[1] = b;
}

Complex::Complex(double a, double b)
{
    this->a = a; 
    this->b = b; 
    c[0] = a;
    c[1] = b;
}

double Complex::getA() const
{
    return c[0]; 
}

double Complex::getB() const
{
    return c[1]; 
}

Complex Complex::add(const Complex& secondComplex) const
{
    double sumA = c[0] + secondComplex.getA();
    double sumB = c[1] + secondComplex.getB();
    return Complex(sumA, sumB);
}

Complex Complex::subtract(const Complex& secondComplex) const
{
    double sumA = c[0] - secondComplex.getA();
    double sumB = c[1] - secondComplex.getB();
    return Complex(sumA, sumB);
}

Complex Complex::multiply(const Complex& secondComplex) const
{
    double sumA = c[0] * secondComplex.getA() - c[1] * secondComplex.getB();
    double sumB = c[1] * secondComplex.getA() + c[0] * secondComplex.getA();
    return Complex(sumA, sumB);
}

Complex Complex::divide(const Complex& secondComplex) const
{
    double sumA = (c[0] * secondComplex.getA() + c[1] * secondComplex.getB()) /
        (secondComplex.getA() * secondComplex.getA()
            + secondComplex.getB() * secondComplex.getB());
    double sumB = (c[1] * secondComplex.getA() - c[0] * secondComplex.getB()) /
        (secondComplex.getA() * secondComplex.getA()
            + secondComplex.getB() * secondComplex.getB());
    return Complex(sumA, sumB);
}

string Complex::toString() const
{
    stringstream ss1, ss2;
    ss1 << c[0];
    ss2 << c[1];

    if (c[1] == 0)
    {
        return ss1.str() + "";
    }
    else
    {
        return ss1.str() + " + " + ss2.str() + "i";
    }
}

int Complex::compareTo(const Complex& secondComplex) const
{
    Complex temp = subtract(secondComplex);
    if (temp.getA() < 0)
    {
        return -1; 
    }
    else if (temp.getA() == 0 && temp.getB() == 0)
    {
        return 0; 
    }
    else
    {
        return 1; 
    }
}

bool Complex::equals(const Complex& secondComplex) const
{
    return (c[0] == secondComplex.getA() && c[1] == secondComplex.getB());
}

Complex& Complex::operator+=(const Complex& secondComplex)
{
    *this = add(secondComplex);
    return *this; 
}

Complex& Complex::operator-=(const Complex& secondComplex)
{
    *this = subtract(secondComplex);
    return *this; 
}

Complex& Complex::operator*=(const Complex& secondComplex)
{
    *this = multiply(secondComplex);
    return *this; 
}

Complex& Complex::operator/=(const Complex& secondComplex)
{
    *this = divide(secondComplex);
    return *this; 
}

int& Complex::operator[](int index)
{
    if (index == 0)
    {
        return c[0];
    }
    else if (index == 1)
    {
        return c[1];
    }
    else
    {
        throw runtime_error("subscript out of range");
    }
}

Complex& Complex::operator++()
{
    c[0] += c[0];
    c[1] += c[1];
    return *this; 
}

Complex& Complex::operator--()
{
    c[0] -= c[0];
    c[1] -= c[1];
    return *this; 
}

Complex Complex::operator++(int dummy)
{
    Complex temp(a, b);
    c[0] += c[0];
    c[1] += c[1];
    return temp;
}

Complex Complex::operator--(int dummy)
{
    Complex temp(a, b);
    c[0] -= c[0];
    c[1] -= c[1];
    return temp;
}

Complex Complex::operator+()
{
    return *this;
}

Complex Complex::operator-()
{
    return Complex(-a, -b);
}

ostream& operator<<(ostream& out, const Complex& complex)
{
    if (complex.b == 0)
    {
        out << complex.c[0];
    }
    else
    {
        out << complex.c[0] << " + " << complex.c[1] << "i";
    }
    return out;
}

istream& operator>>(istream& in, const Complex& complex)
{
    cout << "Enter a: ";
    in >> complex.c[0];
    cout << "Enter b: ";
    in >> complex.c[1];
    return in; 
}

bool operator<(const Complex& c1, const Complex& c2)
{
    return (c1.compareTo(c2) < 0);
}

bool operator<=(const Complex& c1, const Complex& c2)
{
    return (c1.compareTo(c2) <= 0);
}

bool operator>(const Complex& c1, const Complex& c2)
{
    return (c1.compareTo(c2) > 0);
}

bool operator>=(const Complex& c1, const Complex& c2)
{
    return (c1.compareTo(c2) >= 0);
}

bool operator==(const Complex& c1, const Complex& c2)
{
    return c1.equals(c2);
}
bool operator!=(const Complex& c1, const Complex& c2)
{
    return !(c1.equals(c2));
}

Complex operator+(const Complex& c1, const Complex& c2)
{
    return c1.add(c2);
}
Complex operator-(const Complex& c1, const Complex& c2)
{
    return c1.subtract(c2);
}
Complex operator*(const Complex& c1, const Complex& c2)
{
    return c1.multiply(c2);
}
Complex operator/(const Complex& c1, const Complex& c2)
{
    return c1.divide(c2);
}