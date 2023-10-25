#ifndef BANKACCOUNTHEADER_H
#define BANKACCOUNTHEADER_H

#include <fstream>
#include <memory>
#include <string>
#include <vector>

// Define the constants
const double MIN_BALANCE = 9.99, REWARDS_AMOUNT = 1000.00, REWARDS_RATE = 0.04;

class BankAccount {
 private:
  std::string accountName;  // First and last name of the account holder
  int accountNumber;        // The account number for the bank account
  double accountBalance;    // The current amount of money in the bank account
  int accountId;            // A unique id for every bank account

 public:
  static int count;  // Number of objects created
  // Default constructor
  BankAccount();
  // Regular constructor
  BankAccount(std::string, int, int, double);

  // Getters
  // Return the account balance
  double getAccountBalance();
  // Return the account name
  std::string getAccountName();
  // Return the account number
  int getAccountNumber();
  // Return the account id
  int getAccountId();
  // Return the count
  static int getCount();

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

  // Return true if the bank account is the same as the other, return false
  // otherwise
  bool equals(BankAccount);
};

#endif  // !BANKACCOUNTHEADER_H
