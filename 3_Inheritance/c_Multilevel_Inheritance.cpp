//The following demonstrates Multilevel Inheritance.
//There is a grandparent from which parent inherits and the child inherits from the parent.

#include <iostream>
using namespace std;

// Base class: Animal
class Animal 
{
public:
    void eat() 
    {
        cout << "Animal eating." << std::endl;
    }
};

// Derived class: Mammal (inherits from Animal)
class Mammal : public Animal 
{
public:
    void sleep() 
    {
        cout << "Mammal sleeping." << std::endl;
    }
};

// Derived class: Human (inherits from Mammal)
class Human : public Mammal 
{
public:
    void talk() 
    {
        cout << "Human talking." << std::endl;
    }
};

int main() 
{
    Human person;
    person.eat(); // Call base class method
    person.sleep(); // Call derived class method
    person.talk(); // Call further derived class method

    return 0;
}
