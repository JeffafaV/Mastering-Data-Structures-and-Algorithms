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

// inserting an element in a sorted array
void insert_sort(struct Array *arr, int x)
{
	if (arr->length == arr->size) // check if there is space in the array
	{
		return;
	}
	
	int i = arr->length-1;
	
	// checks to see if index is 0 or greater and if element of index is greater than value x
	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i+1] = arr->A[i];
		i--;
	}
	
	arr->A[i+1] = x;
	arr->length++;
}

// checks to see if array is sorted
bool is_sorted(struct Array arr)
{
	for (int i = 0; i < arr.length-1; i++)
	{
		// if the element ahead is greater than the current element then return false
		if (arr.A[i] > arr.A[i+1])
		{
			return false;
		}
	}
	
	return true; // array is sorted
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// rearranges the negative numbers to the left and positive numbers to the right
// this doesn't necessarily sort from least to greatest
void rearrange(struct Array *arr)
{
	int i = 0;
	int j = arr->length-1;
	
	while (i < j)
	{
		// i increments only if the element of i is less than 0
		// if not true it stops and its element is positive
		while(arr->A[i] < 0)
		{
			i++;
		}
		// j increments only if the element of j is greater than or equal to 0
		// if not true it stops and its element is negative
		while(arr->A[j] >= 0)
		{
			j--;
		}
		
		if (i < j)
		{
			swap(&arr->A[i], &arr->A[j]); // swaps the positive and negative number to the correct side
		}
	}
}

int main()
{
    struct Array arr = {{2,3,5,10,15}, 10, 5};
	int element = 20;
	
	display(arr);
	insert_sort(&arr, element);
	display(arr);
	printf("Sorted: %d\n",is_sorted(arr));
	
	struct Array arr2 = {{2,3,5,15,10}, 10, 5};
	
	display(arr2);
	printf("Sorted: %d\n",is_sorted(arr2));
	
	struct Array arr3 = {{2,-3,25,10,-15,-7}, 10, 6};
	
	display(arr3);
	rearrange(&arr3);
	display(arr3);
	
    return 0;
}
