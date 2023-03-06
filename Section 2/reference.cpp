#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &r = a; // reference
    
    cout << a << endl << r << endl;
    
    a = 25; // change a and r will change
    
    cout << a << endl << r << endl;
    
    r = 50; // change r and a will change
    
    cout << a << endl << r << endl;
    
    int b = 30;
    r = b; // a will now be b since r is b
    
    cout << a << endl << r << endl;
    
    return 0;
}