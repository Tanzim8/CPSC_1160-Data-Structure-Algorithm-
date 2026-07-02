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
    
}