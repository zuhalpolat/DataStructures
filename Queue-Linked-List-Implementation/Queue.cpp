#include "Queue.h"
#include <iostream>
using namespace std;


Queue::Queue()
{
	head = NULL;
	tail = NULL;
}


Queue::~Queue()
{
}

void Queue::enqueue(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;

	if (isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

int Queue::dequeue()
{
	if (isEmpty())
	{
		cout << endl << "The queue is empty!" << endl;
		return -1;
	}
	else
	{
		Node* front = head;
		int data = head->data;
		
		head = head->next;
		delete front;
		
		return data;
	}
}

int Queue::front()
{
	if (isEmpty())
		return -1;
	return head->data;
}

bool Queue::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void Queue::print()
{
	Node* temp = head;

	cout << endl << "The queue: ";
	while (temp != NULL)
	{
		if(temp->next == NULL)
			cout << temp->data << endl;
		else
			cout << temp->data << ", ";
		temp = temp->next;
	}
}
