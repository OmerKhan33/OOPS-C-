#include <iostream>
using namespace std;

class Sum
{
    private:
        int x, y, z; // Private data members for encapsulation
    
    public:
        void add()
        {
            cout << "Enter two numbers to be added: ";
            cin >> x;
            cin >> y;
            z = x + y; // Perform the addition
            cout << "The sum is = " << z;
        }
        // Other public methods can be added here for further abstraction
};

int main()
{
    Sum ad; // Create an instance of the Sum class
    ad.add(); // Call the add method
}
