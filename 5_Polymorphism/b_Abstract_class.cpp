// The followng code demonstrates the concept of Abstract class  (Pure virtual function)

#include<iostream>
using namespace std;

//Abstract base class 
class Base           
{ 
    public: 
    virtual void show() = 0;    // Pure Virtual Function 
}; 
class Derived:public Base 
{ 
    public: 
        void show() 
        {  
            cout << "Implementation of Virtual Function in Derived class\n";  
        } 

 
}; 
 
int main() 
{ 
    //Base obj;   //Compile Time Error if you uncomment this line of code
    Base *b; 
    Derived d; 
    b = &d; 
    b->show(); 
} 
// In the above example Base class is abstract, with pure virtual show() function, hence we cannot 
// create object of base class. One important thing to note is that, you should override the pure 
// virtual function of the base class in the derived class. If you fail the override it, the derived class 
// will become an abstract class as well. 