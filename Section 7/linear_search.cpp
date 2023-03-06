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

// searches for key by going through the array one by one
int linear_search(struct Array arr, int key)
{
	for (int i = 0; i < arr.length; i++)
	{
		if (key == arr.A[i]) // if element matches key then return the index
		{
			return i;
		}
	}
	
	return -1;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// searches for key by going through the array one by one
// swaps with the element that's to the left of it so it can be searched faster
int linear_search_swap(struct Array *arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i]) // if element matches key then return the index
		{
			// swaps the wanted value to be closer for faster search when it is searched again
			swap(&arr->A[i], &arr->A[i-1]); 
			return i;
		}
	}
	
	return -1;
}

// searches for key by going through the array one by one
// swaps with the first element so it can be searched faster
int linear_search_swap_front(struct Array *arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i]) // if element matches key then return the index
		{
			// swaps the wanted value to be at the front for faster search when it is searched again
			swap(&arr->A[i], &arr->A[0]); 
			return i;
		}
	}
	
	return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
	int element = 5;
	
	display(arr);
	printf("The index for the element %d is %d\n\n", element, linear_search(arr,element));
    
    linear_search_swap(&arr,element);
	display(arr);
	printf("The index for the element %d is %d\n\n", element, linear_search_swap(&arr,element));
	
	linear_search_swap_front(&arr,element);
	display(arr);
	printf("The index for the element %d is %d\n", element, linear_search_swap_front(&arr,element));
	
    return 0;
}
