//This code explains the concept of Friend Functions

#include <iostream>
using namespace std;

// Forward declaration of the Square class
class Square;

// Rectangle class definition
class Rectangle 
{
    int width, height;

public:
    // Constructor with default values for width and height
    Rectangle(int w = 1, int h = 1): width(w), height(h) {} 

    // Display the area of the rectangle
    void display() 
    {
        cout << "Rectangle: " << width * height << endl;
    }

    // Morph the rectangle into a square
    void morph(Square &);
};

// Square class definition
class Square 
{
    int side;

public:
    // Constructor with default value for side
    Square(int s = 1): side(s) {} 

    // Display the area of the square
    void display() 
    {
        cout << "Square: " << side * side << endl;
    }

    // Declare Rectangle as a friend class to access its private members
    friend class Rectangle;
};

// Implementation of the morph function (defined outside the class)
void Rectangle::morph(Square &s) 
{
    width = s.side;
    height = s.side;
}

int main() 
{
    // Create a Rectangle object with width 5 and height 10
    Rectangle rec(5, 10);

    // Create a Square object with side length 5
    Square sq(5);

    cout << "Before:" << endl;
    rec.display(); // Display the area of the rectangle
    sq.display(); // Display the area of the square

    // Morph the rectangle into a square
    rec.morph(sq);

    cout << "\nAfter:" << endl;
    rec.display(); // Display the updated area of the rectangle
    sq.display(); // Display the area of the square (unchanged)

    return 0;
}
