// bank management system

#include <iostream>
#include <string>
using namespace std;

// Class to represent a bank account
class BankAccount 
{
    private:
        string accountNumber;
        double balance;

    public:
        // Constructor
        BankAccount(const string& accNum, double initialBalance) 
        {
            accountNumber = accNum;
            balance = initialBalance;
        }

        // Member function to deposit funds
        void deposit(double amount) 
        {
            balance += amount;
        }

        // Member function to withdraw funds
        void withdraw(double amount) 
        {
            if (balance >= amount) 
            {
                balance -= amount;
            }
            else 
            {
                cout << "Insufficient balance. Cannot withdraw." << endl;
            }
        }

        // Getter for account balance
        double getBalance() const 
        {
            return balance;
        }

        // Overloaded + operator to add balances of two accounts
        BankAccount operator+(const BankAccount& other) 
        {
            BankAccount result("Combined", balance + other.balance);
            return result;
        }

        // Friend function to display account details
        friend void displayAccountDetails(const BankAccount& acc);
};

// Friend function definition
void displayAccountDetails(const BankAccount& acc) 
{
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Balance: $" << acc.balance << endl;
}

int main() 
{
    // Create two bank accounts
    BankAccount acc1("12345", 1000.0);
    BankAccount acc2("67890", 2000.0);

    // Deposit and withdraw
    acc1.deposit(500.0);
    acc2.withdraw(300.0);

    // Display account details
    displayAccountDetails(acc1);
    displayAccountDetails(acc2);

    // Combine balances using operator overloading
    BankAccount combined = acc1 + acc2;
    cout << "Combined Balance: $" << combined.getBalance() << endl;

    return 0;
}
