#include <stdio.h>
#include <stdlib.h>

// individual node struct
struct Node
{
	struct Node *lChild; // pointer that points to a left child node
	int data; // node's value
	struct Node *rChild; // pointer that points to a right child node
} *root = NULL; // global struct Node variable set to null

// inserts a node to the binary search tree with key as its values
// note that this binary search tree does not adjust its height
// Ex. inserting 1, 2, 3, 4, 5 in that order will cause the tree to
// have a max height of 5. However, inserting 3, 2, 5, 1, 4 in that 
// order will give the tree a max height of 3. Essentially this 
// implementation has an O(n) search time complexity because of the 
// order that the numbers are inserted
void insert(int key)
{
	// used to traverse the binary search tree if it is non-empty
	struct Node *t = root;
	// r is one node behind t and if insertion 
	// is possible then it is the parent node of 
	// the newly inserted node of a non-empty tree
	struct Node *r;
	// used to create and initialize a new node
	struct Node *p;
	
	// binary search tree has no nodes
	if (root == NULL)
	{
		// creates a new node in heap using p
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key; // set the node's value to the key's value
		p->lChild = NULL; // set node's left child to null
		p->rChild = NULL; // set node's right child to null
		root = p; // set root to p since it is the first node
		return; // end insert call
	}
	
	// traverse the binary search tree until t reaches null
	while (t != NULL)
	{
		// move r down one node to t
		r = t;
		
		// key is less than the current node's value
		if (key < t->data)
		{
			// the key is at the left branch
			// move t down to it's left child
			t = t->lChild;
		}
		// key is greater than the current node's value
		else if (key > t->data)
		{
			// the key is at the right branch
			// move t down to it's right child
			t = t->rChild;
		}
		// node's value is the same as the key
		else
		{
			// a binary search tree cannot have duplicates
			// nothing is inserted and we end the function call
			return;
		}
	}
	
	// creates a new node in heap using p
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key; // set the node's value to the key's value
	p->lChild = NULL; // set node's left child to null
	p->rChild = NULL; // set node's right child to null
	
	
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