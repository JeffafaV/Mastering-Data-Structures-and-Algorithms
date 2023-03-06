#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {10,5};
    cout << r.length << endl;
    cout << r.breadth << endl;
    
    struct Rectangle *p = &r;
    cout << p->length << endl; // to access through pointer you use arrow
    cout << p->breadth << endl;
    
    struct Rectangle *p1;
    p1 = new struct Rectangle;
    p1->length = 15;
    p1->breadth = 7;
    
    cout << p1->length << endl;
    cout << p1->breadth << endl;
    
    return 0;
}