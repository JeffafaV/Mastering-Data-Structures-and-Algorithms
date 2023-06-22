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

struct Node* rinsert(struct Node *p, int key)
{
	if (p == NULL)
	{
		struct Node *t = NULL;
		
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lChild = NULL;
		t->rChild = NULL;
		
		return t;
	}
	
	if (key < p->data)
	{
		p->lChild = rinsert(p->lChild, key);
	}
	else if (key > p->data)
	{
		p->rChild = rinsert(p->rChild, key);
	}
	
	return p;
}

int height(struct Node *p)
{
	int x;
	int y;
	
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

struct Node* inPred(struct Node *p)
{
	while (p != NULL && p->rChild != NULL)
	{
		p = p->rChild;
	}
	
	return p;
}

struct Node* inSucc(struct Node *p)
{
	while (p != NULL && p->lChild != NULL)
	{
		p = p->lChild;
	}
	
	return p;
}

struct Node* delete(struct Node *p, int key)
{
	struct Node *q;
	
	if (p == NULL)
	{
		return NULL;
	}
	if (p->lChild == NULL && p->rChild == NULL)
	{
		if (p == root)
		{
			root = NULL;
		}
		
		free(p);
		return NULL;
	}
	
	if (key < p->data)
	{
		p->lChild = delete(p->lChild, key);
	}
	else if (key > p->data)
	{
		p->rChild = delete(p->rChild, key);
	}
	else
	{
		if (height(p->lChild) > height(p->rChild))
		{
			q = inPred(p->lChild);
			p->data = q->data;
			p->lChild = delete(p->lChild, q->data);
		}
		else
		{
			q = inSucc(p->rChild);
			p->data = q->data;
			p->rChild = delete(p->rChild, q->data);
		}
	}
	
	return p;
}

int main()
{
	root = rinsert(root, 50);
	rinsert(root, 10);
	rinsert(root, 40);
	rinsert(root, 20);
	rinsert(root, 30);
	
	delete(root, 30);
	
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