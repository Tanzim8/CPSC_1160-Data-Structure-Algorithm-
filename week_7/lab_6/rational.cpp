/*
M. Rahman
ID-100409251
Lab-6, CPSC-1160
References: 
1. https://www.geeksforgeeks.org/cpp/increment-and-decrement-operator-overloading-in-c/
2. https://www.geeksforgeeks.org/cpp/types-of-operator-overloading-in-cpp/
3. https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm
4. https://www.geeksforgeeks.org/cpp/overloading-stream-insertion-operators-c/
5. chatGPT, for understanding the tasks better
*/
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
    Rational leftRational(left);
    return leftRational + right;
}

Rational Rational::operator=(const Rational& rvalue){
    if(this != &rvalue){
        num = rvalue.num;
        den = rvalue.den;
    }
    return *this;
}
/*
The assignment operator copies one Rational object into another.

For example, if I write r2 = r1, then r2 gets the same numerator and denominator as r1.

For r3 = r2 = r2 - r1, C++ works from right to left. First, it calculates r2 - r1. Then it stores that answer in r2. Then it stores the same answer in r3. So both r2 and r3 get the result.

But for (r3 = r2) = r2 - r1, there is a problem if operator= returns Rational. Returning Rational means it returns a copy, not the real object. So the second assignment changes the copy, not the real r3.

To fix this, operator= should return Rational& instead of Rational. Rational& means it returns the real object itself. Then (r3 = r2) still refers to the real r3, so the next assignment can change r3 correctly.

So the better assignment operator should return Rational&.
*/

//unary overloading
Rational Rational:: operator+() const{
    return *this;
}


Rational Rational:: operator-() const{
    Rational result(-num, den);
    return result;
}

istream& operator>>(istream& in, Rational& r){
    int numerator, denominator;
    cout << "Enter numerator: ";
    in >> numerator;
    cout << "Enter denominator: ";
    in >> denominator;
    r.set(numerator, denominator);
    return in;
}

ostream& operator<<(ostream& out, const Rational& r){
    out << r.display();
    return out;
}

int Rational:: operator[](int index) const{
    if(index == 0){
        return num;
    }
    else if(index ==1){
        return den;
    }
    else{
        throw out_of_range("Index must be 0 or 1");
    }
}
