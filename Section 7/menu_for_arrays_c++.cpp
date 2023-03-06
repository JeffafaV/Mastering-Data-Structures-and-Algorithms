#include <iostream>

using namespace std;

// array class
class Array
{
	private:
    int *A; // points to array
    int size; // size of array
    int length; // number of elements in array
	
	public:
	Array()
	{
		size = 10;
		length = 0;
		A = new int[size];
	}
	
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int[size];
	}
	
	~Array()
	{
		delete []A;
	}
	
	void display();
	void insert(int index, int x);
	int del(int index);
	int binary_search(int key);
	int sum();
};

// prints the array
void Array::display()
{
    cout << "Elements in array:" << endl;
    
    for (int i = 0; i < length; i++) // displaying elements in array
    {
        cout << A[i] << " ";
    }
	cout << endl;
	cout << "Array length:" << endl;
	cout << length << endl;
}

// adds element at a specific index
void Array::insert(int index, int x)
{
	if (index >= 0 && index <= length) // checks to see if index is valid
	{
		for (int i = length; i > index; i--)
		{
			A[i] = A[i-1]; // incrementing the position of each element that is in the way
		}
		
		// A[index] is empty which means we can now insert an element
		A[index] = x;
		length++; // incrementing length
	}
}

// deletes element of selected index
int Array::del(int index)
{
	int x = 0;
	
	if (index >= 0 && index < length) // check to see if index is valid
	{
		x = A[index];
		
		for (int i = index; i < length-1; i++)
		{
			A[i] = A[i+1]; // copying the element ahead of it to fill deleted position
		}
		
		length--;
	}
	
	return x;
}

// searches for key/element by dividing the array by two with each iteration
int Array::binary_search(int key)
{
	int l, mid, h; // three different indexes needed
	l = 0; // low index
	h = length-1; // high index
	
	while (l <= h) // if the lower index is ever greater than the high index than value is not in array
	{
		mid = (l+h)/2; // middle index
		if (key == A[mid])
		{
			return mid;
		}
		else if (key < A[mid]) // key is lower than the middle index
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
int Array::sum()
{
	int s = 0;
	
	for (int i = 0; i < length; i++)
	{
		s = s + A[i]; // adds all elements in the array
	}
	
	return s;
}

int main()
{
	Array *arr1;
	int ch, sz;
	int x, index;
	
	cout << "Enter size of array: ";
	cin >> sz;
	arr1 = new Array(sz);
	
	do
	{
		cout << "Menu" << endl;
		cout << "1. Display" << endl;
		cout << "2. Insert" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Search" << endl;
		cout << "5. Sum" << endl;
		cout << "6. Exit" << endl;
		
		cout << "Enter option: ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
			{
				arr1->display();
				break;
			}
			case 2:
			{
				cout << "Enter an element: ";
				cin >> x;
				cout << "Enter an index: ";
				cin >> index;
				arr1->insert(index, x);
				break;
			}
			case 3:
			{
				cout << "Enter an index: ";
				cin >> index;
				cout << "Deleting element " << arr1->del(index) << endl;
				break;
			}
			case 4:
			{
				cout << "Enter an element: ";
				cin >> x;
				cout << "The element " << x << " is at the index " << arr1->binary_search(x) << endl;
				break;
			}
			case 5:
			{
				cout << "The sum of all the elements in the array is " << arr1->sum() << endl;
				break;
			}
		}
	}
	while (ch < 6);
	
    return 0;
}
