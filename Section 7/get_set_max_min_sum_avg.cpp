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

// gets element of selected index
int get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length) // checks if index is valid
	{
		return arr.A[index]; // returns element of index
	}
	
	return -1;
}

// changes element of selected index
void set(struct Array *arr, int index, int x)
{
	if (index >= 0 && index < arr->length) // checks if index is valid
	{
		arr->A[index] = x; // changes element to equal x
	}
}

// finds and returns the greatest element in the array
int max(struct Array arr)
{
	int max = arr.A[0];
	
	for (int i = 1; i < arr.length; i++)
	{
		if (max < arr.A[i]) // checks to see if element in array is greater than max
		{
			max = arr.A[i]; // max is now the element
		}
	}
	
	return max;
}

// finds and returns the smallest element in the array
int min(struct Array arr)
{
	int min = arr.A[0];
	
	for (int i = 1; i < arr.length; i++)
	{
		if (min > arr.A[i]) // checks to see if element in array is smaller than min
		{
			min = arr.A[i]; // min is now the element
		}
	}
	
	return min;
}

int sum(struct Array arr)
{
	int s = 0;
	
	for (int i = 0; i < arr.length; i++)
	{
		s = s + arr.A[i]; // adds all elements in the array
	}
	
	return s;
}

float avg(struct Array arr)
{
	return (float)sum(arr)/arr.length; // returns the average of the array
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
	
	display(arr);
	int index = 2;
	
	printf("The element for index %d is %d\n\n", index, get(arr, index));
	
	set(&arr, 0, 15);
	display(arr);
	
	printf("The biggest number is %d\n", max(arr));
	printf("The smallest number is %d\n", min(arr));
	printf("The sum of the array is %d\n", sum(arr));
	printf("The average of the array is %f", avg(arr));
	
    return 0;
}
