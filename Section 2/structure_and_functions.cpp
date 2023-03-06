#include <iostream>

using namespace std;

// using struct in functions
struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b) // initialize length and breadth
{
    r->length = l; // pointers use arrow
    r->breadth = b;
}

int area(struct Rectangle r) // struct as parameter
{
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r)
{
    int p;
    p = 2 * (r.length + r.breadth);
    
    return p;
}
// modular programming (uses functions)
int main()
{
    struct Rectangle r = {0,0};
    
    int l;
    int b;
    
    printf("Enter length and breadth\n");
    cin >> l >> b;
    
    initialize(&r, l, b); // call by value and address
    
    int a = area(r);
    int p = perimeter(r);
    
    printf("Area = %d\nPerimeter = %d\n", a, p);
    
    return 0;
}
