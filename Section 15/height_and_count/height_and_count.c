#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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

int count(struct Node *p)
{
	if (p != NULL)
	{
		return count(p->lChild)+count(p->rChild)+1;
	}
	
	return 0;
}

int height(struct Node *p)
{
	int x = 0;
	int y = 0;
	
	if (p == NULL)
	{
		return 0;
	}
	
	x = height(p->lChild);
	y = height(p->rChild);
	
	if (x > y)
	{
		return x + 1;
	}
	
	return y + 1;
}

int main()
{
	treeCreate();
	printf("Count: %d\n", count(root));
	printf("Height: %d\n", height(root));
	
	return 0;
}