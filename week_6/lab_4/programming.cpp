#include <iostream>
using namespace std;

struct StringList{
    int capacity;
    int size;
    int* list;
}
StringList(){
    capacity = 3;
    size = 0;
    list = new int[capacity];
}