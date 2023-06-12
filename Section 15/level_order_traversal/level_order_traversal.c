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

void levelorder(struct Node *p)
{
	struct Queue q;
	create(&q, 100);
	
	printf("%d ", p->data);
	enqueue(&q, p);
	
	while (!isEmpty(q))
	{
		p = dequeue(&q);
		
		if (p->lChild != NULL)
		{
			printf("%d ", p->lChild->data);
			enqueue(&q, p->lChild);
		}
		if (p->rChild != NULL)
		{
			printf("%d ", p->rChild->data);
			enqueue(&q, p->rChild);
		}
	}
}

int main()
{
	treeCreate();
	printf("Levelorder:\n");
	levelorder(root);
	
	return 0;
}