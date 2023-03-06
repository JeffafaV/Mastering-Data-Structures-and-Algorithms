#include <iostream>

using namespace std;

// array abstract data type (adt)
struct Array // struct for array
{
    int *A; // points to array
    int size; // size of array
    int length; // number of elements in array
};

void display(struct Array arr)
{
    printf("Elements in array:\n");
    
    for (int i = 0; i < arr.length; i++) // displaying elements in array
    {
        printf("%d ", arr.A[i]);
    }
	printf("\nArray length:\n");
	printf("%d\n", arr.length);
}

int main()
{
    struct Array arr;
    int n;
    
    printf("Enter size of an array: ");
    scanf("%d",&arr.size); // & is needed when reading a value using scanf
    
    arr.A = (int*)malloc(arr.size*sizeof(int)); // creates array in heap
    arr.length = 0; // 0 elements in the heap
    
    printf("Enter amount of elements in array: ");
    scanf("%d",&n);
    
    printf("Enter elements in array: ");
    for(int i = 0; i < n; i++) // entering n element values in array
    {
        scanf("%d",&arr.A[i]);
    }
    
    arr.length = n; // length is the same as n
    display(arr);
    
    return 0;
}
