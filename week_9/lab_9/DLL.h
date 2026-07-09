#ifndef DLL_H
#define DLL_H
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
template <typename T>
class DLL{
public:
template <typename T>
    class Node{
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;
    public:
        Node(T value);
        Node(T value, Node<T>* before, Node<T>* after);
        friend class DLL;
    };
private: 
    Node<T>* head;
    Node<T>* tail;
    int listSize;
public:
    // default constructor
    DLL();

    DLL(int n, T data);

    DLL(T arr[], int size);

    //copy constructor
    DLL(const DLL<T> & other);

    friend istream & operator>>(istream & in, DLL<T>& list);
    //copy assignment
    DLL<T>& operator=(const DLL<T>& other);
    //offset operator
    Node<T>* operator[](const int idx);
    friend ostream & operator<<(ostream & out, const DLL<T>& list);
    //toString method
    string toString() const;
    //adds at the begining of the list
    void addFirst(T data);
    //adds at the last of the list
    void addLast(T data);
    //removes the first element of the list
    T removeFirst();
    //removes the last element of the list
    T removeLast();
    //inserts data after p
    void insertAfter(Node<T>* p, T data);
    //returns the number of elements in the list
    int size();

    bool search(T target, int &idx);
    int remove(T target);

    //destructor
    ~DLL();
};
#endif