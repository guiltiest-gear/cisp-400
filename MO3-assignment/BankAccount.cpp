#include <fstream>
#include <iostream>
#include <string>

#include "BankAccountHeader.h"
using std::to_string, std::string, std::ifstream, std::cout;

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

// Fill the array we created
void fillArray(ifstream &input, BankAccount arr[]) {
  // Init the variables we need
  string firstName, lastName, accountName;
  int id, accountNumber;
  double accountBalance;

  for (int i = 0; i < length; i++) {
    // Read the fields of the file, one bank acc at a time
    input >> firstName >> lastName >> id >> accountNumber >> accountBalance;

    // Now put the first name and last name together for the account name
    accountName = firstName + " " + lastName;

    // Init a temp instance of BankAccount
    BankAccount tmp(accountName, id, accountNumber, accountBalance);
    // Push the temp instance to the array
    arr[i] = tmp;
  }
}

void printArray(BankAccount arr[]) {
  cout << "FAVORITE BANK - CUSTOMER DETAILS\n"
       << "--------------------------------\n";
  for (int i = 0; i < length; i++) cout << arr[i].toString() << '\n';
}

// Return the index of the smallest element of the array
int smallestBalance(BankAccount arr[]) {
  double tmp[length];
  int index = 0;
  // Push the account balances into a temp array
  for (int i = 0; i < length; i++) tmp[i] = arr[i].getAccountBalance();

  // Search for the smallest balance
  for (int i = 1; i < length; i++)
    if (tmp[i] < tmp[index]) index = i;

  return index;
}

// Return the index of the largest element of the array
int largestBalance(BankAccount arr[]) {
  double tmp[length];
  int index = 0;
  // Push the account balances into a temp array
  for (int i = 0; i < length; i++) tmp[i] = arr[i].getAccountBalance();

  // Search for the largest balance
  for (int i = 1; i < length; i++)
    if (tmp[i] > tmp[index]) index = i;

  return index;
}

void checkDuplicates(BankAccount arr[]) {
  bool duplicate = false;
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (arr[i].getAccountId() == arr[j].getAccountId()) {
        duplicate = true;
        arr[j].setAccountName("XXXX XXXX");
        arr[j].setAccountNumber(0);
        arr[j].setAccountBalance(0.00);
      }
    }
  }

  if (duplicate) {
    cout << "Duplicate accounts found: Reprinting list\n\n";
    printArray(arr);
  }
}
