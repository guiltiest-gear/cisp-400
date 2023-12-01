#include <iostream>
#include <memory>

#include "Bank.h"

using std::shared_ptr, std::make_shared, std::cout, std::cin, std::string;

int main() {
  shared_ptr<UserAccount> newAcc =
      make_shared<CheckingAccount>("John Smith", 9999, 1420, 154.67);
  shared_ptr<UserAccount> remove =
      make_shared<CheckingAccount>("Fernando Diaz", 323468, 1234, 250.0);
  shared_ptr<UserAccount> temp =
      make_shared<SavingsAccount>("Lily Zhaou", 786534, 1242, 001.98);
  // temp->withdraw(100);
  shared_ptr<UserAccount> temp2 =
      make_shared<CheckingAccount>("Vai Vu", 432657, 1240, 987.56);
  shared_ptr<UserAccount> temp3 =
      make_shared<CheckingAccount>("Sugata Misra", 987654, 1238, 10004.80);
  string filename;
  int action;
  cout << "What is the file name? ";
  cin >> filename;            // Bankdata.txt
  Bank WellsFargo(filename);  // test action 1 : incorrect file name
  WellsFargo.sortAccounts();
  WellsFargo.displayAccounts();

  for (int i = 2; i <= 10; i++) {
    // a total of 9 tests from test 2 through test 10
    cout << "Which action would you like to test? ";
    cin >> action;
    if (action == 2) {  // add a new account
      string accountName;
      WellsFargo.displayAccounts();
      WellsFargo.addAccount(newAcc);
      cout << "***** Adding New Account *****\n";
      // WellsFargo.displayAccount(temp);
      cout << newAcc->toString() << '\n';
      cout << "***** Displaying Resulting Sorted Database *****\n";
      WellsFargo.sortAccounts();
      WellsFargo.displayAccounts();
    } else if (action == 3) {  // remove and display
      WellsFargo.displayAccounts();
      WellsFargo.removeAccount(remove);
      cout << "***** Removing Account *****\n";
      // WellsFargo.displayAccount(temp);
      cout << remove->toString() << '\n';
      cout << "***** Displaying Resulting Sorted Database *****\n";
      WellsFargo.displayAccounts();
      if (WellsFargo.removeAccount(remove))
        cout << "***** Account Does not Exist *****\n";
    } else if (action == 4) {  // backing up accounts
      Bank Backup(WellsFargo);
      WellsFargo.displayAccounts();
      if (Backup.checkSame(WellsFargo))
        cout << "Verified Backup\n";  // verifying that they are same;
      else
        cout << "Backup Error\n";
    } else if (action == 5) {  // back up and remove account from original
      Bank Backup(WellsFargo);
      WellsFargo.displayAccounts();
      WellsFargo.removeAccount(temp2);
      if (Backup.checkSame(WellsFargo))
        cout << "Verified Backup\n";  // verifying that they are same;
      else
        cout << "Backup Error Databases do not match\n";
    } else if (action == 6) {  // withdraw money from CheckingAccount
      WellsFargo.addAccount(temp2);
      WellsFargo.displayAccounts();
      if (WellsFargo.accountWithdraw(temp2, 20))
        cout << "Withdraw Successful for this amount 20$\n";
      else
        cout << "Withdraw Unsuccessful for this amount 20$\n";
      // WellsFargo.displayAccounts(temp2);
      cout << temp2->toString() << '\n';
      if (WellsFargo.accountWithdraw(temp2, -20))
        cout << "Withdraw Successful for this amount -20$\n";
      else
        cout << "Withdraw Unsuccessful for this amount -20$\n";
      // WellsFargo.displayAccounts(temp2);
      cout << temp2->toString() << '\n';
    } else if (action == 7) {  // action 7 try to withdraw more money from
                               // CheckingAccount to check min balance
      WellsFargo.displayAccounts();
      if (WellsFargo.accountWithdraw(temp3, 10000.00))
        cout << "Withdraw Successful for this amount 100$\n";
      else
        cout << "Withdraw Unsuccessful for this amount - Minimum funds 99.99\n";
      // WellsFargo.displayAccounts(temp);
      cout << temp->toString() << '\n';
      if (WellsFargo.accountWithdraw(temp3, 5000))
        cout << "Withdraw Successful for this amount 5000$\n";
      else
        cout << "Withdraw Unsuccessful - Insufficient funds for this amount "
                "5000$\n";
      cout << temp3->toString() << '\n';
      // WellsFargo.displayAccounts(temp);
    } else if (action == 8) {  // withdraw money from savings account
      WellsFargo.displayAccounts();
      WellsFargo.accountWithdraw(temp, 20);
      if (WellsFargo.accountWithdraw(temp, 20))
        cout << "Withdraw Successful\n";
      else
        cout
            << "Withdraw Unsuccessful - Cannot Withdraw from Savings Account\n";
      // WellsFargo.displayAccounts(temp);
      cout << temp->toString() << '\n';
    } else if (action == 9) {  // deposit money into savings
      WellsFargo.displayAccounts();
      if (WellsFargo.accountDeposit(temp, 1001))
        cout << "Deposit Successful for $1001 - rewards added\n";
      cout << temp->toString() << '\n';
      // WellsFargo.displayAccounts(temp);
      if (WellsFargo.accountDeposit(temp, 20))
        cout << "Deposit Successful for $20\n";
      cout << temp->toString() << '\n';
      // WellsFargo.displayAccount(temp);
    } else if (action == 10) {  // deposit money into checking
      WellsFargo.displayAccounts();
      if (WellsFargo.accountDeposit(temp, -20))
        cout << "Deposit Successful\n";
      else
        cout << "Deposit Unsuccessful - Negative Amount: -$20\n";
      if (WellsFargo.accountDeposit(temp, 20))
        cout << "Deposit Successful for $20\n";
      else
        cout << "Deposit Unsuccessful\n";
    } else {
      cout << "Testing Ends\n";
    }
  }
}
