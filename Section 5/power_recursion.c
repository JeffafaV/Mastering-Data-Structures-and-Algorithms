#include <stdio.h>

// getting the result for m^n with recursion
int power(int m, int n) // time complexity: O(n)
{
    if (n == 0)
    {
        return 1;
    }
    
    return power(m, n-1) * m;
}

// getting the result for m^n with recursion by reducing in half each time
// Ex: 2^8 is the same (2*2)^4 so we can multipy m to itself and reduce n by half
int power1(int m, int n) // time complexity: O(log n)
{
    if (n == 0)
    {
        return 1;
    }
    
    if (n % 2 == 0) // power is even
    {
        return power1(m*m,n/2);
    }
    
    return power1(m*m, (n-1)/2) * m; // power is odd
}

int main()
{
    int r = power(2, 9);
    
    printf("%d\n", r);
    
    int r1 = power1(2, 9);
    
    printf("%d\n", r1);

    return 0;
}
