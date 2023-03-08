#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    // create variable of type struct rectangle
    struct Rectangle r = {10,5};
    printf("%d\n", r.length);
    printf("%d\n", r.breadth);
    
    // create retangle pointer and point to r
    struct Rectangle *p = &r;
    // to access through pointer use arrow
    printf("%d\n", p->length);
    printf("%d\n", p->breadth);
    
    // create rectangle pointer and create a rectangle in heap
    struct Rectangle *p1;
    p1 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p1->length = 15;
    p1->breadth = 7;
    
    printf("%d\n", p1->length);
    printf("%d\n", p1->breadth);
    
    return 0;
}