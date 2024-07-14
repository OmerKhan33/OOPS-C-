#include<iostream>
using namespace std;

class A
{
    public:
        // Member function: prints a message with no arguments
        void print()
        {
            cout << "Function with no arguments" << endl;
        }

        // Member function: prints a message with an integer argument
        void printt(int i)
        {
            cout << "Function with argument " << i << " is called" << endl;
        }

        // Member function: prints a message (defined within the class)
        void printtt()
        {
            cout << "Function within the class called" << endl;
        }
};

int main()
{
    // Create an object 'op' of class A
    A op;

    // Call member functions using the object
    op.print();   // Calls print()
    op.printt(4); // Calls printt(4)
    op.printtt(); // Calls printtt()

    return 0;
}
