//This Example tends to explain the types of constructors.


#include<iostream>
using namespace std;

class Area
{
    private:
        double length;
        double width;
    public:
        // Default constructor: initializes length to 20 and width to 15
        Area()
        {
            length = 20;
            width = 15;
        } 

        // Copy constructor: creates a new object with modified dimensions
        Area(const Area &A2)
        {
            length = A2.length + 5; // Increase length by 5
            width = A2.width + 5;   // Increase width by 5
        }

        // Parameterized constructor with integer arguments
        Area(int l, int w)
        {
            length = l;
            width = w;
        }

        // Parameterized constructor with double arguments
        Area(double l, double w)
        {
            length = l;
            width = w;
        }

        // Calculate the area (length * width)
        double Calculate()
        {
            return length * width;
        }
};

int main()
{
    // Create an object A1 using the default constructor
    Area A1;
    cout << "The area is: " << A1.Calculate() << endl;

    // Create an object A2 using the copy constructor (based on A1)
    Area A2 = A1;
    cout << "The area is: " << A2.Calculate() << endl;

    // Create an object A3 using the integer parameterized constructor
    Area A3(2, 3);
    cout << "The area is: " << A3.Calculate() << endl;

    // Create an object A4 using the double parameterized constructor
    Area A4(2.55, 2.33);
    cout << "The area is: " << A4.Calculate();

    return 0;
}
