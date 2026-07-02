#include "DLL.h";
#include <iostream>
#include <stdexcept>
using namespace std;

DLL::Node::Node(int value){
    data = value;
    next = nullptr;
    prev = nullptr;
}
DLL::Node::Node(int value, Node* before, Node* after){
    data = value;
    next = after;
    prev = before;
}

DLL::DLL(){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

DLL::DLL(int n, int data){
    head = nullptr;
    tail = nullptr;
    listSize = 0;

    for(int i =0; i<n; i++){
        addLast(data);
    }
}

DLL::DLL(int arr[], int size){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    for(int i = 0; i<size; i++){
        addLast(arr[i]);
    }
}

DLL::DLL(const DLL & other){
    head = nullptr;
    tail = nullptr;
    listSize =0;

    Node* current = other.head;

    while(current != nullptr){
        addLast(current->data);
        current=current->next;
    }
}

istream & operator>>(istream & in, DLL& list){
    int value;
    in>>value;
    list.addLast(value);
    return in;
};

DLL& DLL:: operator=(const DLL& other){
    if(this == & other){
        return *this;
    }
    while(head != nullptr){
        removeFirst();
    }
    Node* current = other.head;
    while(current != nullptr){
        addLast(current->data);
        current = current->next;
    }
    return *this;
}

DLL:: Node* DLL::operator[](const int idx){
    if(head == nullptr){
        throw runtime_error("Empty List");
    }
    if (idx < 0 || idx >= listSize) {
        throw out_of_range("Invalid index");
    }
    int count =0;
    Node* current = head;
    while(count != idx){
        current = current->next;
        count++;
    }
    return current;
};

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

string DLL:: toString() const{
    string listStrn = "";

    DLL::Node* current = head;
    while(current != nullptr){
        listStrn.append(to_string(current->data));
        listStrn.append("");
        current = current->next;
    }
}

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

int DLL:: removeLast(){
    Node* toRemove = tail;
    if(head == nullptr){
        throw runtime_error("empty list");
    }
    int value = tail->data;

    tail = tail->prev;

    if(tail == nullptr){
        head == nullptr;
    }else{
        tail->next = nullptr;
    }
    delete toRemove;
    listSize--;
    return value;
}

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