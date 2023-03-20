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
	// substitutes constructor
    void initialize(int l, int b)
    {
		// functions can directly access length and breadth
        length = l;
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
    
	cout << "Enter length and breadth" << endl;
    cin >> l >> b;
    
    r.initialize(l, b); // call by value
    
    int a = r.area();
    int p = r.perimeter();
    
	cout << "Area = " << a << endl;
	cout << "Perimeter = " << p << endl;
    
    return 0;
}
