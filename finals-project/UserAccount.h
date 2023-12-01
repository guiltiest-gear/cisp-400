#pragma once
// #include "UserAccount.h"
// #include "Helper.h"
#include <fstream>
#include <memory>
#include <string>
#include <vector>

class UserAccount {
 private:
  int accountNumber, id;
  std::string accountName;
  double accountBalance;

 public:
  static const double MIN_BALANCE;
  static const double REWARD_RATE;
  static const double MIN_REWARD_AMOUNT;

  // Constructors
  UserAccount();
  UserAccount(std::string accountName, int id, int accountNumber,
              double accountBalance);

  // getters
  std::string getAccountName();
  int getAccountNumber();
  double getAccountBalance();
  void setAccountName(std::string accountName);
  void setAccountNumber(int number);
  void setId(int id);
  void setAccountBalance(double accountBalance);
  // bool operator==(<shared_ptr<UserAccount> a, shared_ptr<UserAccount> b);
  // bool equals(shared_ptr<UserAccount> a);
  virtual std::string toString();
  virtual bool withdraw(double amount);

  std::string fixPoint(std::string number);
  // virtual
  void calculateBalance();
  virtual void deposit(double amount);
  bool equalTo(std::shared_ptr<UserAccount> a);
  void addReward(double amount);
  int getId();
};
