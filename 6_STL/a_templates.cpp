// Templates are a feature of the C++ programming language that allows functions and classes to 
// operate with generic types. This allows a function or class to work on many different data types 
// without being rewritten for each one.

#include <iostream> 
using namespace std ; 
// creating a generic function ‘swap (parameter-list)’ using template : 

template <class X>  
void my_swap(X &a, X &b) //dont use swap as name of function as it will generate error in main function.
{ 
    X tp; 
    tp = a; 
    a = b; 
    b = tp; 
    cout << " Swapped elements values of a and b are  " << a << " and  " << b << " respectively " << endl; 
} 
int main( ) 
{ 
    int a = 10, b = 20 ; 
    float c = 10.5, d = 20.5 ; 
    my_swap(a, b);     // function swapping ‘int’ elements  
    my_swap(c , d);     // function swapping ‘float’ elements  
    return 0; 
}