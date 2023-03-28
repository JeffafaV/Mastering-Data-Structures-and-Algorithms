#include <stdio.h>

// sum of natural numbers using recursion up to n (recursive)
// space complexity: O(n)
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    return sum(n-1) + n;
}

// sum of natural numbers using loop up to n (iterative)
// space complexity: O(1)
int i_sum(int n)
{
    int s = 0;
    
    for (int i = 0; i <= n; i++)
    {
        s = s + i;
    }
    
    return s;
}

int main()
{
    int r;
    r = sum(5);
    
    printf("%d ", r);
    
    printf("\n");
    
    int r1;
    r1 = i_sum(5);
    
    printf("%d ", r1);
    
    return 0;
}
