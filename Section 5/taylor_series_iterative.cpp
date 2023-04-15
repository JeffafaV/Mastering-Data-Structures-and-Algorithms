#include <stdio.h>

// e^x = 1 + x^1/1! + x^2/2! + x^3/3! + x^4/4! + ... + n terms
// euler's number to the power of x using taylor series with iteration
double e(int x, int n) // x is degree or power and n is precision or number of terms
{
    double s = 1; // total
    double num = 1; // x to the power product
    double den = 1; // factorial product
    
	// looping through n terms
    for (int i = 1; i <= n; i++)
    {
		// num is the product of the previous product and the degree
		// which basically simulates power
        num = num * x;
		// den is the product of the previous product and the ith term
		// which simulates factorial
        den = den * i;
		
		// add result from the last call with this call's term
        s = s + num / den;
    }
    
    return s;
}

int main()
{
    printf("%lf\n", e(1,10));

    return 0;
}
