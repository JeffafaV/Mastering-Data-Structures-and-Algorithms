#include <stdio.h>

// tree recursion
// time complexity: O(2^n)
// space complexity: O(n)
/*
	technically the time complexity is O(2^(n+1)-1)
	and the space complexity is O(n+1) because 
	there are function calls for 0 as well
	making the range 0 to n
*/
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n-1); // calling twice creates tree recursion
        fun(n-1); // have to follow the call and return hierachy to understand
    }
}

int main()
{
    fun(3);
    
    return 0;
}