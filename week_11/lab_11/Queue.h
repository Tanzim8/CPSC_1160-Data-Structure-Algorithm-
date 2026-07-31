/*
Name: M. Rahman
ID: 100409251
Course: CPSC1160 (Lab_11)*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int queueSize;

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Enqueue method
    void enqueue(const T& x);

    // Dequeue method
    void dequeue();

    // Front element
    const T& front() const;

    // Size method
    int size() const;

    // Empty method
    bool empty() const;

    // Clear method
    void clear();

    // Friend operator
    template<class U>
    friend ostream& operator<<(ostream& out, const Queue<U>& q);
};


// Constructor — O(1)
template<class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    queueSize = 0;
}


// Destructor — O(n)
template<class T>
Queue<T>::~Queue() {
    clear();
}


// Add at rear — O(1)
template<class T>
void Queue<T>::enqueue(const T& x) {
    Node* toAdd = new Node(x);

    if (head == nullptr) {
        head = toAdd;
        tail = toAdd;
    }
    else {
        tail->next = toAdd;
        tail = toAdd;
    }

    queueSize++;
}


// Remove from front — O(1)
template<class T>
void Queue<T>::dequeue() {
    if (head == nullptr) {
        throw runtime_error("Empty Queue");
    }

    Node* toRemove = head;

    head = head->next;

    delete toRemove;

    queueSize--;

    if (head == nullptr) {
        tail = nullptr;
    }
}


// Return front value — O(1)
template<class T>
const T& Queue<T>::front() const {
    if (head == nullptr) {
        throw runtime_error("Empty Queue");
    }

    return head->data;
}


// Return number of elements — O(1)
template<class T>
int Queue<T>::size() const {
    return queueSize;
}


// Check whether empty — O(1)
template<class T>
bool Queue<T>::empty() const {
    return queueSize == 0;
}


// Remove all elements — O(n)
template<class T>
void Queue<T>::clear() {
    while (head != nullptr) {
        dequeue();
    }
}


// Print front to rear — O(n)
template<class U>
ostream& operator<<(ostream& out, const Queue<U>& q) {
    out << "[";

    typename Queue<U>::Node* current = q.head;

    while (current != nullptr) {
        out << current->data;

        if (current->next != nullptr) {
            out << ", ";
        }

        current = current->next;
    }

    out << "]";

    return out;
}

#endif