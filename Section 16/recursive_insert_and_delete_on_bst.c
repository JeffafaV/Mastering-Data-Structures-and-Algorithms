#include <stdio.h>
#include <stdlib.h>

// individual node struct
struct Node
{
	struct Node *lChild; // pointer that points to a left child node
	int data; // node's value
	struct Node *rChild; // pointer that points to a right child node
} *root = NULL; // global struct Node variable set to null

// inserts a node to the binary search tree with key as its value.
// Note, inserting 1, 2, 3, 4, 5 in that order will cause the tree to
// have a max height of 5. However, inserting 3, 2, 5, 1, 4 in that 
// order will give the tree a max height of 3. Essentially this 
// implementation has an O(n) search time complexity instead of O(log(n))
// because the numbers can be inserted in any order and this 
// binary search tree does not adjust its height to optimize search
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
	
	// new node's value is less than parent node's value
	if (key < r->data)
	{
		// set r's left child to p
		r->lChild = p;
	}
	// new node's value is greater than parent node's value
	else
	{
		// set r's right child to p
		r->rChild = p;
	}
}

// inorder traversal using recursion
// inorder will print the tree in order
// from least to greatest
void inorder(struct Node *p)
{
	// p is a node
	if (p != NULL)
	{
		// recursive call using the left child
		inorder(p->lChild);
		// then print the current node
		printf("%d ", p->data);
		// recursive call using the right child
		inorder(p->rChild);
	}
}

// search for and return a node with a given key
// if node doesn't exist then return null
struct Node* search(int key)
{
	// node pointer used to travel the binary search tree
	struct Node *t = root;
	
	// continue looping until t reaches null (end of tree)
	while (t != NULL)
	{
		// key matches the current node's value
		if (key == t->data)
		{
			// return node
			return t;
		}
		// key is less than the current node's value
		else if (key < t->data)
		{
			// set t to t's left child node
			t = t->lChild;
		}
		// key is greater than the current node's value
		else
		{
			// set t to t's right child node
			t = t->rChild;
		}
	}
	
	// reaching here means t is null, meaning
	// the key's value doesn't exist in the tree
	return NULL;
}

// inserts a node to the binary search tree with key as its value
// using recursion calls. Note that this insert also has the same 
// problem as the one above because the max tree height can be n 
// instead of log(n) depending on the order of inserts made.
// note that duplicate values can't be inserted in the tree
struct Node* rinsert(struct Node *p, int key)
{
	// p is not pointing to a node
	if (p == NULL)
	{
		// create a node pointer 
		struct Node *t = NULL;
		// use t to create a new node in heap
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key; // set t's value to key
		t->lChild = NULL; // set t's left child pointer to null
		t->rChild = NULL; // set t's right child pointer to null
		
		// return the new node's address
		// note that if this is the first insertion
		// then you must set the root when called.
		// look at the main function for example
		return t;
	}
	
	// key is less than the current node's value
	if (key < p->data)
	{
		// set p's left child to a recursive call using p's left child
		// note that this just resets the same child node for 
		// all existing nodes and is used to traverse the tree
		// and insert the new node
		p->lChild = rinsert(p->lChild, key);
	}
	// key is greater than the current node's value
	else if (key > p->data)
	{
		// set p's right child to a recursive call using p's right child
		// note that this just resets the same child node for 
		// all existing nodes and is used to traverse the tree
		// and insert the new node
		p->rChild = rinsert(p->rChild, key);
	}
	
	// return the current node's address
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