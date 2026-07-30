#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <forward_list>
#include <stdexcept>
#include <SLL.h>
using namespace std;

class Queue{
private:
    struct Node{
        int data;
        Node* next;
        Node(int value){
            data = value;
            next=nullptr;
        }
    };
    Node* head;
    Node* tail;
    int queueSize;
public:
    Queue();

    //enqueue method
    void enqueue(const int& x);

    //dequeue method
    void dequeue();

    //front element
    const int& front() const;

    //size method
    int size() const;

    //empty method
    bool empty() const;

    //clear method
    void clear();

    friend ostream& operator<<(ostream& out, const Queue& mq);
};

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
    queueSize = 0;
};

void Queue::enqueue(const int& x){
    Node* toAdd = new Node (x);
    if(head == nullptr){
        head=tail= toAdd;
    }
    tail->next = toAdd;
    tail = toAdd;
    queueSize++;
}

void Queue:: dequeue(){
    if(head == nullptr){
        throw runtime_error("Empty Queue");
    }
    Node* toRemove = new Node(head->data);
    head = head->next;
    delete toRemove;

    queueSize--;

    if(head == nullptr){
        tail == nullptr;
    }
}
#endif