#include <iostream>

using namespace std;

int main()
{
    int A[5]; // just declaring
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;
    
    cout << sizeof(A) << endl; // total amount of bytes in array: 5 * 4 bytes
    cout << A[1] << endl;
    printf("%d\n", A[2]);
    
    cout << endl;
    
    int B[5] = {2, 4, 6, 8 , 10}; // declaring and initializing
    
    cout << sizeof(B) << endl; // total amount of bytes in array: 5 * 4 bytes
    cout << B[1] << endl;
    printf("%d\n", B[2]);
    
    cout << endl;
    
    int C[] = {2, 4, 6, 8 , 10 , 12, 14}; // initialized with 7 elements
    
    cout << sizeof(C) << endl; // total amount of bytes in array: 7 * 4 bytes
    cout << C[1] << endl;
    printf("%d\n", C[2]);
    
    cout << endl;
    
    int D[10] = {2, 4, 6, 8, 10, 12};
    
    cout << sizeof(D) << endl; // total amount of bytes in array: 10 * 4 bytes
    cout << D[6] << endl; // empty
    printf("%d\n", D[7]); // empty
    
    cout << endl;
    
    for (int i = 0; i < 10; i++) // print all elements in array
    {
        cout << D[i] << endl;
    }
    
    cout << endl;
    
    for (int x:D) // for each loop
    {
        cout << x << endl;
    }
    
    return 0;
}
