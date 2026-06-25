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
