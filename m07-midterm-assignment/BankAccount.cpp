#include <fstream>
#include <iostream>
#include <string>

#include "BankAccountHeader.h"

using std::to_string, std::string, std::ifstream;

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

// Return true if the bank account is the same as the other, return false
// otherwise
bool BankAccount::equals(BankAccount other) {
  if (this->accountId == other.accountId)
    return true;
  else
    return false;
}

// Init the count variable to 0
// NOTE: MAKE SURE TO DECLARE THE VARIABLE OR ELSE YOU *WILL* GET A LINKER ERROR
int BankAccount::count = 0;

// Number of objects created
int BankAccount::getCount() { return count; }

// Default constructor
BankAccount::BankAccount() {
  accountName = "";
  accountNumber = 0;
  accountBalance = 0.00;
  // Every time we create an instance, increment count
  count++;
}

// Regular constructor
BankAccount::BankAccount(string name, int id, int number, double balance) {
  accountName = name;
  accountId = id;
  accountNumber = number;
  accountBalance = balance;
  // Every time we create an instance, increment count
  count++;
}
