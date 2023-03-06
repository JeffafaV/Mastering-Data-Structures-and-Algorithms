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

// deletes node and returns its value based on specified position
int del(struct Node *p, int pos)
{
	struct Node *q = NULL; // q should be behind p by one node
	// default value in case invalid position was entered
	int x = -1; // this value can be changed if the linked list also has negative numbers
	
	if (pos < 1 || pos > count(head)) // invalid position
	{
		return x;
	}
	
	if (pos == 1) // deleting head node
	{
		while (p->next != head) // move p to the last node (node that points to head)
		{
			p = p->next;
		}
		
		x = head->data; // copy the head node's data
		
		if (head == p) // check if head is the only node
		{
			free(head); // delete head node
			head = NULL; // head pointer points to null
		}
		else // head is not the only node
		{
			p->next = head->next; // the last node should point to what head is pointing at
			free(head); // delete the head node
			head = p->next; // head points to the node that the last node is pointing at
		}
	}
	else // deleting any other node
	{
		// moving p to the node that will be deleted and q will be behind by one node
		for (int i = 0; i < pos-1; i++)
		{
			q = p;
			p = p->next;
		}
		
		x = p->data; // copy node p's data
		q->next = p->next; // q's node should point to whatever p's node is pointing at
		free(p); // delete p
	}
	
	return x;
}

int main()
{
	int a[] = {2, 3, 4, 5, 6};
	create(a, 5);
	display(head);
	printf("\n");
	
	printf("Deleting: %d\n", del(head, 1));
	display(head);
	
	return 0;
}