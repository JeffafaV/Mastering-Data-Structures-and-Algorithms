#include <iostream>

using namespace std;

int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    int p;
    p = 2 * (length + breadth);
    
    return p;
}
// modular programming (uses functions)
int main()
{
    int length = 0;
    int breadth = 0;
    
    printf("Enter length and breadth\n");
    cin >> length >> breadth;
    
    int a = area(length,breadth);
    int p = perimeter(length,breadth);
    
    printf("Area = %d\nPerimeter = %d\n", a, p);
    
    return 0;
}
