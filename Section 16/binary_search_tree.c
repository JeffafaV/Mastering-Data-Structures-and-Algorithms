#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lChild;
	int data;
	struct Node *rChild;
} *root = NULL;

void insert(int key)
{
	struct Node *t = root;
	struct Node *r;
	struct Node *p;
	
	if (root == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lChild = NULL;
		p->rChild = NULL;
		root = p;
		return;
	}
	
	while (t != NULL)
	{
		r = t;
		if (key < t->data)
		{
			t = t->lChild;
		}
		else if (key > t->data)
		{
			t = t->rChild;
		}
		else
		{
			return;
		}
	}
	
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lChild = NULL;
	p->rChild = NULL;
	
	if (key < r->data)
	{
		r->lChild = p;
	}
	else
	{
		r->rChild = p;
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

struct Node* search(int key)
{
	struct Node *t = root;
	
	while (t != NULL)
	{
		if (key == t->data)
		{
			return t;
		}
		else if (key < t->data)
		{
			t = t->lChild;
		}
		else
		{
			t = t->rChild;
		}
	}
	
	return NULL;
}

int main()
{
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);
	
	inorder(root);
	printf("\n");
	
	struct Node *temp;
	temp = search(20);
	
	if (temp != NULL)
	{
		printf("Element %d is found\n", temp->data);
	}
	else
	{
		printf("Element is not found\n");
	}
	
	return 0;
}