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

// counts number of nodes in the linked list
int count(struct Node *p)
{
	int l = 0;
	
	while (p != NULL)
	{
		l++;
		p = p->next;
	}
	
	return l;
}

// deletes a node in the linked list and returns the value of the deleted node
int del(struct Node *p, int pos)
{
	struct Node *q = NULL; // q will be one node behind p
	int x = -1; // default value assuming linked list has no negative numbers
	
	if (pos < 1 || pos > count(p)) // invalid index
	{
		return x; // returns default and deletes nothing
	}
	
	// deleting first node
	if (pos == 1)
	{
		q = first; // q points to the first node
		x = first->data; // copy value of the first node
		first = first->next; // first points to the second node which is now the first node
		free(q); // deleting the previously first node
		return x;
	}
	else // deleting any non-first node
	{
		// moving p to the node that will be deleted and q will be behind by one node
		for (int i = 0; i < pos-1; i++)
		{
			q = p;
			p = p->next;
		}
		
		q->next = p->next; // q will point to whatever p was pointing to
		x = p->data; // copy value of the node that will be deleted
		free(p); // deleting node p
		return x;
	}
}

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	create(a, 5);
	
	display(first);
	printf("\n");
	
	cout << "Deleting: " << del(first, 4) << endl;
	display(first);
	
	return 0;
}