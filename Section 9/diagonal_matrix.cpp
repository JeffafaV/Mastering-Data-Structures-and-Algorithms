#include <iostream>

using namespace std;

struct Matrix
{
	int a[10]; // fixed size array that will contain the diagonal elements
	int n; // n * n matrix
};

// insert element x in the array if i equals j which means it is diagonal
// array starts at 0 but we are starting the matrix at 1 hence the i-1
void set(struct Matrix *m, int i, int j, int x)
{
	if (i == j)
	{
		m->a[i-1] = x;
	}
}

// returns element in array if i and j are equal and 0 if not
int get(struct Matrix m, int i, int j)
{
	if (i == j)
	{
		return m.a[i-1];
	}
	else
	{
		return 0;
	}
}

// displays the elements in the array as a diagonal matrix
// note that we didn't create a matrix but we are displaying the array as such
void display(struct Matrix m)
{
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			if (i == j) // is diagonal
			{
				printf("%d ", m.a[i]); // print element in array
			}
			else // not diagonal
			{
				printf("0 "); // print 0
			}
		}
		printf("\n"); // increments the line for the next row
	}
}

int main()
{
    struct Matrix mat;
	mat.n = 4;
	
	set(&mat, 1, 1, 5);
	set(&mat, 2, 2, 8);
	set(&mat, 3, 3, 9);
	set(&mat, 4, 4, 12);
	
	display(mat);
	printf("\n");
	printf("%d\n", get(mat, 2, 2)); // prints the second element in array
	
    return 0;
}
