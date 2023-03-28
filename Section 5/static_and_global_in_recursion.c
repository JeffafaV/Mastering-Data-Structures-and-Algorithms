#include <stdio.h>

// no static variable or global variable
int fun(int n)
{
    if (n > 0)
    {
        return fun(n-1) + n; // the + n is done on return
    }
    
    return 0;
}

// static variable example
int fun1(int n)
{
	// static variable
    static int x = 0; // doesn't reset with each call
    if (n > 0)
    {
        x++;
        return fun1(n-1) + x; // x is the same value for each return
    }
    
    return 0;
}

// global variable
int x2 = 0; // doesn't reset with each call
// global variable example
int fun2(int n)
{
    if (n > 0)
    {
        x2++; // increments the global variable x2
        return fun2(n-1) + x2; // x2 is the same value for each return
    }
    
    return 0;
}

int main()
{	
    int rNone;
    rNone = fun(5);
    printf("%d\n", rNone);
	
	rNone = fun(5);
    printf("%d\n", rNone);
    
    int rStat;
    rStat = fun1(5);
    printf("%d\n", rStat);
    
	rStat = fun1(5); // calling the function again in main doesn't reset x
    printf("%d\n", rStat);
    
    int rGlob;
    rGlob = fun2(5);
    printf("%d\n", rGlob);
    
    rGlob = fun2(5); // calling the function again in main doesn't reset x2
    printf("%d\n", rGlob);

    return 0;
}
