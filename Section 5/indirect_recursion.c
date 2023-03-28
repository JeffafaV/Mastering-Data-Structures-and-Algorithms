#include <stdio.h>

// declaring funB so that the compiler knows that it exists
// when it is called in funA
void funB(int n);

// indirect recursion circles between different recursive functions
void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n-1); // calls funB
    }
}

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n/2); // calls funA
    }
}

int main()
{
    funA(20);
    
    return 0;
}