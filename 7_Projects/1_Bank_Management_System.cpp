/*
The following code demostrates some of the concepts of Object Oriented Programing
The code demonstrates a bank management system.
*/

#include <iostream>
#include <string>
using namespace std;

// Base class for BankAccount
class BankAccount 
{
    protected:
        string accountNumber;
        double balance;

    public:
        // Constructor
        BankAccount(const string& accNum, double initialBalance)
            : accountNumber(accNum), balance(initialBalance) {}

        // Virtual functions for deposit and withdraw
        virtual void deposit(double amount) 
        {
            balance += amount;
        }

        virtual void withdraw(double amount) 
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

        // Virtual function to display account details
        virtual void display() const 
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
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

    // Derived class for SavingsAccount
    class SavingsAccount : public BankAccount 
    {
    public:
        SavingsAccount(const string& accNum, double initialBalance)
            : BankAccount(accNum, initialBalance) {}

        void deposit(double amount) override 
        {
            // Apply interest rate for savings account
            balance += amount * 1.02; // Example: 2% interest
        }

        void display() const override 
        {
            cout << "Savings Account - ";
            BankAccount::display();
        }
};

// Derived class for CheckingAccount
class CheckingAccount : public BankAccount 
{
public:
    CheckingAccount(const string& accNum, double initialBalance)
        : BankAccount(accNum, initialBalance) {}

    void withdraw(double amount) override 
    {
        // Apply transaction fee for checking account
        const double transactionFee = 1.0; // Example: $1 fee
        if (balance >= amount + transactionFee) 
        {
            balance -= (amount + transactionFee);
        } 
        else 
        {
            cout << "Insufficient balance. Cannot withdraw." << endl;
        }
    }

    void display() const override 
    {
        cout << "Checking Account - ";
        BankAccount::display();
    }
};

// Friend function definition
void displayAccountDetails(const BankAccount& acc) 
{
    acc.display();
}

int main() 
{
    // Create savings and checking accounts
    SavingsAccount savings("SA123", 1000.0);
    CheckingAccount checking("CA456", 2000.0);

    // Deposit and withdraw
    savings.deposit(500.0);
    checking.withdraw(300.0);

    // Display account details
    displayAccountDetails(savings);
    displayAccountDetails(checking);

    // Combine balances using operator overloading
    BankAccount combined = savings + checking;
    cout << "Combined Balance: $" << combined.getBalance() << endl;

    return 0;
}
