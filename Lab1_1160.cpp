/*
Name: M Tanzim Rahman
ID: 100409251
Lab 1 - CPSC 1160
References: 
1. https://en.cppreference.com/cpp/string/byte/isalpha
2. https://www.geeksforgeeks.org/dsa/isupper-islower-application-c/
3. https://www.geeksforgeeks.org/cpp/isdigit-in-cpp/
4. https://en.cppreference.com/cpp/string/byte/isspace
5. https://en.cppreference.com/cpp/string/byte/ispunct
6. https://www.geeksforgeeks.org/cpp/cpp-program-to-print-ascii-value-of-a-character/
7. I took AI's help to understand the exact tasks for the lab and to design the main function for all the functions.
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Task 1: This is the task 1 for Lab 1 CPSC 1160
//pass by value function
void applyBonusValue(int score, int bonus){
    score = score + bonus;
}
//pass by reference function
void applyBonusRef(int& score, int bonus){
    score=score+bonus;
}

//Task 2: This is the task 2 for Lab 1 CPSC 1160
void filterArray(int arr[], int size, int& newSize){
    newSize = 0;
    for(int i =0; i<size; i++){
        if(arr[i] >= 0 ){
            arr[newSize] = arr[i];
            newSize++;
        }
    }
}

//Task 3: This is the task 3 for Lab 1 CPSC 1160
void processArray(int arr[], int size, int& maxVal, int& minVal){
    for(int i = 0; i < size; i++){
        if(arr[i]< minVal){
            minVal = arr[i];
        }if(arr[i]>maxVal){
            maxVal = arr[i];
        }
    }
}

//Task 4: This is the task 4 for Lab 1 CPSC 1160
//checking if the password length is at least 8 characters long
bool isValid(const string& password){
    if(password.length() < 8){
        return false;
    }

    //checking if the first character is a letter or not
    char firstChar = password[0];
    if(!isalpha(firstChar)){
        return false;
    }

    //checking if the pssword contains at least 2 lowercase letters and 1 uppercase letters & exactly 2 digits and at least 1 special character
    int count = 0;
    int upperCount = 0;
    int digitCount = 0;
    int specialCount = 0;

    for(int i =0; i< password.length(); i++){
        if(isalpha(password[i]) && islower(password[i])){
            count++;
        }
        if(isalpha(password[i]) && isupper(password[i])){
            upperCount++;
        }
        if(isdigit(password[i])){
            digitCount++;
        }
        //checking if the password contains any whitespace characters
        if(isspace(password[i])){
            return false;
        }
        //checking if the password contains at least 1 special character
        if(ispunct(password[i])){
            specialCount++;
        }
    }
    if(count >= 2 && upperCount >= 1 && digitCount == 2 && specialCount >= 1){
        return true;
    }
    return false;
}

//trying with passing by value

// bool isValid(string password){
//     if(password.length() < 8){
//         return false;
//     }

//     //checking if the first character is a letter or not
//     char firstChar = password[0];
//     if(!isalpha(firstChar)){
//         return false;
//     }

//     //checking if the pssword contains at least 2 lowercase letters and 1 uppercase letters & exactly 2 digits and at least 1 special character
//     int count = 0;
//     int upperCount = 0;
//     int digitCount = 0;
//     int specialCount = 0;

//     for(int i =0; i< password.length(); i++){
//         if(isalpha(password[i]) && islower(password[i])){
//             count++;
//         }
//         if(isalpha(password[i]) && isupper(password[i])){
//             upperCount++;
//         }
//         if(isdigit(password[i])){
//             digitCount++;
//         }
//         //checking if the password contains any whitespace characters
//         if(isspace(password[i])){
//             return false;
//         }
//         //checking if the password contains at least 1 special character
//         if(ispunct(password[i])){
//             specialCount++;
//         }
//     }
//     if(count >= 2 && upperCount >= 1 && digitCount == 2 && specialCount >= 1){
//         return true;
//     }
//     return false;
// }

/*
Explanation of the difference between passing by value and passing by reference:

When we pass a variable by value, a copy of the variable is created and passed to the function. This means that any changes made to the variable inside the function do not affect the original variable outside the function. In contrast, when we pass a variable by reference, we pass a reference
There is no significant difference when I try using passing with value rather than passing with reference! The main difference is Passing by reference is more efficient as it does not creates any copy of the password. For small passwords or strings passing by value is fine but for larger strings or passwords passing by value would take more memory and time. That is the reaosn why passing by reference is more efficient*/

