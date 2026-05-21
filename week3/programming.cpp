#include <iostream>
using namespace std;
//Question 1
int sumDigits(int num){
    int sum = 0;
    if(num == 0){
        return num;
    }
    int digit = num%10;
    sum+=digit;
    return sum + sumDigits(num/10);
}

//Question 2
void displaySingleDigits(int arr[], int size){
    if(size == 0){
        return;
    }
    int lastElement = arr[size-1];
    if(lastElement <=9 && lastElement >=-9){
        cout << lastElement  << " ";
    }
    return displaySingleDigits(arr, size-1);
}

//Part 2
//Question 3
void merge(const int data1[],int n,const int data2[],int m,int data3[]){ 
int i, j, k; 
for (i = j = k = 0; i < n && i < m;    ){ 
    if (data1[i] < data2[j]) 
    data3[k++] = data1[i++]; 
    else  
    data3[k++] = data2[j++]; 
    } 
    while (i < n) { 
    data3[k++] = data1[i++]; 
    } 
    while (j < m) { 
    data3[k++] = data2[j++]; 
    } 
} 
// the function that sorts arr[strat...end] using merge() 
void mergeSort(int arr[], int start, int end) { 
    if (start >= end)   // Base case: 1 or 0 elements 
            return;  
    int mid = start + (end - start) / 2; // step 1 
    mergeSort(arr, start, mid);      //step 2  
    mergeSort(arr, mid + 1, end);    //step 2  
    merge(arr, start, mid, end);     //step 3 
}

int main(){
    //Q-1
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Sum of digits = " << sumDigits(number) << endl;

    //Q-2
    int arr[] = {12, 5, -3, 100, 8, 42, -7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Single-digit numbers (from last to first): ";
    displaySingleDigits(arr, size);

    cout << endl;
    return 0;
}