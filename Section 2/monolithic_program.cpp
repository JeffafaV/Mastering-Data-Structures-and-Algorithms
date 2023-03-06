#include <iostream>

using namespace std;

// monolithic programming (doesn't use functions)
int main()
{
    int length = 0;
    int breadth = 0;
    
    printf("Enter length and breadth\n");
    cin >> length >> breadth;
    
    int area = length * breadth;
    int perimeter = 2 * (length + breadth);
    
    printf("Area = %d\nPerimeter = %d\n", area, perimeter);
    
    return 0;
}
