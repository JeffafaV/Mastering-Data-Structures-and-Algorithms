#include <iostream>

using namespace std;

int main()
{
    int *p;
    int *q;
    
    // allocating p
    p = (int*)malloc(5*sizeof(int)); // p = new int[5]
    
    // intiliazing *p
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]); // printing the array p points to
    }
    
    q = (int*)malloc(10*sizeof(int)); // q can hold 10 elements
    
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i]; // transfering elements in array from p to q
    }
    
    // we want p to point to the same array as q and delete the initial array p pointed to
    free(p); // deletes the array p pointed to initially
    p = q; // p now points to the same address as q which has a bigger array
    q = NULL; // q points to nowhere
    
    cout << endl;
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p[i]); // prints the initialized values followed by uninitialized 0s
    }
    
    return 0;
}
