#include <iostream>

using namespace std;

// iterative function for Fibonacci sequence
int fib(int n)
{
    int t0 = 0; // 0th position
    int t1 = 1; // 1st position
    int s = 0;
    
    if (n <= 1) // first two positions are just 0 and 1
    {
        return n;
    }
    
    for (int i = 2; i <= n; i++) // starts at 2nd position
    {
        s = t0 + t1; // adds previous 2 positions
        t0 = t1; // increments by 1 position
        t1 = s; // increments by 1 position
    }
    
    return s;
}

// excessive recursive function for Fibonacci sequence
int rfib(int n) // time complexity: O(2^n)
{
    if (n <= 1)
    {
        return n;
    }
    
    return rfib(n - 2) + rfib(n - 1); // is called twice increasing time complexity
}

// memoization recursive function for Fibonacci sequence
int F[10];

int mfib(int n) // time complexity: O(n)
{
    // have to follow hierarchy to understand
    if (n <= 1)
    {
        F[n] = n; // inserting 0th and 1st position values
        return n;
    }
    else
    {
        // skips this if position is not initialized in array
        if (F[n-2] == -1)
        {
            F[n-2] = mfib(n-2); // initializes value into array through a recursion call
        }
        
        // skips this if position is not initialized in array
        if (F[n-1] == -1)
        {
            F[n-1] = mfib(n-1); // initializes value into array through a recursion call
        }
        
        F[n] = F[n-2] + F[n-1]; // current position value based on the last two added
        return F[n];
    }
}

int main()
{
    // initializing array for memoization
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    
    printf("%d\n", fib(5));
    
    printf("%d\n", rfib(5));
    
    printf("%d\n", mfib(5));

    return 0;
}
