// The following code explains the concept of static data members.
//
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    static int nextEmployeeID; // Static variable to keep track of the next employee ID
    string name; // Employee's name
    int age; // Employee's age
    static int totalEmployees; // Total number of employees

public:
    Employee()
    {
        cout << "Enter your name: ";
        getline(cin, name); // Read the employee's name
        cout << "Enter your age: ";
        cin >> age; // Read the employee's age
        cin.ignore(); // Ignore the newline character
    }

    void displayEmployee()
    {
        cout << "Employee ID: " << nextEmployeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Total Employees: " << totalEmployees << endl << "________________" << endl;
        nextEmployeeID++; // Increment the next employee ID
        totalEmployees++; // Increment the total number of employees
    }
};

int Employee::nextEmployeeID = 1; // Initialize the static variable
int Employee::totalEmployees = 1; // Initialize the total number of employees

int main()
{
    Employee e1;
    system("cls"); // Clear the console screen
    Employee e2;
    system("cls"); // Clear the console screen
    e1.displayEmployee();
    e2.displayEmployee();
}
