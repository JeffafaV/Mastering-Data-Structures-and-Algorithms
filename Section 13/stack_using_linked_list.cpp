#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*top = NULL;

// push element to the stack
void push(int x)
{
	struct Node *t; // used to create new node
	t = (struct Node*)malloc(sizeof(struct Node)); // create new node in heap
	
	// checking if our stack data structure is full
	// t would be null if our stack data structure is full because we wouldn't be able to create more nodes in memory
	// the stack will probably never be full since we would have to create millions of nodes to use up all of the memory
	// it would probably be better to just have a count function and a limit of nodes to test stack fullness
	if (t == NULL)
	{
		printf("Stack overflow\n");
	}
	else // stack isn't full
	{
		t->data = x;
		t->next = top; // t's next pointer points to the previous top node
		top = t; // t is the new top node
	}
}

// pop element from the stack
int pop()
{
	struct Node *t; // used to delete node
	int x = -1; // default value
	
	// checking if stack data structure is empty
	if (top == NULL)
	{
		printf("Stack underflow\n");
	}
	else // stack is not empty
	{
		t = top; // t points to the top node
		top = top->next; // the new top node is the next node
		x = t->data; // get the original node's data
		free(t); // delete the original top node
	}
	
	return x;
}

// display stack
void display()
{
	struct Node *p; // used to traverse stack/linked list
	p = top;
	
	while (p != NULL) // the last node will point to null
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	
	display();
	printf("\n");
	printf("Popping: %d\n", pop());
	display();
	
	return 0;
}