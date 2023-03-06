#include <iostream>

using namespace std;

int main()
{
    // array created in stack (static)
    int a[5] = {2,4,6,8,10};
    
    // array created in heap (dynamic)
    int *p;
    p = (int*)malloc(5*sizeof(int)); // p = new int[5]
    
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]); // this prints value in array in heap
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        // can also do p + i
        cout << &p[i] << " "; // this prints element's address in array in heap
    }
    
    return 0;
}
