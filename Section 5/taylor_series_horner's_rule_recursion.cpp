#include <iostream>

using namespace std;

// e^x = 1 + x/1[1 + x/2[1 + x/3[1 + x/4[...[n terms]]]]]
// euler's number using horner's rule with recursion
double e(int x, int n) // x is degree and n is precision
{
    static double s = 0;
    
    if (n == 0)
    {
        return s; // s is total
    }
    
    s = 1 + s*x/n; // evaluating on call (solving backwards)
    
    return e(x, n - 1);
}

int main()
{
    printf("%lf\n", e(2,10));

    return 0;
}
