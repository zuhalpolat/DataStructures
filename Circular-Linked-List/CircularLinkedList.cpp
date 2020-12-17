#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

CircularLinkedList::CircularLinkedList()
{
}


CircularLinkedList::~CircularLinkedList()
{
}

void CircularLinkedList::insertAtBegin(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	Node* previous;

	if (head == NULL)
	{
		head = temp;
		head->next = head;
	}
	else
	{
		previous = head;

		while (previous->next != head)
		{
			previous = previous->next;
		}
		previous->next = temp;
		temp->next = head;
		head = temp;
	}
}

void CircularLinkedList::insertAtEnd(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	Node* previous;

	if (head == NULL)
	{
		head = temp;
		head->next = head;
	}
	else
	{
		previous = head;

		while (previous->next != head)
		{
			previous = previous->next;
		}
		previous->next = temp;
		temp->next = head;
	}
}

void CircularLinkedList::insertAtPosition(int data, int position)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;

	Node* previous;

	if (position > count() + 1 || position < 1)
	{
		cout << "The location does not exist..." << endl;
	}
	else if (position == 1)
	{
		previous = head;

		while (previous->next != NULL)
		{
			previous = previous->next;
		}
		previous->next = temp;
		temp->next = head;
		head = temp;
	}
	else if (position == count() + 1)
	{
		previous = head;

		while (previous->next != NULL)
		{
			previous = previous->next;
		}
		previous->next = temp;
		temp->next = head;
	}
	else
	{
		previous = head;
		for (int i = 0; i < position - 2; i++)
		{
			previous = previous->next;
		}
		temp->next = previous->next;
		previous->next = temp;
	}
}

void CircularLinkedList::removeDatas(int data)
{
	Node* temp = head;
	Node* deleted = NULL, *previous;
	int i = 0;

	while (temp->next != head)
	{
		if (head->data == data)
		{
			previous = head;
			
			while (previous->next != head)
			{
				previous = previous->next;
			}
			deleted = head;
			previous->next = head->next;
			delete deleted;
			head = previous->next;
			temp = head;
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
		if (temp->next != head)
		{
			temp = temp->next;
			i++;
		}
		else
			return;
	}
}

void CircularLinkedList::removeByPosition(int position)
{
	Node* temp = head;
	Node* deleted = temp;

	if (position < 1 || position > count())
	{
		cout << "The position does not exist!!" << endl;
	}
	else if (position == 1)
	{
		deleted = temp;
		
		while (deleted->next != head)
		{
			deleted = deleted->next;
		}
		deleted->next = head->next;
		head = deleted->next;
	}
	else
	{
		for (int i = 0; i < position - 1; i++)
		{
			deleted = temp;
			temp = temp->next;
		}
		deleted->next = temp->next;
		delete temp;
		return;
	}
}

void CircularLinkedList::removeDuplicates()
{
	Node* temp = head;
	Node* temp2, *duplicate;

	while (temp->next != head)
	{
		temp2 = temp;

		while (temp2->next != head)
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

void CircularLinkedList::reverse()
{
	Node* temp = head;
	Node* next, *previous = NULL;

	do {
		next = temp->next;
		temp->next = previous;
		previous = temp;
		temp = next;
	} while (temp != head);

	head->next = previous;
	head = previous;
}

void CircularLinkedList::sort()
{
	int swapped, i;
	Node* temp = head;
	Node* next = NULL;

	if (temp == NULL)
		return;
	do {
		swapped = 0;
		temp = head;

		while (temp->next != head)
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

void CircularLinkedList::swap(Node * a, Node * b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int CircularLinkedList::count()
{
	Node* temp = head;
	int number = 0;
	
	do {
		number++;
		temp = temp->next;
	} while (temp != head);
	
	return number;
}

void CircularLinkedList::display()
{
	Node* temp = head;

	cout << endl << endl << "The Linked List: " << endl;
	
	do {
		cout << "Data: " << temp->data << endl;
		temp = temp->next;
	} while (temp != head);
}