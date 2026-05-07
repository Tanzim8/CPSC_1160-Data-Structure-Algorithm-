#include <iostream>
using namespace std;

void filterArray(int arr[], int size, int& newSize){
    newSize = 0;
    for(int i =0; i<size; i++){
        if(arr[i] >= 0 ){
            arr[newSize] = arr[i];
            newSize++;
        }
    }
}

int main(){
    int arr[5] = {5,- 7, 9, -1, 8};
    int newSize;
    //printing the initial array
    for(int i=0; i<5; i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    //using the function
    filterArray(arr, 5, newSize);
    //printing the array after the function
    for(int i=0; i<newSize; i++){
        cout << arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}