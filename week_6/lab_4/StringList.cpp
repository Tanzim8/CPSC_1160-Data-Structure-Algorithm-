#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct StringList {
private:
    string* items;   // dynamic array of strings
    int size;        // current number of elements
    int capacity;    // maximum capacity

    // Time Complexity: O(n)
    // Because it copies all existing strings into a new bigger array
    void resize() {    // increase capacity by 2
        //TODO   
        int newCapacity = capacity+2;
        string* newItems = new string[newCapacity];

        for(int i =0; i<size; i++){
            newItems[i] = items[i];
        }

        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }

public:
    // Constructor with initial capacity of 3
    // Time Complexity: O(1)
    //Because it only creates an array of fixed size 3
    StringList() {
        //TODO
        capacity = 3;
        size = 0;
        items = new string[capacity];
    }

    // Destructor
    // Time Complexity: O(1)
    //Because delete[] items is counted as constant time for this level.
    ~StringList() {
        //TODO
        delete[] items;
    }
    // adds str at the end of array of strings 
    // Time Complexity: O(n)
    // Because in the worst case, resize() may be called
    void add(const string& str) {
        //TODO
        if(size == capacity){
            resize();
        }
        items[size] = str;
        size++;
    }
    //returns the string in the given index, 
    //it throws exception if index is invalid
    // Time Complexity: O(1)
    //Because accessing items[index] directly takes constant time.
    string get(int index) {
        //TODO
        if(index < 0 || index >= size){
            throw out_of_range("Invalid index");
        }
        return items[index];
    }
    // prints the StringList
    // Time Complexity: O(n)
    void print() {
        //TODO
        for(int i =0; i<size; i++){
            cout << items[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    try {
        StringList list;
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");
        list.add("Date");  // triggers resize
        list.print();

        cout << "Item at index 2: " << list.get(2) << endl;

        // Uncomment to test exception
        cout << list.get(10) << endl;  // throws out_of_range
    }
    catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
