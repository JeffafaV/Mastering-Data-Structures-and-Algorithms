#include <iostream>
#include "queue_c++.h"

// class used to create a tree
class Tree
{
	private:
	// the initial or root node of the binary tree
	Node *root;
	
	public:
	// default constructor
	Tree()
	{
		// setting root to null
		root = NULL;
	}
	void createTree(); // creates a binary tree
	void preorder(Node *p); // preorder traversal of the tree
	void preorder(){preorder(root);} // used to publicly call preorder with private root variable
	void postorder(Node *p); // postorder traversal of the tree
	void postorder(){postorder(root);} // used to publicly call postorder with private root variable
	void inorder(Node *p); // inorder traversal of the tree
	void inorder(){inorder(root);} // used to publicly call inorder with private root variable
	void levelorder(Node *p); // levelorder traversal of the tree
	void levelorder(){levelorder(root);} // used to publicly call levelorder with private root variable
	int height(Node *p); // gets the max height of a tree
	int height(){return height(root);} // used to publicly call height with private root variable
};

// creates a binary tree
void Tree::createTree()
{
	// holds a dequeued node
	Node *p;
	// holds a child node of p
	Node *t;
	// used to hold a value of a node. if the
	// value is -1 then we don't create a node
	int x;
	// creates q with a max capacity of 100
	// used to store nodes in a queue to preserve the 
	// order that the nodes will be inserted in the tree
	Queue q(100);
	
	// entering value of root node
	cout << "Enter root value: ";
	cin >> x;
	
	// creating root node in heap
	root = new Node;
	root->data = x; // setting root value
	root->lChild = NULL; // set left child to null
	root->rChild = NULL; // set right child to null
	q.enqueue(root); // queue the root node
	
	// keep looping until the queue is empty
	while(!q.isEmpty())
	{
		// p holds a dequeued node (that node is deleted from queue)
		// for this node we will either create child nodes for 
		// or we will keep its lChild, rChild, or both as null
		p = q.dequeue();
		
		// enter value to add a left child to p or -1 for null
		cout << "Enter left child value of " << p->data << ": ";
		cin >> x;
		
		// add left child if x is not -1
		if (x != -1)
		{
			// use t to create a new node in heap
			t = new Node;
			t->data = x; // setting value of t
			t->lChild = NULL; // set left child to null
			t->rChild = NULL; // set right child to null
			p->lChild = t; // set p's lChild to t
			q.enqueue(t); // insert t to the queue
		}
		
		// enter value to add a right child to p or -1 for null
		cout << "Enter right child value of " << p->data << ": ";
		cin >> x;
		
		// add right child if x is not -1
		if (x != -1)
		{
			// use t to create a new node in heap
			t = new Node;
			t->data = x; // setting value of t
			t->lChild = NULL; // set left child to null
			t->rChild = NULL; // set right child to null
			p->rChild = t; // set p's rChild to t
			q.enqueue(t); // insert t to the queue
		}
	}
}

// preorder traversal of the tree
// Ex.	1
// 	   / \
//    2   3
// preorder: 1, 2, 3
void Tree::preorder(Node *p)
{
	// stop recursive calls when p is null
	if (p != NULL)
	{
		// first print current node
		cout << p->data << " ";
		// recursively call left child
		preorder(p->lChild);
		// recursively call right child
		preorder(p->rChild);
	}
}

// inorder traversal of the tree
// Ex.	1
// 	   / \
//    2   3
// inorder: 2, 1, 3
void Tree::inorder(Node *p)
{
	// stop recursive calls when p is null
	if (p != NULL)
	{
		// recursively call left child
		inorder(p->lChild);
		// then print current node
		cout << p->data << " ";
		// recursively call right child
		inorder(p->rChild);
	}
}

// postorder traversal of the tree
// Ex.	1
// 	   / \
//    2   3
// postorder: 2, 3, 1
void Tree::postorder(Node *p)
{
	// stop recursive calls when p is null
	if (p != NULL)
	{
		// recursively call left child
		postorder(p->lChild);
		// recursively call right child
		postorder(p->rChild);
		// lastly print current node
		cout << p->data << " ";
	}
}

// levelorder traversal of the tree
// Ex.	1
// 	   / \
//    2   3
// levelorder: 1, 2, 3
void Tree::levelorder(Node *p)
{
	// creates q with a max capacity of 100
	// used to store nodes in a queue to preserve 
	// the order that the nodes will be printed
	Queue q(100);
	
	// print the initial or root node
	cout << p->data << " ";
	// queue the root node
	q.enqueue(p);
	
	// keep looping until the queue is empty
	while (!q.isEmpty())
	{
		// p holds a dequeued node (that node is deleted from queue)
		// for this node we will check if it has any child nodes
		p = q.dequeue();
		
		// check to see if p has a lChild
		if (p->lChild != NULL)
		{
			// print the left child
			cout << p->lChild->data << " ";
			// queue the left child
			q.enqueue(p->lChild);
		}
		// check to see if p has a rChild
		if (p->rChild != NULL)
		{
			// print the right child
			cout << p->rChild->data << " ";
			// queue the right child
			q.enqueue(p->rChild);
		}
	}
}

// returns the maximum height of the tree
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