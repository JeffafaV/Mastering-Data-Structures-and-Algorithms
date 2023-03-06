#include <iostream>

using namespace std;

// tree recursion
void fun(int n)
{
    // time complexity: O(2^n)
    // space complexity: O(n)
	
    if (n > 0)
    {
        printf("%d ", n);
        fun(n-1); // calling twice creates tree recursion
        fun(n-1); // have to follow the call and return hierachy to understand
    }
}

int main()
{
    fun(3);
    
    return 0;
}