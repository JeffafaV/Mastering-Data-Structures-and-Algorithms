#include <iostream>

using namespace std;

// head recursion
void fun_head(int n)
{
    if (n > 0)
    {
        fun_head(n-1); // recursion first
        printf("%d ", n);
    }
}

// tail recursion
void fun_tail(int n)
{
    if (n > 0)
    {
        printf("%d ", n); // order of recursion call matters
        fun_tail(n-1); // recursion second
    }
}

int main()
{
	// for both recursions
	// time complexity: O(n)
	// space complexity: O(n)
	
    int x = 3;
    
    fun_head(x); // values are printed as function is returned
    cout << endl;
    fun_tail(x); // values are printed as function is called

    return 0;
}
