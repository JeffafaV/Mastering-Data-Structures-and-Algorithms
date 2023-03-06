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

void recursive_display(struct Node *p)
{
	// static means the value won't be reset to 0 for each call
	static int flag = 0; // flag is 0 to allow head to be displayed for the first time it appears
	
	// if will be false when head appears a second time
	if (p != head || flag == 0)
	{
		flag = 1; // set flag to one to stop head from being displayed again
		printf("%d ", p->data);
		recursive_display(p->next); // recursive call using the next node
	}
	
	flag = 0; // reset the flag so that when this function is called again it will work
}

int main()
{
	int a[] = {2, 3, 4, 5, 6};
	create(a, 5);
	
	display(head);
	//recursive_display(head);
	
	return 0;
}