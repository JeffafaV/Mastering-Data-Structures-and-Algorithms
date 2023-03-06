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

int main()
{
    struct Sparse s;
    
    create(&s);
    display(s);

    return 0;
}
