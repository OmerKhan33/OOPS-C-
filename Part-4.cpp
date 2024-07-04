//This code demonstrates the concept of istream and ostream operator overloading

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
            f = i; // This line should be corrected to set the member variables correctly
        }

        // Overload the output stream operator (<<) to display the distance
        friend ostream &operator<<(ostream &output, const Distance &D)
        {
            cout << "F: " << D.feet << " I: " << D.inch << endl;
            return output;
        }

        // Overload the input stream operator (>>) to read the distance
        friend istream &operator>>(istream &input, Distance &D)
        {
            input >> D.feet >> D.inch;
            return input;
        }
};

int main()
{
    Distance D1(11, 10), D2(5, 11), D3;
    cout << "Enter the value of object : " << endl;
    cin >> D3; // Read the distance from user input
    cout << "First Distance : " << D1 << endl; // Display D1
    cout << "Second Distance : " << D2 << endl; // Display D2
    cout << "Third Distance : " << D3 << endl; // Display D3
    return 0;
}
