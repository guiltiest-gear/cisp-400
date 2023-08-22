#include <string>

#include "BankAccountHeader.h"
using std::to_string, std::string;

// Return the account balance
double BankAccount::getAccountBalance() { return accountBalance; }
// Return the account name
string BankAccount::getAccountName() { return accountName; }
// Return the account number
int BankAccount::getAccountNumber() { return accountNumber; }

// Set the account balance with the argument
void BankAccount::setAccountBalance(double amount) { accountBalance = amount; }

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
         "Account Balance: " + to_string(accountBalance) + '\n';
}
