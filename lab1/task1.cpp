#include <iostream>
using namespace std;

class BankAccount {
    public:
        int balance;
   
    BankAccount() : balance(0) {}
    BankAccount(int b) : balance(b) {}

    void printBalance() {
        cout << balance << endl;
    }

    void withdraw(int amount) {
        if(amount > balance) {
            cout << "Invalid balance" << endl;
        } else {
            balance -= amount;
            cout << "Withdraw Successful" << endl;
            cout << "New Balance: " << balance << endl;
        }
    }
};

int main() {
    BankAccount account1;
    BankAccount account2(1000);
    BankAccount account3 = account2;

    cout << "Account 1 balance: ";
    account1.printBalance();

    cout << "Account 2 balance: ";
    account2.printBalance();

    cout << "Account 3 balance: ";
    account3.printBalance();

    cout << "Account 3: ";
    account3.withdraw(100);

    cout << "Account 3 balance: ";
    account3.printBalance();

    cout << "Account 2 balance: ";
    account2.printBalance();

    return 0;
}
