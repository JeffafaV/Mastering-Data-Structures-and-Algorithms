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

// this way is not recommended if the linked list has multiple data in it
// our linked list has only one piece of data for each node
// this version reverses the data of the nodes and not the links themselves
void reverse_data(struct Node *p)
{
	int *a; // creating pointer
	struct Node *q = p; // used to traverse linked list
	
	a = (int *)malloc(sizeof(int)*count(p)); // creating array in heap with the size of the linked list
	
	int i = 0;
	while (q != NULL)
	{
		a[i] = q->data; // store current node's data into the array
		q = q->next; // q increments to the next node
		if (q != NULL)
		{
			i++; // increment index in array
		}
	}
	
	q = p; // q should point to the first node again
	
	while (q != NULL)
	{
		q->data = a[i]; // change node's data to what is stored in the array
		q = q->next; // q increments to the next node
		i--; // decrement index in array
	}
}

// this way is the recommended way to reverse a linked list
// this version reverses the direction of each link of each node
// this means each node keeps its values but it changes what it points to
void reverse_link(struct Node *p)
{
	struct Node *q = NULL; // behind p by one node
	struct Node *r = NULL; // behind q by one node
	
	while (p != NULL) // increment all pointers
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r; // this step is reversing the link of each node to r which is behind q by one
	}
	
	// q which is the last node should now be the first node because the linked list was reversed
	first = q;
}

// similar as reverse_link but with recursion
// the first call of this function in main should use NULL for q and first for p
void reverse_link_recursive(struct Node *q, struct Node *p)
{
	if (p != NULL)
	{
		reverse_link_recursive(p, p->next); // recursive call
		// p is ahead of q
		// this line reverses the link by swapping p and q for each call
		p->next = q;
	}
	else
	{
		first = q; // q which was the last node should now be the first node in the linked list
	}
}

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	create(a, 5);
	
	display(first);
	printf("\n");
	
	//reverse_data(first);
	//reverse_link(first);
	reverse_link_recursive(NULL, first);
	display(first);
	
	return 0;
}