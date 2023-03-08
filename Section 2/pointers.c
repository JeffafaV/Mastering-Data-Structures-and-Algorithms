#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    int a = 10;
    int *p; // initializing
    p = &a; // declaring
    
    printf("%d\n", a);
    printf("%d\n", *p);
	// printf("Using pointer %d %d\n", p, &a); // produces warning due to type
    printf("Using pointer %p %p\n\n", p, &a); // both print the address of a
    
    // array in stack (predefined allocation)
    int B[5] = {2,4,6,8,10};
    int *p1;
    p1 = B;
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", B[i]);
    }
    
    printf("\n");
    
    // can use pointer to loop through array
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", p1[i]);
    }
    
    printf("\n");
    
    int *p2;
    // array in heap (runtime allocation)
    p2 = (int*)malloc(5*sizeof(int));
    // initializing
    p2[0] = 10;
    p2[1] = 15;
    p2[2] = 14;
    p2[3] = 21;
    p2[4] = 31;
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", p2[i]);
    }
    printf("\n");
    // delete array in heap
    free(p2);
    
    // create pointers of different types
    int *p3;
    char *p4;
    float *p5;
    double *p6;
    struct Rectangle *p7;
    
    // whatever the data type of a pointer it will always have the same amount of memory
    printf("%ld\n", sizeof(p3));
    printf("%ld\n", sizeof(p4));
    printf("%ld\n", sizeof(p5));
    printf("%ld\n", sizeof(p6));
    printf("%ld\n", sizeof(p7));
    
    return 0;
}