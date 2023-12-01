#pragma once

#include <memory>
#include <string>
#include <vector>
// #include "UserAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
class Bank {
 public:
  class FileException {
   private:
    int value;

   public:
    explicit FileException(int v);
    int getValue();
  };

 private:
  // static int dataSize;
  std::vector<std::shared_ptr<UserAccount>> accountsVector;

 public:
  explicit Bank(std::string filename);
  Bank(const Bank &other);
  // void fillVector (ifstream &input,vector<shared_ptr<UserAccount>>
  // &accountsVector);
  void addAccount(std::shared_ptr<UserAccount> a);     // should sort vector
  bool removeAccount(std::shared_ptr<UserAccount> a);  // vector remove method
  void sortAccounts();  // use STL sort using Greater THan Function Object
  void displayAccounts();
  bool accountDeposit(std::shared_ptr<UserAccount> a, double amount);
  bool accountWithdraw(std::shared_ptr<UserAccount> a, double amount);
  // bool backupAccounts();
  bool checkSame(Bank &other);
};
