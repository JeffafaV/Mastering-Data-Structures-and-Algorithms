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

// searches for key by dividing the array by two with each iteration
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

// searches for key by dividing the array by two with each iteration
// recursive version
int r_binary_search(int a[], int l, int h, int key)
{
	int mid;
	
	if (l <= h)
	{
		mid = (l+h)/2; // middle index
		if (key == a[mid])
		{
			return mid;
		}
		else if (key < a[mid]) // key is less than the middle index
		{
			return r_binary_search(a, l, mid-1, key); // high index is equal to the middle index - 1
		}
		else // key is greater than the middle index
		{
			return r_binary_search(a, mid+1, h, key); // low index is equal to the middle index + 1
		}
	}
	
	return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
	int element = 5;
	
	display(arr);
	printf("The index for the element %d is %d\n", element, binary_search(arr,element));
	printf("The index for the element %d is %d", element, r_binary_search(arr.A,0,arr.length-1,element));
	
    return 0;
}
