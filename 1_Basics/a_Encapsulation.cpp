#include <iostream>
using namespace std;

class Add
{
    public:
        // Constructor initializes the 'total' attribute
        Add(int i = 0)
        {
            total = i;
        }

        // Method to add a number to the 'total'
        void addnum(int number)
        {
            total += number;
        }

        // Method to retrieve the current 'total'
        int getTotal()
        {
            return total;
        }

    private:
        int total; // Private data member encapsulates the 'total'
};

int main()
{
    Add a; // Create an instance of the Add class
    a.addnum(10);
    a.addnum(20);
    cout << "The total is: " << a.getTotal() << endl;
    return 0;
}
