#include <iostream>  
#include <string>
using namespace std; 
  
class Shape 
{ 
   protected: 
      int width, height; 
       
   public: 
      Shape( int a = 0, int b = 0)
      { 
        width = a; 
        height = b; 
      } 
 
       //pure virtual function 
    virtual int area() =0;  
}; 

class Rectangle: public Shape 
{ 
    public: 
        Rectangle( int a = 0, int b = 0):Shape(a, b) {} 
        int area () 
        {  
            cout << "Rectangle class area :" <<endl; 
            return (width * height);  
        } 
}; 
class Triangle: public Shape 
{ 
public: 
    Triangle( int a = 0, int b = 0):Shape(a, b) {} 
    int area () 
    {  
        cout << "Triangle class area :" <<endl; 
        return (width * height / 2);  
    } 
}; 
// Main function for the program 
int main() 
{ 
    Shape *shape; 
    Rectangle rec(10,7); 
    Triangle  tri(10,5); 
    // store the address of Rectangle 
    shape = &rec; 
    // call rectangle area. 
    shape->area(); 
    // store the address of Triangle 
    shape = &tri; 
    // call triangle area. 
    shape->area(); 
    return 0; 
} 
/*
When we create a pure virtual function in Abstract class, we reserve a slot for a function in the 
VTABLE(studied in last topic), but doesn't put any address in that slot. Hence the VTABLE will 
be incomplete. 
As the VTABLE for Abstract class is incomplete, hence the compiler will not let the creation of 
object for such class and will display an error message whenever you try to do so
*/