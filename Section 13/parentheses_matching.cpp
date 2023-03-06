#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char data;
	struct Node *next;
}*top = NULL;

// push element to the stack
void push(char x)
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
char pop()
{
	struct Node *t; // used to delete node
	char x = -1; // default value
	
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

// checks if the parentheses are balanced in the expression
// each ( will be pushed in the stack while each ) will pop a ( from the stack
// the expression will be balanced if there is the same amount of ( and ) making the stack empty
// it will be unbalanced if there is anything left in the stack at the end
// or when the function tries to pop in an empty stack
int is_balanced(char *expr)
{
	for (int i = 0; expr[i] != '\0'; i++) // loops until it reaches end of string
	{
		if (expr[i] == '(') // push ( to the stack
		{
			push(expr[i]);
		}
		else if (expr[i] == ')') // pop ( if the stack is not empty
		{
			// if we try to pop in an empty stack that means it is unbalanced
			// because we have more ) than (
			if (top == NULL) // stack is empty
			{
				return 0; // return false
			}
			
			pop();
		}
	}
	
	// stack is empty
	if (top == NULL)
	{
		return 1; // return true
	}
	else // there is more ( than ) making it unbalanced
	{
		return 0; // return false
	}
}

int main()
{
	char expr[] = "((a+b)*(c-d))";
	
	printf("Expression: %s\n", expr);
	
	if (is_balanced(expr) == 1)
	{
		printf("The expression is balanced");
	}
	else
	{
		printf("The expression is not balanced");
	}
	
	return 0;
}