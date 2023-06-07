#include <iostream>
#include "queue_c++.h"

class Tree
{
	public:
	Node *root;
	Tree()
	{
		root = NULL;
	}
	void createTree();
	void preorder();
	void postorder();
	void inorder();
	void levelorder();
	void height();
};

void Tree::createTree()
{
	Node *p;
	Node *t;
	int x;
	Queue q(100);
	
	cout << "Enter root value: ";
	cin >> x;
	
	root = new Node;
	root->data = x;
	root->lChild = NULL;
	root->rChild = NULL;
	q.enqueue(root);
	
	while(!q.isEmpty())
	{
		p = q.dequeue();
		cout << "Enter left child value of " << p->data << ":";
		cin >> x;
		
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lChild = NULL;
			t->rChild = NULL;
			p->lChild = t;
			q.enqueue(t);
		}
		
		cout << "Enter right child value of " << p->data << ":";
		cin >> x;
		
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lChild = NULL;
			t->rChild = NULL;
			p->rChild = t;
			q.enqueue(t);
		}
	}
}

void Tree::preorder(struct Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		preorder(p->lChild);
		preorder(p->rChild);
	}
}

void Tree::inorder(struct Node *p)
{
	if (p != NULL)
	{
		inorder(p->lChild);
		cout << p->data << " ";
		inorder(p->rChild);
	}
}

void Tree::postorder(struct Node *p)
{
	if (p != NULL)
	{
		postorder(p->lChild);
		postorder(p->rChild);
		cout << p->data << " ";
	}
}

void Tree::levelorder(struct Node *p)
{
	
}

int Tree::height(struct Node *p)
{
	
}

int main()
{
	treeCreate();
	printf("Preorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPostorder:\n");
	postorder(root);
	
	return 0;
}