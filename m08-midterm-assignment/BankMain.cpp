#include <cctype>
#include <iostream>
#include <string>

#include "BankHeader.h"

using std::cout, std::string, std::getline, std::cin;

char printMenu(Bank bank) {
  // Init out return value
  char option;

  // Print the menu
  cout << "\nMENU\n";
  cout << "v - View Account Balance\n";
  cout << "w - Withdraw from Account\n";
  cout << "d - Deposit into Account\n";
  cout << "a - Add an Account\n";
  cout << "r - Remove an Account\n";
  cout << "q - Quit\n\n";

  // Set option to an empty char
  option = ' ';

  // Loop to make sure we have an actual valid option
  while (option != 'd' && option != 'a' && option != 'v' && option != 'r' &&
         option != 'w' && option != 'q') {
    cout << "Choose an option: ";
    string s;
    // Get our option
    getline(cin, s, '\n');
    cin.clear();
    // Get the first char in the string
    option = s.at(0);
    // Set to lowercase in case of uppercase use
    option = tolower(option);
  }

  // Case statement to run based on our choice
  // Make sure to reset option after every statement to avoid an infinite loop
  switch (option) {
    // Remove an account
    case 'r':
      cout << "Remove Account: Coming Soon\n";
      option = ' ';
      cin.clear();
      break;
    // Deposit into an account
    case 'd':
      bank.deposit();
      option = ' ';
      cin.ignore(9999, '\n');
      break;
    // View an account balance
    case 'v':
      bank.viewBalance();
      option = ' ';
      cin.ignore(9999, '\n');
      break;
    // Withdraw money provided that min balance is maintained and if funds are
    // sufficient
    case 'w':
      bank.withdraw();
      option = ' ';
      cin.ignore(9999, '\n');
      break;
    // Add an account
    case 'a':
      cout << "Add Account: Coming Soon\n";
      break;
    // Quit the ATM application
    case 'q':
      cout << "Good Bye!\n";
      break;
    // If we don't get a valid case, just reset
    default:
      option = ' ';
      cin.ignore(9999, '\n');
      break;
  }
  return option;
}

int main() {
  // Init an instance of Bank and load BankData.txt to create the bank account
  Bank bank("BankData.txt");

  // Get our option for our selection
  char option = printMenu(bank);

  // Keep looping as long as we don't get the quit instruction
  while (option != 'q') option = printMenu(bank);

  return 0;
}
