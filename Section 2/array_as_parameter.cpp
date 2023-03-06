#include <iostream>

using namespace std;

void fun(int a[], int n) // arrays only pass by address
{
    // produces warning
    // cout << "fun function " << sizeof(a)/sizeof(int) << endl; // prints 2 instead of 5 (8/4)
    
    // pass size as separate parameter
    cout << "fun correct " << n << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;
    
    a[0] = 15; // should change in main
}

int* fun2(int size) // creates an array and return its pointer
{
    int *p;
    p = new int[size]; // creating array
    
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1; // intializing elements
    }
    
    return p;
}

int main()
{
    int a[] = {2,4,6,8,10};
    int n = 5;
    fun(a, n);
    cout << "main function " << sizeof(a)/sizeof(int) << endl; // prints size (20/4)
    
    for (int x:a) // for each loop
    {
        cout << x << " ";
    }
    
    cout << endl;
    
    int *ptr;
    int sz = 5;
    
    ptr = fun2(sz);
    
    for (int i = 0; i < sz; i++) // printing array initialized in fun2
    {
        cout << ptr[i] << endl;
    }
    
    return 0;
}
