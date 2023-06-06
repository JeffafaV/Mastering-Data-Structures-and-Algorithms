#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

// nodes used for the tree (and array)
class Node
{
	public:
	Node *lChild; // left child node
	int data; // data value of node
	Node *rChild; // right child node
};


// Queue is a queue using an array
// used to help with the order of node creation for tree
// order will be top to bottom and left to right
class Queue
{
	private:
	int size; // size of queue
	int front; // index of first node of queue
	int rear; // index of last node of queue
	// first * is for pointer and second * is for array
	Node **que; // holds an array of Node pointers
	
	public:
	// default constructor that creates array and sets member variables for the queue
	Queue()
	{
		front = -1; // initial position of front for empty queue
		rear = -1; // initial position of rear for empty queue
		size = 10; // default size for array used for queue
		que = new Node*[size]; // creating array of Node pointers
	}
	// parameterized constructor that creates array and sets member variables for the queue
	Queue(int size)
	{
		front = -1; // initial position of front for empty queue
		rear = -1; // initial position of rear for empty queue
		this->size = size; // given size for array used for queue
		que = new Node*[size]; // creating array of Node pointers
	}
	void enqueue(Node *x); // adds a node to the array
	Node* dequeue(); // deletes the first node from the array and returns it
	
};

// adds a node to the array
void Queue::enqueue(Node *x)
{
	// queue is full
	if (rear == size-1)
	{
		cout << "Queue is full" << endl;
	}
	// queue is not full
	else
	{
		// increment rear to the next position
		rear++;
		// set the rear node to equal to x
		que[rear] = x;
		// note that we increment first and then we set.
		// this iteration of a queue will move the rear 
		// pointer until it reaches the end of the array
	}
}

// deletes the first node from the array 
// and returns the deleted node
Node* Queue::dequeue()
{
	// node set to NULL, will be set to the first node in the array
	Node *x = NULL;
	
	// queue is empty
	if (front == rear)
	{
		cout << "Queue is empty" << endl;
	}
	// queue is not empty
	else
	{
		// increment front to the next position
		front++;
		// set x to equal to the front node
		x = q->que[q->front];
		// note that we don't actually delete values 
		// in the array, instead we increment the 
		// front to make it seem like a node was deleted.
		// also, front doesn't point to the first node,
		// front+1 does. also, as front moves forward, 
		// the max capacity of the queue/array shrinks
	}
	
	// returns node x which was the first node in the queue and 
	// it will be the next node that will be created in the tree
	return x;
}

// check to see if queue is empty
int isEmpty(struct Queue q)
{
	// front and rear are the same index
	// meaning the queue is empty
	if (q.front == q.rear)
	{
		return 1;
	}
	
	// queue is not empty
	return 0;
}

#endif