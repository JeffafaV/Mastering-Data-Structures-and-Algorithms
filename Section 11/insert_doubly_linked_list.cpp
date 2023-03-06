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

// get the length of the linked list
int count(struct Node *p)
{
	int len = 0; // initial length is 0
	
	while (p != NULL) // continue as long as p is not null
	{
		len++; // increment
		p = p->next; // go to next node
	}
	
	return len;
}

// inserts a node at a given index
void insert(struct Node *p, int index, int x)
{
	struct Node *t; // temporary pointer used to create new node
	
	if (index < 0 || index > count(p)) // invalid index
	{
		return;
	}
	
	if (index == 0) // inserting new node as the first node
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creating new node
		t->data = x; // setting the new node's data
		t->prev = NULL; // prev is null because it is the first node
		t->next = first; // new first node will point to the original first node
		first->prev = t; // old first node's prev will point to the new first node
		first = t; // first points to the new node t
	}
	else // inserting new node at any other valid index
	{
		for (int i = 0; i < index-1; i++) // move p to the node behind the index node
		{
			p = p->next;
		}
		
		t = (struct Node*)malloc(sizeof(struct Node)); // creating new node
		t->data = x; // setting the new node's data
		t->prev = p; // p should be behind t so prev points to p
		t->next = p->next; // the new node's next points to whatever p's next points to
		
		if (p->next != NULL) // p->next is a node
		{
			p->next->prev = t; // p's next node's prev pointer should point to t because p->next is ahead of t
		}
		p->next = t; // p node's next points to t
	}
}

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	create(a, 5);
	
	display(first);
	printf("\n");
	
	insert(first, 2, 25);
	display(first);
	
	return 0;
}