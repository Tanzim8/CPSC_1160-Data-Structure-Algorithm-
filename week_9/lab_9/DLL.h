#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Node class outside DLL
template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T value);
    Node(T value, Node<T>* before, Node<T>* after);
};

// DLL class
template <typename T>
class DLL {
private:
    Node<T>* head;
    Node<T>* tail;
    int listSize;

public:
    // default constructor
    DLL();

    // constructor with n copies of data
    DLL(int n, T data);

    // array constructor
    DLL(T arr[], int size);

    // copy constructor
    DLL(const DLL<T>& other);

    // copy assignment
    DLL<T>& operator=(const DLL<T>& other);

    // offset operator
    Node<T>* operator[](const int idx);

    // toString method
    string toString() const;

    // adds at the beginning of the list
    void addFirst(T data);

    // adds at the last of the list
    void addLast(T data);

    // removes the first element of the list
    T removeFirst();

    // removes the last element of the list
    T removeLast();

    // inserts data after p
    void insertAfter(Node<T>* p, T data);

    // returns the number of elements in the list
    int size();

    bool search(T target, int& idx);

    T remove(T target);

    // destructor
    ~DLL();

    // friend operators
    template <typename U>
    friend istream& operator>>(istream& in, DLL<U>& list);

    template <typename U>
    friend ostream& operator<<(ostream& out, const DLL<U>& list);

    //removes all nodes in odd positions
    void filter();

    //merge function
    DLL<T> merge(DLL<T>& list1, DLL<T>& list2);
};
#include "DLL.cpp"

#endif