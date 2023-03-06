#include <stdio.h>
#include <stdlib.h>

// struct for queue using array
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
	que->front = -1; // initial position of front
	que->rear = -1; // initial position of back
	que->q = (int *)malloc(que->size*sizeof(int)); // create array of size size
}

// inserts element to the queue
void enqueue(struct Queue *que, int x)
{
	// the queue is full if the rear pointer reaches the end of the array
	if (que->rear == que->size-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		que->rear++; // increment rear
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
		que->front++; // increment front
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
	for (int i = que.front+1; i <= que.rear; i++)
	{
		printf("%d ", que.q[i]);
	}
	printf("\n");
}

// this implementation is really bad
// this was created in order to avoid an O(n) time
// complexity when deleting an item from the queue which it does
// however a major problem is that as we queue and unqueue we are
// essentially making the queue smaller and smaller because
// we continue to move the front pointer forward as we delete
// basically we can have a completely empty array but the program
// would say that the queue is both full and empty

// using just one pointer (rear pointer) and pushing all the elements
// to the left when we delete an item would be O(n) but would be 
// less problematic than this version
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
	
	enqueue(&q, 10);
	dequeue(&q);
	
	return 0;
}