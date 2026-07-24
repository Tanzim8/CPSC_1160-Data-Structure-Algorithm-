/*
Name: M. Rahman
ID: 100409251
Course: CPSC1160 (Lab_10)*/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template<class T>
class Stack{
    private:
        vector<T> data;

    public:
        //constructor
        Stack();

        //push_method
        void push(const T& e);

        //POP
        void pop();

        //top/peek
        const T& top() const;

        //peek
        const T& peek() const;

        //size
        int size() const;

        //empty
        bool empty() const;

        //clear
        void clear();

        //freind operator<<
        template<class U>
        friend ostream& operator<<(ostream& out, const Stack<U>& stack);
};

// O(1)
template<class T>
Stack<T>::Stack(){

}

//push
// Amortized O(1)
template<class T>
void Stack<T>::push(const T& value){
    data.push_back(value);
}


//pop
// O(1)
template<class T>
void Stack<T>::pop(){

    if(data.empty()){
        throw runtime_error("Empty Stack");
    }
    data.pop_back();
}

//top
// O(1)
template<class T>
const T& Stack<T>:: top() const{
    if(data.empty()){
        throw runtime_error("Empty Stack");
    }

    return data.back();
}

// O(1)
template<class T>
const T& Stack<T>::peek() const
{
    return top();
}

//size
// O(1)
template<class T>
int Stack<T>:: size() const{
    return static_cast<int>(data.size());
}

//empty
// O(1)
template<class T>
bool Stack<T>:: empty() const{
    return data.empty();
}

//clear
// O(n)
template<class T>
void Stack<T>:: clear(){
    data.clear();
}

// O(n)
template<class U>
ostream& operator<<(ostream& out, const Stack<U>& stack){
    out << "[";
    for(int i =0; i<stack.size(); i++){
        out<< stack.data[i];

        if(i<stack.size()-1){
            out<< ", ";
        }
    }
    out << "]";
    return out;

}
#endif 