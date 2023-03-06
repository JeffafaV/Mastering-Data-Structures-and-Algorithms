#include <iostream>

using namespace std;

// array abstract data type (adt)
struct Array // struct for array
{
    int A[10]; // array of size 10
    int size; // size of array
    int length; // number of elements in array
};

// prints the array
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

// deletes element of selected index
int del(struct Array *arr, int index)
{
	int x = 0;
	
	if (index >= 0 && index < arr->length) // check to see if index is valid
	{
		x = arr->A[index];
		
		for (int i = index; i < arr->length-1; i++)
		{
			arr->A[i] = arr->A[i+1]; // copying the element ahead of it to fill deleted position
		}
		
		arr->length--;
	}
	
	return x;
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
	
	display(arr);
	printf("Deleting %d from the array\n", del(&arr,4));
	display(arr);
    
    return 0;
}
