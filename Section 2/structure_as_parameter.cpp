#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void fun_value(struct Rectangle r) // call by value
{
    cout << "Call by value:" << endl;
    r.length = 20;
    cout << "Length " << r.length << endl;
    cout << "Breadth " << r.breadth << endl;
}

void fun_address(struct Rectangle *r) // call by address
{
    cout << "Call by address:" << endl;
    r->length = 20;
    cout << "Length " << r->length << endl;
    cout << "Breadth " << r->breadth << endl;
}

struct Rectangle *fun() // creates struct rectangle object type using pointer
{
    struct Rectangle *p;
    p = new struct Rectangle; // creating object in heap
    
    p->length = 15;
    p->breadth = 7;
    
    return p;
}

int main()
{
    struct Rectangle r = {10,5};
    fun_value(r);
    
    printf("Length %d\nBreadth %d\n", r.length,r.breadth);
    
    struct Rectangle r1 = {10,5};
    fun_address(&r1);
    
    printf("Length %d\nBreadth %d\n", r1.length,r1.breadth);
    
    struct Rectangle *p = fun(); // main access fun object
    cout << endl;
    cout << "Length " << p->length << endl;
    cout << "Breadth " << p->breadth << endl;
    
    return 0;
}