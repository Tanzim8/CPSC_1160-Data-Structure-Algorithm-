/*
Name: M. Rahman
ID: 100409251
CPSC-1160
References: 
1. https://www.geeksforgeeks.org/cpp/doubly-linked-list-in-cpp/
2. ChatGPT and class lectures
*/

#include "DLL.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
using namespace std;


// Time Complexity: O(1)
// Creates one node and sets data, next, prev.
template <typename T>
Node<T>::Node(T value) {
    data = value;
    next = nullptr;
    prev = nullptr;
}


// Time Complexity: O(1)
// Creates one node and connects it to before and after.
template <typename T>
Node<T>::Node(T value, Node<T>* before, Node<T>* after) {
    data = value;
    prev = before;
    next = after;
}


// Time Complexity: O(1)
// Initializes an empty DLL.
template <typename T>
DLL<T>::DLL() {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}


// Time Complexity: O(n)
// Loops n times and calls addLast(), which is O(1) each time.
template <typename T>
DLL<T>::DLL(int n, T data) {
    head = nullptr;
    tail = nullptr;
    listSize = 0;

    for (int i = 0; i < n; i++) {
        addLast(data);
    }
}


// Time Complexity: O(n)
// Loops through the array of size and adds each value to the DLL.
template <typename T>
DLL<T>::DLL(T arr[], int size) {
    head = nullptr;
    tail = nullptr;
    listSize = 0;

    for (int i = 0; i < size; i++) {
        addLast(arr[i]);
    }
}


// Time Complexity: O(n)
// Copies every node from other into the new DLL.
template <typename T>
DLL<T>::DLL(const DLL<T>& other) {
    head = nullptr;
    tail = nullptr;
    listSize = 0;

    Node<T>* current = other.head;

    while (current != nullptr) {
        addLast(current->data);
        current = current->next;
    }
}


// Time Complexity: O(1)
// Reads one value and adds it to the end of the DLL using addLast().
template <typename T>
istream& operator>>(istream& in, DLL<T>& list) {
    T value;
    in >> value;
    list.addLast(value);
    return in;
}


// Time Complexity: O(n)
// First clears the current list, then copies every node from other.
template <typename T>
DLL<T>& DLL<T>::operator=(const DLL<T>& other) {
    if (this == &other) {
        return *this;
    }

    while (head != nullptr) {
        removeFirst();
    }

    Node<T>* current = other.head;

    while (current != nullptr) {
        addLast(current->data);
        current = current->next;
    }

    return *this;
}


// Time Complexity: O(n)
// Traverses from head to the index position.
template <typename T>
Node<T>* DLL<T>::operator[](const int idx) {
    if (head == nullptr) {
        throw runtime_error("Empty List");
    }

    if (idx < 0 || idx >= listSize) {
        throw out_of_range("Invalid index");
    }

    Node<T>* current = head;

    for (int i = 0; i < idx; i++) {
        current = current->next;
    }

    return current;
}


// Time Complexity: O(n)
// Traverses the whole list and prints every node.
template <typename T>
ostream& operator<<(ostream& out, const DLL<T>& list) {
    Node<T>* current = list.head;

    if (current == nullptr) {
        throw runtime_error("empty list");
    }

    while (current != nullptr) {
        out << current->data << " ";
        current = current->next;
    }

    return out;
}


// Time Complexity: O(n)
// Traverses the whole list and builds a string from all node values.
template <typename T>
string DLL<T>::toString() const {
    stringstream ss;

    Node<T>* current = head;

    while (current != nullptr) {
        ss << current->data << " ";
        current = current->next;
    }

    return ss.str();
}


// Time Complexity: O(1)
// Adds one node at the beginning using head pointer.
template <typename T>
void DLL<T>::addFirst(T data) {
    Node<T>* toAdd = new Node<T>(data);

    if (head == nullptr) {
        head = tail = toAdd;
    } else {
        toAdd->next = head;
        head->prev = toAdd;
        head = toAdd;
    }

    listSize++;
}


