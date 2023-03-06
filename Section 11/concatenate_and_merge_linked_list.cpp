#include <iostream>

using namespace std;

struct Node
{
	int data; // data of current node
	struct Node *next; // pointer points to the address of the next node
}*first = NULL,*second = NULL,*third = NULL; // first pointer is the head of the first linked list, second is the head of the second linked list, and third is the head of the merged linked list

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

// used to create the second linked list
// this is the same as the original create function but this uses the global pointer second
// there is a way to create multiple linked list with just one function
// to do that we have to use double pointers
void create2(int a[], int n)
{
	struct Node *t;
	struct Node *last;
	
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = a[0];
	second->next = NULL;
	last = second;
	
	for (int i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = a[i];
		t->next = NULL;
		
		last->next = t;
		last = t;
	}
}

// adding the second linked list behind the first linked list
// p is the first linked list and q is the second
void concat(struct Node *p, struct Node *q)
{
	third = p; // third will be the head of the concatenated linked list
	
	while (p->next != NULL) // p should stop at the last node of its linked list and not NULL
	{
		p = p->next;
	}
	
	// the last node of the first linked list will point to the first node of the second linked list
	p->next = q;
}

// merges two sorted linked list into one sorted linked list
// p is the first linked list and q is the second
void merge(struct Node *p, struct Node *q)
{
	struct Node *last; // points to the last node in the merged linked list
	
	// checks which first node in both linked list is smaller to be the first node in the merged linked list
	if (p->data < q->data) // first node in first linked list is smaller
	{
		third = p; // the first node of the merged linked list will start at the first linked list
		last = p; // the first node will also be the last
		p = p->next; // p points to the next node in the first linked list
		last->next = NULL; // points to null because there are no other nodes in the merged linked list
	}
	else // first node in second linked list is smaller
	{
		third = q; // the first node of the merged linked list will start at the second linked list
		last = q;
		q = q->next; // q points to the next node in the second linked list
		last->next = NULL;
	}
	
	while (p != NULL && q != NULL) // continue merging first and second linked list until one of them are null
	{
		if (p->data < q->data) // first linked list's node is smaller than the second linked list's node
		{
			last->next = p; // the next/new node in the merge linked list will be p
			last = p; // move the last pointer to the new node in the merge linked list
			p = p->next; // move p to the next node in the first linked list
			last->next = NULL; // points to null because last points to the last node
		}
		else // second linked list's node is smaller than the first linked list's node
		{
			last->next = q; // the next/new node in the merge linked list will be q
			last = q; // move the last pointer to the new node in the merge linked list
			q = q->next; // move q to the next node in the second linked list
			last->next = NULL; // points to null because last points to the last node
		}
	}
	
	// adding any remaining nodes to the linked list
	if (p != NULL)
	{
		last->next = p;
	}
	if (q != NULL)
	{
		last->next = q;
	}
}

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	int b[] = {5, 15, 25, 35, 45};
	create(a, 5);
	create2(b, 5);
	
	display(first);
	printf("\n");
	display(second);
	printf("\n");
	
	//concat(first, second);
	merge(first, second);
	display(third);
	
	return 0;
}