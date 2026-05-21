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
// void merge(const int data1[],int n,const int data2[],int m,int data3[]){ 
// int i, j, k; 
// for (i = j = k = 0; i < n && i < m;    ){ 
//     if (data1[i] < data2[j]) 
//     data3[k++] = data1[i++]; 
//     else  
//     data3[k++] = data2[j++]; 
//     } 
//     while (i < n) { 
//     data3[k++] = data1[i++]; 
//     } 
//     while (j < m) { 
//     data3[k++] = data2[j++]; 
//     } 
// } 

//fixed merge for merge sort for question 3
void merge(int arr[], int start, int mid, int end){
    int temp[end-start+1];
    int i = start;
    int j = mid+1;
    int k = 0;

    while(i<= mid && j<=end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int x = 0; x<k; x++){
        arr[start+x] = temp[x];
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

//Part 3
//Question 4
// int partition(int arr[], int size) { 
// int pivot = arr[0]; 
// int low = 1; 
// int high = size - 1; 
// while (low < high) { 
//     // Move low to the right  
//     while (low < size && arr[low] <= pivot)    
//             low++; 
//         // Move high to the left  
//         while (arr[high] > pivot)    
//             high--; 
//         // If low < high, swap elements 
//         if (low < high)   
//             swap(arr[low], arr[high]); 
//     } 
//     // Step 4: Swap pivot with element before low 
//     swap(arr[0], arr[low-1]); 
//     // Return final position of pivot 
//     return low-1; 
// } 

//the fixed partition function for quicksort
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(i <= j){
        while(i <= high && arr[i]<= pivot){
            i++;
        }
        while(j >= low && arr[j]> pivot){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high);
// Quick Sort function 
void quickSort(int arr[], int size) { 
    quickSort(arr, 0, size - 1); 
} 
// Quick Sort Helper function 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        // Partition the array 
        int pivotIndex = partition(arr, low, high); 
        // Recursively sort left and right parts 
        quickSort(arr, low, pivotIndex - 1); 
        quickSort(arr, pivotIndex + 1, high); 
    } 
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

    //Q-3
    int arr3[] = {8, 3, 5, 1, 9, 2};
    int size3 = 6;

    mergeSort(arr3, 0, size3 - 1);
    
    for (int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }

    //Q-4
    int arr4[] = {6, 3, 8, 2, 7, 4};
    int size4 = 6;

    cout << "Before sorting: ";
    for (int i = 0; i < size4; i++) {
        cout << arr4[i] << " ";
    }

    cout << endl;

    quickSort(arr4, 0, size4 - 1);

    cout << "After sorting: ";
    for (int i = 0; i < size4; i++) {
        cout << arr4[i] << " ";
    }

    cout << endl;

    return 0;
}