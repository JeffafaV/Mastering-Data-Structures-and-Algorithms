#include <iostream>

using namespace std;

struct Node
{
	int data; // data of current node
	struct Node *next; // pointer points to the address of the next node
}*head = NULL; // global pointer that points to the head node

void create(int a[], int n)
{
	struct Node *t; // temporary pointer
	 // points to the last node
	struct Node *last; // in a circular linked list the last node points to the head node, not null
	
	head = (struct Node*)malloc(sizeof(struct Node)); // node created in heap
	head->data = a[0]; // set head node's data to the first element in the array
	head->next = head; // next points to head because there is only one node and it is circular
	last = head; // head is the only node so far so it is also the last node
	
	for (int i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creates new node
		t->data = a[i]; // set the new node's data to the next array's element
		t->next = last->next; // t is the new last node and the last node should be pointing to the head node
		
		last->next = t; // last points to the new last node
		last = t; // last equals to the new node t
	}
}

void display(struct Node *p)
{
	// using a do while loop so that the head node can be displayed
	do
	{
		printf("%d ", p->data); // display current node's data
		p = p->next; // move to next node
	}while (p != head); // continues as long as p is not the head node
}

// gets the length of the linked list
int count(struct Node *p)
{
	int len = 0; // initial length is 0
	
	// this if is in case p is null
	// without the if, the do while will make the length as 1
	// which is wrong because if the head is null that means the length is 0
	if (p == NULL)
	{
		return len;
	}
	
	// the do is so that we are able to print the initial head node once
	do
	{
		len++;
		p = p->next;
	}while (p != head); // continues as long as p is not the head node
	
	return len;
}

// inserts node with its data in a specified index
void insert(struct Node *p, int index, int x)
{
	struct Node *t; // used to create new node
	
	if (index < 0 || index > count(p)) // invalid index
	{
		return;
	}
	
	if (index == 0) // inserting new node as the first node
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creates new node
		t->data = x; // setting the new node's data
		
		if (head == NULL) // creating first node in an empty linked list
		{
			head = t; // the new node is the only node so it is also the head node
			head->next = head; // the new node loops itself
		}
		else // inserting new node as head node in a non-empty linked list
		{
			while (p->next != head) // p will point to the last node (the node that points to head)
			{
				p = p->next;
			}
			
			p->next = t; // the last node will point to the new node
			t->next = head; // the new head node will point to the previous head node
			head = t; // the new node is the head node
		}
	}
	else // inserting new node at any other valid index
	{
		// moving p to the correct node which is the node behind the index node
		for (int i = 0; i < index-1; i++)
		{
			p = p->next;
		}
		
		t = (struct Node*)malloc(sizeof(struct Node)); // creates new node
		t->data = x; // setting the new node's data
		t->next = p->next; // the new node t will point to whatever p is pointing to
		p->next = t; // p points to t
	}
}

int main()
{
	int a[] = {2, 3, 4, 5, 6};
	create(a, 5);
	display(head);
	printf("\n");
	
	insert(head, 2, 10);
	display(head);
	
	return 0;
}