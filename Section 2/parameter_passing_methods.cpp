#include <iostream>

using namespace std;

// call by value
// doesn't change the values of the arguments
void swap_value(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// call by address (modular machine code)
// changes the values of the arguments
void swap_address(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// call by reference (monolithic machine code)
// changes the values of the arguments
void swap_reference(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// call by reference is only applicable in C++
int main()
{
    int num1 = 10;
    int num2 = 15;
    
    swap_value(num1, num2); // doesn't swap
    
    cout << "First number " << num1 << endl;
    cout << "Second number " << num2 << endl;
    
    swap_address(&num1, &num2); // swaps (preferred)
    
    cout << "First number " << num1 << endl;
    cout << "Second number " << num2 << endl;
    
    swap_reference(num1, num2); // swaps back(not preferred)
    
    cout << "First number " << num1 << endl;
    cout << "Second number " << num2 << endl;
    
    return 0;
}