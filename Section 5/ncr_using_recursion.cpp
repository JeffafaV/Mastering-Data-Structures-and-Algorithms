#include <iostream>

using namespace std;

// n!/(r!(n-r)!) ncr formula
// factorial using recursion
int fact(int n) // three parts that all use factorial
{
    if (n == 0)
    {
        return 1;
    }
    
    return fact(n-1) * n;
}

int ncr(int n, int r) // uses factorial recursion
{
    int num;
    int den;
    
    // num and den both make recursion calls to fact
    num = fact(n);
    den = fact(r) * fact(n-r);
    
    return num/den;
}

// ncr using recursion
int r_ncr(int n, int r) // time complexity: O(2^n)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    
    return r_ncr(n-1,r-1) + r_ncr(n-1,r); // recursion call twice
}

int main()
{
    printf("%d\n", ncr(5,3)); // first number has to be greater than or equal to second
    
    printf("%d\n", r_ncr(5,3));

    return 0;
}
