#ifndef BANKHEADER_H
#define BANKHEADER_H

#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "BankAccountHeader.h"

// Bank Class Header file
// This class simulates a Bank by storing Bank Accounts in a vector
// It provides an API for customer interaction via ATM like functions
class Bank {
 private:
  std::shared_ptr<BankAccount> bptr;
  std::vector<std::shared_ptr<BankAccount>> accountsVector;

 public:
  // Constructor that reads bank database from file
  // it calls the fillVector method to populate the database
  explicit Bank(std::string filename);
  // Withdraw amount
  void withdraw();
  // Check balance
  void viewBalance();
  // Deposit amount
  void deposit();
  // Helper function
  void fillVector(std::ifstream &, std::vector<std::shared_ptr<BankAccount>> &);
  // Admin function print all accounts
  void printVector(std::vector<std::shared_ptr<BankAccount>> &);
  // Sort accounts
  void sortAccounts(std::vector<std::shared_ptr<BankAccount>> const &, int,
                    int);
};

// Helper function for quicksort
int intPart(std::vector<std::shared_ptr<BankAccount>> const &, int, int);

// Binary search and return the index of the value
int binarySearch(std::vector<std::shared_ptr<BankAccount>> const &, int, int,
                 int);
// Check if a name exists in a vector and return true if it does, return false
// otherwise
bool nameCheck(std::vector<std::shared_ptr<BankAccount>> &, std::string);
#endif  // !BANKHEADER_H
