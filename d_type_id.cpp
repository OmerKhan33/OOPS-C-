// typeid 
#include <iostream> // Include the I/O stream library for input and output operations
#include <typeinfo> // Include the type info library for using typeid
using namespace std; // Use the standard namespace to avoid prefixing std::

int main () 
{ 
    int *a, b; // Declare a pointer to an int 'a' and an int 'b'
    a = 0; // Initialize the pointer 'a' to null (0)
    b = 0; // Initialize the integer 'b' to 0

    // Check if the type of 'a' is different from the type of 'b'
    if (typeid(a) != typeid(b)) 
    { 
        // If they are of different types, output their types
        cout << "a and b are of different types:\n"; 
        cout << "a is: " << typeid(a).name() << '\n'; // Output the type of 'a'
        cout << "b is: " << typeid(b).name() << '\n'; // Output the type of 'b'
    } 

    return 0; // Return 0 to signal successful completion
}
