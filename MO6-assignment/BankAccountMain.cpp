#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "BankAccountHeader.h"

using std::cout, std::ifstream, std::vector, std::shared_ptr;

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
  // Init a vector for the bank accounts and fill it
  vector<shared_ptr<BankAccount>> accountsVector = fillVector(input);

  // NOTE: DO NOT FORGET TO CLOSE FILE, SERIOUSLY DO NOT, NO DANGLING POINTERS,
  // NO MEM LEAKS, DO NOT FORGET
  input.close();

  // Now print the vector
  printVector(accountsVector);

  // Print the account with the largest balance
  cout << "Largest Balance:\n"
       << accountsVector.at(largest(accountsVector))->toString() << '\n';

  // Print the account with the smallest balance
  cout << "Smallest balance:\n"
       << accountsVector.at(smallest(accountsVector))->toString() << '\n';

  // Print the number of objects using the static count method
  cout << "Using the static count, there are " << BankAccount::getCount()
       << " accounts\n";
  // Print the number of objects using the vector size method
  cout << "Using vector size, there are " << accountsVector.size()
       << " accounts\n\n";

  // Check if there's duplicates
  checkDuplicates(accountsVector);

  // Print the vector again
  printVector(accountsVector);

  // Print the number of objects using the static count method
  cout << "Using the static count, there are " << BankAccount::getCount()
       << " accounts\n";
  // Print the number of objects using the vector size method
  cout << "Using vector size, there are " << accountsVector.size()
       << " accounts\n\n";

  // Insert the new accounts into the vector
  insertAccount(accountsVector);
  cout << "Inserted Three New Accounts: Reprinting List\n\n";
  printVector(accountsVector);

  // Print the number of objects using the static count method
  cout << "Using the static count, there are " << BankAccount::getCount()
       << " accounts\n";
  // Print the number of objects using the vector size method
  cout << "Using vector size, there are " << accountsVector.size()
       << " accounts\n\n";

  return 0;
}
