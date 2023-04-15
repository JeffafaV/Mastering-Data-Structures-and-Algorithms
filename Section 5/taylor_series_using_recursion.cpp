#include <stdio.h>

// e^x = 1 + x^1/1! + x^2/2! + x^3/3! + x^4/4! + ... + n terms
// euler's number to the power of x using taylor series with recursion
double e(int x, int n) // x is degree or power and n is precision or number of terms
{
	// static variables don't reset for each call
    static double p = 1; // initial power or exponent
    static double f = 1; // initial factorial
    double r; // result
    
	// return 1 when n reaches 0
    if (n == 0)
    {
        return 1;
    }
    
	// recursively calling function
    r = e(x, n - 1);
    p = p * x; // numerator
    f = f * n; // denominator
    
	// add result from the last call with this call's term
    return r + p / f;
}

int main()
{
    printf("%lf\n", e(4,15));

    return 0;
}
