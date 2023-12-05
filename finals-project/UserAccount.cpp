#include "UserAccount.h"
// #include "Helper.h"
#include <memory>

using std::shared_ptr, std::string;

UserAccount::UserAccount() {
  this->id = 0;
  this->accountBalance = 0;
  this->accountNumber = 0;
  this->accountName = "";
}

UserAccount::UserAccount(std::string accountName, int id, int accountNumber,
                         double accountBalance) {
  this->accountName = accountName;
  this->id = id;
  this->accountNumber = accountNumber;
  this->accountBalance = accountBalance;
}

// getters
string UserAccount::getAccountName() { return accountName; }
int UserAccount::getAccountNumber() { return accountNumber; }
double UserAccount::getAccountBalance() { return accountBalance; }
int UserAccount::getId() { return id; }
// setting balance may be needed by admin

// helper method
std::string UserAccount::fixPoint(string number) {
  int i = number.find('.');
  return number.substr(0, i + 3);
}

bool UserAccount::equalTo(shared_ptr<UserAccount> a) {
  // compare all fields of this user account with a
  if (this->id != a->getId())
    return false;
  else if (this->accountBalance != a->getAccountBalance())
    return false;
  else if (this->accountNumber != a->getAccountNumber())
    return false;
  else if (this->accountName != a->getAccountName())
    return false;
  else
    return true;
}

std::string UserAccount::toString() {
  // std::cout<<fixPoint(std::to_string(accountBalance));
  return "Account Name: " + accountName + "\n" +
         "Account Number: " + std::to_string(accountNumber) + "\n" +
         "Account Balance: " + fixPoint(std::to_string(accountBalance)) + "\n";
}

// setters : cannot change number and accountName
void UserAccount::setAccountName(string accountName) { return; }
void UserAccount::setAccountNumber(int number) { return; }
void UserAccount::setAccountBalance(double accountBalance) {
  this->accountBalance = accountBalance;
}

void UserAccount::setId(int id) { this->id = id; }

bool UserAccount::withdraw(double amount) { return false; }
void UserAccount::deposit(double amount) {
  // Deposit into account
  accountBalance += amount;
  // Check if the deposit amount is greater than or equal to the reward amount,
  // If true, call addReward
  // if (amount >= MIN_REWARD_AMOUNT) addReward(amount);
}

void UserAccount::addReward(double amount) {
  accountBalance = accountBalance + REWARD_RATE * amount;
}

const double UserAccount::MIN_BALANCE = 9.99;
const double UserAccount::MIN_REWARD_AMOUNT = 1000.0;
const double UserAccount::REWARD_RATE = 0.04;
