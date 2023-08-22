#include <iostream>

#include "BankAccountHeader.h"

using std::cout;

int main() {
  // Declare and init bank accounts
  BankAccount accountZero, accountOne("Matilda Patel", 1232, -4.00),
      accountTwo("Fernando Diaz", 1234, 250.00),
      accountThree("Howard Chen", 1236, 194.56);
  // Display the bank accounts
  cout << accountZero.toString() << '\n'
       << accountOne.toString() << '\n'
       << accountTwo.toString() << '\n'
       << accountThree.toString() << '\n';
  // Deposit 999 dollars into Fernando's account and 1000.25 into Howard's
  // account
  accountTwo.deposit(999.00);
  accountThree.deposit(1000.25);
  cout << accountTwo.toString() << '\n' << accountThree.toString() << '\n';
  // Withdraw 10000 from Matilda's account and 90 from Fernando's account
  // If withdraw is not possible, display "Insufficient funds", otherwise,
  // display "Remaining Blance: " balance amount
  if (accountOne.withdraw(10000.00) == true)
    cout << "Insufficient funds\n";
  else
    cout << "Remaining balance: " << accountOne.getAccountBalance() << '\n';

  if (accountTwo.withdraw(90.00) == true)
    cout << "Insufficient funds\n";
  else
    cout << "Remaining balance: " << accountTwo.getAccountBalance() << '\n';

  // Print the total amount of all the bank accounts created
  cout << "Total amounts: "
       << accountZero.getAccountBalance() + accountOne.getAccountBalance() +
              accountTwo.getAccountBalance() + accountThree.getAccountBalance()
       << '\n';
  return 0;
}
