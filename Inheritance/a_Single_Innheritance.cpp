//The following code is an example of Single Inheritance.
//There is a single parent and a single child inherits its attributes from the the parent.

#include <iostream>
using namespace std;

// Base class: Parent
class Parent 
{
public:
    int id_p; // Public data member in the base class

    void printID_p() 
    {
        cout << "Base ID: " << id_p << endl;
    }
};

// Derived class: Child (publicly inherited from Parent)
class Child : public Parent 
{
public:
    int id_c; // Additional data member in the derived class

    void printID_c() 
    {
        cout << "Child ID: " << id_c << endl;
    }
};

int main() 
{
    Child obj1; // Create an object of the Child class
    obj1.id_p = 7; // Access the public data member from the base class
    obj1.printID_p(); // Call the base class method
    obj1.id_c = 91; // Set the derived class data member
    obj1.printID_c(); // Call the derived class method

    return 0;
}
