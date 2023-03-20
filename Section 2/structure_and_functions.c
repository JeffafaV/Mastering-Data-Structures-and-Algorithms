#include <stdio.h>

// using struct in functions
struct Rectangle
{
    int length;
    int breadth;
};

// initialize length and breadth
// we are changing values of rectangle so we need a pointer
void initialize(struct Rectangle *r, int l, int b)
{
    r->length = l; // pointers use arrow
    r->breadth = b;
}

// struct as parameter
// we are not changing values in rectangle so no pointer is necessary
int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

// struct as parameter
// we are not changing values in rectangle so no pointer is necessary
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
    scanf("%d %d", &l, &b);
    
    initialize(&r, l, b); // call by value and address
    
    int a = area(r);
    int p = perimeter(r);
    
    printf("Area = %d\nPerimeter = %d\n", a, p);
    
    return 0;
}
