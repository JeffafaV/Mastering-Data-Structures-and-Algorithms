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
	
	// extraction operator overloading (input operator >>)
	friend istream &operator>>(istream &is, Sparse &s);
	// friend makes the function a global function that can access private members of Sparse
	// insertion operator overloading (output operator <<)
	friend ostream &operator<<(ostream &os, Sparse &s);
	
	Sparse operator+(Sparse &s);
};

istream &operator>>(istream &is, Sparse &s)
{
	cout << "Enter row, column, and non-zero element:\n";
	
	for (int i = 0; i < s.num; i++)
	{
		// have to enter elements ordered from first to last position in the matrix
		// i.e. left to right and top to bottom or else it won't print correctly
		cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
	}
	
	return is;
}

ostream &operator<<(ostream &os, Sparse &s)
{
	int k = 0; // index for elements in the array
	for (int i = 0; i < s.m; i++)
	{
		for (int j = 0; j < s.n; j++)
		{
			// going through the matrix with two for loops
			// the i and j declared in the for loops are not the same
			// as the i and j in the Element class
			// it is checking if the current iteration of i and j in
			// the for loops matches the row(i) and column(j) of the kth element in the array
			// if it does then it prints the element and k is incremented
			if (i == s.ele[k].i && j == s.ele[k].j)
			{
				cout << s.ele[k++].x << " ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
	
	return os;
}

Sparse Sparse::operator+(Sparse &s)
{
	Sparse *sum;
	int i = 0; // index for first array
	int j = 0; // index for second array
	int k = 0; // index for sum array
	
	sum = new Sparse(m, n, num+s.num);
	
	while (i < num && j < s.num)
	{
		// if the first array's row is less than the second array's row
		// then add the first array's element to k and increment k and i
		if (ele[i].i < s.ele[j].i)
		{
			sum->ele[k++] = ele[i++];
		}
		// if the second array's row is less than the first array's row
		// then add the second array's element to k and increment k and j
		else if (ele[i].i > s.ele[j].i)
		{
			sum->ele[k++] = s.ele[j++];
		}
		else // if rows are equal then we check columns
		{
			// if the first array's column is less than the second array's column
			// then add the first array's element to k and increment k and i
			if (ele[i].j < s.ele[j].j)
			{
				sum->ele[k++] = ele[i++];
			}
			// if the second array's column is less than the first array's column
			// then add the second array's element to k and increment k and j
			else if (ele[i].j > s.ele[j].j)
			{
				sum->ele[k++] = s.ele[j++];
			}
			else // if columns are also equal then we copy the row and column of either arrays and add x from both arrays
			{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}
	
	for (; i < num; i++) // add any remaining elements from the first array
	{
		sum->ele[k++] = ele[i];
	}
	
	for (; j < s.num; j++) // add any remaining elements from the second array
	{
		sum->ele[k++] = s.ele[j];
	}
	
	sum->m = m;
	sum->n = n;
	sum->num = num + s.num;
	
	return *sum;
}

int main()
{
	Sparse s1 = Sparse(5, 5, 5);
	Sparse s2 = Sparse(5, 5, 5);
	
	cin >> s1;
	cin >> s2;
	
	Sparse sum = s1 + s2;
	
	cout << "First Matrix:" << endl << s1;
	cout << "Second Matrix:" << endl << s2;
	cout << "Sum Matrix:" << endl << sum;
	
	return 0;
}