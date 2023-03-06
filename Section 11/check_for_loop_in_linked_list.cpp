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

// checks if the linked list is looping
// if q ever overlaps p and they end up on the same node then the linked list is looping
// otherwise q would reach null and it would be considered non-looping
int is_looped(struct Node *f)
{
	struct Node *p, *q; // p and q will traverse the linked list
	// both pointers start at the start of the linked list
	p = f;
	q = f;
	
	do
	{
		// p will iterate by one node while q will iterate by two nodes
		p = p->next;
		q = q->next;
		
		// to move q another node we have to first check if it is null
		// if q is not null then we can freely move it to the next node
		// however if it is null then we will be unable to move it any further
		if (q != NULL)
		{
			q = q->next;
		}
		else
		{
			q = q;
		}
	}while(p != NULL && q != NULL && p != q); // this loop will continue unless one of the pointers or both reach null or p and q equal the same
	
	// we have to add this extra if statement because for a linked list with one node that is not looping
	// the program would consider it as looping since both p and q would both be NULL
	// in all other instances q would reach null before p if it was non-looping
	if (p == NULL && q == NULL)
	{
		return 0; // false
	}
	
	if (p == q) // the linked list is looping
	{
		return 1; // true
	}
	else
	{
		return 0;
	}
}

int main()
{
	struct Node *t1, *t2; // extra pointers used to loop two nodes
	int a[] = {10, 20, 30, 40, 50};
	create(a, 5);
	
	// creating a loop in the linked list
	t1 = first->next->next; // pointing to third node
	t2 = first->next->next->next->next; // pointing to last node
	t2->next = t1; // last node pointing to third node which creates loop
	
	if (is_looped(first) == 1)
	{
		printf("The linked list is looping");
	}
	else
	{
		printf("The linked list isn't looping");
	}
	
	return 0;
}