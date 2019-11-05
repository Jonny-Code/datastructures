//Jon Sledge
//COP2535.001
//Queues

#include<iostream>

template <class T>
class Queue
{
private:
	T *queueArray;
	int queueSize;
	int front;
	int rear;
	int numItems;

public:
	Queue(int capacity);
	~Queue();
	void enqueue(T);
	void dequeue(T&);
	bool isEmpty();
	bool isFull();
	void clear();
};

//-------------------method definitions------------------//

template <class T>
Queue<T>::Queue(int capacity) {
	queueArray = new T[capacity];
	queueSize = capacity;
	front = -1;
	rear = -1;
	numItems = 0;
}

template<class T>
Queue<T>::~Queue() {
	delete[] queueArray;
}

template<class T>
void Queue<T>::enqueue(T val) {
	if (isFull()) {
		std::cout << "The queue is full!" << std::endl;
		exit(1111);
	}
	else {
		//calculate the new rear position
		rear = (rear + 1) % queueSize;
		//insert new item
		queueArray[rear] = val;
		//update item count
		numItems++;
	}
}

template <class T>
void Queue<T>::dequeue(T&val) {
	if (isEmpty()) {
		std::cout << "The queue is empty!" << std::endl;
		exit(2222);
	}
	else {
		//move front
		front = (front + 1) % queueSize;
		//retrieve the front item
		val = queueArray[front];
		//update item count
		numItems--;
	}
}

template<class T>
bool Queue<T>::isEmpty() {
	if (numItems == 0)
		return true;
	else
		return false;
}

template<class T>
bool Queue<T>::isFull() {
	if (numItems < queueSize)
		return false;
	else
		return true;
}

template<class T>
void Queue<T>::clear() {
	front = -1;
	rear = -1;
	numItems = 0;
}

//--------------driver---------------//

int main() {
	Queue<float> Queue(5);

	//enqueue 5 items
	std::cout << "Enqueuing 5 items: " << std::endl;
	for (int i = 0; i < 5; i++)
		Queue.enqueue(i*1.1);

	std::cout << "The values in the queue are...\n";

	while (!Queue.isEmpty()) {
		float value;
		Queue.dequeue(value);
		std::cout << value << std::endl;
	}


	return 0;
}