//the makePassword function
string makePassWord(int n){
    //filling the password with 'a' characters to make it n character long
    if(n<8){
        n = 8;
    }
    string password = "";

    password += (char)(rand() % 26 + 'A'); // adding at least 1 uppercase letter

    password += (char)(rand() % 26 + 'a'); // adding at least 1 lowercase letter
    password += (char)(rand() % 26 + 'a'); // adding at least 2 lowercase letters

    password += (char)(rand() % 10 + '0'); // adding exactly 2 digits
    password += (char)(rand() % 10 + '0'); // adding exactly 2 digits

    password += (char)(rand() % 15 + 33); // adding at least 1 special character

    // Filling the rest with letters or special characters only
    while (password.length() < n) {
        int choice = rand() % 3;
        char ch;

        if (choice == 0) {
            ch = 'A' + rand() % 26;  // uppercase
        } 
        else if (choice == 1) {
            ch = 'a' + rand() % 26;  // lowercase
        } 
        else {
            ch = '!' + rand() % 15;  // special character
        }

        password += ch;
    }
    return password;
}

int main() {
    srand(time(0));

    // Testing Task 1

    cout << "Task 1: Bonus Functions" << endl;

    int marks = 80;
    int bonus = 20;

    cout << "Initial Value: " << marks << endl;

    applyBonusValue(marks, bonus);
    cout << "Pass by value result: " << marks << endl;

    applyBonusRef(marks, bonus);
    cout << "Pass by reference result: " << marks << endl;

    cout << endl;

    /*
    Explanation:
    When I called the first function, the original value stayed the same.
    The bonus was added only to a copy of the variable inside the function.

    For the second function, the score was passed by reference using &.
    This means the original variable was changed directly.
    */

    // Testing Task 2

    cout << "Task 2: Process Array" << endl;

    int arr1[5] = {5, 7, 9, 1, 8};
    int maxVal;
    int minVal;

    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    processArray(arr1, 5, maxVal, minVal);

    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;

    cout << endl;

    // Testing Task 3


    cout << "Task 3: In-Place Filter" << endl;

    int arr2[5] = {5, -7, 9, -1, 8};
    int newSize;

    cout << "Original array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;

    filterArray(arr2, 5, newSize);

    cout << "Filtered array: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl << endl;

    // Testing Task 4

    cout << "Task 4: Password Validation" << endl;

    int n;

    cout << "Enter password size: ";
    cin >> n;

    string generatedPassword = makePassWord(n);

    cout << "Generated password: " << generatedPassword << endl;
    cout << "Is generated password valid? " << boolalpha << isValid(generatedPassword) << endl;

    cout << endl;

    cout << "Testing given passwords:" << endl;

    cout << "Xx_&9x2Yc: " << boolalpha << isValid("Xx_&9x2Yc") << endl;
    cout << "cmpt11@ca: " << boolalpha << isValid("cmpt11@ca") << endl;
    cout << "passCode2%c1: " << boolalpha << isValid("passCode2%c1") << endl;
    cout << "Xx_&9x21Yc: " << boolalpha << isValid("Xx_&9x21Yc") << endl;
    cout << "Pe&11x: " << boolalpha << isValid("Pe&11x") << endl;
    cout << "#Pt1xx1: " << boolalpha << isValid("#Pt1xx1") << endl;
    cout << "Cpsc& 81: " << boolalpha << isValid("Cpsc& 81") << endl;

    return 0;
}