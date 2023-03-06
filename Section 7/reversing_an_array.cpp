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

// reverses an array by pushing to another array
void reverse(struct Array *arr)
{
	int *b;
	int i,j;
	
	b = (int *)malloc(arr->length*sizeof(int)); // create a new array
	for (i = arr->length-1, j = 0; i >= 0; i--, j++)
	{
		// pushing the original array backwards to the new array
		b[j] = arr->A[i]; // the new array is reversed
	}
	
	for (int i = 0; i < arr->length; i++)
	{
		arr->A[i] = b[i]; // copying the reversed array to the original array
	}
	
	free(b);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// reverses an array by swaping elements
void reverse_swap(struct Array *arr)
{
	int i,j;
	
	for (i = 0, j = arr->length-1; i < j; i++, j--) // stops when i and j cross each other
	{
		swap(&arr->A[i],&arr->A[j]); // swaps i's element with j's element as they increment
	}
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
	int element = 5;
	
	display(arr);
	reverse(&arr);
	display(arr);
	reverse_swap(&arr);
	display(arr);
	
    return 0;
}
