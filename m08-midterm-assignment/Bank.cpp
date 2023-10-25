#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "BankHeader.h"

using std::string, std::ifstream, std::istringstream, std::make_shared,
    std::vector, std::shared_ptr, std::cout, std::iter_swap, std::getline,
    std::cin, std::find;

// Normal constructor
Bank::Bank(string filename) {
  // Init the variables required
  ifstream inputFile(filename);
  // Abort if we can't find the file
  if (inputFile.bad()) {
    cout << "Error! File not found!\n";
    exit(1);
  }
  // Use the helper function to fill the vector
  fillVector(inputFile, accountsVector);
  // Sort the vector after we fill it
  sortAccounts(accountsVector, 0, accountsVector.size() - 1);
  // Print the vector
  printVector(accountsVector);
}

// Fill the vector
void Bank::fillVector(ifstream &input,
                      vector<shared_ptr<BankAccount>> &accountsVector) {
  // Init the variables required
  string firstName, lastName, accountName, data;
  int id, accountNumber;
  double accountBalance;
  istringstream instream;
  try {
    if (input) {
      while (!input.eof()) {
        getline(input, data);
        istringstream instream(data);
        instream >> firstName;
        instream >> lastName;
        instream >> id;
        instream >> accountNumber;
        instream >> accountBalance;
        accountName = firstName + " " + lastName;
        shared_ptr<BankAccount> tmp = make_shared<BankAccount>(
            accountName, id, accountNumber, accountBalance);
        accountsVector.push_back(tmp);
      }
    } else {
      // As great as C++ strings are, no point in using a mutable object, use a
      // const char array, or C-style string
      throw "File Not Found";
    }
  } catch (const char message) {
    cout << message << '\n';
    exit(1);
  }
}

// Print the vector
void Bank::printVector(vector<shared_ptr<BankAccount>> &accountsVector) {
  // Create an iterator to loop over the vector
  vector<shared_ptr<BankAccount>>::iterator it;

  // Loop over the vector and print the bank accounts
  for (it = accountsVector.begin(); it != accountsVector.end(); it++)
    cout << it->get()->toString() << '\n';
}

// Helper function for quicksort
int part(vector<shared_ptr<BankAccount>> const &accountsVector, int start,
         int end) {
  int pivot = accountsVector.at(start)->getAccountNumber();

  int count = 0;
  for (int i = start + 1; i <= end; i++)
    if (accountsVector.at(i)->getAccountNumber() <= pivot) count++;

  // Give pivot element correct position
  int pivotIndex = start + count;
  iter_swap(accountsVector.at(pivotIndex), accountsVector.at(start));

  // Sorting left and right parts of the pivot element
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex) {
    while (accountsVector.at(i)->getAccountNumber() <= pivot) i++;
    while (accountsVector.at(j)->getAccountNumber() > pivot) j--;
    if (i < pivotIndex && j > pivotIndex)
      iter_swap(accountsVector.at(i++), accountsVector.at(j--));
  }

  return pivotIndex;
}

// Sort the accounts with quicksort via account numbers
void Bank::sortAccounts(vector<shared_ptr<BankAccount>> const &accountsVector,
                        int start, int end) {
  // Base case
  if (start >= end) return;

  // Partition the array
  int p = part(accountsVector, start, end);

  // Sorting the left part
  sortAccounts(accountsVector, start, p - 1);

  // Sorting the right part
  sortAccounts(accountsVector, p + 1, end);
}

