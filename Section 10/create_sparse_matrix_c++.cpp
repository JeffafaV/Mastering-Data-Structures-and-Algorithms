#include <iostream>

using namespace std;

class Element
{
	public:
	int i; // row number
	int j; // column number
	int x; // element
};

class Sparse // matrix
{
	private:
	int m; // rows
	int n; // columns
	int num; // number of nonzero elements
	Element *ele; // array of nonzero elements of sparse matrix
	
	public:
	Sparse(int m, int n, int num)
	{
		this->m = m;
		this-> n = n;
		this-> num = num;
		ele = new Element[this->num];
	}
	~Sparse()
	{
		delete []ele;
	}
	
	void read()
	{
		cout << "Enter row, column, and non-zero element:\n";
		
		for (int i = 0; i < num; i++)
		{
			// have to enter elements ordered from first to last position in the matrix
			// i.e. left to right and top to bottom or else it won't print correctly
			cin >> ele[i].i >> ele[i].j >> ele[i].x;
		}
	}
	
	void display()
	{
		int k = 0; // index for elements in the array
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// going through the matrix with two for loops
				// the i and j declared in the for loops are not the same
				// as the i and j in the Element struct
				// it is checking if the current iteration of i and j in
				// the for loops matches the row(i) and column(j) of the kth element in the array
				// if it does then it prints the element and k is incremented
				if (i == ele[k].i && j == ele[k].j)
				{
					cout << ele[k++].x << " ";
				}
				else
				{
					cout << "0 ";
				}
			}
			cout << endl;
		}
	}
};

int main()
{
	Sparse s1 = Sparse(5, 5, 5);
	s1.read();
	s1.display();
	
	return 0;
}