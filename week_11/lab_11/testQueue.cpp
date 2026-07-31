#include <iostream>
#include <iomanip>   
#include <string>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> qi;

    for (int i = 1; i <= 5; ++i) {
        qi.enqueue(i * 10);
    }

    cout << "qi: " << qi << "\n";
    cout << "front = " << qi.front() << "\n";

    qi.dequeue();

    cout << "after dequeue: " << qi << "\n";

    Queue<double> qd;

    qd.enqueue(2.5);
    qd.enqueue(3.75);

    cout << "qd: " << qd
         << " front = " << qd.front() << "\n";

    Queue<string> qs;

    qs.enqueue("hello");
    qs.enqueue(string("world"));

    cout << "qs: " << qs
         << " front = " << qs.front() << "\n";

    qs.clear();

    cout << "qs cleared, empty? "
         << boolalpha << qs.empty() << "\n";

    try {
        qs.dequeue();
    }
    catch (const exception& e) {
        cout << "caught: " << e.what() << "\n";
    }

    return 0;
}
