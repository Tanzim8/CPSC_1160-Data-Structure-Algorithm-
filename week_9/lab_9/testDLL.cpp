#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    try {
        cout << "Testing filter() with integers:" << endl;

        DLL<int> intList;
        intList.addLast(10);
        intList.addLast(20);
        intList.addLast(30);
        intList.addLast(40);
        intList.addLast(50);

        cout << "Original integer list: " << intList << endl;

        intList.filter();

        cout << "After filter(): " << intList << endl;
        cout << "Expected if removing odd positions 1,3,5: 20 40" << endl;


        cout << "\nTesting filter() with strings:" << endl;

        DLL<string> strList;
        strList.addLast("apple");
        strList.addLast("banana");
        strList.addLast("cherry");
        strList.addLast("date");
        strList.addLast("mango");

        cout << "Original string list: " << strList << endl;

        strList.filter();

        cout << "After filter(): " << strList << endl;
        cout << "Expected if removing odd positions 1,3,5: banana date" << endl;


        cout << "\nTesting merge() with integers:" << endl;

        DLL<int> intList1;
        intList1.addLast(1);
        intList1.addLast(3);
        intList1.addLast(5);

        DLL<int> intList2;
        intList2.addLast(2);
        intList2.addLast(4);
        intList2.addLast(6);

        cout << "Integer list 1: " << intList1 << endl;
        cout << "Integer list 2: " << intList2 << endl;

        DLL<int> intMerger;
        DLL<int> mergedInts = intMerger.merge(intList1, intList2);

        cout << "Merged integer list: " << mergedInts << endl;
        cout << "Expected: 1 2 3 4 5 6" << endl;


        cout << "\nTesting merge() with strings:" << endl;

        DLL<string> strList1;
        strList1.addLast("apple");
        strList1.addLast("cherry");
        strList1.addLast("mango");

        DLL<string> strList2;
        strList2.addLast("banana");
        strList2.addLast("date");
        strList2.addLast("orange");

        cout << "String list 1: " << strList1 << endl;
        cout << "String list 2: " << strList2 << endl;

        DLL<string> strMerger;
        DLL<string> mergedStrings = strMerger.merge(strList1, strList2);

        cout << "Merged string list: " << mergedStrings << endl;
        cout << "Expected: apple banana cherry date mango orange" << endl;


        cout << "\nTesting exception handling:" << endl;

        DLL<int> emptyList;

        cout << "Trying to filter an empty list..." << endl;
        emptyList.filter();

    } catch (runtime_error& e) {
        cout << "Runtime error caught: " << e.what() << endl;
    } catch (out_of_range& e) {
        cout << "Out of range error caught: " << e.what() << endl;
    } catch (exception& e) {
        cout << "General exception caught: " << e.what() << endl;
    }

    return 0;
}