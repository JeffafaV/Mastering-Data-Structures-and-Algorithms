#include <iostream>

using namespace std;

struct Term
{
	int coef; // coefficient
	int ex; // variable's exonent
};

struct Poly
{
	int n; // number of terms in the polynomial
	struct Term *t; // an array of terms or coefficients and exponents
};

void create(struct Poly *p)
{
	printf("Number of terms in the polynomial: ");
	scanf("%d", &p->n);
	p->t = (struct Term*)malloc(p->n*sizeof(struct Term));
	
	printf("Enter coefficient and exonent:\n");
	for (int i = 0; i < p->n; i++)
	{
		scanf("%d%d", &p->t[i].coef, &p->t[i].ex);
	}
}

void display(struct Poly p)
{
	for (int i = 0; i < p.n; i++)
	{
		if (i+1 != p.n)
		{
			printf("%dx^%d+", p.t[i].coef, p.t[i].ex);
		}
		else
		{
			printf("%dx^%d", p.t[i].coef, p.t[i].ex);
		}
	}
	printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
	int i = 0; // index for first polynomial
	int j = 0; // index for second polynomial
	int k = 0; // index for the sum polynomial
	struct Poly *sum;
	
	sum = (struct Poly*)malloc(sizeof(struct Poly));
	sum ->t = (struct Term*)malloc((p1->n+p2->n)*sizeof(struct Term));
	
	while (i < p1->n && j < p2->n)
	{
		// if the first polynomial's exponent is greater then the second polynomial's exponent
		// then add the first polynomial's term to the sum polynomial and increment i and k
		if (p1->t[i].ex > p2->t[j].ex)
		{
			sum->t[k++] = p1->t[i++];
		}
		// if the second polynomial's exponent is greater then the first polynomial's exponent
		// then add the second polynomial's term to the sum polynomial and increment j and k
		else if (p1->t[i].ex < p2->t[j].ex)
		{
			sum->t[k++] = p2->t[j++];
		}
		else // both exponents are equal
		{
			// add any polynomial's exponenet because they are the same
			// add the first and second polynomial's coefficients and increment i, j, and k
			sum->t[k].ex = p1->t[i].ex;
			sum->t[k++].coef = p1->t[i++].coef + p2->t[j++].coef;
		}
	}
	
	// add any remaining terms from the polynomials
	for (; i < p1->n; i++)
	{
		sum->t[k++] = p1->t[i];
	}
	for (; j < p2->n; j++)
	{
		sum->t[k++] = p2->t[j];
	}
	
	sum->n = k;
	
	return sum;
}

int main()
{
	struct Poly p1, p2;
	struct Poly *p3;
	
	create(&p1);
	create(&p2);
	
	p3 = add(&p1,&p2);
	
	printf("First polynomial:\n");
	display(p1);
	printf("Second polynomial:\n");
	display(p2);
	printf("Sum polynomial:\n");
	display(*p3);
	
	return 0;
}