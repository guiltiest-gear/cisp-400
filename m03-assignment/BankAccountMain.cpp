#include <fstream>
#include <iostream>

#include "BankAccountHeader.h"

using std::cout, std::ifstream;

int main() {
  // Init an array for the bank accounts
  BankAccount accountsArray[length];

  // Open up the file to be used
  ifstream input("BankData.txt");
  // If we couldn't open the file, abort the program
  if (!input) {
    cout << "Error! File could not be opened! Exiting program...\n";
    // Close the file anyway just in case
    input.close();
    // Exit with error code 1
    exit(1);
  }

  // Fill the array
  fillArray(input, accountsArray);

  // Now push the array to the output
  printArray(accountsArray);

  // Figure out who has the largest and smallest balance
  int largestIndex = largestBalance(accountsArray);
  cout << "Largest balance:\n"
       << accountsArray[largestIndex].toString() << '\n';

  int smallestIndex = smallestBalance(accountsArray);
  cout << "Smallest balance:\n"
       << accountsArray[smallestIndex].toString() << '\n';

  // Check for the duplicates
  checkDuplicates(accountsArray);

  // NOTE: DO NOT FORGET TO CLOSE FILE, SERIOUSLY DO NOT, NO DANGLING POINTERS,
  // NO MEM LEAKS, DO NOT FORGET
  input.close();

  return 0;
}
