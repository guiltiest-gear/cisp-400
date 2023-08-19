// Program    : CheckMultiple7Main.cpp
// Author     : Jade Fox
// Due Date   : August 27, 2023
// Description: Write a program that determines if an integer is a multiple of 7
//              The program should prompt the user to enter an integer,
//              determine if it is a multiple of 7 by using a given formula and
//              output the result.

#include <iostream>
using std::cout, std::cin;

// Function prototypes

// Input a number and return it
int inputNumber();
// Check if a number is a multiple of 7, return true if number is a multiple
bool checkMultiple7(int);
// Display the results
void displayResults(int, bool);

int main() {
  int number = inputNumber();
  displayResults(number, checkMultiple7(number));
  return 0;
}

int inputNumber() {
  int number;
  cout << "Please enter an integer: ";
  cin >> number;
  return number;
}

bool checkMultiple7(int n) { return (n % 7 == 0); }

void displayResults(int n, bool result) {
  if (result == true) {
    cout << n << " is a multiple of 7.\n";
  } else {
    cout << n << " is not a multiple of 7.\n";
  }
}
