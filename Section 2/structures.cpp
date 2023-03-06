#include <iostream>

using namespace std;

// total 9 bytes but padding makes it 12 bytes
struct Rectangle
{
    int length; // 4 bytes
    int breadth; // 4 bytes
    char x; // using only 1 byte but has 4 bytes total
};

struct Rectangle r1;

int main()
{
    struct Rectangle r1 = {10,5};
    
    printf("%lu\n", sizeof(r1)); // lu is the data type long unsigned
    
    cout << r1.length << endl;
    cout << r1.breadth << endl;
    
    r1.length = 15;
    r1.breadth = 7;
    
    cout << r1.length << endl;
    cout << r1.breadth << endl;
    
    return 0;
}