#include <iostream>

using namespace std;

class LowerTri
{
	private:
	int *a; // pointer for array
	int n; // n * n matrix
	
	public:
	LowerTri()
	{
		n = 2;
		a = new int[n*(n+1)/2];
	}
	LowerTri(int n)
	{
		this->n = n;
		a = new int[n*(n+1)/2];
	}
	~LowerTri()
	{
		delete []a;
	}
	
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};

// insert element x in the array if i is greater than or equal to j which means it is lower triangular
// array starts at 0 but we are starting the matrix at 1 hence the i-1 and j-1
void LowerTri::set(int i, int j, int x)
{
	if (i >= j)
	{
		a[i*(i-1)/2 + j-1] = x;
		// a[n*(j-1)-(j-2)*(j-1)/2+i-j] = x;
	}
}

// returns element in array if i is greater than or equal to j and 0 if not
int LowerTri::get(int i, int j)
{
	if (i >= j)
	{
		return a[i*(i-1)/2 + j-1];
		// return a[n*(j-1)-(j-2)*(j-1)/2+i-j];
	}
	
	return 0;
}

// displays the elements in the array as a lower triangular matrix
// note that we didn't create a matrix but we are displaying the array as such
void LowerTri::display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= j) // is lower triangular
			{
				cout << a[i*(i-1)/2 + j-1] << " "; // prints element in array
				// cout << a[n*(j-1)-(j-2)*(j-1)/2+i-j] << " ";
			}
			else // not lower triangular
			{
				cout << "0 "; // prints 0
			}
		}
		cout << endl; // increments the line for the next row
	}
}

int main()
{
    int d;
	cout << "Enter Dimension: ";
	cin >> d;
	
	LowerTri ltm(d);
	
	int x;
	cout << "Enter All Elements:" << endl; // enter n elements n times
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			ltm.set(i,j,x);
		}
	}
	cout << endl << endl;
	ltm.display();
	cout << endl;
	cout << ltm.get(3, 2);
	
    return 0;
}
