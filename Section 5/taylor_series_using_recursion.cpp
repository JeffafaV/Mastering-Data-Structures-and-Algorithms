#include <iostream>

using namespace std;

// e^x = 1 + x^1/1! + x^2/2! + x^3/3! + x^4/4! + ... + n terms 
// euler's number using taylor series with recursion
double e(int x, int n) // x is degree and n is precision
{
    static double p = 1; // initial power or exponent
    static double f = 1; // initial factorial
    double r; // result
    
    if (n == 0)
    {
        return 1;
    }
    
    r = e(x, n - 1);
    p = p * x; // numerator
    f = f * n; // denominator
    
    return r + p/f;
}

int main()
{
    printf("%lf\n", e(4,15));

    return 0;
}
