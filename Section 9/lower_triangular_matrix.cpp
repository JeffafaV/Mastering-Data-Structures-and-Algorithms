#include <iostream>

using namespace std;

struct Matrix
{
	int *a; // pointer for array
	int n; // n * n matrix
};

// insert element x in the array if i is greater than or equal to j which means it is lower triangular
// array starts at 0 but we are starting the matrix at 1 hence the i-1 and j-1
void set(struct Matrix *m, int i, int j, int x)
{
	if (i >= j) // element is not zero
	{
		// array uses row major mapping
		m->a[i*(i-1)/2 + j-1] = x; // formula in [] finds the correct index and places x as its element
		// for column major mapping
		// m->a[m->n*(j-1)-(j-2)*(j-1)/2+i-j] = x;
	}
}

// returns element in array if i is greater than or equal to j and 0 if not
int get(struct Matrix m, int i, int j)
{
	if (i >= j)
	{
		return m.a[i*(i-1)/2 + j-1];
		// return m.a[m.n*(j-1)-(j-2)*(j-1)/2+i-j]
	}
	else
	{
		return 0;
	}
}

// displays the elements in the array as a lower triangular matrix
// note that we didn't create a matrix but we are displaying the array as such
void display(struct Matrix m)
{
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
		{
			if (i >= j) // is lower triangular
			{
				printf("%d ", m.a[i*(i-1)/2 + j-1]); // prints element in array
				// printf("%d ", m.a[m.n*(j-1)-(j-2)*(j-1)/2+i-j]);
			}
			else // not lower triangular
			{
				printf("0 "); // prints 0
			}
		}
		printf("\n"); // increments the line for the next row
	}
}

int main()
{
    struct Matrix mat;
	int x;
	
	printf("Enter Dimension: ");
	scanf("%d",&mat.n);
	
	mat.a = (int *)malloc(mat.n*(mat.n+1)/2*sizeof(int));
	
	printf("Enter All Elements:\n"); // enter n elements n times
	for (int i = 1; i <= mat.n; i++)
	{
		for (int j = 1; j <= mat.n; j++)
		{
			scanf("%d",&x);
			set(&mat, i, j, x);
		}
	}
	printf("\n\n");
	display(mat);
	printf("\n");
	printf("%d",get(mat, 3, 2));
	
    return 0;
}
