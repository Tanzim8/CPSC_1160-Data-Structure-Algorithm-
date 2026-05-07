#include <iostream>
#include <string>
#include <ctime>
using namespace std;

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
string makePassword(int n){
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

    int n;

    cout << "Enter password size: ";
    cin >> n;

    string newPassword = makePassword(n);

    cout << "Generated password: " << newPassword << endl;
    cout << "Is generated password valid? " << boolalpha << isValid(newPassword) << endl;

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