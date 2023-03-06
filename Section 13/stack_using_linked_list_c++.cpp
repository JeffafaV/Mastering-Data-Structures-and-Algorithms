#include <iostream>

using namespace std;

// individual nodes in the stack
class Node
{
	public:
	int data; // data/element in node
	Node *next; // pointer to the next node
};

// stack functions and points to the top of the stack
class Stack
{
	private:
	Node *top; // this will point to the top node
	
	public:
	// constructor
	// top will initially be null
	Stack()
	{
		top = NULL;
	}
	
	void push(int x); // push an element in the stack
	int pop(); // pop an element from the stack
	void display(); // display stack
};

void Stack::push(int x)
{
	Node *t = new Node;
	
	// check if stack is full
	// t will be null if all memory is used up because there will be no more space to create new nodes
	if (t == NULL)
	{
		cout << "Stack overflow" << endl;
	}
	else // stack is not full
	{
		t->data = x; // set the data of new node t
		t->next = top; // t should point to the original top node
		top = t; // t is the new top node
	}
}

int Stack::pop()
{
	int x = -1; // default value
	
	// checking if stack is empty
	if (top == NULL)
	{
		cout << "Stack underflow" << endl;
	}
	else // stack is not empty
	{
		Node *t = top; // create new pointer t that points to top
		top = top->next; // move top to the next node
		x = t->data; // copy the original top's data
		delete t; // delete original top node
	}
	
	return x;
}

void Stack::display()
{
	Node *p = top;
	while (p != NULL) // traverse the stack with p until null is reached
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	Stack stk;
	
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.display();
	
	cout << endl;
	cout << "Popping: " << stk.pop() << endl;
	stk.display();
	
	return 0;
}