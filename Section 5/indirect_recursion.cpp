#include <iostream>

using namespace std;

void funB(int n);

// indirect recursion circles between different recursion functions
void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n-1); // calls funB
    }
}

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n/2); // calls funA
    }
}

int main()
{
    funA(20);
    
    return 0;
}