// The following code demonstrates the concept of Early Binding and Late Binding
#include <iostream>
using namespace std;

// Base class (parent)
class Shape 
{
public:
    // Virtual function for drawing a shape
    virtual void draw() 
    {
        cout << "Drawing a shape." << endl;
    }
};

// Derived class (child)
class Circle : public Shape 
{
public:
    // Overrides the base class function to draw a circle
    void draw() override 
    {
        cout << "Drawing a circle." << endl;
    }
};

int main() 
{
    // Early binding (static binding):
    // The compiler knows which function to call based on the pointer type (Shape*).
    // Calls the overridden function in Circle.
    Shape* shapePtr = new Circle;
    shapePtr->draw();

    // Late binding (run-time polymorphism):
    // The actual function called depends on the object's runtime type (Circle).
    // Achieved through virtual functions.
    Shape* anotherShapePtr = new Circle;
    anotherShapePtr->draw();

    delete shapePtr;
    delete anotherShapePtr;

    return 0;
}
