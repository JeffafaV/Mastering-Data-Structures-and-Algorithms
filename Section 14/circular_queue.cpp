#include <stdio.h>
#include <stdlib.h>

// struct for circular queue using array
struct Queue
{
	int size; // size of array
	int front; // points to the front of the queue
	int rear; // points to the back of the queue
	int *q; // array pointer for dynamic size
};

// creates queue
void create(struct Queue *que, int size)
{
	que->size = size; // sets the size
	que->front = 0; // initial position of front
	que->rear = 0; // initial position of back
	que->q = (int *)malloc(que->size*sizeof(int)); // create array of size size
}

// inserts element to the queue
void enqueue(struct Queue *que, int x)
{
	// the queue is full if the position after rear is the same as front
	// remember that this is circular so if rear's position is size-1
	// then the next position is 0
	if ((que->rear+1)%que->size == que->front)
	{
		printf("Queue is full\n");
	}
	else
	{
		// since we increment that means there will be one empty block
		que->rear = (que->rear+1)%que->size; // increment rear
		que->q[que->rear] = x; // insert element at rear position
	}
}

// deletes element from the queue
int dequeue(struct Queue *que)
{
	// default value
	int x = -1;
	
	// the queue is empty if front and rear are at the same position
	if (que->front == que->rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		// this is an illusion of deleting something because
		// it's not actually deleted instead we just increment
		// the front pointer to show that its not part of the queue
		que->front = (que->front+1)%que->size; // increment front
		x = que->q[que->front]; // set x to front's element
	}
	
	// return value of deleted element or default value
	return x;
}

// displays queue
// we start at que.front+1 because front is a position
// behind the actual front of the queue
void display(struct Queue que)
{
	for (int i = (que.front+1)%que.size; i != (que.rear+1)%que.size; i = (i+1)%que.size)
	{
		printf("%d ", que.q[i]);
	}
	printf("\n");
}

// this is a good implementation but I would prefer if all available space is used
// this implementation always keeps one space empty
int main()
{
	struct Queue q;
	
	create(&q, 5);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	
	display(q);
	
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	
	display(q);
	
	return 0;
}