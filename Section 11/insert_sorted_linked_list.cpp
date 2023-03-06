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

// inserts a value in a sorted array so that it continues to be sorted from least to greatest
void sorted_insert(struct Node *p, int x)
{
	struct Node *t; // points to newly created node to be inserted
	struct Node *q = NULL; // q will be behind p by one node
	
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	
	// checks to see if there are no nodes in the linked list
	// in which case our new node t will be the first node
	if (first == NULL)
	{
		first = t;
	}
	else // if not first then we have to insert our new node t in a sorted position
	{
		// checks to see if p is an actual node and if the data of that node is less than x
		// after the loop p should have the lowest number that is greater than x or null
		// and q should have the highest number that is lower than x or null
		while (p != NULL && p->data < x)
		{
			q = p; // increment q to be p
			p = p->next; // increment p to the next node
		}
		
		// if the new node should be the first node in a nonempty linked list
		if (p == first)
		{
			t->next = first; // t will point to the original first node
			first = t; // t becomes the new first node
		}
		else // new node is not the first
		{
			t->next = q->next; // t will point to what q is pointing to which is p
			q->next = t; // q will now point to t
		}
	}
}

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	create(a, 5);
	
	display(first);
	printf("\n");
	
	sorted_insert(first, 35);
	display(first);
	
	return 0;
}