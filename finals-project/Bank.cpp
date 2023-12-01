#include "Bank.h"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "CheckingAccount.h"
#include "GreaterThan.h"
#include "SavingsAccount.h"
#include "UserAccount.h"

using std::ifstream, std::vector, std::shared_ptr, std::string, std::cout,
    std::make_shared, std::sort;

void fillVector(ifstream &input,
                vector<shared_ptr<UserAccount>> &accountsVector) {
  // Variables to hold fields
  string accountName, firstName, lastName, type;
  int id, accountNumber;
  double accountBalance;
  while (!input.eof()) {
    // Fill in the fields
    input >> firstName >> lastName >> id >> accountNumber >> accountBalance >>
        type;
    // Combine firstName and lastName
    accountName = firstName + " " + lastName;

    // Depending on the type variable, we need to create a different class
    // pointer
    if (type == "S") {
      shared_ptr<UserAccount> tmp = make_shared<SavingsAccount>(
          accountName, id, accountNumber, accountBalance);
      accountsVector.push_back(tmp);
    } else {
      // Only other case is a checking account
      shared_ptr<UserAccount> tmp = make_shared<CheckingAccount>(
          accountName, id, accountNumber, accountBalance);
      accountsVector.push_back(tmp);
    }
  }
}

void Bank::displayAccounts() {
  // Create iterator
  vector<shared_ptr<UserAccount>>::iterator it;
  // Loop over vector and display the accounts
  for (it = accountsVector.begin(); it != accountsVector.end(); it++)
    cout << it->get()->toString() << '\n';
}

Bank::Bank(const Bank &other) {
  // cout<<" In copy constructor  "<<endl;
  // accountsVector.resize(other.accountsVector.size());
  // cout<<accountsVector.size()<<endl;
  // create a cop constructor that copies the two vectors
  // this->accountsVector.resize(other.accountsVector.size());
  this->accountsVector = other.accountsVector;
}

Bank::Bank(string filename) {
  // throw File Open Error - File Exception -99 if file cannot be opened
  // use try catch statement
  try {
    // Attempt to open the file
    ifstream input(filename);
    // If we can't open the file, throw the exception
    if (input.fail()) {
      // Close file handle and throw exception
      input.close();
      throw FileException(-99);
    }
    // If we got here, that must mean we successfully opened the file
    // Fill out the vector
    fillVector(input, accountsVector);
    sortAccounts();
  } catch (FileException error) {
    // Report the error
    cout << "File Open Error " << error.getValue() << '\n';
    // Abort program and exit with error code 1
    exit(1);
  }
}

// should sort vector
void Bank::addAccount(shared_ptr<UserAccount> a) {
  // add an account
  // be sure to keep vector sorted
  // use STL sort using Greater THan Function Object
  accountsVector.push_back(a);
  // After we push back the account, sort the vector
  sortAccounts();
}

void Bank::sortAccounts() {
  // use the STL sort by passing the beginning, end and Greater Than Functor
  GreaterThan Comparison;
  sort(accountsVector.begin(), accountsVector.end(), Comparison);
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount) {
  // return false if amount is negative
  // return true after depositing into account
  if (amount < 0) return false;
  // If we got here, that means we have a valid value
  a->deposit(amount);
  return true;
}

bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount) {
  // if the withdraw amount is suitable then withdraw from account and return
  // true

  // otherwise return false
  // This is a boolean, we can directly return it
  return a->withdraw(amount);
}

bool Bank::checkSame(Bank &other) {
  // check if this bank has the exact same accounts as the other bank
  // use equalTo method created in the UserAccount class (that implements
  // Comparable)
  // return true if same, false otherwise
  // equalTo should check if each and every field matches

  // Create temporary shared pointers to hold the compared accounts
  shared_ptr<UserAccount> thisaccount, otheraccount;
  // Loop through the vectors and check each of them
  bool result;
  for (uint64_t i = 0; i < accountsVector.size(); i++) {
    thisaccount = accountsVector.at(i);
    otheraccount = other.accountsVector.at(i);
    // Test if they're equal
    if (thisaccount->equalTo(otheraccount))
      result = true;
    else
      result = false;
    // The moment the result is false, immediately return, do not wait
    if (result == false) return result;
  }

  return result;
}

bool Bank::removeAccount(shared_ptr<UserAccount> a) {
  vector<shared_ptr<UserAccount>>::iterator it;
  for (it = accountsVector.begin(); it != accountsVector.end(); it++) {
    // Loop over the vector and test the indexes
    // HACK: I know linear search is bad, but it's a small database, and it
    // works, I've given up with std::find
    if (it->get()->equalTo(a) == true) {
      accountsVector.erase(it);
      return false;
    }
  }
  return true;
}

Bank::FileException::FileException(int v) { value = v; }

int Bank::FileException::getValue() { return value; }
