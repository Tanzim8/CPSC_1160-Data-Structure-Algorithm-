/*
name: M. Rahman
ID-100409251
CPSC-1160
Lab-7
References: 
1. https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/
2. https://stackoverflow.com/questions/64695570/printing-head-and-tail-of-singly-linked-list
3. ChatGpt to understand the questions and the tail functinality better. 
*/
#include "SLL.h"

SLL::SLL(){
    head = nullptr;
    tail = nullptr;
    //introduced tail to make addLast() O(1), because we can directly attaced a new node after tail instead of traversing the whole list from head.
    listSize = 0;
}

SLL::SLL(int n, int defaultVal){
    head = nullptr;
    tail = nullptr;
    listSize =0;

    if(n < 0){
        throw invalid_argument("Size cannot be negative!");
    }

    for(int i = 0; i<n; i++){
        addLast(defaultVal);
    }
}

SLL:: SLL(int arr[], int arrSize){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    if(arrSize < 0){
        throw invalid_argument("Array size cannot be negative!");
    }
    for(int i = 0; i<arrSize; i++){
        addLast(arr[i]);
    }
}

SLL::SLL(const SLL& other){
    head = nullptr;
    tail = nullptr;
    listSize = 0;

    Node* current = other.head;
    while(current != nullptr){
        addLast(current->data);
        current = current->next;
    }
}
SLL& SLL::operator=(const SLL& other){

    if(this == &other){
        return *this;
    }
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
    return in;
};

int& SLL:: operator[](int index){
    if(index<0 || index >= listSize){
        throw out_of_range("index out of range");
    }
    Node* current = head;
    for(int i =0; i< index; i++){
        current = current -> next;

    }
    return current->data;
};

string SLL::toString() const{
    string result ="";

    Node* current = head;

    while(current != nullptr){
        result += to_string(current -> data);
        if(current->next != nullptr){
            result += " ";
        }
        current = current -> next;
    }
    return result;
};


//time complexity = O(1) because no loop. 
void SLL:: addFirst(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        newNode -> next = head;
        head = newNode;
    }
    listSize++;
};

//time complexity = O(1) because no loop. 
void SLL:: addLast(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
    listSize++;
}

//time complexity = O(n) because of the while loop.
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
        tail = nullptr;
        listSize--;
        return deleteVal;
    }
    while(current -> next != nullptr){
        previous = current;
        current = current -> next;
    }
    previous -> next = nullptr;
    int removedValue = current -> data;
    delete current;
    tail = previous;
    listSize--;
    return removedValue;
}
//time complexity = O(1) because no loop. 
int SLL:: removeFirst(){
    if(head == nullptr){
        throw runtime_error("List is Empty");
    }
    Node* temp = head;
    head = head-> next;
    if(head == nullptr){
        tail = nullptr;
    }
    int removedValue = temp->data;
    delete temp;
    listSize--;
    return removedValue;
}

//time complexity O(n), because of loop.  
void SLL:: remove(int target){
    if(head == nullptr){
        throw runtime_error("List is empty");
    }

    if(head -> data == target){
        removeFirst();
        return;
    }
    Node* previous = head;
    Node* current = head -> next;

    while(current != nullptr && current -> data != target){
        previous = current;
        current = current -> next;
    }
    if(current == nullptr){
        throw runtime_error("Target not found");
    }
    if(current == tail){
        tail = previous;
    }
    previous -> next = current -> next;
    delete current;
    listSize--;
}

//time complexity O(n), because of loop.  
bool SLL::search(int target, int &index){
    Node* current = head;
    index = 0;
    while(current != nullptr){
        if(current -> data == target){
            return true;
        }
        current = current -> next;
        index++;
    }
    return false;
}

int SLL::size() const{
    return listSize;
}

int SLL::getSize() const{
    return listSize;
}
