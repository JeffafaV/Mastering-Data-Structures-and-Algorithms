#include <stdio.h>

// tower of hanoi using recursion with n disks/numbers and three towers
// have to move all disks/numbers from tower a to tower c
// and tower b is there to help with moving
// can only move one disk/number at a time
// can't have a bigger disk/number on top of a smaller disk/number
void toh(int n, int a, int b, int c)
{
	// the recursive calls simulate each step by changing 
	// the order of the variables but the step won't be 
	// printed until it returns from the first recursive call
    if (n > 0)
    {
		// move one disk/number from tower a to tower b
        toh(n-1,a,c,b);
		
		// prints the step
		// move one disk/number from tower a to tower c
        printf("(%d,%d)\n",a,c);
        
		// move one disk/number from tower b to tower c
        toh(n-1,b,a,c);
    }
}

int main()
{
    // time complexity: O(2^n)
	// space complexity: O(n)
    toh(4,1,2,3);

    return 0;
}
