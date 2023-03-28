#include <stdio.h>

// head recursion
void fun_head(int n)
{
    if (n > 0)
    {
        fun_head(n-1); // recursion first
        printf("%d ", n);
    }
}

// tail recursion
void fun_tail(int n)
{
    if (n > 0)
    {
        printf("%d ", n); // order of recursion call matters
        fun_tail(n-1); // recursion second
    }
}

// function that calls itself is called a recursive function
// each call takes up space in the stack until the function 
// terminates or returns something
int main()
{
	// for both recursions
	// time complexity: O(n)
	// space complexity: O(n)
	
    int x = 3;
    
    fun_head(x); // values are printed as function is returned
    printf("\n");
    fun_tail(x); // values are printed as function is called

    return 0;
}
