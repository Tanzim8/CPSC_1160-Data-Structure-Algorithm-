#include <iostream>
#include <stdexcept>
using namespace std;
class DLL{
    class Node{
    private:
        int data;
        Node* prev;
        Node* next;
    public:
        Node(int value);
        Node(int value, Node* after, Node* before);
        friend class DLL;
    };
private: 
    Node* head;
    Node* tail;
    int size;
public:
    // default constructor
    DLL();

    DLL(int n, int data);

    DLL(int arr[], int size);

    //copy constructor
    DLL(const DLL &);

    friend istream & operator>>(istream &, DLL& list);
    //copy assignment
    DLL& operator=(const DLL&);
    //offset operator
    int& operator[](const int idx);
    friend ostream & operator<<(ostream &, const DLL&);
    //toString method
    string toString() const;
    //adds at the begining of the list
    void addFirst(int data);
    //adds at the last of the list
    void addLast(int data);
    //removes the first element of the list
    int removeFirst();
    //removes the last element of the list
    int removeLast();
    //inserts data after p
    void insertAfter(Node* p, int data);
    //returns the number of elements in the list
    int size();

    //returns a pointer to the i-th node in the list
    Node* get(int i);

    bool search(int target, int &idx);
    int remove(int target);

    //destructor
    ~DLL();
};