#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node // each node is a term
{
	int coef; // holds coefficient
	int exp; // holds exponent
	struct Node *next; // points to the next node
}*poly = NULL;

void create()
{
	struct Node *t; // used to create new nodes
	struct Node *last = NULL; // points to the last node
	int num;
	
	printf("Enter number of terms: ");
	scanf("%d", &num);
	printf("Enter each term's coefficient and exponent:\n");
	
	for (int i = 0; i < num; i++) // creating new node and setting each node/term's values
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		scanf("%d%d", &t->coef, &t->exp);
		t->next = NULL;
		
		if (poly == NULL) // linked list is empty
		{
			poly = t; // poly points to the new node
			last = t; // t is both the first and last node
		}
		else // linked list is not empty
		{
			last->next = t; // last node points to new node
			last = t; // t becomes new last node
		}
	}
}

// displays polynomial
void display(struct Node *p)
{
	while (p != NULL)
	{
		if (p->next != NULL) // current node isn't the last node
		{
			printf("%dx^%d + ",p->coef,p->exp);
		}
		else // current node is the last node
		{
			printf("%dx^%d",p->coef,p->exp);
		}
		
		p = p->next;
	}
}

// finds the sum of the polynomial
// x is the missing x variable in the polynomial
long eval(struct Node *p, int x)
{
	long val = 0;
	
	while(p != NULL)
	{
		// coefficient times x to the power of exponent
		val += p->coef*pow(x,p->exp); // adding current term to the overall value
		p = p->next; // move to next node
	}
	
	return val;
}

int main()
{
	create();
	display(poly);
	printf("\n");
	printf("Sum of polynomial: %ld", eval(poly, 1));
	
	return 0;
}