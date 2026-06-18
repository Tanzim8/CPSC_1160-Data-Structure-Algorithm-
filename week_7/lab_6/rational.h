#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
using namespace std;
class Rational{
private: 
    int num;
    int den;

    int gcd(int a, int b) const;
    void normalize();
public: 
    //constructors
    Rational();
    Rational(int num);
    Rational(int num, int den);

    //copy constructor
    Rational(const Rational& other);

    //destructor
    ~Rational();

    //accesors
    int getNum() const;
    int getDen() const;

    //mutators
    void set(int num, int den);
    void setNum(int num);
    void setDen(int den);

    //Display
    string display(string prefix = "") const;

    //postfix
    Rational operator++(int);

    //prefix
    Rational& operator++();

    //overoading binary operator to handle r2 = r1 + r2
    Rational operator+(const Rational& other) const;

    //overloading unary operator to handle r2 = 4+r1
    friend Rational operator+(int left ,const Rational& right);

    //assignment operator
    Rational operator=(const Rational& rvalue);

    //unary overloading
    Rational operator+() const;

    Rational operator-() const;

    //>>
    friend istream& operator>>(istream& in, Rational& r);

    //<<
    friend ostream& operator<<(ostream& out, const Rational& r);

    int operator[](int index) const;
};
#endif