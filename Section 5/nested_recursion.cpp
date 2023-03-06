#include <iostream>

using namespace std;

// nested recursion
int fun(int n) // have to follow the hiearchy to understand
{
    if (n > 100)
    {
        return n - 10;
    }
    
    // remember that this one line of code has two calls of fun
    return fun(fun(n+11)); // recursion as the parameter of another recursion call makes it nested
}

int main()
{
    int r;
    r=fun(95);
    
    printf("%d\n", r);
    
    return 0;
}