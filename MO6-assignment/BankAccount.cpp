#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "BankAccountHeader.h"
using std::to_string, std::string, std::ifstream, std::cout, std::vector,
    std::shared_ptr, std::make_shared;

// Return the account balance
double BankAccount::getAccountBalance() { return accountBalance; }
// Return the account name
string BankAccount::getAccountName() { return accountName; }
// Return the account number
int BankAccount::getAccountNumber() { return accountNumber; }
// Return the account id
int BankAccount::getAccountId() { return accountId; }

// Set the account balance with the argument
void BankAccount::setAccountBalance(double amount) { accountBalance = amount; }

// Set accountName with an argument
void BankAccount::setAccountName(string name) { accountName = name; }

void BankAccount::setAccountNumber(int number) { accountNumber = number; }

// Add a reward to the balance based on account balance
void BankAccount::addReward(double amount) {
  accountBalance += (REWARDS_RATE * amount);
}

// Deduct from balance and return true if resulting blance is less than
// minimum balance
bool BankAccount::withdraw(double amount) {
  // Check the minimum balance BEFORE we withdraw
  if (accountBalance < MIN_BALANCE) {
    return true;
  } else {
    accountBalance -= amount;
    return false;
  }
}

// Add amount to balance. If amount is greater than rewards amount, call
// addReward
void BankAccount::deposit(double amount) {
  accountBalance += amount;
  if (amount > REWARDS_AMOUNT) BankAccount::addReward(amount);
}

// Return account information as a string with three lines
string BankAccount::toString() {
  return "Account Name: " + accountName + '\n' + "Account Number: " +
         /* Since accountNumber and accountBalance are an int and double
         respectively, I need to convert them to a string first before using
         the concat operator or else that's a type error */
         to_string(accountNumber) + '\n' +
         "Account Balance: " + fixPrecision(to_string(accountBalance)) + '\n';
}

// Affix the decimal to 2 points of precision
string BankAccount::fixPrecision(string number) {
  // Find where the period is
  int i = number.find('.');
  // Truncate the string to just 2 digits after the decimal
  return number.substr(0, i + 3);
}

// Return the vector we're going to use
vector<shared_ptr<BankAccount>> fillVector(ifstream& input) {
  // Init the variables we need
  string firstName, lastName, accountName;
  int id, accountNumber;
  double accountBalance;
  vector<shared_ptr<BankAccount>> vec;

  // Keep looping until we hit the bottom
  while (!input.eof()) {
    // NOTE: Has potential to create infinite loop of input line is commented
    // out, don't ever forget this next line
    // Read from the fields input
    input >> firstName >> lastName >> id >> accountNumber >> accountBalance;

    // Concat the first and last name
    accountName = firstName + " " + lastName;

    // Create a shared pointer and put the info in said pointer
    shared_ptr<BankAccount> tmp = make_shared<BankAccount>(
        accountName, id, accountNumber, accountBalance);

    // Now push the pointer into the array
    vec.push_back(tmp);
  }

  // Return the array we created
  return vec;
}

void printVector(vector<shared_ptr<BankAccount>>& accountsVector) {
  cout << "FAVORITE BANK - CUSTOMER DETAILS\n"
       << "--------------------------------\n";
  int length = accountsVector.size();
  for (int i = 0; i < length; i++)
    cout << accountsVector.at(i)->toString() << '\n';
}

// Return the index of the smallest element of the array
int smallest(vector<shared_ptr<BankAccount>>& accountsVector) {
  vector<double> tmp;
  int index = 0, length = accountsVector.size();
  // Push the account balances into a temp vector
  for (int i = 0; i < length; i++)
    tmp.push_back(accountsVector.at(i)->getAccountBalance());

  // Search for the smallest balance
  for (int i = 0; i < length; i++)
    if (tmp.at(i) < tmp.at(index)) index = i;

  return index;
}

// Return the index of the largest element of the vector
int largest(vector<shared_ptr<BankAccount>>& accountsVector) {
  vector<double> tmp;
  int index = 0, length = accountsVector.size();
  // Push the account balances into a temp vector
  for (int i = 0; i < length; i++)
    tmp.push_back(accountsVector.at(i)->getAccountBalance());

  // Search for the largest balance
  for (int i = 0; i < length; i++)
    if (tmp.at(i) > tmp.at(index)) index = i;

  return index;
}

// Return true if the bank account is the same as the other, return false
// otherwise
bool BankAccount::equals(BankAccount other) {
  if (this->accountId == other.accountId)
    return true;
  else
    return false;
}

// Insert a bank account pointer at a specific location
void insertAccount(vector<shared_ptr<BankAccount>>& accountsVector) {
  // Create the shared pointers
  shared_ptr<BankAccount> account1 =
      make_shared<BankAccount>("Amy Machado", 387623, 1244, 1023.67);
  shared_ptr<BankAccount> account2 =
      make_shared<BankAccount>("Tak Phen", 981243, 1262, 6423.03);
  shared_ptr<BankAccount> account3 =
      make_shared<BankAccount>("Celia Beatle", 465281, 1276, 3.56);

  // Insert the pointers at the correct positions
  accountsVector.insert(accountsVector.begin() + 2, account1);
  accountsVector.insert(accountsVector.begin() + 4, account2);
  accountsVector.insert(accountsVector.begin() + 6, account3);
}

// Check duplicates in the vector
void checkDuplicates(vector<shared_ptr<BankAccount>>& accountsVector) {
  // Get the length of the vector
  int length = accountsVector.size();
  bool duplicates = false;
  // Loop through the vector until we get a hit
  for (int i = 0; i < length - 1; i++)
    for (int j = i + 1; j < length; j++)
      // Check if the account id is equal
      if (removeDuplicate(accountsVector.at(i), accountsVector.at(j))) {
        // Remove the duplicate entry
        accountsVector.erase(accountsVector.begin() + j);
        // Set the length again, since we removed an entry
        // NOTE: Always make sure this is here, we need to set it each iteration
        // because the loop needs to work within the correct bounds
        length = accountsVector.size();
        // This will trigger multiple times, but it doesn't matter if there's
        // one or a billion, set duplicates to true regardless
        duplicates = true;
      }
  if (duplicates) cout << "Duplicates Accounts Found: Reprinting list\n\n";
}

// Remove the duplicates
bool removeDuplicate(shared_ptr<BankAccount> account1,
                     shared_ptr<BankAccount> account2) {
  // If the two pointer account ID's match, return true, otherwise return false
  // HACK: I know the equals method is a thing, I will not be using it, this
  // is easier
  if (account1->getAccountId() == account2->getAccountId())
    return true;
  else
    return false;
}

// Number of objects created
int BankAccount::getCount() { return count; }

// Init the count variable to 0
// NOTE: MAKE SURE TO DECLARE THE VARIABLE OR ELSE YOU *WILL* GET A LINKER ERROR
int BankAccount::count = 0;
