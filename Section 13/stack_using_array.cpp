#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size; // the size of the stack
	int top; // the top of the stack
	int *s; // points to the array/stack
};

// creates a stack
void create(struct Stack *st)
{
	printf("Enter size: ");
	scanf("%d", &st->size);
	st->top = -1; // an empty stack will have the top as -1
	st->s = (int*)malloc(st->size*sizeof(int)); // create array/stack in heap
}

// displays the stack/array
void display(struct Stack st)
{
	for (int i = st.top; i >= 0; i--) // prints the stack beginning with the top
	{
		printf("%d ", st.s[i]);
	}
}

// checks if stack is empty
int is_empty(struct Stack st)
{
	// stack is empty
	if (st.top == -1)
	{
		return 1;
	}
	
	return 0;
}

// checks if stack is full
int is_full(struct Stack st)
{
	// stack is full
	if (st.top == st.size-1)
	{
		return 1;
	}
	
	return 0;
}

// pushes element on the top of the stack
void push(struct Stack *st, int x)
{
	// can't push if the stack is full
	if (is_full(*st) == 1)
	{
		printf("Stack overflow\n");
	}
	else // space is available
	{
		st->top++; // move top to the next available space
		st->s[st->top] = x; // pushing element at top
	}
}

// pops the top element of the stack
int pop(struct Stack *st)
{
	int x = -1; // default value
	
	// can't pop if the stack is empty
	if (is_empty(*st) == 1)
	{
		printf("Stack underflow\n");
	}
	else // stack is not empty
	{
		// it should be noted that we are not actually removing anything
		// instead we're decrementing the top so that the original top is
		// not included in the stack anymore but it is still in the array
		x = st->s[st->top];
		st->top--;
	}
	
	return x;
}

// check an element in the stack at a given index
// position 1 is equal to the top element in the stack
// and position increments as we go down the stack
int peek(struct Stack st, int pos)
{
	int x = -1; // default value
	
	// st.top-pos+1 allows us to get the index in the array for a given position in the stack
	if (st.top-pos+1 < 0 || st.top-pos+1 > st.top) // invalid index
	{
		printf("Invalid index\n");
		return x;
	}
	
	x = st.s[st.top-pos+1];
	
	return x;
}

// returns the top element of the stack
int stack_top(struct Stack st)
{
	// stack isn't empty
	if (is_empty(st) == 0)
	{
		return st.s[st.top];
	}
	
	return -1; // stack is empty
}

int main()
{
	struct Stack st;
	create(&st);
	printf("Popping: %d\n", pop(&st));
	
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	push(&st, 50);
	push(&st, 60);
	display(st);
	printf("\n");
	
	printf("Popping: %d\n", pop(&st));
	display(st);
	
	return 0;
}