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

// adds element at the end
void append(struct Array *arr, int x)
{
	if(arr->length < arr->size) // checks to see if there is space in the array
	{
		// adds element at the next available position
		arr->A[arr->length++] = x; // this also increments length
	}
}

// adds element at a specific index
void insert(struct Array *arr, int index, int x)
{
	if (index >= 0 && index <= arr->length) // checks to see if index is valid
	{
		for (int i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i-1]; // incrementing the position of each element that is in the way
		}
		
		// A[index] is empty which means we can now insert an element
		arr->A[index] = x;
		arr->length++; // incrementing length
	}
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
	
	display(arr);
	append(&arr, 7);
	display(arr);
	insert(&arr, 6, 8);
	display(arr);
    
    return 0;
}
