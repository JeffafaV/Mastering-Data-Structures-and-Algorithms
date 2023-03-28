#include <stdio.h>

// factorial of natural numbers using recursion up to n (recursive)
// space complexity: O(n)
int fact(int n)
{
    if (n == 0)
    {
        return 1; // 0! is 1
    }
    
    return fact(n-1) * n;
}

// factorial of natural numbers using loop up to n (iterative)
// space complexity: O(1)
int i_fact(int n)
{
    int f = 1;
    
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    
    return f;
}

int main()
{
    int r;
    r = fact(5);
    
    printf("%d ", r);
    
	printf("\n");
    
    int r1;
    r1 = i_fact(5);
    
    printf("%d ", r1);
    
    return 0;
}
