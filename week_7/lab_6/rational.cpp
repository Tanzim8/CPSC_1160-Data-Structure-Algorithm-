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
    cout << "Deleting Rational number: " << display() << endl;
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
    this->num = num;
    this->den = den;
    normalize();
}

void Rational:: setNum(int num){
    this->num = num;
}

void Rational:: setDen(int den){
    this->den = den;
    normalize();
}

//display function
// string Rational:: display() const{
//     if(den == 1){
//         return to_string(num);
//     }
//     return to_string(num) + "/" + to_string(den);
// }
string Rational::display(string prefix) const {
    if (den == 1) {
        return prefix + to_string(num);
    }

    return prefix + to_string(num) + "/" + to_string(den);
}

Rational Rational:: operator++(int){
    //old value
    Rational temp(*this);
    //increasing current object by 1
    num += den;
    //simplifying
    normalize();

    //returning the old value
    return temp;
}

//preffix
Rational& Rational:: operator++(){
    num += den;
    normalize();
    return *this;
}

Rational Rational:: operator+(const Rational& other)const{
    Rational result;
    result.num = num*other.den + other.num*den;
    result.den = den*other.den;
    result.normalize();
    return result;
}

//implementing binary operator to handle r2 = 4+r1
Rational operator+(int left ,const Rational& right){
    newNum = left

}

