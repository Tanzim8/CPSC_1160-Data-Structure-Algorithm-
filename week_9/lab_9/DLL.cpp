/*
Name: M. Rahman
ID: 100409251
CPSC-1160
References: 
1. https://www.geeksforgeeks.org/cpp/doubly-linked-list-in-cpp/
2. chatGpt and class lectures*/
#include "DLL.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Time Complexity: O(1)
// Creates one node and sets data, next, prev.
template <typename T>
DLL<T>::Node::Node(T value){
    data = value;
    next = nullptr;
    prev = nullptr;
}

// Time Complexity: O(1)
// Creates one node and connects it to before and after.
template <typename T>
DLL<T>::Node::Node(T value, Node<T>* before, Node<T>* after){
    data = value;
    next = after;
    prev = before;
}

// Time Complexity: O(1)
// Initializes an empty DLL.
template <typename T>
DLL<T>::DLL(){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

// Time Complexity: O(n)
// Loops n times and calls addLast(), which is O(1) each time.
template <typename T>
DLL<T>::DLL(int n, int data){
    head = nullptr;
    tail = nullptr;
    listSize = 0;

    for(int i =0; i<n; i++){
        addLast(data);
    }
}


// Time Complexity: O(n)
// Loops through the array of size n and adds each value to the DLL.
template <typename T>
DLL<T>::DLL(T arr[], int size){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    for(int i = 0; i<size; i++){
        addLast(arr[i]);
    }
}

// Time Complexity: O(n)
// Copies every node from other into the new DLL.
template <typename T>
DLL<T>::DLL(const DLL & other){
    head = nullptr;
    tail = nullptr;
    listSize =0;

    Node<T>* current = other.head;

    while(current != nullptr){
        addLast(current->data);
        current=current->next;
    }
}

// Time Complexity: O(1)
// Reads one integer and adds it to the end of the DLL using addLast().
template <typename T>
istream & operator>>(istream & in, DLL<T>& list){
    T value;
    in>>value;
    list.addLast(value);
    return in;
};


// Time Complexity: O(n)
// First clears the current list, then copies every node from other.
template <typename T>
DLL<T>& DLL<T>:: operator=(const DLL<T>& other){
    if(this == & other){
        return *this;
    }
    while(head != nullptr){
        removeFirst();
    }
    Node<T>* current = other.head;
    while(current != nullptr){
        addLast(current->data);
        current = current->next;
    }
    return *this;
}


// Time Complexity: O(n)
// Traverses from head to the index position.
// Best case: O(1) if idx is 0.
// Worst case: O(n) if idx is near the end.
template <typename T>
DLL<T>:: Node<T>* DLL<T>::operator[](const int idx){
    if(head == nullptr){
        throw runtime_error("Empty List");
    }
    if (idx < 0 || idx >= listSize) {
        throw out_of_range("Invalid index");
    }
    int count =0;
    Node<T>* current = head;
    while(count != idx){
        current = current->next;
        count++;
    }
    return current;
};


// Time Complexity: O(n)
// Traverses the whole list and prints every node.
ostream & operator<<(ostream & out, const DLL& list){
    DLL::Node* current = list.head;
    if(current == nullptr){
        throw runtime_error("empty list");
    }
    while(current != nullptr){
        out<<current->data<<" ";
        current = current->next;
    }
    return out;
}


// Time Complexity: O(n)
// Traverses the whole list and builds a string from all node values.
string DLL:: toString() const{
    string listStrn = "";

    DLL::Node* current = head;
    while(current != nullptr){
        listStrn.append(to_string(current->data));
        listStrn.append(" ");
        current = current->next;
    }
    return listStrn;
}


// Time Complexity: O(1)
// Adds one node at the beginning using head pointer.
void DLL::addFirst(int data){
    Node* toAdd = new Node(data);
    if(head == nullptr){
        head = tail = toAdd;
    }else{
        toAdd->next = head;
        head->prev = toAdd;
        head = toAdd;
    }
    listSize++;
}


// Time Complexity: O(1)
// Adds one node at the end using tail pointer.
void DLL:: addLast(int data){
    Node* toAdd = new Node(data);
    if(head == nullptr){
        head = tail = toAdd;
    }else{
        toAdd->prev = tail;
        tail ->next = toAdd;
        tail = toAdd;
    }
    listSize++;
}


// Time Complexity: O(1)
// Removes the first node using head pointer.
int DLL:: removeFirst(){
    Node* toRemove = head;
    if(toRemove == nullptr){
        throw runtime_error("empty list");
    }
    int value = toRemove->data;
    head = head->next;
    if(head == nullptr){
        tail = nullptr;
    }else{
        head->prev = nullptr;
    }
    delete toRemove;
    listSize--;
    return value;
}


// Time Complexity: O(1)
// Removes the last node using tail pointer.
int DLL:: removeLast(){
    Node* toRemove = tail;
    if(head == nullptr){
        throw runtime_error("empty list");
    }
    int value = tail->data;

    tail = tail->prev;

    if(tail == nullptr){
        head = nullptr;
    }else{
        tail->next = nullptr;
    }
    delete toRemove;
    listSize--;
    return value;
}


// Time Complexity: O(1)
// Inserts directly after the given node pointer p.
// No traversal is needed because p is already given.
void DLL:: insertAfter(Node* p, int data){
    Node* toInsert = new Node(data);

    if(p == nullptr){
        throw runtime_error("empty list");
    }
    Node* after = p->next;

    toInsert->prev = p;
    toInsert->next = after;

    p->next=toInsert;

    if(after != nullptr){
        after->prev = toInsert;
    }else{
        tail = toInsert;
    }
    listSize++;
}

//helper function to get the size. 
// Time Complexity: O(1)
// Returns the stored listSize variable.
int DLL:: size(){
    return listSize;
}

// Time Complexity: O(n)
// Searches node by node from head until target is found or list ends.
// Best case: O(1) if target is at head.
// Worst case: O(n) if target is at the end or not found.
bool DLL:: search(int target, int& index){
    int count = 0;
    if(head == nullptr){
        throw runtime_error("empty list");
    }
    Node* current = head;
    while(current != nullptr){
        if(current->data == target){
            index = count;
            return true;
        }
        current = current-> next;
        count++;
    }
    return false;
}


// Time Complexity: O(n)
// Traverses the whole list once and removes all copies of target.
int DLL::remove(int target){
    int removeCount=0;
    if(head == nullptr){
        throw runtime_error("empty list");
    }
    Node* current = head;
    while(current != nullptr){
        Node* nextNode = current->next;
        if(current->data==target){
            if(current->prev != nullptr){
                current->prev->next = current->next;
            }else{
                head = current ->next;
            }
            if(current->next != nullptr){
                current ->next->prev = current->prev;
            }else{
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
DLL::~DLL() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    listSize = 0;
}
