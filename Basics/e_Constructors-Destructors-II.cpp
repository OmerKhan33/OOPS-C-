//The following program uses dynamic arrays as well as constructors and destructors are also used.


#include<iostream>
using namespace std;

class Arrays
{
    private:
        int* arr1 = new int[10]; // Dynamic array for the first set of data
        int* arr2 = new int[10]; // Dynamic array for the second set of data

    public:
        // Parameterized constructor: Initializes arr1 and arr2 with given data
        Arrays(int obj1[10], int obj2[10])
        {
            for(int i = 0; i < 10; i++)
            {
                arr1[i] = obj1[i];
                arr2[i] = obj2[i];
            }
        }

        // Copy constructor: Creates a new object by copying data from another object
        Arrays(const Arrays &a2)
        {
            for(int i = 0; i < 10; i++)
            {
                arr1[i] = a2.arr1[i];
                arr2[i] = a2.arr2[i];
            }
        }

        // Method to calculate and print the sum of elements in both arrays
        void sum()
        {
            double s1 = 0, s2 = 0;
            for(int i = 0; i < 10; i++)
            {
                s1 += arr1[i];
                s2 += arr2[i];
            }
            cout << "The sum of the first array is: " << s1 << endl;
            cout << "The sum of the second array is: " << s2 << endl;
        }

        // Destructor: Releases memory allocated for dynamic arrays
        ~Arrays()
        {
            delete[] arr1;
            delete[] arr2;
            cout << "\nDestructor called";
        }
};

int main()
{
    int obj1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int obj2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Create an object A1 using the parameterized constructor
    Arrays A1(obj1, obj2);
    A1.sum();

    // Create an object A2 using the copy constructor (based on A1)
    Arrays A2(A1);
    A2.sum();

    return 0;
}
