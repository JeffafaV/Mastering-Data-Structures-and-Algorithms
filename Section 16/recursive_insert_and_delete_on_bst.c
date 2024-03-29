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

// returns the max node height of the binary search tree
int height(struct Node *p)
{
	// used to hold the max node height of the left branch
	int x;
	// used to hold the max node height of the right branch
	int y;
	
	// p is not pointing to a node
	if (p == NULL)
	{
		// there is no node so we return 0
		return 0;
	}
	
	// set x to a recursive call using p's left child
	x = height(p->lChild);
	// set y to a recursive call uisng p's right child
	y = height(p->rChild);
	
	// max height of the left branch is greater than the right
	if (x > y)
	{
		// increment 1 to include the current node and return
		return x + 1;
	}
	
	// max height of the right branch is greater than or equal to the left
	// increment 1 to include the current node and return 
	return y + 1;
}

// gets the inorder predecessor of a node when 
// given that node's left child as the parameter
// Ex.
//        30
//      /    \
//    20      40
//   /  \    /  \
//  10  25  35  45
//
// 30's inorder pred is 25
// 20's inorder pred is 10
// 40's inorder pred is 35
//
// if you were to order the nodes from least to 
// greatest than the inorder pred would be the 
// number behind our given number (as seen in ex.)
struct Node* inPred(struct Node *p)
{
	// continue looping so long as the current
	// node and right child node aren't null
	while (p != NULL && p->rChild != NULL)
	{
		// set p to p's right child
		p = p->rChild;
	}
	
	// return the inorder pred of a node
	return p;
}

// gets the inorder successor of a node when 
// given that node's right child as the parameter
// Ex.
//        30
//      /    \
//    20      40
//   /  \    /  \
//  10  25  35  45
//
// 30's inorder succ is 35
// 20's inorder succ is 25
// 40's inorder succ is 45
//
// if you were to order the nodes from least to 
// greatest than the inorder succ would be the 
// number ahead our given number (as seen in ex.)
struct Node* inSucc(struct Node *p)
{
	// continue looping so long as the current 
	// node and left node aren't null
	while (p != NULL && p->lChild != NULL)
	{
		// set p to p's left child
		p = p->lChild;
	}
	
	// return the inorder succ of a node
	return p;
}

// delete a node from the binary search tree using a given key
// kind of hard to follow but basically we change 
// the value of nodes and then we delete a leaf node 
// so that the structure of the tree stays the same
// Ex.
//        30
//      /    \
//    20      40
//   /  \    /  \
//  10  25  35  45
//
// if we want to delete 30 we have to find its pred or succ.
// since the height is the same for both sides of 30 we 
// use the successor of 30 which is 35. so we replace the value 
// of 30 to 35 and then we traverse down to the node that
// originally held the value 35. once we reach the node that held 
// 35 originally we are able to delete it. so even though we 
// are removing 30 from the tree we are actually deleting the 
// node that originally held 35. the tree ends up looking like this
//
//        35
//      /    \
//    20      40
//   /  \       \
//  10  25      45
//
// the amount of value changes depend on how many preds or succs
// we go through and we always delete a leaf node which may not
// necessarily hold the value we want to delete
struct Node* delete(struct Node *p, int key)
{
	// holds either the predecessor or successor of p
	struct Node *q;
	
	// p is not pointing to a node
	if (p == NULL)
	{
		// there is nothing to delete since the tree is empty
		return NULL;
	}
	
	// p is a leaf node and p's value is the same as the key
	if (p->lChild == NULL && p->rChild == NULL && p->data == key)
	{
		// p is the only node in the binary search tree
		if (p == root)
		{
			// set root to null since p will be deleted
			root = NULL;
		}
		
		// delete p's node
		free(p);
		
		// return null since the node doesn't exist anymore
		// so whatever node that was pointing to p will now point to null
		return NULL;
	}
	
	// key is less than the current node's value
	if (key < p->data)
	{
		// set p's left child to a recursive call using p's left child as a parameter
		// which will just reset p's left child to the address it was already pointing at
		// this is basically used for traversal and will actually not delete anything
		p->lChild = delete(p->lChild, key);
	}
	// key is greater than the current node's value
	else if (key > p->data)
	{
		// set p's right child to a recursive call using p's right child as a parameter
		// which will just reset p's right child to the address it was already pointing at
		// this is basically used for traversal and will actually not delete anything
		p->rChild = delete(p->rChild, key);
	}
	// key is equal to the current node's value
	else
	{
		// the height of the left branch is greater than the height of the right branch
		if (height(p->lChild) > height(p->rChild))
		{
			// set q to p's inorder predecessor
			q = inPred(p->lChild);
			// set p to its inorder predecessor
			p->data = q->data;
			// set p's left pointer to a recursive call using p's left pointer and q's data as the key
			// note that we don't actually delete the node here 
			// we either just reset p's left child pointer to the address it was 
			// already pointing at or we set a node's left child pointer to 
			// null after a node gets deleted. this is also used for traversal
			// also note that the predecessor becomes the new key marked for deletion
			p->lChild = delete(p->lChild, q->data);
		}
		// the height of the left branch is less than or equal to the height of the right branch
		else
		{
			// set q to p's inorder successor
			q = inSucc(p->rChild);
			// set p to its inorder successor
			p->data = q->data;
			// set p's right pointer to a recursive call using p's right pointer and q's data as the key
			// note that we don't actually delete the node here 
			// we either just reset p's right child pointer to the address it was 
			// already pointing at or we set a node's right child pointer to 
			// null after a node gets deleted. this is also used for traversal
			// also note that the successor becomes the new key marked for deletion
			p->rChild = delete(p->rChild, q->data);
		}
	}
	
	// return the current node
	return p;
}

int main()
{
	// insert values into the tree using the recursive insert function
	root = rinsert(root, 50); // must set root for first insert
	rinsert(root, 10);
	rinsert(root, 40);
	rinsert(root, 20);
	rinsert(root, 30);
	
	// delete a node from the tree
	delete(root, 30);
	
	// print all values in the tree from least to greatest
	inorder(root);
	printf("\n");
	
	// node pointer that holds a searched node's address
	struct Node *temp;
	// set temp to the searched node's address
	// if node doesn't exist then temp is set to null
	temp = search(20);
	
	// temp holds a node
	if (temp != NULL)
	{
		// print the node's value
		printf("Element %d is found\n", temp->data);
	}
	// temp doesn't hold a node
	else
	{
		// print node not found
		printf("Element is not found\n");
	}
	
	return 0;
}