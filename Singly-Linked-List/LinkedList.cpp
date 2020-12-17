#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::insertAtBegin(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void LinkedList::insertAtEnd(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::insertAtPosition(int data, int position)
{
	int size;
	size = count();

	if (position > size)
	{
		cout << "It is not possible to insert at this position..." << endl;
	}
	else
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = nullptr;

		Node* temp2 = head;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else if (position == 1)
		{
			insertAtBegin(data);
		}
		else if (position == size + 1)
		{
			tail->next = temp;
			tail = temp;
		}
		else
		{
			for (int i = 0; i < position - 2; i++)
			{
				temp2 = temp2->next;
			}
			temp->next = temp2->next;
			temp2->next = temp;
		}
	}
}


void LinkedList::removeByPosition(int position)
{
	Node* temp = head;
	Node* previous = NULL;

	if (head != nullptr && position == 1)
	{
		Node* new_head = NULL;
		new_head->next = temp->next;
		delete temp;
		temp = head = new_head;
		return;
	}
	else if (position == count())
	{
		Node* deleted = NULL;

		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = deleted;
		delete deleted;
		tail = temp;
		temp->next = NULL;
		return;
	}
	for (int i = 0; i < position - 1; i++)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = temp->next;
	delete temp;
}

void LinkedList::removeByData(int data)
{
	Node* temp = head;
	Node* deleted;
	int i = 0;

	while(temp->next != NULL)
	{
		if (i == 0 && temp->data == data)
		{
			deleted = temp;
			head = temp->next;
			delete deleted;
			temp = head;
		}
		else if (i == count() - 2 && temp->next->data == data)
		{
			deleted = temp->next;
			delete deleted;
			tail = temp;
			temp->next = NULL;
		}
		else if (temp->data == data)
		{
			deleted = head;
			for (int j = 0; j < i - 1; j++)
			{
				deleted = deleted->next;
			}
			deleted->next = temp->next;
			delete temp;
			temp = deleted;
		}
		if (temp->next != NULL)
		{
			temp = temp->next;
			i++;
		}
		else 
			return;
	}
}

void LinkedList::removeDuplicate()
{
	Node* temp = head;
	Node* duplicate, *temp2;
	int ddata;

	while (temp != NULL && temp->next != NULL)
	{
		temp2 = temp;

		while (temp2->next != NULL)
		{
			if (temp->data == temp2->next->data)
			{
				duplicate = temp2->next;
				temp2->next = temp2->next->next;
				delete duplicate;
			}
			else
				temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void LinkedList::display()
{
	Node* temp = head;
	if (temp == NULL)
	{
		cout << "No data in the list..." << endl;
		return;
	}
	while (temp)
	{
		cout << "Data: " << temp->data << endl;
		temp = temp->next;
	}
}

void LinkedList::reverse()
{
	Node* temp = head;
	Node* prev = NULL;
	Node* next = NULL;

	while (temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
}

void LinkedList::sort()
{
	int swapped, i;
	Node* temp = head;
	Node* next = NULL;

	if (temp == NULL)
		return;
	do {
		swapped = 0;
		temp = head;

		while (temp->next != next)
		{
			if (temp->data > temp->next->data)
			{
				swap(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
	} while (swapped);
}


void LinkedList::swap(Node * a, Node * b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int LinkedList::count()
{
	Node* temp = head;
	int number = 0;

	if (temp == NULL)
		return 0;
	while (temp)
	{
		temp = temp->next;
		number++;
	}
	return number;
}
