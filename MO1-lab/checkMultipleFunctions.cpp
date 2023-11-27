#include <iostream>

#include "checkMultipleHeader.h"

using std::cout, std::cin;

// Ask for input from the user, then return that input
int inputNumber() {
  int number;
  cout << "Please enter an integer: ";
  cin >> number;
  return number;
}

// If n evenly divides by 7, return true, otherwise, return false
bool checkMultiple7(int n) { return (n % 7 == 0); }

// If the result is true, display that the number is a multiple of 7
// otherwise display the number is not a multiple of 7
void displayResults(int n, bool result) {
  if (result == true) {
    cout << n << " is a multiple of 7.\n";
  } else {
    cout << n << " is not a multiple of 7.\n";
  }
}
