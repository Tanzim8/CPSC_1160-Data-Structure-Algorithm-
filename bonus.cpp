//Task 1: This is the task 1 for Lab 1 CPSC 1160
#include <iostream>
using namespace std;
//pass by value function
void applyBonusValue(int score, int bonus){
    score = score + bonus;
}
//pass by reference function
void applyBonusRef(int& score, int bonus){
    score=score+bonus;
}
int main(){
    //original variable
    int marks = 80;
    int bonus = 20; 
    //initial value print
    cout << "Initial Value: "<< marks << endl;

    applyBonusValue(marks, bonus);
    //printing after using the first function pass by value
    cout << "Pass by value result: "<< marks << endl;

    applyBonusRef(marks,bonus);
    //printing after using the second function pass by reference
    cout << "Pass by reference result: " << marks << endl;

    /*
    Explanation: 
    When I called the first function the original value of the original variable stayed the same the bonus mainly got added inside the function and just a copy of the original value changed when I used the first function and the main value of the original value stayed the same.
    For the 2nd function, this is a pass by reference function and the & inside the function parameters with the original value makes sure the original value of initial score changes when the function is used.  
    */
}