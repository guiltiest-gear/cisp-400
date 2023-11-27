#ifndef BANKACCOUNTHEADER_H
#define BANKACCOUNTHEADER_H

#include <fstream>
#include <string>

// Define the constants
const double MIN_BALANCE = 9.99, REWARDS_AMOUNT = 1000.00, REWARDS_RATE = 0.04;

// Define the length of the array
const int length = 8;

class BankAccount {
 private:
  std::string accountName;  // First and last name of the account holder
  int accountNumber;        // The account number for the bank account
  double accountBalance;    // The current amount of money in the bank account
  int accountId;            // A unique id for every bank account

 public:
  // Default constructor to set name to empty string, account number to 0, and
  // balance to 0
  BankAccount() {
    accountName = "";
    accountNumber = 0;
    accountBalance = 0.00;
  }

  // Regular constructor
  BankAccount(std::string name, int id, int number, double balance) {
    accountName = name;
    accountId = id;
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
  // Return the account id
  int getAccountId();

  // Setters
  // Set accountBalance with an argument
  void setAccountBalance(double);

  // Set accountName with an argument
  void setAccountName(std::string);

  // Set accountNumber with an argument
  void setAccountNumber(int);

  // Add a reward to the balance based on account balance
  void addReward(double);

  // Deduct from balance and return true if resulting blance is less than
  // minimum balance
  bool withdraw(double);

  // Add amount to balance. If amount is greater than rewards amount, call
  // addReward
  void deposit(double);

  // Return account information as a string with three lines
  std::string toString();

  // Affix the decimal to 2 points of precision
  std::string fixPrecision(std::string);
};

// Fill the array we created
void fillArray(std::ifstream&, BankAccount[]);

// Print the array to std output
void printArray(BankAccount[]);

// Return the index of the smallest element of the array
int smallestBalance(BankAccount[]);

// Return the index of the largest element of the array
int largestBalance(BankAccount[]);

// Check for duplicates in the array
void checkDuplicates(BankAccount[]);

#endif  // !BANKACCOUNTHEADER_H
