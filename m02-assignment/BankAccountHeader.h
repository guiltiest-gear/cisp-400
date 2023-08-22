#ifndef BANKACCOUNTHEADER_H
#define BANKACCOUNTHEADER_H

#include <string>

// Define the constants
const double MIN_BALANCE = 9.99, REWARDS_AMOUNT = 1000.00, REWARDS_RATE = 0.04;

class BankAccount {
 private:
  std::string accountName;  // First and last name of the account holder
  int accountNumber;        // The account number for the bank account
  double accountBalance;    // The current amount of money in the bank account

 public:
  // Default constructor to set name to empty string, account number to 0, and
  // balance to 0
  BankAccount() {
    accountName = "";
    accountNumber = 0;
    accountBalance = 0.00;
  }

  // Regular constructor
  BankAccount(std::string name, int number, double balance) {
    accountName = name;
    accountNumber = number;
    accountBalance = balance;
  }

  // Getters
  // Return the account balance
  double getAccountBalance();
  // Return the account name
  std::string getAccountName();
  // Return the account number
  int getAccountNumber();

  // Setters
  // Set accountBalance with an argument
  void setAccountBalance(double amount);

  // Add a reward to the balance based on account balance
  void addReward(double amount);

  // Deduct from balance and return true if resulting blance is less than
  // minimum balance
  bool withdraw(double amount);

  // Add amount to balance. If amount is greater than rewards amount, call
  // addReward
  void deposit(double amount);

  // Return account information as a string with three lines
  std::string toString();
};

#endif  // !BANKACCOUNTHEADER_H