// Time Complexity: O(1)
// Adds one node at the end using tail pointer.
template <typename T>
void DLL<T>::addLast(T data) {
    Node<T>* toAdd = new Node<T>(data);

    if (head == nullptr) {
        head = tail = toAdd;
    } else {
        toAdd->prev = tail;
        tail->next = toAdd;
        tail = toAdd;
    }

    listSize++;
}


// Time Complexity: O(1)
// Removes the first node using head pointer.
template <typename T>
T DLL<T>::removeFirst() {
    if (head == nullptr) {
        throw runtime_error("empty list");
    }

    Node<T>* toRemove = head;
    T value = toRemove->data;

    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }

    delete toRemove;
    listSize--;

    return value;
}


// Time Complexity: O(1)
// Removes the last node using tail pointer.
template <typename T>
T DLL<T>::removeLast() {
    if (head == nullptr) {
        throw runtime_error("empty list");
    }

    Node<T>* toRemove = tail;
    T value = tail->data;

    tail = tail->prev;

    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }

    delete toRemove;
    listSize--;

    return value;
}


// Time Complexity: O(1)
// Inserts directly after the given node pointer p.
template <typename T>
void DLL<T>::insertAfter(Node<T>* p, T data) {
    if (p == nullptr) {
        throw runtime_error("invalid pointer");
    }

    Node<T>* toInsert = new Node<T>(data);
    Node<T>* after = p->next;

    toInsert->prev = p;
    toInsert->next = after;

    p->next = toInsert;

    if (after != nullptr) {
        after->prev = toInsert;
    } else {
        tail = toInsert;
    }

    listSize++;
}


// Time Complexity: O(1)
// Returns the stored listSize variable.
template <typename T>
int DLL<T>::size() {
    return listSize;
}


// Time Complexity: O(n)
// Searches node by node from head until target is found or list ends.
template <typename T>
bool DLL<T>::search(T target, int& index) {
    if (head == nullptr) {
        throw runtime_error("empty list");
    }

    int count = 0;
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            index = count;
            return true;
        }

        current = current->next;
        count++;
    }

    return false;
}


// Time Complexity: O(n)
// Traverses the whole list once and removes all copies of target.
template <typename T>
T DLL<T>::remove(T target) {
    if (head == nullptr) {
        throw runtime_error("empty list");
    }

    int removeCount = 0;
    Node<T>* current = head;

    while (current != nullptr) {
        Node<T>* nextNode = current->next;

        if (current->data == target) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
            listSize--;
            removeCount++;
        }

        current = nextNode;
    }

    return removeCount;
}


// Time Complexity: O(n)
// Traverses the whole list and deletes every node.
template <typename T>
DLL<T>::~DLL() {
    Node<T>* current = head;

    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    listSize = 0;
}
template <typename T>
void DLL<T>::filter(){
    if(head == nullptr){
        throw runtime_error("empty list");
    }
    Node<T>* current = head;
    int count = 0;
    while(current!= nullptr){
        Node<T>* nextNode = current->next;
        if(count%2 != 0){
            if(current->prev != nullptr){
                current->prev->next = current->next;
            }else{
                head = current->next;
            }
            if(current->next != nullptr){
                current->next->prev = current ->prev;
            }else{
                tail = current->prev;
            }
            delete current;
            listSize--;
        }
        current=nextNode;;
        count++;
        }
}
template <typename T>
DLL<T> DLL<T>::merge(DLL<T>& list1, DLL<T>& list2){
    DLL<T> list3;
    Node<T>* listOneCounter = list1.head;
    Node<T>* listTwoCounter = list2.head;
    while(listOneCounter!= nullptr && listTwoCounter!=nullptr){
        if(listOneCounter->data < listTwoCounter->data){
            list3.addLast(listOneCounter->data);
            listOneCounter= listOneCounter->next;
        }else{
            list3.addLast(listTwoCounter->data);
            listTwoCounter = listTwoCounter->next;
        }
    }
    while(listOneCounter != nullptr){
        list3.addLast(listOneCounter->data);
        listOneCounter = listOneCounter->next;
    }
    while(listTwoCounter != nullptr){
        list3.addLast(listTwoCounter->data);
        listTwoCounter = listTwoCounter->next;
    }
    return list3;
}