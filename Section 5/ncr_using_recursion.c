#include <stdio.h>

// factorial using recursion
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    return fact(n-1) * n;
}

// n!/(r!*(n-r)!) ncr formula has three parts that all use factorial
// ncr using factorial recursion
int ncr(int n, int r) // time complexity: O(n)
{
    int num;
    int den;
    
    // num and den both make recursion calls to fact
    num = fact(n);
    den = fact(r) * fact(n-r);
    
    return num/den;
}

// ncr using recursion with Pascal's Triangle
int r_ncr(int n, int r) // time complexity: O(2^n)
{
	// when n = r there is only one way to combine
	// when r = 0 then we get n!/n! which is 1
    if (n == r || r == 0)
    {
        return 1;
    }
    
	// Pascal's triangle shows that we can get ncr by getting
	// the previous two values and adding them
    return r_ncr(n-1,r-1) + r_ncr(n-1,r);
}

int main()
{
	// first number has to be greater than or equal to second
    printf("%d\n", ncr(5,3));
    
    printf("%d\n", r_ncr(5,3));

    return 0;
}
