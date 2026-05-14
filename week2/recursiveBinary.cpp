// in binary search when left is  greater than right that is the base case and it exits the function with a return of -1
int binarySearch(int arr[], int left, int right, int target){
    if(left > right){
        return -1;
    }
    int mid = left + (right - left) /2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] > target){
        return binarySearch(arr, left, mid -1 , target);
    }else{
        return binarySearch(arr, mid+1, right, target);
    }
}