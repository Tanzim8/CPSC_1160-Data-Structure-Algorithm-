#include "rational.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
using namespace std;

//helper gcd function
int Rational:: gcd(int a, int b) const{
    a = abs(a);
    b = abs(b);

    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }

    return a;
}

//helper normalize function

void Rational::normalize(){
    if(den == 0){
        throw invalid_argument("Denominator cannot be zero");
    }
    //keep nehative sign in numerator
    if(den<0){
        num = -num;
        den = - den;
    }

    int divisor = gcd(num, den);

    if(divisor != 0){
        num = num/divisor;
        den = den/divisor;
    }
}

//default constructor
Rational::Rational(): num(0), den(1){}

//one peremeter constructor
Rational::Rational(int num): num(num), den(1){}

//two parameter constructor
Rational::Rational(int num, int den): num(num), den(den){
    normalize();
}

//copy constructor
Rational::Rational(const Rational& other): num(other.num), den(other.den){}

//destructor
Rational::~Rational(){
    cout << "Deleting Rational number: " << num << "/" << display() << endl;
}

//getters

int Rational:: getNum() const{
    return num;
}

int Rational:: getDen() const{
    return den;
}

//setters
void Rational:: set(int num, int den){
    num = num;
    den = den;
    normalize();
}

void Rational:: setNum(int num){
    num = num;
    normalize();
}

void Rational:: setDen(int den){
    den = den;
    normalize();
}

//display function
string Rational:: display() const{
    if(den == 1){
        return to_string(num);
    }
    return to_string(num) + "/" + to_string(den);
}
