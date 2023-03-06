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

// removes duplicates in a sorted linked list
void remove_duplicate(struct Node *p)
{
	struct Node *q = p->next; // q will be one node ahead of p
	
	while (q != NULL)
	{
		if (p->data != q->data) // not a duplicate, increment q and p
		{
			p = q;
			q = q->next;
		}
		else // duplicate
		{
			p->next = q->next; // p points to whatever q is pointing to
			free(q); // delete q
			q = p->next; // q points to one node ahead of p
		}
	}
}

int main()
{
	int a[] = {10, 20, 20, 20, 30, 40, 40, 40, 50};
	create(a, 9);
	
	display(first);
	printf("\n");
	
	remove_duplicate(first);
	display(first);
	
	return 0;
}