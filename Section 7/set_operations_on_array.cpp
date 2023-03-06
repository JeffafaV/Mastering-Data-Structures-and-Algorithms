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

// does the set operation union
// union is the set of all elements that belong to either a or b or both
// basically pushing everything into the new array except we don't want duplicates
struct Array* set_union(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	i = 0; // index for arr1
	j = 0; // index for arr2
	k = 0; // index for arr3
	
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array)); // creating new array in heap
	
	// checks to see if i and j are less than the size of their arrays
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j]) // checks to see if element in i is smaller than element in j
		{
			arr3->A[k++] = arr1->A[i++]; // push element in i to the new array and then increment i and k
		}
		else if (arr2->A[j] < arr1->A[i]) // element in j is smaller than element in i
		{
			arr3->A[k++] = arr2->A[j++]; // push element in j to the new array and then increment j and k
		}
		else // element in both arrays are the same
		{
			// only push that element once and increment both i and j
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	
	// copy any remaining elements in arr1 to the new array
	for (; i < arr1->length; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}
	// copy any remaining elements in arr2 to the new array
	for (; j < arr2->length; j++)
	{
		arr3->A[k++] = arr2->A[j];
	}
	
	arr3->length = k; // set arr3 length
	arr3->size = arr3->length; // set arr3 size to be equal to its length
	
	return arr3;
}

// does the set operation intersection
// intersection is the set of all elements that belong to both a and b
// basically pushing every element that is a duplicate
struct Array* set_intersection(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	i = 0; // index for arr1
	j = 0; // index for arr2
	k = 0; // index for arr3
	
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array)); // creating new array in heap
	
	// checks to see if i and j are less than the size of their arrays
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j]) // checks to see if element in i is smaller than element in j
		{
			i++; // not a duplicate so increment i
		}
		else if (arr2->A[j] < arr1->A[i]) // element in j is smaller than element in i
		{
			j++; // not a duplicate so increment j
		}
		else // element in both arrays are the same
		{
			// only push that element once and increment both i and j
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	
	arr3->length = k; // set arr3 length
	arr3->size = arr3->length; // set arr3 size to be equal to its length
	
	return arr3;
}

// does the set operation difference
// difference is the set of all elements in a that are not in b
// ex. a = {1,2,3,4} b = {3,4,5,6} then difference = {1,2}
struct Array* set_difference(struct Array *arr1, struct Array *arr2)
{
	int i,j,k;
	i = 0; // index for arr1
	j = 0; // index for arr2
	k = 0; // index for arr3
	
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array)); // creating new array in heap
	
	// checks to see if i and j are less than the size of their arrays
	while (i < arr1->length && j < arr2->length)
	{
		// only pushes elements in arr1
		if (arr1->A[i] < arr2->A[j]) // checks to see if element in i is smaller than element in j
		{
			arr3->A[k++] = arr1->A[i++]; // push element in i to the new array and then increment i and k
		}
		else if (arr2->A[j] < arr1->A[i]) // element in j is smaller than element in i
		{
			j++; // increment j
		}
		else // element in both arrays are the same
		{
			// increment both i and j
			i++;
			j++;
		}
	}
	
	// copy any remaining elements in arr1 to the new array
	for (; i < arr1->length; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}
	
	arr3->length = k; // set arr3 length
	arr3->size = arr3->length; // set arr3 size to be equal to its length
	
	return arr3;
}

int main()
{
    struct Array arr = {{2,6,10,15,25}, 10, 5};
	struct Array arr2 = {{3,6,7,15,20}, 10, 5};
	struct Array *arr3;
	struct Array *arr4;
	struct Array *arr5;
	
	arr3 = set_union(&arr, &arr2);
	arr4 = set_intersection(&arr, &arr2);
	arr5 = set_difference(&arr, &arr2);
	display(arr);
	display(arr2);
	display(*arr3);
	display(*arr4);
	display(*arr5);
	
    return 0;
}
