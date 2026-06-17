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
    string display() const;

    //postfix
    Rational Rational:: operator++(int);

    //prefix
    Rational& Rational:: operator++();
};
#endif