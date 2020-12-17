#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
{
	head = nullptr;
}


Stack::~Stack()
{
}

void Stack::push(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Stack::pop()
{
	Node* deleted = head;

	if (isEmpty())
		cout << endl << "The stack is empty!" << endl;
	else
	{
		cout << endl << "The " << head->data << " popped." << endl;
		head = head->next;
		delete deleted;
	}
}

void Stack::top()
{
	if (isEmpty())
		cout << endl << "The stack is empty!" << endl;
	else
	{
		cout << endl << "The top value is " << head->data << endl;
	}
}

bool Stack::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void Stack::print()
{
	Node* temp = head;
	
	cout << endl << "Stack: ";
	while (temp)
	{
		if (temp->next != NULL)
			cout << temp->data << ",";
		else
			cout << temp->data;
		temp = temp->next;
	}
}
