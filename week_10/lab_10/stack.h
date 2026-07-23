#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Stack{
    private:
        vector<int> data;

    public:
        //constructor
        Stack();

        //push_method
        void push(const int& e);

        //POP
        void pop();

        //top/peek
        const int& top() const;

        //size
        int size() const;

        //empty
        bool empty() const;

        //clear
        void clear();

        //freind operator<<
        friend ostream& operator<<(ostream& out, const Stack& stack);
};
#endif 