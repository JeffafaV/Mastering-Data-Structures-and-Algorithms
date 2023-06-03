#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

// nodes used for the tree (and array)
struct Node
{
	struct Node *lChild; // left child node
	int data; // data value of node
	struct Node *rChild; // right child node
};


// Queue is a circular queue using an array
// used to help with the order of node creation for tree
// order will be top to bottom and left to right
struct Queue
{
	int size; // size of queue
	int front; // index of first node of queue
	int rear; // index of last node of queue
	// first * is for pointer and second * is for array
	struct Node **que; // holds an array of Node pointers
};

// creates array and its attributes for the circular queue
void create(struct Queue *q, int size)
{
	q->size = size; // setting size of array
	q->front = 0; // front index 0 since queue is empty
	q->rear = 0; // rear index 0 since queue is empty
	q->que = (struct Node **)malloc(q->size*sizeof(struct Node *)); // creating array of Node pointers
}

// adds a node to the array
void enqueue(struct Queue *q, struct Node *x)
{
	// queue is full
	if ((q->rear+1)%q->size == q->front)
	{
		printf("Queue is full\n");
	}
	// queue is not full
	else
	{
		// increment rear to the next position
		q->rear = (q->rear+1)%q->size;
		// set the rear node to equal to x
		q->que[q->rear] = x;
		// note that we increment first and then we set.
		// this iteration of a circular queue will
		// always have at least one empty space
	}
}

// deletes the first node from the array 
// and returns the deleted node
struct Node* dequeue(struct Queue *q)
{
	// node set to NULL, will be set to the first node in the array
	struct Node *x = NULL;
	
	// queue is empty
	if (q->front == q->rear)
	{
		printf("Queue is empty\n");
	}
	// queue is not empty
	else
	{
		// increment front to the next position
		q->front = (q->front+1)%q->size;
		// set x to equal to the front node
		x = q->que[q->front];
		// note that we don't actually delete values 
		// in the array, instead we increment the 
		// front to make it seem like a node was deleted.
		// also, front doesn't point to the first node,
		// (front+1)%size does
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