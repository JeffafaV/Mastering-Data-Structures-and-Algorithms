#include <stdio.h>

int main()
{
	// different ways to declare an array
	
	// declaring an array of size 5 without initializing
	// all the elements will have garbage values
    int a[5];
	
	// declaring an array of size 5 and initializing
	// all the elements are set
    int b[5] = {1,2,3,4,5};
	
	// declaring an array of size 10 and initializing some values
	// some elements are set and the ones that aren't will be set to 0
    int c[10] = {2,4,6};
	
	// declaring an array of size 5 and initializing all values to 0
	// note that you're technically setting only the first 0 but since 
	// at least one element is set then the rest of the array is set to 0
    int d[5] = {0};
	
	// declaring an array with no set size.
	// since there is no size, the size depends on 
	// the number of elements that are initialized
    int e[] = {1,2,3,4,5,6};
    
	// loop through array a
    for (int i = 0; i < 5; i++)
    {
		// prints garbage values
		printf("%d ", a[i]);
    }
    
    printf("\n");
    
	// loop through array b
    for (int i = 0; i < 5; i++)
    {
		// prints the initialized values
		printf("%d ", b[i]);
    }
    
    printf("\n");
    
	// loop through array c
    for (int i = 0; i < 10; i++)
    {
		// prints the initialized values followed by 
		// the uninitialized values which are 0s
		printf("%d ", c[i]);
    }
    
    printf("\n");
    
	// loop through array d
    for (int i = 0; i < 5; i++)
    {
		// prints the one initialized 0 and the remaining uninitialized 0s
		printf("%d ", d[i]);
    }
    
    printf("\n");
    
	// loop through array e
    for (int i = 0; i < 6; i++)
    {
		// prints the initialized values
		printf("%d ", e[i]);
    }
    
	printf("\n");
    
	// loop through array a
    for (int i = 0; i < 5; i++)
    {
        // prints the addresses of the elements in a.
		// note that the addresses are contiguous meaning 
		// that the elements are next to each other in memory
		printf("%p ", &a[i]);
    }
    
    return 0;
}
