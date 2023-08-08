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

int main()
{
	// inserting values into the binary search tree
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);
	
	// printing the tree using inorder traversal
	// which will print the values in order
	inorder(root);
	printf("\n");
	
	// node pointer used to hold a node
	struct Node *temp;
	// set temp to the node with a given the key
	temp = search(20);
	
	// node with key was found 
	if (temp != NULL)
	{
		// print node's value
		printf("Element %d is found\n", temp->data);
	}
	// node with key was not found
	else
	{
		// print node not found
		printf("Element is not found\n");
	}
	
	return 0;
}