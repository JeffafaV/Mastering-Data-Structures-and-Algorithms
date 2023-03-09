#include <stdio.h>
#include <stdlib.h>

// structure that holds two variables
struct Rectangle
{
    int length;
    int breadth;
};

 // call by value (creates copy and doesn't change arguments)
void fun_value(struct Rectangle r)
{
    printf("Call by value:\n");
    
    r.length = 20;
    printf("Length %d\n", r.length);
    printf("Breadth %d\n", r.breadth);
}

 // call by address (changes the values of the arguments)
void fun_address(struct Rectangle *r)
{
    printf("Call by address:\n");
    
    r->length = 20;
    printf("Length %d\n", r->length);
    printf("Breadth %d\n", r->breadth);
}

 // creates struct rectangle object type in heap using pointer
struct Rectangle* fun()
{
    struct Rectangle *p;
    // creating object in heap
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    
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
    
    // p points to rectangle object created in the function
    struct Rectangle *p = fun();
    printf("\n");
    printf("Length %d\n", p->length);
    printf("Breadth %d\n", p->breadth);
    
    return 0;
}