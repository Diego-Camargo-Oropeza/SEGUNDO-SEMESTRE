#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Bank_Account
{
private:
    int acc_num;
    string name;
    double balance;

public:
    Bank_Account()
    {
        cout << "Enter account number: ";
        cin >> acc_num;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter account holder's name: ";
        getline(cin, name);

        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "A deposit of $" << amount << " has been made.\n";
    }

    void withdrawal(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "A withdrawal of $" << amount << " has been made.\n";
        }
        else
        {
            cout << "Insufficient balance to complete the transaction.\n";
        }
    }

    void check_balance()
    {
        cout << "Current balance: $" << balance << endl;
    }
};

int main()
{
    Bank_Account myAccount;
    myAccount.deposit(100.0);
    myAccount.check_balance();
    myAccount.withdrawal(50.0);
    myAccount.check_balance();

    return 0;
}
