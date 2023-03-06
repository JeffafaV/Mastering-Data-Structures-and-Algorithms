#include <iostream>

using namespace std;

struct Element
{
    int i; // row number
    int j; // column number
    int x; // element
};

struct Sparse // matrix
{
    int m; // rows
    int n; // columns
    int num; // number of nonzero elements
    struct Element *ele; // array of nonzero elements of sparse matrix
};

void create(struct Sparse *s)
{
    printf("Enter dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter number of nonzero elements: ");
    scanf("%d", &s->num);
    
    s->ele = (struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter row, column, and non-zero element:\n");
    
    for (int i = 0; i < s->num; i++)
    {
		// have to enter elements ordered from first to last position in the matrix
		// i.e. left to right and top to bottom or else it won't print correctly
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

void display(struct Sparse s)
{
    int k = 0; // index for elements in the array
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
			// going through the matrix with two for loops
			// the i and j declared in the for loops are not the same
			// as the i and j in the Element struct
			// it is checking if the current iteration of i and j in
			// the for loops matches the row(i) and column(j) of the kth element in the array
			// if it does then it prints the element and k is incremented
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
	struct Sparse *sum;
	int i = 0; // index for first array
	int j = 0; // index for second array
	int k = 0; // index for sum array
	
	sum = (struct Sparse *)malloc(sizeof(struct Sparse));
	sum->ele = (struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));
	
	while (i < s1->num && j < s2->num)
	{
		// if the first array's row is less than the second array's row
		// then add the first array's element to k and increment k and i
		if (s1->ele[i].i < s2->ele[j].i)
		{
			sum->ele[k++] = s1->ele[i++];
		}
		// if the second array's row is less than the first array's row
		// then add the second array's element to k and increment k and j
		else if (s1->ele[i].i > s2->ele[j].i)
		{
			sum->ele[k++] = s2->ele[j++];
		}
		else // if rows are equal then we check columns
		{
			// if the first array's column is less than the second array's column
			// then add the first array's element to k and increment k and i
			if (s1->ele[i].j < s2->ele[j].j)
			{
				sum->ele[k++] = s1->ele[i++];
			}
			// if the second array's column is less than the first array's column
			// then add the second array's element to k and increment k and j
			else if (s1->ele[i].j > s2->ele[j].j)
			{
				sum->ele[k++] = s2->ele[j++];
			}
			else // if columns are also equal then we copy the row and column of either arrays and add x from both arrays
			{
				sum->ele[k] = s1->ele[i];
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
			}
		}
	}
	
	for (; i < s1->num; i++) // add any remaining elements from the first array
	{
		sum->ele[k++] = s1->ele[i];
	}
	
	for (; j < s2->num; j++) // add any remaining elements from the second array
	{
		sum->ele[k++] = s2->ele[j];
	}
	
	sum->m = s1->m;
	sum->n = s1->n;
	sum->num = s1->num + s2->num;
	
	return sum;
}

int main()
{
    struct Sparse s1,s2;
	struct Sparse *s3;
    
    create(&s1);
	create(&s2);
	
	s3 = add(&s1, &s2);
	
	printf("First Matrix:\n");
	display(s1);
	
    printf("Second Matrix:\n");
	display(s2);
	
	printf("Sum Matrix:\n");
	display(*s3);
	
    return 0;
}
