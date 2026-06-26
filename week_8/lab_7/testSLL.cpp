/*
name: M. Rahman
ID-100409251
CPSC-1160
Lab-7
Testing file: testSLL.cpp
Reference: 
1. I took ChatGpt's help to design the testSLL.cpp
*/

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "SLL.h"

using namespace std;

int main() {

    cout << "===== Testing Default Constructor =====" << endl;
    SLL list1;
    cout << "list1: " << list1.toString() << endl;
    cout << "Size: " << list1.size() << endl;
    cout << endl;


    cout << "===== Testing addFirst() =====" << endl;
    list1.addFirst(30);
    list1.addFirst(20);
    list1.addFirst(10);
    cout << "After addFirst 30, 20, 10: " << list1.toString() << endl;
    cout << "Size: " << list1.size() << endl;
    cout << endl;


    cout << "===== Testing addLast() =====" << endl;
    list1.addLast(40);
    list1.addLast(50);
    cout << "After addLast 40, 50: " << list1.toString() << endl;
    cout << "Size: " << list1.getSize() << endl;
    cout << endl;


    cout << "===== Testing Constructor with n and default value =====" << endl;
    SLL list2(5, 7);
    cout << "list2 should have five 7s: " << list2.toString() << endl;
    cout << "Size: " << list2.size() << endl;
    cout << endl;


    cout << "===== Testing Array Constructor =====" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    SLL list3(arr, 5);
    cout << "list3 from array: " << list3.toString() << endl;
    cout << "Size: " << list3.size() << endl;
    cout << endl;


    cout << "===== Testing Copy Constructor =====" << endl;
    SLL list4(list3);
    cout << "Original list3: " << list3.toString() << endl;
    cout << "Copied list4:   " << list4.toString() << endl;

    list4[0] = 99;
    cout << "After changing list4[0] to 99:" << endl;
    cout << "list3 should stay same: " << list3.toString() << endl;
    cout << "list4 changed:          " << list4.toString() << endl;
    cout << endl;


    cout << "===== Testing Copy Assignment Operator =====" << endl;
    SLL list5;
    list5.addLast(100);
    list5.addLast(200);

    cout << "Before assignment:" << endl;
    cout << "list5: " << list5.toString() << endl;
    cout << "list1: " << list1.toString() << endl;

    list5 = list1;

    cout << "After list5 = list1:" << endl;
    cout << "list5: " << list5.toString() << endl;
    cout << "list1: " << list1.toString() << endl;

    list5[0] = 999;
    cout << "After changing list5[0] to 999:" << endl;
    cout << "list5 changed: " << list5.toString() << endl;
    cout << "list1 same:    " << list1.toString() << endl;
    cout << endl;


    cout << "===== Testing Self Assignment =====" << endl;
    list1 = list1;
    cout << "After list1 = list1: " << list1.toString() << endl;
    cout << endl;


    cout << "===== Testing operator[] =====" << endl;
    cout << "list1[0]: " << list1[0] << endl;
    cout << "list1[2]: " << list1[2] << endl;
    list1[2] = 300;
    cout << "After list1[2] = 300: " << list1.toString() << endl;
    cout << endl;


    cout << "===== Testing search() =====" << endl;
    int index;

    if (list1.search(300, index)) {
        cout << "Found 300 at index: " << index << endl;
    } else {
        cout << "300 not found." << endl;
    }

    if (list1.search(9999, index)) {
        cout << "Found 9999 at index: " << index << endl;
    } else {
        cout << "9999 not found." << endl;
    }
    cout << endl;


    cout << "===== Testing removeFirst() =====" << endl;
    int removedFirst = list1.removeFirst();
    cout << "Removed first value: " << removedFirst << endl;
    cout << "After removeFirst: " << list1.toString() << endl;
    cout << "Size: " << list1.size() << endl;
    cout << endl;


    cout << "===== Testing removeLast() =====" << endl;
    int removedLast = list1.removeLast();
    cout << "Removed last value: " << removedLast << endl;
    cout << "After removeLast: " << list1.toString() << endl;
    cout << "Size: " << list1.size() << endl;
    cout << endl;


    cout << "===== Testing remove(target) =====" << endl;
    cout << "Before remove(300): " << list1.toString() << endl;
    list1.remove(300);
    cout << "After remove(300):  " << list1.toString() << endl;
    cout << "Size: " << list1.size() << endl;
    cout << endl;


    cout << "===== Testing Extraction Operator >> using stringstream =====" << endl;
    SLL list6;
    stringstream input("4 11 22 33 44");
    input >> list6;

    cout << "list6 after input: " << list6.toString() << endl;
    cout << "Size: " << list6.size() << endl;
    cout << endl;


    cout << "===== Testing Exceptions =====" << endl;

    try {
        SLL badList(-3, 10);
    } catch (exception& e) {
        cout << "Caught exception for negative constructor size: " << e.what() << endl;
    }

    try {
        cout << list6[100] << endl;
    } catch (exception& e) {
        cout << "Caught exception for invalid index: " << e.what() << endl;
    }

    try {
        list6.remove(999);
    } catch (exception& e) {
        cout << "Caught exception for target not found: " << e.what() << endl;
    }

    try {
        SLL emptyList;
        emptyList.removeFirst();
    } catch (exception& e) {
        cout << "Caught exception for removeFirst on empty list: " << e.what() << endl;
    }

    try {
        SLL emptyList;
        emptyList.removeLast();
    } catch (exception& e) {
        cout << "Caught exception for removeLast on empty list: " << e.what() << endl;
    }

    try {
        stringstream badInput("-2");
        SLL list7;
        badInput >> list7;
    } catch (exception& e) {
        cout << "Caught exception for negative input size: " << e.what() << endl;
    }

    cout << endl;
    cout << "===== All Tests Completed =====" << endl;

    return 0;
}