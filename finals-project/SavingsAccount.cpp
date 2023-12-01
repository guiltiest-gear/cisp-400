#include "SavingsAccount.h"

#include "UserAccount.h"

using std::string;

SavingsAccount::SavingsAccount() { UserAccount(); }

SavingsAccount::SavingsAccount(std::string accountName, int id,
                               int accountNumber, double accountBalance)
    // This is here to make sure the parameters are correctly passed
    : UserAccount(accountName, id, accountNumber, accountBalance) {
  // Do nothing here, just let inheritance do its job
}

string SavingsAccount::toString() {
  return "Account Name: " + getAccountName() + "\n" +
         "Account Number: " + std::to_string(getAccountNumber()) + "\n" +
         "Account Balance: " + fixPoint(std::to_string(getAccountBalance())) +
         "\n" + "Account Type: Savings \n";
}

bool SavingsAccount::withdraw(double amount) {
  // cout << "Withdraw Unsuccessful - Cannot Withdraw from Savings "
  //         "Account\n";
  return false;
}

void SavingsAccount::deposit(double amount) {
  setAccountBalance(getAccountBalance() + amount);
  // Check if reward is applicable
  if (amount >= MIN_REWARD_AMOUNT) addReward(amount);
}
