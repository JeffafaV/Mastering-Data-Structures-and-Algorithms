#include <iostream>

using namespace std;

// sum of natural numbers using recursion up to n (recursive)
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    return sum(n-1) + n;
}

// sum of natural numbers using loop up to n (iterative)
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
    
    cout << endl;
    
    int r1;
    r1 = i_sum(5);
    
    printf("%d ", r1);
    
    return 0;
}
