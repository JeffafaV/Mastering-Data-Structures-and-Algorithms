#include <iostream>

using namespace std;

// tower of hanoi using recursion
void toh(int n, int a, int b, int c) // can only move one disk at a time
{
    if (n > 0)
    {
        // imagine the whole stack is going from a to b
        toh(n-1,a,c,b);
        printf("(%d,%d)\n",a,c);
        // then that stack can move from b to c
        // we're combining steps but the recursion does each step one at a time using the middle tower
        toh(n-1,b,a,c);
    }
}

int main()
{
    // time complexity: O(2^n)
    toh(4,1,2,3);

    return 0;
}
