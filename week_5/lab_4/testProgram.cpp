/*
Lab-4
M. Rahman
100409251
CPSC 1160
References:
1. https://stackoverflow.com/questions/75816075/using-pointers-to-copy-an-array
2. https://www.geeksforgeeks.org/cpp/c-program-to-check-prime-number/
3. chatGPT used to impleent the main functiom. 
*/
#include <iostream>
using namespace std;

//A
double* copyArray (double data [], int size);

double* copyArray (double data [], int size){
    double* newArray = new double[size];
    for(int i =0; i<size; i++){
        newArray[i] = data[i];
    }
    return newArray;
}

//B
int* reverse (int* data, int size);
int* reverse (int* data, int size){
    int* newArray = new int[size];
    for(int i =size-1; i>=0; i--){
        newArray[size-1-i] = data[i];
    }
    return newArray;
}

//C
int* primes(int number, int& size);

//helper function
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
int* primes(int number, int& size){
    size = 0;
    for(int i =2; i<number; i++){
        if(isPrime(i)){
            size++;
        }
    }
    int *list = new int[size];
    int index = 0;

    for(int i =2; i<number; i++){
        if(isPrime(i)){
            list[index] = i;
            index++;
        }
    }
    return list;
}

//D
void minMax(double *list, int size, double *min, double *max);

void minMax(double *list, int size, double *min, double *max){
    *min = list[0];
    *max = list[0];
    for(int i =1; i<size; i++){
        if(list[i] <*min){
            *min = list[i];
        }if(list[i] > *max){
            *max = list[i];
        }
    }
}

//E
int main() {
    // Testing A: copyArray
    cout << "Testing copyArray:" << endl;

    double dataA[] = {1.1, 2.2, 3.3, 4.4};
    int sizeA = 4;

    double* copiedArray = copyArray(dataA, sizeA);

    cout << "Original array: ";
    for (int i = 0; i < sizeA; i++) {
        cout << dataA[i] << " ";
    }
    cout << endl;

    cout << "Copied array: ";
    for (int i = 0; i < sizeA; i++) {
        cout << copiedArray[i] << " ";
    }
    cout << endl;

    delete[] copiedArray;
    copiedArray = nullptr;

    cout << endl;


    // Testing B: reverse
    cout << "Testing reverse:" << endl;

    int dataB[] = {10, 20, 30, 40, 50};
    int sizeB = 5;

    int* reversedArray = reverse(dataB, sizeB);

    cout << "Original array: ";
    for (int i = 0; i < sizeB; i++) {
        cout << dataB[i] << " ";
    }
    cout << endl;

    cout << "Reversed array: ";
    for (int i = 0; i < sizeB; i++) {
        cout << reversedArray[i] << " ";
    }
    cout << endl;

    delete[] reversedArray;
    reversedArray = nullptr;

    cout << endl;


    // Testing C: primes
    cout << "Testing primes:" << endl;

    int primeSize;
    int* primeList = primes(20, primeSize);

    cout << "Prime numbers less than 20: ";
    for (int i = 0; i < primeSize; i++) {
        cout << primeList[i] << " ";
    }
    cout << endl;

    cout << "Number of primes: " << primeSize << endl;

    delete[] primeList;
    primeList = nullptr;

    cout << endl;


    // Testing D: minMax
    cout << "Testing minMax:" << endl;

    double dataD[] = {4.5, 2.1, 9.8, 1.3, 7.0};
    int sizeD = 5;

    double minimum;
    double maximum;

    minMax(dataD, sizeD, &minimum, &maximum);

    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    return 0;
}
