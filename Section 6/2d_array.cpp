#include <iostream>

using namespace std;

int main()
{
    // 2d array created in stack
    int a[3][4]; // [3] = rows, [4] = columns
    
    // initializing array
    for (int i = 0; i < 4; i++)
    {
        a[0][i] = i + 1; // initialize to 1 to 4
        a[1][i] = 2 + 2 * i; // initialize to even numbers
        a[2][i] = 1 + 2 * i; // initialize to odd numbers
    }
    
    // nested for loop to print all elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", a[i][j]);
        }
        
        printf("\n");
    }
    
    cout << endl;
    
    // 2d array created in stack and heap
    int *b[3]; // array of pointers for row position created in stack
    b[0] = (int*)malloc(4*sizeof(int)); // columns are created in heap
    b[1] = (int*)malloc(4*sizeof(int));
    b[2] = (int*)malloc(4*sizeof(int));
    
    // initializing array
    for (int i = 0; i < 4; i++)
    {
        b[0][i] = i + 1;
        b[1][i] = 2 + 2 * i;
        b[2][i] = 1 + 2 * i;
    }
    
    // nested for loop to print all elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", b[i][j]);
        }
        
        printf("\n");
    }
    
    cout << endl;
    
    // 2d array created in heap
    int **c;
    c = (int**)malloc(3*sizeof(int*)); // array of pointers for row position created in heap
    c[0] = (int*)malloc(4*sizeof(int)); // columns are created in heap
    c[1] = (int*)malloc(4*sizeof(int));
    c[2] = (int*)malloc(4*sizeof(int));
    
    // initializing array
    for (int i = 0; i < 4; i++)
    {
        c[0][i] = i + 1;
        c[1][i] = 2 + 2 * i;
        c[2][i] = 1 + 2 * i;
    }
    
    // nested for loop to print all elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", c[i][j]);
        }
        
        printf("\n");
    }
    
    cout << endl;
    
    // 2d array created in heap in c++
    int **d;
    d = new int*[3];
    d[0] = new int[4];
    d[1] = new int[4];
    d[2] = new int[4];
    
    // initializing array
    for (int i = 0; i < 4; i++)
    {
        d[0][i] = i + 1;
        d[1][i] = 2 + 2 * i;
        d[2][i] = 1 + 2 * i;
    }
    
    // nested for loop to print all elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", d[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
