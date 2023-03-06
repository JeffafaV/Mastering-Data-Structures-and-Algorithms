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

// inserts a node at a given index with its data x
void insert(struct Node *p, int index, int x)
{
	if (index < 0 || index > count(p)) // invalid index
	{
		return;
	}
	
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	
	if (index == 0)
	{
		// if index is 0 that means we want to insert a new node t as the first node
		// that means the original first node should be the second node
		// so t should point to the first node and we set the first node to t
		t->next = first;
		first = t;
	}
	else
	{
		// we want to insert a new node t at the specified index
		// first move to the node p that will be behind the new node t
		for (int i = 0; i < index-1; i++)
		{
			p = p->next;
		}
		
		// whatever that node p points to, the new node t should point to as well
		// then node p should point to the new node t
		t->next = p->next;
		p->next = t;
	}
}

int main()
{
	int a[] = {3, 5, 7};
	create(a, 3);
	
	display(first);
	printf("\n");
	
	insert(first, 0, 10);
	display(first);
	
	return 0;
}