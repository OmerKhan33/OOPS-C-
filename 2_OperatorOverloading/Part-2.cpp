//This code demonstrates the concept prefix and postfix operator overloading

#include<iostream>
using namespace std;

// Define a class called Count
class Count
{
    private:
        int count; // Private member variable to store the count

    public:
        // Default constructor initializes count to 0
        Count()
        {
            count = 0;
        }

        // Parameterized constructor allows setting an initial count value
        Count(int c)
        {
            count = c;
        }

        // Getter method to retrieve the current count value
        int getCount()
        {
            return count;
        }

        // Overload the prefix increment operator (++count)
        Count operator ++()
        {
            Count temp;
            temp.count = ++count;
            return temp;
        }

        // Overload the postfix increment operator (count++)
        Count operator++(int)
        {
            return Count(count++);
        }
};

int main()
{
    Count c1, c2; // Create two Count objects
    cout << "\nc1=" << c1.getCount();
    cout << "\nc2=" << c2.getCount();

    ++c1; // Increment c1 using the prefix increment operator (c1=1)
    c2 = ++c1; // Increment c1 and assign to c2 (prefix increment, c1=2, c2=2)
    cout << "\nc1=" << c1.getCount();
    cout << "\nc2=" << c2.getCount();

    c2 = c1++; // Assign c1 to c2 and then increment c1 (postfix increment, c1=3, c2=2)
    cout << "\nc1=" << c1.getCount();
    cout << "\nc2=" << c2.getCount();

    return 0;
}
