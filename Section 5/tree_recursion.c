#include <stdio.h>

// tree recursion
// time complexity: O(2^n)
// space complexity: O(n)
/*
	time complexity is O(2^n) or more specifically O(2^(n+1)-1) 
	because each call is calling itself twice. This means that 
	we are constantly getting two times as many calls from the 
	previous call. The space complexity is O(n) or more specifically 
	O(n+1) because that is the maximum height the stack ever goes 
	when calling and ending function calls.
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