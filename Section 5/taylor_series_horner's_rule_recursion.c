#include <stdio.h>

// e^x = 1 + x/1[1 + x/2[1 + x/3[1 + x/4[...[n terms]]]]]
// euler's number to the power of x using taylor series with horner's rule recursively
double e(int x, int n) // x is degree or power and n is precision or number of terms
{
	// static variable doesn't reset for each call
    static double s = 1; // holds the sum which is initially set to 1
    
	// returns sum when n reaches 0
    if (n == 0)
    {
        return s; // s is the answer when we reach this point
    }
    
	// evaluating on call
    s = 1 + s * x / n; // multiply sum with this call's term and then add 1
    
	// recursively call function
    return e(x, n - 1);
}

int main()
{
    printf("%lf\n", e(2,10));

    return 0;
}
