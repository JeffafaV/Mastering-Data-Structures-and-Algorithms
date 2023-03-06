#include <iostream>

using namespace std;

// no static variable or global variable
int fun(int n)
{
    if (n > 0)
    {
        return fun(n-1) + n; // the + n is done on return
    }
    
    return 0;
}

// static variable
int fun1(int n)
{
    static int x = 0; // doesn't reset with each call
    if (n > 0)
    {
        x++; // increments x
        return fun1(n-1) + x;
    }
    
    return 0;
}

// global variable
int x2 = 0; // doesn't reset as well with each call
int fun2(int n)
{
    if (n > 0)
    {
        x2++; // increments the global variable x2
        return fun2(n-1) + x2;
    }
    
    return 0;
}

int main()
{	
    int r;
    r = fun(5);
    printf("%d\n", r);
    
    int r1;
    r1 = fun1(5);
    printf("%d\n", r1);
    
    
    int r2;
    r2 = fun2(5);
    printf("%d\n", r2);
    
    int r3;
    r3 = fun2(5); // calling the function again in main doesn't reset
    printf("%d\n", r3);

    return 0;
}
