#include <iostream>

using namespace std;

// class
class Rectangle
{
	private:
    int length;
    int breadth;
    
	public:
	// default contructor
	// runs if rectangle object is created without arguments
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    
	// contructor with parameters
	// runs when rectangle object uses arguments
    Rectangle(int l, int b)
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
    
	// mutator/setter
    void setLength(int l)
    {
        length = l;
    }
    
	// mutator/setter
    void setBreadth(int b)
    {
        breadth = b;
    }
    
	// accessor/getter
    int getLength()
    {
        return length;
    }
    
	// accessor/getter
    int getBreadth()
    {
        return breadth;
    }
    
	// destructor
	// runs when object is destroyed
	// is usually used for deallocating memory
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
