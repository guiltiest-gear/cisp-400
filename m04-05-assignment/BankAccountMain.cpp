#include <fstream>
#include <iostream>
#include <vector>

#include "BankAccountHeader.h"

using std::cout, std::ifstream, std::vector;

int main() {
  // Open up the file to be used
  ifstream input("BankData.txt");
  // If we couldn't open the file, abort the program
  if (input.fail()) {
    cout << "Error! File could not be opened! Exiting program...\n";
    // Close the file anyway just in case
    input.close();
    // Exit with error code 1
    exit(1);
  }

  // Since we're not working with arrays, we need to return a vector and store
  // it here
  // Init a vector for the bank accounts
  vector<BankAccount> accountsArray = fillVector(input);

  // NOTE: DO NOT FORGET TO CLOSE FILE, SERIOUSLY DO NOT, NO DANGLING POINTERS,
  // NO MEM LEAKS, DO NOT FORGET
  input.close();

  // Now print the vector
  printVector(accountsArray);

  // Print the largest element
  int largest_index = largestBalance(accountsArray);
  cout << "Largest balance:\n"
       << accountsArray.at(largest_index).toString() << '\n';

  // Now print the smallest element
  int smallest_index = smallestBalance(accountsArray);
  cout << "Smallest balance:\n"
       << accountsArray.at(smallest_index).toString() << '\n';

  // Print the number of objects using static count
  cout << "Using the static count, there are " << BankAccount::getCount()
       << " accounts\n";
  // Do the same thing except using the size operator
  cout << "Using vector size, there are " << accountsArray.size()
       << " accounts\n\n";

  // Detect and delete any duplicates
  accountsArray = removeDuplicates(accountsArray);
  printVector(accountsArray);

  // Print the number of objects using static count
  cout << "Using the static count, there are " << BankAccount::getCount()
       << " accounts\n";
  // Do the same thing except using the size operator
  cout << "Using vector size, there are " << accountsArray.size()
       << " accounts\n\n";

  // Insert three new accounts
  accountsArray =
      insertAccount(accountsArray, "Amy Machado", 387623, 1244, 1023.67, 2);
  accountsArray =
      insertAccount(accountsArray, "Tak Phen", 981243, 1262, 6423.03, 4);
  accountsArray =
      insertAccount(accountsArray, "Celia Beatle", 465281, 1276, 3.56, 6);
  cout << "Inserted three new accounts: reprinting list\n\n";
  printVector(accountsArray);

  // Print the number of objects using static count
  cout << "Using the static count, there are " << BankAccount::getCount()
       << " accounts\n";
  // Do the same thing except using the size operator
  cout << "Using vector size, there are " << accountsArray.size()
       << " accounts\n";

  return 0;
}
