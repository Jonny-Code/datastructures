//Jon Sledge
//COP2535.001
//Intro to stacks, static stack
#include<iostream>
using namespace std;

template <class T>
class Stack
{
private:
	T* stackArray;
	int stackSize;
	int top;

public:
	Stack(int);
	void push(T);
	void pop(T &);
	bool isFull();
	bool isEmpty();
};

//-----------------Method Definitions---------------//

//Stack constructor
template<class T>
Stack<T>::Stack(int size) {
	stackArray = new T[size];
	stackSize = size;
	top = -1;
}

//Stack push
template<class T>
void Stack<T>::push(T num) {
	if (isFull())
	{
		cout << "The stack is full! " << endl << endl;
		exit(1111);
	}
	else
	{
		top++;
		stackArray[top] = num;
	}
}

//Stack pop
template<class T>
void Stack<T>::pop(T &num) {
	if (isEmpty())
	{
		cout << "The stack is empty! " << endl << endl;
		exit(2222);
	}
	else
	{
		num = stackArray[top];
		top--;
	}
}

//Stack isFull
template<class T>
bool Stack<T>::isFull() {
	if (top == stackSize - 1)
		return true;
	else
		return false;
}

//Stack isEmpty
template <class T>
bool Stack<T>::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

int main() {
	Stack<float> Stack(5);

	float catchVar;

	//push 5 values into the stack
	for (int i = 0; i < 5; i++)
	{
		Stack.push(i + 1);
		cout << "Pushing : " << (i + 1) << endl;
	}

	cout << endl << endl;

	//pop off the stack
	for (int j = 0; j < 5; j++)
	{
		Stack.pop(catchVar);
		cout << "Popping : " << catchVar << endl;
	}

	return 0;
}