#include <iostream>
#include <stdexcept>
#include "rational.h"
using namespace std;
int main() {
    Rational a; // 0/1
    Rational b(3); // 3/1
    Rational c(4, 8); // 4/8 -> normalized to 1/2
    Rational d(-15, -20); // normalized to 3/4
    Rational e(18, -9); // normalized to -2/1
    Rational f(c); // copies 1/2
    cout << "a=" << a.display() << "\n"; // prints 0
    cout << "b=" << b.display() << "\n"; // prints 3
    cout << "c=" << c.display() << "\n"; // prints 1/2
    cout << "d=" << d.display() << "\n"; // prints 3/4
    cout << "e=" << e.display() << "\n"; // prints -2
    cout << "f=" << f.display() << "\n"; // prints ½
    // Demonstrate normalization and exception
    try {
    d.setDen(6);
    cout << "d=" << d.display() << "\n"; // prints 1/2
    d.set(5, -7);
    cout << "d=" << d.display() << "\n"; // prints -5/7
    //d.set(5, 0); //throws remove comment to test each case.
    //d.setDen(0); //throws
    Rational bad(1, 0); // throws

    }
    catch (const invalid_argument& e) {
    cout << "Error : " << e.what() << "\n";
    }

    //postfix & prefix test
    cout<< "Postfix and Prefix test: \n";
    Rational r1(4, -8);
    cout <<r1.display("r1=") <<"\n"; //prints r1= -1/2
    r1++;
    cout <<r1.display("r1=") <<"\n"; //prints r1= 1/2
    Rational r2=r1++;
    cout<<r1.display("r1=") <<"\t"<< r2.display("r2=") <<"\n";


    cout<<"Testing unary operator + & -: \n";
    Rational r3;
    r3 = -r2;
    r1 = +r3;
    cout << r1.display("r1=") << "\t"
        << r2.display("r2=") << "\t"
        << r3.display("r3=") << "\n";
        
    return 0;
}