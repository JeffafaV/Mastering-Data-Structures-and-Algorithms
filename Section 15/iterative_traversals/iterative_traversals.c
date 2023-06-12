#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

struct Node *root = NULL;

void treeCreate()
{
	struct Node *p;
	struct Node *t;
	int x;
	struct Queue q;
	create(&q, 100);
	
	printf("Enter root value: ");
	scanf("%d", &x);
	
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lChild = NULL;
	root->rChild = NULL;
	enqueue(&q, root);
	
	while(!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter left child value of %d: ", p->data);
		scanf("%d", &x);
		
		if (x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lChild = NULL;
			t->rChild = NULL;
			p->lChild = t;
			enqueue(&q, t);
		}
		
		printf("Enter right child value of %d: ", p->data);
		scanf("%d", &x);
		
		if (x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lChild = NULL;
			t->rChild = NULL;
			p->rChild = t;
			enqueue(&q, t);
		}
	}
}

void preorder(struct Node *p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		preorder(p->lChild);
		preorder(p->rChild);
	}
}

void inorder(struct Node *p)
{
	if (p != NULL)
	{
		inorder(p->lChild);
		printf("%d ", p->data);
		inorder(p->rChild);
	}
}

void postorder(struct Node *p)
{
	if (p != NULL)
	{
		postorder(p->lChild);
		postorder(p->rChild);
		printf("%d ", p->data);
	}
}

void ipreorder(struct Node *p)
{
	struct Stack stk;
	stackCreate(&stk, 100);
	
	while (p || !isEmptyStack(stk))
	{
		if (p != NULL)
		{
			printf("%d ", p->data);
			push(&stk, p);
			p = p->lChild;
		}
		else
		{
			p = pop(&stk);
			p = p->rChild;
		}
	}
}

void iinorder(struct Node *p)
{
	struct Stack stk;
	stackCreate(&stk, 100);
	
	while (p || !isEmptyStack(stk))
	{
		if (p != NULL)
		{
			push(&stk, p);
			p = p->lChild;
		}
		else
		{
			p = pop(&stk);
			printf("%d ", p->data);
			p = p->rChild;
		}
	}
}

int main()
{
	treeCreate();
	printf("Preorder:\n");
	preorder(root);
	printf("\nIterative Preorder:\n");
	ipreorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nIterative Inorder:\n");
	iinorder(root);
	
	return 0;
}