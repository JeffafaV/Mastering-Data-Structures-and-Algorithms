#include <stdio.h>

int main()
{
    // just declaring
    int A[5];
    // initializing three indexes
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;
    
    // total amount of bytes in array: 5 * 4 bytes
    printf("%ld\n", sizeof(A));
    // prints initialized values
    printf("%d\n", A[1]);
    printf("%d\n\n", A[2]);
    
    // declaring and initializing
    int B[5] = {2, 4, 6, 8, 10};
    
    // total amount of bytes in array: 5 * 4 bytes
    printf("%ld\n", sizeof(B));
    printf("%d\n", B[1]);
    printf("%d\n\n", B[2]);
    
    // initialized with 7 elements without declaring size
    int C[] = {2, 4, 6, 8, 10, 12, 14};
    
    // total amount of bytes in array: 7 * 4 bytes
    printf("%ld\n", sizeof(C));
    printf("%d\n", C[1]);
    printf("%d\n\n", C[2]);
    
    int D[10] = {2, 4, 6, 8, 10, 12};
    
    // total amount of bytes in array: 10 * 4 bytes
    printf("%ld\n", sizeof(D));
    // prints uninitialized garbage values
    printf("%d\n", D[6]);
    printf("%d\n\n", D[7]);
    
    // print all elements in array
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", D[i]);
    }
    
    return 0;
}
