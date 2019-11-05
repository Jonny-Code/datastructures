//Jon Sledge
//COP2535.001
//introductiong to linked lists

#include<iostream>
using namespace std;

class ListNode
{
public:
	ListNode(double v, ListNode *p)
	{
		value = v;
		next = p;
	}

private:
	double value;
	ListNode *next;
	friend class LinkedList;
};

class LinkedList
{
public:
	void add(double x);
	bool isMember(double x);
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList();
private:
	ListNode *head;
};

//--------------------method definitions-----------------------//

void LinkedList::add(double x) {
	head = new ListNode(x, head);
}

bool LinkedList::isMember(double x) {
	ListNode *p = head;

	while (p != NULL)
	{
		if (p->value == x) return true;
		else p = p->next;
	}

	return false;
}

//linked list destructor
//deallocates memory for the linked list
LinkedList::~LinkedList() {
	while (head != 0)
	{
		ListNode *p = head;
		head = head->next;
		delete p;
	}
}

int main() {

	//variables
	LinkedList list1;

	cout << "This program constructs a list of numbers "
		<< "and allows the user to check numbers on list. "
		<< endl << endl;

	cout << "enter 5 numbers: " << endl;
	for (int i = 0; i < 5; i++)
	{
		float x;
		cin >> x;
		list1.add(x);
	}

	//let user test
	
	for (int i = 0; i < 5; i++)
	{
		float x;
		cout << "Enter a number to check if its in the list: " << endl;
		cin >> x;

		if (list1.isMember(x)) cout << x << " is on the list!" << endl;
		else cout << x << " is not on list list!" << endl;

	}

	return 0;
}