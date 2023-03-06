#include <iostream>

using namespace std;

class Diagonal
{
	private:
	int *a; // pointer for array
	int n; // n * n matrix
	
	public:
	Diagonal()
	{
		n = 2;
		a = new int[n];
	}
	Diagonal(int n)
	{
		this->n = n;
		a = new int[n];
	}
	~Diagonal()
	{
		delete []a;
	}
	
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};

// insert element x in the array if i equals j which means it is diagonal
// array starts at 0 but we are starting the matrix at 1 hence the i-1
void Diagonal::set(int i, int j, int x)
{
	if (i == j)
	{
		a[i-1] = x;
	}
}

// returns element in array if i and j are equal and 0 if not
int Diagonal::get(int i, int j)
{
	if (i == j)
	{
		return a[i-1];
	}
	
	return 0;
}

// displays the elements in the array as a diagonal matrix
// note that we didn't create a matrix but we are displaying the array as such
void Diagonal::display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				cout << a[i] << " ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}

int main()
{
    Diagonal dia(4);
	
	dia.set(1, 1, 5);
	dia.set(2, 2, 8);
	dia.set(3, 3, 9);
	dia.set(4, 4, 12);
	
	dia.display();
	cout << endl;
	cout << dia.get(2, 2) << endl; // prints the second element in array
	
    return 0;
}
