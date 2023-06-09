#include <iostream>
#include "queue_c++.h"

class Tree
{
	private:
	Node *root;
	
	public:
	Tree()
	{
		root = NULL;
	}
	void createTree();
	void preorder(Node *p);
	void preorder(){preorder(root);}
	void postorder(Node *p);
	void postorder(){postorder(root);}
	void inorder(Node *p);
	void inorder(){inorder(root);}
	void levelorder(Node *p);
	void levelorder(){levelorder(root);}
	int height(Node *p);
	int height(){return height(root);}
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
		cout << "Enter left child value of " << p->data << ": ";
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
		
		cout << "Enter right child value of " << p->data << ": ";
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

void Tree::preorder(Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		preorder(p->lChild);
		preorder(p->rChild);
	}
}

void Tree::inorder(Node *p)
{
	if (p != NULL)
	{
		inorder(p->lChild);
		cout << p->data << " ";
		inorder(p->rChild);
	}
}

void Tree::postorder(Node *p)
{
	if (p != NULL)
	{
		postorder(p->lChild);
		postorder(p->rChild);
		cout << p->data << " ";
	}
}

void Tree::levelorder(Node *p)
{
	Queue q(100);
	
	cout << p->data << " ";
	q.enqueue(p);
	
	while (!q.isEmpty())
	{
		p = q.dequeue();
		
		if (p->lChild != NULL)
		{
			cout << p->lChild->data << " ";
			q.enqueue(p->lChild);
		}
		if (p->rChild != NULL)
		{
			cout << p->rChild->data << " ";
			q.enqueue(p->rChild);
		}
	}
}

int Tree::height(Node *p)
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
		return x+1;
	}
	
	return y+1;
}

int main()
{
	Tree t;
	t.createTree();
	cout << "Preorder:" << endl;
	t.preorder();
	cout << endl;
	cout << "Inorder:" << endl;
	t.inorder();
	cout << endl;
	cout << "Postorder:" << endl;
	t.postorder();
	cout << endl;
	cout << "Levelorder:" << endl;
	t.levelorder();
	cout << endl;
	cout << "Height:" << endl;
	cout << t.height();
	
	return 0;
}