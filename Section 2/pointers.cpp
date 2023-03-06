#include <iostream>

using namespace std;

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
    
    cout << a << endl;
	cout << *p << endl; // prints value of a
	// printf("Using pointer %d %d\n", p, &a); // produces warning due to type
    printf("Using pointer %p %p\n\n", p, &a); // both print the address of a
    
    int B[5] = {2,4,6,8,10}; // array in stack (predefined allocation)
    int *p1;
    p1 = B;
    
    for (int i = 0; i < 5; i++)
    {
        cout << B[i] << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++) // can use pointer to loop through array
    {
        cout << p1[i] << endl;
    }
    
    cout << endl;
    
    int *p2;
    p2 = new int[5]; // array in heap (runtime allocation)
    p2[0] = 10;
    p2[1] = 15;
    p2[2] = 14;
    p2[3] = 21;
    p2[4] = 31;
    
    for (int i = 0; i < 5; i++)
    {
        cout << p2[i] << endl;
    }
    
    delete [] p2; // delete array in heap
    cout << endl;
    
    int *p3;
    char *p4;
    float *p5;
    double *p6;
    struct Rectangle *p7;
    
    // whatever the data type of a pointer it will always have the same amount of memory
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;
    cout << sizeof(p6) << endl;
    cout << sizeof(p7) << endl;
    
    return 0;
}