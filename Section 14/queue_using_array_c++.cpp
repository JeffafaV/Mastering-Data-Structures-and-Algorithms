#include <iostream>

using namespace std;

// class for queue using array
class Queue
{
	private:
	int front; // points to the front of the queue
	int rear; // points to the back of the queue
	int size; // size of array
	int *q; // array pointer for dynamic size
	
	public:
	// default constructor
	Queue()
	{
		front = -1;
		rear = -1;
		size = 10;
		q = new int[size];
	}
	
	// parameterized constructor
	Queue(int size)
	{
		front = -1; // initial position of front
		rear = -1; // initial position of rear
		this->size = size; // sets the size
		q = new int[size]; // creates array of size size
	}
	
	void enqueue(int x);
	int dequeue();
	void display();
};

// inserts element to the queue
void Queue::enqueue(int x)
{
	// the queue is full if the rear pointer reaches the end of the array
	if (rear == size-1)
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		rear++; // increment rear
		q[rear] = x; // insert element at rear position
	}
}

// deletes element from the queue
int Queue::dequeue()
{
	// default value
	int x = -1;
	
	// the queue is empty if front and rear are at the same position
	if (front == rear)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		front++; // increment front
		x = q[front]; // set x to front's element
	}
	
	return x;
}

// displays queue
// we start at front+1 because front is a position
// behind the actual front of the queue
void Queue::display()
{
	for (int i = front+1; i <= rear; i++)
	{
		cout << q[i] << " ";
	}
	
	cout << endl;
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
	Queue q(5);
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	
	q.display();
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	q.display();
	
	q.enqueue(10);
	q.dequeue();
	
	return 0;
}