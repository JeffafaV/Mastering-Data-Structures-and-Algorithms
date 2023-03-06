#include <iostream>

using namespace std;

// converted struct to class
class Rectangle
{
private:
    int length;
    int breadth;
    
public:
    // sets values to whatever user inputs
    void initialize(int l, int b) // doesn't need a class parameter
    {
        length = l; // functions can directly access length and breadth
        breadth = b;
    }

    int area() // returns area
    {
        return length * breadth;
    }

    int perimeter() // returns parameter
    {
        int p;
        p = 2 * (length + breadth);
    
        return p;
    }
};

// modular programming (uses functions)
int main()
{
    Rectangle r = Rectangle(); // creates class object
    
    int l;
    int b;
    
    printf("Enter length and breadth\n");
    cin >> l >> b;
    
    r.initialize(l, b); // call by value
    
    int a = r.area();
    int p = r.perimeter();
    
    printf("Area = %d\nPerimeter = %d\n", a, p);
    
    return 0;
}
