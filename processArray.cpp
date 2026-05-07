#include <iostream>
using namespace std;

void processArray(int arr[], int size, int& maxVal, int& minVal){
    for(int i = 0; i < size; i++){
        if(arr[i]< minVal){
            minVal = arr[i];
        }if(arr[i]>maxVal){
            maxVal = arr[i];
        }
    }
}

int main(){
    int arr[5] = {5, 7, 9, 1, 8};
    int maxVal = arr[0];
    int minVal = arr[0];
    //printing the initial array
    for(int i=0; i<5; i++){
        cout << arr[i]<<" ";
    }
    cout << "\nInitial Max & min val: " << "Max: "<< maxVal << ", "<< "Min: "<< minVal << endl;
    //using the function
    processArray(arr, 5, maxVal, minVal);
    cout << "Max & min val after using the function: " << "Max: "<< maxVal << ", "<< "Min: "<< minVal << endl;
}