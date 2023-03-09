#include <stdio.h>
#include <stdlib.h>

 // arrays only pass by address
void fun(int a[], int n)
{
    // produces warning
	// the a variable falls victim to array decay
	// a is not an array of ints but a pointer
	// printf("fun function %ld\n", sizeof(a)/sizeof(int)); // prints 2 (8/4) instead of 5
    
    // pass size as separate parameter
	printf("fun correct %d\n", n);
    
    for (int i = 0; i < n; i++)
    {
		printf("%d ", a[i]);
    }
    printf("\n");
    
	// changes the array in main
    a[0] = 15;
}

// creates an array in heap and return its pointer
int* fun2(int size)
{
    int *p;
	p = (int *)malloc(size*sizeof(int)); // creating array
    
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1; // intializing elements
    }
    
    return p;
}

int main()
{
    int a[] = {2,4,6,8,10};
    int n = 5;
    fun(a, n);
	printf("main function %ld\n", sizeof(a)/sizeof(int)); // prints size (20/4)
    
    for (int i = 0; i < n; i++)
    {
		printf("%d ", a[i]);
    }
    
	printf("\n");
    
    int *ptr;
    int sz = 5;
    
    ptr = fun2(sz);
    
    for (int i = 0; i < sz; i++) // printing array initialized in fun2
    {
		printf("%d\n", ptr[i]);
    }
    
    return 0;
}
