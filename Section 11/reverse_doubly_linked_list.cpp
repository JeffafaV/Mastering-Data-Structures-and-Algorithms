#include <iostream>

using namespace std;

// a doubly linked list has nodes that can point to the next and previous nodes
struct Node
{
	struct Node *prev; // prev pointer points to the previous node
	int data; // data of current node
	struct Node *next; // next pointer points to the next node
}*first = NULL; // global pointer that points to the first node

void create(int a[], int n)
{
	struct Node *t; // temporary pointer
	struct Node *last; // points to the last node
	
	first = (struct Node*)malloc(sizeof(struct Node)); // node created in heap
	first->data = a[0]; // set first node's data to the first element in the array
	first->prev = NULL; // prev is null because there is only one node
	first->next = NULL; // next is null because there is only one node
	last = first; // first is the only node so far so it is also the last node
	
	for (int i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creates new node
		t->data = a[i]; // set the new node's data to the next array's element
		t->next = NULL; // next is NULL because it is the last node
		t->prev = last; // prev is the previous last node
		last->next = t; // previous last node points to the new last node
		last = t; // last points to the new node t
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

// reverses the linked list by reversing the links of each node
void reverse(struct Node *p)
{
	struct Node *t; // used to help swap pointers
	
	// to reverse the linked list all we have to do is swap the next and prev pointers
	// and then first should point to the last node of the linked list because it is now the first
	while (p != NULL) // continue until p is null
	{
		t = p->next; // save p->next to t
		p->next = p->prev; // next will now be the previous
		p->prev = t; // previous will now be the next
		
		// finding the first node by checking if the previous node is null
		if (p->prev == NULL) // the first node shouldn't have a previous node
		{
			first = p; // the last node is now the first node
		}
		
		p = p->prev; // since previous points to the next node we iterate through the linked list with prev
	}
}

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	create(a, 5);
	
	display(first);
	printf("\n");
	
	reverse(first);
	display(first);
	
	return 0;
}