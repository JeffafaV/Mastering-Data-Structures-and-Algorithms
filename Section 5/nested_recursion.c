#include <stdio.h>

// nested recursion
int fun(int n) // have to follow the hiearchy to understand
{
    if (n > 100)
    {
        return n - 10;
    }
    
    // this one line of code has two calls of fun
	// have to do the inside recursive call first and the outside call second
    return fun(fun(n+11)); // a recursive call as the argument of another recursive call makes it nested
}

int main()
{
    int r;
    r = fun(95);
    
    printf("%d\n", r);
    
    return 0;
}