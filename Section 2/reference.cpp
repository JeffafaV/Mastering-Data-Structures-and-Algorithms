#include <iostream>

using namespace std;

// pass by reference is only applicable in C++
int main()
{
    int a = 10;
    int &r = a; // r is referencing a so they share the same memory
    
    cout << a << endl << r << endl;
    
    a = 25; // change a and r will change
    
    cout << a << endl << r << endl;
    
    r = 50; // change r and a will change
    
    cout << a << endl << r << endl;
    
    int b = 30;
    r = b; // initializing r to b will also change a to b
    
    cout << a << endl << r << endl;
    
    return 0;
}