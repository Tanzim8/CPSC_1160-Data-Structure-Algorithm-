#include "SLL.h"

SLL::SLL(){
    head = nullptr;
    size = 0;
}

SLL::SLL(int size, int defaultVal){
    head = nullptr;
    this->size = size;
    for(int i = 0; i<size; i++){
        addLast(defaultVal);
    }
}

SLL:: SLL(int arr[], int arrSize){
    head = nullptr;
    size = arrSize;
    for(int i = 0; i<arrSize; i++){
        addLast(arr[i]);
    }
}

SLL::SLL(const SLL& other){
    head = nullptr;
    size = 0;

    Node* current = other.head;
    while(current != nullptr){
        addLast(current->data);
        current = current->next;
    }
}
SLL& SLL::operator=(const SLL& other){
    while(head != nullptr){
        removeFirst();
    }
    Node* current = other.head;
    while(current!= nullptr){
        addLast(current->data);
        current = current->next;
    }
    return *this;
}

SLL::~SLL(){
    while(head != nullptr){
        removeFirst();
    }
};

istream& operator>>(istream& in, SLL& list){
    int n;
    int value;
    while(list.head != nullptr){
        list.removeFirst();
    }
    in>>n;

    if(n<0){
        throw invalid_argument("Size cannot be negative!");
    }
    
    for(int i = 0; i<n; i++){
        in>>value;
        list.addLast(value);
    }
};

int& SLL:: operator[](int index){
    if(index<0 || index >= size){
        throw out_of_range("index out of range");
    }
    Node* current = head;
    for(int i =0; i< index; i++){
        current = current -> next;

    }
    return current->data;
};

string& SLL:: toString() const{
    string result ="";

    Node* current = head;

    while(current != nullptr){
        result += to_string(current -> data)+ "";
        current = current -> next;
    }
    return result;
};

void SLL:: addFirst(int val){
    Node* newNode = new Node(val);
    newNode -> next = head;
    head = newNode;
    size++;
};

void SLL:: addLast(int val){
    if(head == nullptr){
        addFirst(val);
        return;
    }
    Node* current = head;
    while(current -> next != nullptr){
        current = current -> next;
    }
    Node* newNode = new Node(val);
    current -> next = newNode;
    size++;
}

int SLL:: removeLast(){
    if(head == nullptr){
        throw runtime_error("List is empty");
    }

    Node* current = head;
    Node* previous = nullptr;
    if(current -> next == nullptr){
        int deleteVal = current -> data;
        delete current;
        head = nullptr;
        size--;
        return deleteVal;
    }
    while(current -> next != nullptr){
        previous = current;
        current = current -> next;
    }
    previous -> next = nullptr;
    int removedValue = current -> data;
    delete current;
    size--;
    return removedValue;
}
