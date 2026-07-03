/*
References: 
1. took ChatGpt's help to design the testDLL.cpp file*/
#include <iostream>
#include <stdexcept>
#include "DLL.h"

using namespace std;

int main() {
    cout << " Testing Default Constructor :" << endl;
    DLL list1;
    cout << "Empty list created." << endl;
    cout << "Size: " << list1.size() << endl;

    cout << "\n Testing addFirst and addLast :" << endl;
    list1.addFirst(20);
    list1.addFirst(10);
    list1.addLast(30);
    list1.addLast(40);

    cout << "List should be: 10 20 30 40" << endl;
    cout << "toString(): " << list1.toString() << endl;
    cout << "operator<<: " << list1 << endl;
    cout << "Size: " << list1.size() << endl;

    cout << "\n  Testing Constructor DLL(n, data) :" << endl;
    DLL list2(5, 7);
    cout << "List should be: 7 7 7 7 7" << endl;
    cout << list2 << endl;
    cout << "Size: " << list2.size() << endl;

    cout << "\n Testing Constructor DLL(arr, size) :" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    DLL list3(arr, 5);
    cout << "List should be: 1 2 3 4 5" << endl;
    cout << list3 << endl;
    cout << "Size: " << list3.size() << endl;

    cout << "\n  Testing Copy Constructor :" << endl;
    DLL list4(list3);
    cout << "Copied list should be: 1 2 3 4 5" << endl;
    cout << list4 << endl;

    cout << "\nChanging original list3 by adding 99..." << endl;
    list3.addLast(99);
    cout << "Original list3: " << list3 << endl;
    cout << "Copied list4 should stay unchanged: " << list4 << endl;

    cout << "\n Testing Copy Assignment Operator :" << endl;
    DLL list5;
    list5.addLast(100);
    list5.addLast(200);

    cout << "Before assignment list5: " << list5 << endl;
    list5 = list3;
    cout << "After list5 = list3, list5 should match list3:" << endl;
    cout << "list5: " << list5 << endl;

    cout << "\n Testing operator[] :" << endl;
    try {
        DLL::Node* p = list5[2];
        cout << "Node at index 2 should contain 3." << endl;
        cout << "Actual data: " << p->data << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n Testing insertAfter :" << endl;
    try {
        DLL::Node* p = list5[2];
        list5.insertAfter(p, 88);
        cout << "After inserting 88 after index 2:" << endl;
        cout << list5 << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n Testing search :" << endl;
    int idx = -1;

    if (list5.search(88, idx)) {
        cout << "88 found at index: " << idx << endl;
    } else {
        cout << "88 not found." << endl;
    }

    idx = -1;
    if (list5.search(500, idx)) {
        cout << "500 found at index: " << idx << endl;
    } else {
        cout << "500 not found." << endl;
    }

    cout << "\n Testing removeFirst :" << endl;
    try {
        int removed = list5.removeFirst();
        cout << "Removed first value: " << removed << endl;
        cout << "List now: " << list5 << endl;
        cout << "Size: " << list5.size() << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n Testing removeLast :" << endl;
    try {
        int removed = list5.removeLast();
        cout << "Removed last value: " << removed << endl;
        cout << "List now: " << list5 << endl;
        cout << "Size: " << list5.size() << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n Testing remove(target) :" << endl;
    DLL list6;
    list6.addLast(5);
    list6.addLast(10);
    list6.addLast(5);
    list6.addLast(20);
    list6.addLast(5);
    list6.addLast(30);

    cout << "Before removing 5:" << endl;
    cout << list6 << endl;

    try {
        int count = list6.remove(5);
        cout << "Number of 5s removed: " << count << endl;
        cout << "After removing 5:" << endl;
        cout << list6 << endl;
        cout << "Size: " << list6.size() << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n Testing operator>> :" << endl;
    DLL list7;
    cout << "Enter one integer to add to list7: ";
    cin >> list7;
    cout << "list7 now contains: " << list7 << endl;

    cout << "\n Testing Exceptions :" << endl;
    DLL emptyList;

    try {
        emptyList.removeFirst();
    } catch (exception& e) {
        cout << "removeFirst on empty list caught: " << e.what() << endl;
    }

    try {
        emptyList.removeLast();
    } catch (exception& e) {
        cout << "removeLast on empty list caught: " << e.what() << endl;
    }

    try {
        DLL::Node* bad = list1[100];
        cout << bad->data << endl;
    } catch (exception& e) {
        cout << "operator[] invalid index caught: " << e.what() << endl;
    }

    cout << "\n All Tests Finished " << endl;

    return 0;
}