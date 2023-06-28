#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// the initial or root node of the binary tree
struct Node *root = NULL;

// creates a binary tree
void treeCreate()
{
	// holds a dequeued node
	struct Node *p;
	// holds a child node of p
	struct Node *t;
	// used to hold a value of a node. if the
	// value is -1 then we don't create a node
	int x;
	// used to store nodes in the queue to preserve the 
	// order that the nodes will be inserted in the tree
	struct Queue q;
	// creates q with a max  capacity of 100
	create(&q, 100);
	
	// entering value of root node
	printf("Enter root value: ");
	scanf("%d", &x);
	
	// creating root node in heap
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x; // setting root value
	root->lChild = NULL; // set left child to null
	root->rChild = NULL; // set right child to null
	enqueue(&q, root); // queue the root node
	
	// keep looping until the queue is empty
	while(!isEmpty(q))
	{	
		// p holds a dequeued node (that node is deleted from queue)
		// for this node we will either create child nodes for 
		// or we will keep its lChild, rChild, or both as null
		p = dequeue(&q);
		
		// enter value to add a left child to p or -1 for null
		printf("Enter left child value of %d: ", p->data);
		scanf("%d", &x);
		
		// add left child if x is not -1
		if (x != -1)
		{
			// use t to create a new node in heap
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x; // setting value of t
			t->lChild = NULL; // set left child to null
			t->rChild = NULL; // set right child to null
			p->lChild = t; // set p's lChild to t
			enqueue(&q, t); // insert t to the queue
		}
		
		// enter value to add a right child to p or -1 for null
		printf("Enter right child value of %d: ", p->data);
		scanf("%d", &x);
		
		// add right child if x is not -1
		if (x != -1)
		{
			// use t to create a new node in heap
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x; // setting value of t
			t->lChild = NULL; // set left child to null
			t->rChild = NULL; // set right child to null
			p->rChild = t; // set p's rChild to t
			enqueue(&q, t); // insert t to the queue
		}
	}
}

// preorder traversal of the tree
// Ex.	1
// 	   / \
//    2   3
// preorder: 1, 2, 3
void preorder(struct Node *p)
{
	// stop recursive calls when p is null
	if (p != NULL)
	{
		// first print current node
		printf("%d ", p->data);
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
void inorder(struct Node *p)
{
	// stop recursive calls when p is null
	if (p != NULL)
	{
		// recursively call left child
		inorder(p->lChild);
		// then print current node
		printf("%d ", p->data);
		// recursively call right child
		inorder(p->rChild);
	}
}

// postorder traversal of the tree
// Ex.	1
// 	   / \
//    2   3
// postorder: 2, 3, 1
void postorder(struct Node *p)
{
	// stop recursive calls when p is null
	if (p != NULL)
	{
		// recursively call left child
		postorder(p->lChild);
		// recursively call right child
		postorder(p->rChild);
		// lastly print current node
		printf("%d ", p->data);
	}
}

int main()
{
	// create tree
	treeCreate();
	// print preorder traversal of tree
	printf("Preorder:\n");
	preorder(root);
	// print inorder traversal of tree
	printf("\nInorder:\n");
	inorder(root);
	// print postorder traversal of tree
	printf("\nPostorder:\n");
	postorder(root);
	
	return 0;
}