#include <stdio.h>

// iterative function for Fibonacci sequence
// this is similar to tabulation however this version
// doesn't save the fibonacci number of each iteration in a vector 
// instead it saves the previous two fibonacci numbers, adds them, and then increments positions
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
// time complexity: O(2^n) because each call will call itself
// twice until it reaches 1 or 0
// note that some branches reach 1 or 0 faster than others 
// creating branches of different length and less calls
// but the time complexity will still estimate O(2^n)
int rfib(int n)
{
	// the fibonacci number of n when n is 0 or 1 is n
    if (n <= 1)
    {
        return n;
    }
    
	// addition of the previous two terms using recursion
    return rfib(n - 2) + rfib(n - 1); // is called twice increasing time complexity
}

// array used for memoization
// make sure this is bigger than n
int F[10];
// memoization recursive function for Fibonacci sequence
int mfib(int n) // time complexity: O(n)
{
    // the fibonacci number of n when n is 0 or 1 is n
    if (n <= 1)
    {
		// unnecessary because they will be set by the other if statements
        //F[n] = n;
        return n;
    }
    else // unnecessary else because the rest of the function runs the same without it
    {
        // runs if the n-2 fibonacci number in the array has not been calculated yet
        if (F[n-2] == -1)
        {
			// calculates the n-2 fibonacci number with a recursion call
			// and places it in the array
            F[n-2] = mfib(n-2);
        }
        
        // runs if the n-1 fibonacci number in the array has not been calculated yet
        if (F[n-1] == -1)
        {
			// calculates the n-1 fibonacci number with a recursion call
			// and places it in the array
            F[n-1] = mfib(n-1);
        }
        
		// current fibonacci number is the addition of the last two fibonacci numbers 
		// which are already calculated in the array and then is inserted into the array
        F[n] = F[n-2] + F[n-1];
		// return the fibonacci number of n
        return F[n];
    }
}

int main()
{
    // initializing array with default value for memoization
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    
    printf("%d\n", fib(5));
    
    printf("%d\n", rfib(5));
    
    printf("%d\n", mfib(5));

    return 0;
}
