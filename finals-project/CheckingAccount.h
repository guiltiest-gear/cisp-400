#pragma once
#include <string>

#include "UserAccount.h"

class CheckingAccount : public UserAccount {
 public:
  static const double MIN_BALANCE_CHECKING;

 public:
  CheckingAccount();
  CheckingAccount(std::string accountName, int id, int accountNumber,
                  double accountBalance);
  virtual std::string toString();
  virtual bool withdraw(double amount);
  virtual void deposit(double amount);
  // virtual bool operator==(shared_ptr<CheckingAccount> a );
};
