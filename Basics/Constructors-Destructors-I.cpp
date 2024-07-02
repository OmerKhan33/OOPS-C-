// The following program covers the concepts of Connstructors and Destructors

#include<iostream>
using namespace std;

class ABC
{
    public:
        int length;
        int height;

        // Parameterized constructor
        ABC(int x, int y)
        {
            length = x;
            height = y;
        }

        // Default constructor (no parameters)
        ABC()
        {
            cout << "Constructor called" << endl;
        }

        // Destructor (called when an object is destroyed)
        ~ABC()
        {
            cout << "Object deleted" << endl;
        }
};

int main()
{
    // Create an object 'op' using the parameterized constructor
    ABC op(10, 20);
    cout << "Length is: " << op.length << endl;
    cout << "Height is: " << op.height << endl;

    // Create an object 'op1' using the default constructor
    ABC op1;

    // Note: The destructor for 'op1' will be called when it goes out of scope

    return 0;
}
