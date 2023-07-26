#ifndef STACK_H
#define STACK_H

#include "queue.h" // only needed for the Node struct

// creating a structure for a stack data structure
struct Stack
{
	int size; // size of stack
	int top; // points to the top of the stack
	struct Node **s; // used to hold an array of Node pointers
};

// initializes the stack
void stackCreate(struct Stack *st, int size)
{
	st->size = size; // set stack size
	st->top = -1; // set stack top
	st->s = (struct Node **)malloc(st->size*sizeof(struct Node *)); // create array of Node pointers with a max capacity of size
}

// pushes elements to the top of the stack
void push(struct Stack *st, struct Node *x)
{
	// the stack is full
	if (st->top == st->size-1)
	{
		printf("Stack overflow\n");
	}
	// stack is not full
	else
	{
		// increment top
		st->top++;
		// insert x to the stack using top as an index
		st->s[st->top] = x;
	}
}

// deletes a node pointer from the struct and returns the deleted node pointer
struct Node *pop(struct Stack *st)
{
	// node pointer that will be used to hold the deleted node pointer
	struct Node *x = NULL;
	
	// there is nothing in the stack
	if (st->top == -1)
	{
		printf("Stack underflow\n");
	}
	// there is something in the stack
	else
	{
		// first set x to the node pointer at the top of the stack
		// and then decrement top
		x = st->s[st->top--];
	}
	
	// returns the deleted node pointer
	return x;
}

// check to see if stack is empty
int isEmptyStack(struct Stack st)
{
	// stack is empty
	if (st.top == -1)
	{
		return 1;
	}
	
	// stack is not empty
	return 0;
}

// check to see if stack is full
int isFullStack(struct Stack st)
{
	// the stack is full
	if (st.top == st.size-1)
	{
		return 1;
	}
	
	// the stack is not full
	return 0;
}

#endif