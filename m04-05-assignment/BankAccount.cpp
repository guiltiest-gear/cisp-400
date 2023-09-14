#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "BankAccountHeader.h"
using std::to_string, std::string, std::ifstream, std::cout, std::vector;

// Return the account balance
double BankAccount::getAccountBalance() { return accountBalance; }
// Return the account name
string BankAccount::getAccountName() { return accountName; }
// Return the account number
int BankAccount::getAccountNumber() { return accountNumber; }
// Return the account id
int BankAccount::getAccountId() { return accountId; }

// Set the account balance with the argument
void BankAccount::setAccountBalance(double amount) { accountBalance = amount; }

// Set accountName with an argument
void BankAccount::setAccountName(string name) { accountName = name; }

void BankAccount::setAccountNumber(int number) { accountNumber = number; }

// Add a reward to the balance based on account balance
void BankAccount::addReward(double amount) {
  accountBalance += (REWARDS_RATE * amount);
}

// Deduct from balance and return true if resulting blance is less than
// minimum balance
bool BankAccount::withdraw(double amount) {
  // Check the minimum balance BEFORE we withdraw
  if (accountBalance < MIN_BALANCE) {
    return true;
  } else {
    accountBalance -= amount;
    return false;
  }
}

// Add amount to balance. If amount is greater than rewards amount, call
// addReward
void BankAccount::deposit(double amount) {
  accountBalance += amount;
  if (amount > REWARDS_AMOUNT) BankAccount::addReward(amount);
}

// Return account information as a string with three lines
string BankAccount::toString() {
  return "Account Name: " + accountName + '\n' + "Account Number: " +
         /* Since accountNumber and accountBalance are an int and double
         respectively, I need to convert them to a string first before using
         the concat operator or else that's a type error */
         to_string(accountNumber) + '\n' +
         "Account Balance: " + fixPrecision(to_string(accountBalance)) + '\n';
}

// Affix the decimal to 2 points of precision
string BankAccount::fixPrecision(string number) {
  // Find where the period is
  int i = number.find('.');
  // Truncate the string to just 2 digits after the decimal
  return number.substr(0, i + 3);
}

// Return the vector we're going to use
vector<BankAccount> fillVector(ifstream& input) {
  // Init the variables we need
  string firstName, lastName, accountName;
  int id, accountNumber;
  double accountBalance;
  vector<BankAccount> vec;

  // HACK: We can't use vec.size() since the vector doesn't have anything in it,
  // so we only use a constant just this once
  for (int i = 0; i < 8; i++) {
    // Read from the fields
    input >> firstName >> lastName >> id >> accountNumber >> accountBalance;

    // Concat the first and last name
    accountName = firstName + " " + lastName;

    // Init a temp instance of BankAccount
    BankAccount tmp(accountName, id, accountNumber, accountBalance);

    // Now push tmp into the vector
    vec.push_back(tmp);
  }
  return vec;
}

void printVector(vector<BankAccount> vec) {
  cout << "FAVORITE BANK - CUSTOMER DETAILS\n"
       << "--------------------------------\n";
  int length = vec.size();
  for (int i = 0; i < length; i++) cout << vec.at(i).toString() << '\n';
}

// Return the index of the smallest element of the vector
int smallestBalance(vector<BankAccount> vec) {
  vector<double> tmp;
  int index = 0, length = vec.size();
  // Push the account balances into a temp vector
  for (int i = 0; i < length; i++) tmp.push_back(vec.at(i).getAccountBalance());

  // Search for the smallest balance
  for (int i = 1; i < length; i++)
    if (tmp.at(i) < tmp.at(index)) index = i;

  return index;
}

// Return the index of the largest element of the vector
int largestBalance(vector<BankAccount> vec) {
  vector<double> tmp;
  int index = 0, length = vec.size();
  // Push the account balances into a temp vector
  for (int i = 0; i < length; i++) tmp.push_back(vec.at(i).getAccountBalance());

  // Search for the largest balance
  for (int i = 1; i < length; i++)
    if (tmp.at(i) > tmp.at(index)) index = i;

  return index;
}

// Return true if the bank account is the same as the other, return false
// otherwise
bool BankAccount::equals(BankAccount other) {
  if (this->accountId == other.accountId) {
    return true;
  } else {
    return false;
  }
}

// Remove duplicates in the vector
vector<BankAccount> removeDuplicates(vector<BankAccount> vec) {
  bool duplicate = false;
  int length = vec.size();
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      // Check if the the acccount id is equal
      if (vec.at(i).equals(vec.at(j))) {
        duplicate = true;
        /* Since the erase method is overloaded, we need to essentially do a
         * sort of *(arr + i) with the vectors
         * This should delete the duplicate */
        vec.erase(vec.begin() + j);
        /* NOTE: Since we deleted an entry from the vector, we need to update
         * the length accordingly, or else we'll get an out of range error */
        length = vec.size();
      }
    }
  }

  if (duplicate) {
    cout << "Duplicate account found: Reprinting list\n\n";
    return vec;
  } else {
    // If we didn't find anything, that means the array is still intact
    return vec;
  }
}

// Insert a bank account at a specific position
vector<BankAccount> insertAccount(vector<BankAccount> vec, string name, int id,
                                  int number, double balance, int pos) {
  // Create an instance of BankAccount with the correct parameters
  BankAccount newAccount(name, id, number, balance);
  // NOTE: Don't forget about zero-based indexing
  vec.insert(vec.begin() + pos, newAccount);
  return vec;
}

// Number of objects created
int BankAccount::getCount() { return count; }

// Init the count variable to 0
int BankAccount::count = 0;
// NOTE: MAKE SURE TO DECLARE THE VARIABLE OR ELSE YOU *WILL* GET A LINKER ERROR
