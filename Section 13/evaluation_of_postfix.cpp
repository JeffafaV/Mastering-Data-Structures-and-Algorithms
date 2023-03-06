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

// checks the precedence of a given character
// precedence list from highest to lowest precedence:
// * and / 2
// + and - 1
// if any other character is entered then there is no precedence so return 0
int pre(char x)
{
	if (x == '*' || x == '/')
	{
		return 2;
	}
	else if (x == '+' || x == '-')
	{
		return 1;
	}
	
	return 0;
}

// checks to see if character is an operand
int is_operand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
	{
		return 0; // false
	}
	else
	{
		return 1; // true
	}
}

// changes the expression from infix to postfix
char *in_to_post(char *in)
{
	char *post; // used to store the postfix expression
	post = (char*)malloc(sizeof(char));
	
	int i = 0; // traverse infix
	int j = 0; // traverse postfix
	while (in[i] != '\0') // scan through infix expression
	{
		// check if current infix character is an operand
		if (is_operand(in[i]) == 1)
		{
			post[j] = in[i]; // insert current character to the postfix expression
			// increment i and j
			i++;
			j++;
		}
		else // current infix character is not an operand
		{
			int top_pre; // gets the precedence of the top element in the stack
			if (top != NULL) // element is present in the stack
			{
				top_pre = pre(top->data);
			}
			else // empty stack so top_pre will have the default value 0
			{
				top_pre = 0;
			}
			
			// checking if current infix character has a higher precedence than the top element in the stack
			if (pre(in[i]) > top_pre)
			{
				// push the current infix character into the stack and increment i
				push(in[i]);
				i++;
			}
			else // current infix character does not have a higher precedence than the top element
			{
				// pop the top element from the stack and add it to the postfix expression then increment j
				post[j] = pop();
				j++;
			}
		}
	}
	
	// popping out the rest of the stack and adding it to the postfix expression
	while (top != NULL)
	{
		post[j] = pop();
		j++;
	}
	
	return post;
}

// evaluates and solves the postfix expression
int eval(char *post)
{
	int x1; // holds the second popped item in the stack
	int x2; // holds the first popped item in the stack
	int r; // holds the result of the expression
	
	// goes through the postfix expression
	for (int i = 0; post[i] != '\0'; i++)
	{
		// check if current character in post is an operand
		if (is_operand(post[i]) == 1)
		{
			// push the operand into the stack
			push(post[i]-'0'); // the -'0' is to convert the char to an int
		}
		else // current character is not an operand
		{
			// pop the top two operands in the stack
			x2 = pop();
			x1 = pop();
			
			// switch case depending on the operator and operation that will be performed
			switch(post[i])
			{
				case '+':
					r = x1 + x2;
					break;
				case '-':
					r = x1 - x2;
					break;
				case '*':
					r = x1 * x2;
					break;
				case '/':
					r = x1 / x2;
					break;
			}
			
			// push result into the stack
			push(r);
		}
	}
	
	// returns the element on the top of the stack
	// which should be the answer of the expression
	return top->data;
}

int main()
{
	char infix[] = "2+3*4-8/2";
	printf("Infix expression: %s\n", infix);
	
	char *postfix = in_to_post(infix);
	printf("Postfix expression: %s\n", postfix);
	
	printf("Result of expression: %d", eval(postfix));
	
	return 0;
}