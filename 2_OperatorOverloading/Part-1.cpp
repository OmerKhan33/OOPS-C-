//In the following code the addition of two complex numbers is performed
//through operator overloading

#include<iostream>
using namespace std;

// Define a Complex class
class Complex
{
    private:
        int real; // Real part of the complex number
        int imag; // Imaginary part of the complex number

    public:
        // Constructor with default values for real and imaginary parts
        Complex(int r = 0, int i = 0)
        {
            real = r;
            imag = i;
        }

        // Overload the + operator to add two complex numbers
        Complex operator + (Complex const &obj)
        {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }

        // Display the complex number in the format "real + imagi"
        void print()
        {
            cout << real << "+" << imag << "i" << endl;
        }
};

int main()
{
    // Create two Complex objects
    Complex c1(12, 11), c2(23, 2);

    // Add c1 and c2 using the overloaded + operator
    Complex c3 = c1 + c2;

    // Display the result
    c3.print();

    return 0;
}
