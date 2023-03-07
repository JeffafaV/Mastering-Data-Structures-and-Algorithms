#include <stdio.h>

// structures group related variables into one place
struct Rectangle
{
    int length; // 4 bytes
    int breadth; // 4 bytes
    char x; // uses only 1 byte but has 4 bytes total
};

//struct Rectangle r1;

int main()
{
	// creating a struct variable and initializing length and breadth
    struct Rectangle r1 = {10,5};
    
	// total amount of bytes: 3 variables * 4 bytes
    printf("%ld\n", sizeof(r1));
	// printing memmber variables
    printf("%d\n", r1.length);
    printf("%d\n", r1.breadth);
	// uninitialized
	printf("%c\n", r1.x);
    
	// changing values
    r1.length = 15;
    r1.breadth = 7;
	r1.x = 'x';
    
    printf("%d\n", r1.length);
    printf("%d\n", r1.breadth);
	printf("%c\n", r1.x);
    
    return 0;
}