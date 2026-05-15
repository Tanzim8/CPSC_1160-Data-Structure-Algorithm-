/*
Lab 2
CPSC 1160
M. Tanzim Rahman
ID-100409251
References: 
https://stackoverflow.com/questions/60826175/how-to-convert-from-hexadecimal-to-decimal-in-c-recursively
https://nirajsdatabase.blogspot.com/2017/07/hexadecimal-to-decimal-using-recursion-c.html

*/
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

//part A
int decimal(char hexChar){
    hexChar = toupper(hexChar);
    if(hexChar >= '0' && hexChar <= '9'){
        return hexChar - '0';
    }else if(hexChar >= 'A' && hexChar <= 'F'){
        return hexChar - 'A' + 10;
    }
    return -1; // Invalid character
}

//part B
/*
For a hexadecimal string s:
hexToDecimal(s) = decimal(s[0]) * 16^(s.length() -1) + hexToDecimal(rest of s)
Example:
hexToDecimal("A12F") = decimal('A') * 16^3 + hexToDecimal("12F")
                     = 10 * 4096 + 303
                     = 41263
*/

//part C
int hexToDecimal(string hex){
    if(hex.length() == 0){
        return 0; // Base case: empty string
    }

    char fistChar = hex[0]; 
    string restOfHex = hex.substr(1); 
    int power = hex.length() - 1;

    return decimal(fistChar) * pow(16, power) + hexToDecimal(restOfHex);
}

int main() {
    string hex;

    cout << "Enter a hexadecimal number: ";
    cin >> hex;

    cout << "Decimal value: " << hexToDecimal(hex) << endl;

    return 0;
}