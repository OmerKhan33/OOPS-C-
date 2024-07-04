// This codes demonstrated the bool operator overloading

#include<iostream>
using namespace std;

// Define a class called Distance
class Distance
{
    private:
        int feet; // Private member variable for feet
        int inch; // Private member variable for inches

    public:
        // Default constructor initializes feet and inches to 0
        Distance()
        {
            feet = 0;
            inch = 0;
        }

        // Parameterized constructor allows setting initial feet and inches
        Distance(int f, int i)
        {
            feet = f;
            inch = i;
        }

        // Display the distance (feet and inches)
        void show()
        {
            cout << "F: " << feet << " I: " << inch << endl;
        }

        // Overload the less than operator (<) to compare distances
        bool operator < (Distance const &obj)
        {
            if (feet < obj.feet)
            {
                return true;
            }
            if (feet == obj.feet && inch < obj.inch)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    // Create two Distance objects
    Distance D1(11, 10), D2(5, 11);

    // Compare D1 and D2 using the overloaded < operator
    if (D1 < D2)
    {
        cout << "D1 is less than D2" << endl;
    }
    else
    {
        cout << "D2 is less than D1" << endl;
    }

    return 0;
}
