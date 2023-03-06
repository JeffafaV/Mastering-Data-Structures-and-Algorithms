#include <iostream>

using namespace std;

// class
class Rectangle
{
private:
    int length;
    int breadth;
    
public:
    Rectangle() // default contructor
    {
        length = 0;
        breadth = 0;
    }
    
    Rectangle(int l, int b) // contructor with parameters
    {
        length = l; // set variable in class to parameter
        breadth = b;
    }
    
    int area() // returning area
    {
        return length * breadth;
    }
    
    int perimeter() // returning parameter
    {
        return 2 * (length + breadth);
    }
    
    void setLength(int l) // mutator
    {
        length = l;
    }
    
    void setBreadth(int b) // setter
    {
        breadth = b;
    }
    
    int getLength() // accessor
    {
        return length;
    }
    
    int getBreadth() // getter
    {
        return breadth;
    }
    
    ~Rectangle()
    {
        cout << "Destructor";
    }
};

// modular programming (uses functions)
int main()
{
    Rectangle r = Rectangle(10,5);
    
    cout << "Area " << r.area() << endl;
    cout << "Perimeter " << r.perimeter() << endl;
    
    return 0;
}
