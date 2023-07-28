#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// used to hold the root node of the tree
struct Node *root = NULL;

// creates tree data structure
void treeCreate()
{
	// used to hold a deleted node's address from the queue
	struct Node *p;
	// used to create a new node in heap
	struct Node *t;
	// used to hold the value of the new node
	int x;
	
	// create a queue with with a max capacity of 100
	// queue is necessary for proper ordering and insertion of child nodes
	struct Queue q;
	create(&q, 100);
	
	// enter value for the root value
	printf("Enter root value: ");
	scanf("%d", &x);
	
	// creates root node in heap
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x; // set the root's value
	root->lChild = NULL; // set the root's left child to null
	root->rChild = NULL; // set the root's right child to null
	enqueue(&q, root); // insert root in the queue
	
	// continue looping until the queue is empty
	while(!isEmpty(q))
	{
		// set p to the first node in the queue
		// and delete the node from the queue
		p = dequeue(&q);
		
		// enter the value for p's left child
		// note: if -1 is inserted then the left child of p will remain null
		printf("Enter left child value of %d: ", p->data);
		scanf("%d", &x);
		
		// inserted value is not -1
		if (x != -1)
		{
			// create a new node in heap using t
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x; // set t's value
			t->lChild = NULL; // set t's left child to null
			t->rChild = NULL; // set t's right child to null
			p->lChild = t; // set p's left child to point to t
			enqueue(&q, t); // insert t which is the new node to the queue
		}
		
		// enter the value for p's right child
		// note: if -1 is inserted then the right child of p will remain null
		printf("Enter right child value of %d: ", p->data);
		scanf("%d", &x);
		
		// inserted value is not -1
		if (x != -1)
		{
			// create a new node in heap using t
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x; // set t's value
			t->lChild = NULL; // set t's left child to null
			t->rChild = NULL; // set t's right child to null
			p->rChild = t; // set p's right child to point to t
			enqueue(&q, t); // insert t which is the new node to the queue
		}
	}
}

// preorder tree traversal using recursion
void preorder(struct Node *p)
{
	// p points to a node
	if (p != NULL)
	{
		// first print current node
		printf("%d ", p->data);
		// recursive call using p's left child
		preorder(p->lChild);
		// recursive call using p's right child
		preorder(p->rChild);
	}
}

// inorder tree traversal using recursion
void inorder(struct Node *p)
{
	// p points to a node
	if (p != NULL)
	{
		// recursive call using p's left child
		inorder(p->lChild);
		// then print current node
		printf("%d ", p->data);
		// recursive call using p's right child
		inorder(p->rChild);
	}
}

// postorder tree traversal using recursion
void postorder(struct Node *p)
{
	// p points to a node
	if (p != NULL)
	{
		// recursive call using p's left child
		postorder(p->lChild);
		// recursive call using p's right child
		postorder(p->rChild);
		// lastly print current node
		printf("%d ", p->data);
	}
}

// levelorder tree traversal using iteration
void levelorder(struct Node *p)
{
	// create a queue with with a max capacity of 100
	// queue is necessary for proper ordering and traversal of child nodes
	struct Queue q;
	create(&q, 100);
	
	// prints the root node's value
	printf("%d ", p->data);
	// insert root into the queue
	enqueue(&q, p);
	
	// continue looping until queue is empty
	while (!isEmpty(q))
	{
		// set p to the first node in the queue
		// then delete that node from the queue
		p = dequeue(&q);
		
		// p has a left child
		if (p->lChild != NULL)
		{
			// print the left child's value
			printf("%d ", p->lChild->data);
			// insert left child into the queue
			enqueue(&q, p->lChild);
		}
		// p has a right child
		if (p->rChild != NULL)
		{
			// print the right child's value
			printf("%d ", p->rChild->data);
			// insert right child into the queue
			enqueue(&q, p->rChild);
		}
	}
}

int main()
{
	// create the tree data structure
	treeCreate();
	
	// prints the levelorder traversal
	printf("Levelorder:\n");
	levelorder(root);
	
	return 0;
}