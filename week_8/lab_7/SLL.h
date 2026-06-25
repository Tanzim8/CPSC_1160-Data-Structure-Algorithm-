#include <iostream>
#include <stdexcept>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};
class SLL{
private: 
    Node* head;
    int size;
public: 
    SLL();

    SLL(int size, int defaultVal);

    SLL(int arr[], int arrSize);

    SLL(const SLL& other);

    SLL& operator=(const SLL& other);

    ~SLL();

    friend istream& operator>>(istream& in, SLL& list);

    int& operator[](int index);

    string& toString() const;

    void addFirst(int val);

    void addLast(int val);

    int removeLast();

    int removeFirst();

    void remove(int target);

    bool search(int target, int &index);

};