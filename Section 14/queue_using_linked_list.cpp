#include <stdio.h>
#include <stdlib.h>

// queue using linked list by chaining nodes
struct Node
{
	int data; // contains data of node
	struct Node *next; // points to the next node
}*front = NULL, *rear = NULL; // front and rear pointers of the linked list

// adds element to the queue
void enqueue(int x)
{
	// temporary pointer used to create the new node
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	
	// check if the pointer was able to allocate memory in heap
	// if it couldn't then we can consider the queue as full
	if (t == NULL)
	{
		printf("Queue is full\n");
	}
	else
	{
		t->data = x; // set the new node's data to x
		t->next = NULL; // set the new node's next pointer to null
		
		// check if the new node is the first node of the linked list
		if (front == NULL)
		{
			// new node is the first node so both front and rear equal to t
			front = t;
			rear = t;
		}
		else
		{
			rear->next = t; // the last node's next pointer points to the new node
			rear = t; // the new node is the new last node in the linked list
		}
	}
}

// deletes element from the queue
int dequeue()
{
	// default value
	int x = -1;
	
	// temporary pointer used to delete the first node
	struct Node *t;
	
	// check if the linked list is not empty
	if (front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		x = front->data; // set x to the first node's data
		t = front; // set t to point to the front node
		front = front->next; // set front to point to the next node
		free(t); // delete the original first node
	}
	
	// returns deleted element or default value
	return x;
}

// displays queue
void display()
{
	struct Node *p = front;
	
	// loops through all the nodes in the linked list
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	
	printf("\n");
}

// I would like to implement a linked list with no global struct variables
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	
	display();
	
	printf("%d\n", dequeue());
	
	display();
	
	return 0;
}