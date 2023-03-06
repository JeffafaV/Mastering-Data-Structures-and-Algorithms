#include <iostream>

using namespace std;

// class for a single node
class Node
{
	public:
	int data; // data of the node
	Node *next; // pointer to point to the next node or null in the linked list
};

// complete linked list with all nodes
// utilizes the node class
class LinkedList
{
	private:
	Node *first; // points to first node in the linked list
	
	public:
	// default constructor
	LinkedList() // linked list will be initially empty so first points to null
	{
		first = NULL;
	}
	
	// parameterized constructor creates linked list with a given size and array of values
	LinkedList(int a[], int n);
	~LinkedList(); // destructor deletes entire linked list
	
	void display(); // display linked list
	void insert(int index, int x); // insert node at a given index
	int del(int pos); // delete node at a given position
	int length(); // size of linked list
};


LinkedList::LinkedList(int a[], int n)
{
	Node *last; // points to the last node
	Node *t; // creates a new node
	
	first = new Node; // creating the first node
	first->data = a[0]; // setting data of the node to the first element in the array
	first->next = NULL; // first points to null because it is the only node
	last = first; // since we have only one node it is also the last
	
	for (int i = 1; i < n; i++) // sets the rest of the nodes
	{
		t = new Node; // create next new node
		t->data = a[i]; // the new node's data is set to the next element in the array
		t->next = NULL; // it points to null because it is the last node
		last->next = t; // set the previous last node to point to the newly created node
		last = t; // set last to the new last node
	}
}

LinkedList::~LinkedList()
{
	Node *p = first; // p points to the first node
	while (p != NULL) // true until p is null
	{
		first = first->next; // move first to the next node
		delete p; // delete the previous first node with the help of p
		p = first; // set p to equal the new first node
	}
}

void LinkedList::display()
{
	Node *p = first; // p points to the first node
	
	while (p != NULL)
	{
		cout << p->data << " "; // print current node's data
		p = p->next; // move p to the next node
	}
}

int LinkedList::length()
{
	Node *p = first; // p points to the first node
	int len = 0; // starting length is 0
	
	while (p != NULL)
	{
		len++; // iterate to count current node
		p = p->next; // move p to the next node
	}
	
	return len; // return length
}

void LinkedList::insert(int index, int x)
{
	Node *p = first; // p points to the first node
	Node *t; // used to help create new node
	
	if (index < 0 || index > length()) // if index is out of bounds then do nothing and return
	{
		return;
	}
	
	t = new Node; // creating new node
	t->data = x; // set the data of the new node to x
	t->next = NULL; // the new node currently points to null
	
	if (index == 0) // inserting at index 0
	{
		t->next = first; // the new node will be the first node so it has to point to previous first node
		first = t; // the new node becomes the new first node
	}
	else // inserting at any other valid index
	{
		for (int i = 0; i < index-1; i++) // move pointer p to the correct index
		{
			p = p->next;
		}
		
		t->next = p->next; // the new node will point to whatever p was pointing to
		p->next = t; // p points to the new node t
	}
}

int LinkedList::del(int pos)
{
	Node *q = NULL; // q will be behind p by one node
	Node *p; // declaring pointer p
	int x = -1; // default data if position is out of scope
	
	if (pos < 1 || pos > length()) // position is out of scope
	{
		return x;
	}
	
	if (pos == 1) // want to delete the first node
	{
		p = first; // set p to the first node
		first = first->next; // set the second node to be the new first node
		x = p->data; // copy the previous first node's data
		delete p; // delete old first node
	}
	else // want to delete any other valid node
	{
		p = first; // set p to the first node
		
		for (int i = 0; i < pos-1; i++) // move pointer p and q to the correct position
		{
			q = p;
			p = p->next;
		}
		
		q->next = p->next; // set q to point to whatever p is pointing to
		x = p->data; // copy node p's data
		delete p; // delete p's node
	}
	
	return x; // return deleted value
}

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	LinkedList l(a, 5);
	
	l.display();
	cout << endl;
	cout << "Current length of the linked list is " << l.length() << endl;
	
	l.insert(3, 10);
	l.display();
	cout << endl;
	
	cout << "Deleting " << l.del(3) << " from the linked list" << endl;
	l.display();
	
	return 0;
}