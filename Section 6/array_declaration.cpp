#include <iostream>

using namespace std;

int main()
{
	// array declaration
    int a[5];
    int b[5] = {1,2,3,4,5};
    int c[10] = {2,4,6};
    int d[5] = {0};
    int e[ ] = {1,2,3,4,5,6}; // array size depends on the number of elements initialized when size is not declared
    
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " "; // random values
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " "; // initialized values
    }
    
    cout << endl;
    
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " "; // initialized values followed by 0s
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << d[i] << " "; // all 0s
    }
    
    cout << endl;
    
    for (int i = 0; i < 6; i++)
    {
        cout << e[i] << " "; // initialized values
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++)// prints addresses of a
    {
        cout << &a[i] << " "; // the addresses are contiguous
    }
    
    return 0;
}
