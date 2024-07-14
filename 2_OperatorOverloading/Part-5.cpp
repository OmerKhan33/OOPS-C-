//Ths code demonstrates operator overloading in arrays


#include<iostream>
using namespace std;

const int SIZE = 10;

// Define a class called safearray
class safearray
{
    private:
        int arr[SIZE]; // Private array to store integer values

    public:
        // Constructor initializes the array with values from 0 to SIZE-1
        safearray()
        {
            for (int i = 0; i < SIZE; i++)
            {
                arr[i] = i;
            }
        }

        // Overload the subscript operator [] to access array elements
        int &operator[](int i)
        {
            if (i >= SIZE)
            {
                cout << "Out of Bound" << endl;
                return arr[0]; // Return the first element if index is out of bounds
            }
            return arr[i]; // Return the element at the specified index
        }
};

int main()
{
    safearray A; // Create an instance of the safearray class
    cout << "Value of A[2]: " << A[2] << endl; // Access element at index 2
    cout << "Value of A[5]: " << A[5] << endl; // Access element at index 5
    cout << "Value of A[12]: " << A[12] << endl; // Index 12 is out of bounds, so it displays a message and returns the first element

    return 0;
}
