#include <iostream>

using namespace std;

struct Node
{
	int data; // data of current node
	struct Node *next; // pointer points to the address of the next node
}*first = NULL; // global pointer that points to the first node

void create(int a[], int n)
{
	struct Node *t; // temporary pointer
	struct Node *last; // points to the last node
	
	first = (struct Node*)malloc(sizeof(struct Node)); // node created in heap
	first->data = a[0]; // set first node's data to the first element in the array
	first->next = NULL; // next is NULL because there is only one node
	last = first; // first is the only node so far so it is also the last node
	
	for (int i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creates new node
		t->data = a[i]; // set the new node's data to the next array's element
		t->next = NULL; // next is NULL because it is the last node
		
		// remember that last and first are pointers that points to nodes in heap
		// first is fixed in its position and we use last to traverse the linked list
		// before last equals to the new node we first change what last->next is pointing to
		// originally pointed at null we change it to the address of the next newly created node t
		// now the previous node or the original node now points to the next node
		
		// think of nodes as their own entities
		// pointers are able to point to the node's address, and directly make changes to the node's values
		// so if a pointer changes something in the node/entity
		// then now every pointer that points to that entity/node will have the same changes
		last->next = t; // last points to the new last node
		last = t; // last equals to the new node t
	}
}

void display(struct Node *p)
{
	while (p != NULL) // checks if p is a node or null
	{
		printf("%d ", p->data); // prints data of current node
		p = p->next; // p is the next node or null if there isn't one
	}
}

// searches for an element in the linked list through linear search
struct Node *linear_search(struct Node *p, int key)
{
	while (p != NULL)
	{
		if (p->data == key) // check if current node's data is equal to the key
		{
			return p; // return current node
		}
		
		p = p->next; // p is the next node or null
	}
	
	return NULL; // key was not found
}

// searches for an element in the linked list through linear search recursively
struct Node *linear_search_recursion(struct Node *p, int key)
{
	if (p == NULL)
	{
		return NULL;
	}
	
	if (p->data == key)
	{
		return p;
	}
	
	// keeps checking the next node until p is null or key is found
	return linear_search_recursion(p->next, key);
}

// searches for an element in the linked list through linear search
// and moves node with key to the front so it can be searched again faster
struct Node *linear_move_to_front(struct Node *p, int key)
{
	struct Node *q = NULL; // q will be behind p by one node
	while (p != NULL)
	{
		if (p->data == key) // check if current node's data is equal to the key
		{
			// we're removing node p's current position and moving it to the first position
			// first thing to handle is changing what node p points to
			// p would no longer point to what it was originally pointing to
			// with q being behind p by one node, q will now point to what p was pointing to
			// then, if p were to be in the front, that means that the original first node will be second
			// therefore, p will point to the first node
			// lastly, first should point to p because p should be the first node
			q->next = p->next;
			p->next = first;
			first = p;
			
			return p; // return current node
		}
		
		q = p; // q will be the current node p
		p = p->next; // p is the next node or null
	}
	
	return NULL; // key was not found
}

int main()
{
	struct Node *temp;
	struct Node *temp2;
	struct Node *temp3;
	int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
	create(a, 8);
	
	display(first);
	printf("\n");
	
	temp = linear_search(first, 25);
	
	if (temp != NULL)
	{
		printf("Key was found: %d\n", temp->data);
	}
	else
	{
		printf("Key was not found\n");
	}
	printf("\n");
	
	temp2 = linear_search_recursion(first, 27);
	
	if (temp2 != NULL)
	{
		printf("Key was found: %d\n", temp2->data);
	}
	else
	{
		printf("Key was not found\n");
	}
	printf("\n");
	
	temp3 = linear_move_to_front(first, 25);
	
	if (temp3 != NULL)
	{
		printf("Key was found: %d\n", temp3->data);
	}
	else
	{
		printf("Key was not found\n");
	}
	
	display(first);
	
	return 0;
}