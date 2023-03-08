#include <stdio.h>

int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
    int num1 = 10;
    int num2 = 15;
    int sum;
    
    // result of function will be stored in sum
    sum = add(num1, num2);
    
    printf("Sum is %d", sum);
    
    return 0;
}