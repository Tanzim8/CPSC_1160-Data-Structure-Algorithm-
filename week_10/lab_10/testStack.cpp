#include <iostream>
#include <iomanip>   // needed for boolalpha manipulator
#include <string>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> si;


    for (int i = 1; i <= 5; ++i)
        si.push(i * 10);

    cout << "si: " << si << "\n";
    cout << "top=" << si.top() << "\n";

    si.pop();
    cout << "after pop: " << si << "\n";

    Stack<double> sd;
    sd.push(2.5);
    sd.push(3.75);

    cout << "sd: " << sd << " top=" << sd.top() << "\n";

    Stack<string> ss;
    ss.push("hello");
    ss.push(string("world"));

    cout << "ss: " << ss << " top=" << ss.top() << "\n";

    ss.clear();
    cout << "ss cleared, empty? "
         << boolalpha << ss.empty() << "\n";

    try {
        ss.pop();
    } catch (const std::exception& e) {
        cout << "caught: " << e.what() << "\n";
    }

    return 0;
}