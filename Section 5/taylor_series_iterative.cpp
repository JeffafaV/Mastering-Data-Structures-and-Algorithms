#include <iostream>

using namespace std;

// e^x = 1 + x^1/1! + x^2/2! + x^3/3! + x^4/4! + ... + n terms
// euler's number using taylor series with iteration
double e(int x, int n) // x is degree and n is precision
{
    double s = 1; // total
    double num = 1; // x to the power sum
    double den = 1; // factorial sum
    
    for (int i = 1; i <= n; i++)
    {
        num = num * x;
        den = den * i;
        s = s + num/den;
    }
    
    return s;
}

int main()
{
    printf("%lf\n", e(1,10));

    return 0;
}