// Withdraw from an account
void Bank::withdraw() {
  string firstName, lastName, accountName;
  int accountNumber;
  double amount;
  // Ask for the first and last name
  cout << "What is the account first name? ";
  cin >> firstName;
  cout << "What is the account last name? ";
  cin >> lastName;
  // Concat them together with a space
  accountName = firstName + " " + lastName;
  // HACK: I really don't want to reinvent the wheel by resorting the vector
  // just for this one thing, and then putting it back, this is good enough
  if (!nameCheck(accountsVector, accountName)) {
    cout << "Error! Name not found! Please try again\n";
    // Erase the strings
    accountName.clear();
    firstName.clear();
    lastName.clear();
    // Retry the entry
    Bank::withdraw();
  }
  cout << "What is the account number? ";
  cin >> accountNumber;
  // Binary search should return the index of the value
  int index =
      binarySearch(accountsVector, 0, accountsVector.size() - 1, accountNumber);
  if (index == -1) {
    cout << "Error! Account number not found! Please try again\n";
    Bank::withdraw();
  }
  cout << "What is the dollar amount? ";
  cin >> amount;
  bool result = accountsVector.at(index).get()->withdraw(amount);
  if (result)
    cout << "\nInsufficient funds\n";
  else
    cout << "\nAmmount withdrawn from account\n";
}

// Check balance of an account
void Bank::viewBalance() {
  string firstName, lastName, accountName;
  int accountNumber;
  // Ask for the first and last name
  cout << "What is the account first name? ";
  cin >> firstName;
  cout << "What is the account last name? ";
  cin >> lastName;
  // Concat them together with a space
  accountName = firstName + " " + lastName;
  if (!nameCheck(accountsVector, accountName)) {
    cout << "Error! Name not found! Please try again\n";
    // Erase the strings
    accountName.clear();
    firstName.clear();
    lastName.clear();
    // Retry the entry
    Bank::viewBalance();
  }
  cout << "What is the account number? ";
  cin >> accountNumber;
  // Binary search should return the index of the value
  int index =
      binarySearch(accountsVector, 0, accountsVector.size() - 1, accountNumber);
  if (index == -1) {
    cout << "Error! Account number not found! Please try again\n";
    Bank::viewBalance();
  }
  // After all of the error checks, finally print the account
  cout << "\n----------------------------------------\n";
  cout << accountsVector.at(index).get()->toString();
  cout << "----------------------------------------\n";
}

// Deposit an ammount into a bank account
void Bank::deposit() {
  string firstName, lastName, accountName;
  int accountNumber;
  double amount;
  // Ask for the first and last name
  cout << "What is the account first name? ";
  cin >> firstName;
  cout << "What is the account last name? ";
  cin >> lastName;
  // Concat them together with a space
  accountName = firstName + " " + lastName;
  if (!nameCheck(accountsVector, accountName)) {
    cout << "Error! Name not found! Please try again\n";
    // Erase the strings
    accountName.clear();
    firstName.clear();
    lastName.clear();
    // Retry the entry
    Bank::deposit();
  }
  cout << "What is the account number? ";
  cin >> accountNumber;
  // Binary search should return the index of the value
  int index =
      binarySearch(accountsVector, 0, accountsVector.size() - 1, accountNumber);
  if (index == -1) {
    cout << "Error! Account number not found! Please try again\n";
    Bank::deposit();
  }
  cout << "What is the dollar amount? ";
  cin >> amount;
  accountsVector.at(index).get()->deposit(amount);
  cout << "\nAmmount deposited into account\n";
}

// Binary search and return the index of the value
int binarySearch(vector<shared_ptr<BankAccount>> const &accountsVector, int l,
                 int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;

    // Check if x is present at mid
    if (accountsVector.at(m)->getAccountNumber() == x) return m;
    // If x is greater, ignore left half
    else if (accountsVector.at(m)->getAccountNumber() < x)
      l = m + 1;
    // If x is smaller, ignore right half
    else
      r = m - 1;
  }

  // If we get here, then the value isn't present
  return -1;
}

// Check if a name exists in a vector
bool nameCheck(vector<shared_ptr<BankAccount>> &accountsVector, string name) {
  // Create a temporary vector to hold the strings
  vector<string> tmp;
  // Generate an iterator
  vector<shared_ptr<BankAccount>>::iterator it;

  for (it = accountsVector.begin(); it != accountsVector.end(); it++)
    // Push the account names into the temporary vector
    tmp.push_back(it->get()->getAccountName());

  if (find(tmp.begin(), tmp.end(), name) != tmp.end())
    return true;
  else
    return false;
}
