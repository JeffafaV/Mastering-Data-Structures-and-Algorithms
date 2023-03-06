#include <iostream>

using namespace std;

// array abstract data type (adt)
struct Array // struct for array
{
    int *A; // points to array
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

// searches for key/element by dividing the array by two with each iteration
int binary_search(struct Array arr, int key)
{
	int l, mid, h; // three different indexes needed
	l = 0; // low index
	h = arr.length-1; // high index
	
	while (l <= h) // if the lower index is ever greater than the high index than value is not in array
	{
		mid = (l+h)/2; // middle index
		if (key == arr.A[mid])
		{
			return mid;
		}
		else if (key < arr.A[mid]) // key is lower than the middle index
		{
			h = mid - 1; // new high index is the middle index - 1
		}
		else // key is higher than the middle index
		{
			l = mid + 1; // new low index is the middle index + 1
		}
	}
	
	return -1;
}

// sums up the entire array
int sum(struct Array arr)
{
	int s = 0;
	
	for (int i = 0; i < arr.length; i++)
	{
		s = s + arr.A[i]; // adds all elements in the array
	}
	
	return s;
}

int main()
{
	struct Array arr1;
	int ch;
	int x, index;
	
	printf("Enter size of array: ");
	scanf("%d", &arr1.size);
	arr1.A = (int *)malloc(arr1.size*sizeof(int));
	arr1.length = 0;
	
	do
	{
		printf("Menu\n");
		printf("1. Display\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Search\n");
		printf("5. Sum\n");
		printf("6. Exit\n");
		
		printf("Enter option: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
			{
				display(arr1);
				break;
			}
			case 2:
			{
				printf("Enter an element: ");
				scanf("%d", &x);
				printf("Enter an index: ");
				scanf("%d", &index);
				insert(&arr1, index, x);
				break;
			}
			case 3:
			{
				printf("Enter an index: ");
				scanf("%d", &index);
				del(&arr1, index);
				break;
			}
			case 4:
			{
				printf("Enter an element: ");
				scanf("%d", &x);
				printf("The element %d is at index %d\n", x, binary_search(arr1,x));
				break;
			}
			case 5:
			{
				printf("The sum of all the elements in the array is %d\n", sum(arr1));
				break;
			}
		}
	}
	while (ch < 6);
	
    return 0;
}
