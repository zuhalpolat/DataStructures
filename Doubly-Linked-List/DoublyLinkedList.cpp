#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}


DoublyLinkedList::~DoublyLinkedList()
{

}

void DoublyLinkedList::insertAtBegin(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void DoublyLinkedList::insertAtEnd(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;

	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

void DoublyLinkedList::insertAtPosition(int data, int position)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;
	Node* previous;

	if (position > count() + 1 || position < 1)
	{
		cout << "The location does not exist..." << endl;
	}
	else if (position == 1)
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	else if (position == count() + 1)
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	else
	{
		previous = head;
		for (int i = 0; i < position - 2; i++)
		{
			previous = previous->next;
		}
		temp->next = previous->next;
		temp->prev = previous;
		previous->next->prev = temp;
		previous->next = temp;
	}
}

void DoublyLinkedList::removeDatas(int data)
{
	Node* temp = head;
	Node* deleted = NULL;
	int i = 0;

	while (temp)
	{
		if (head->data == data)
		{
			deleted = temp;
			temp->next->prev = NULL;
			head = temp->next;
			delete deleted;
			temp = head;
		}
		else if (temp->data == data && temp->next == NULL)
		{
			deleted = temp;
			tail->prev->next = NULL;
			tail = temp->prev;
			delete deleted;
			temp->next = NULL;
		}
		else if(temp->data == data)
		{
			deleted = head;
			
			for (int j = 0; j < i - 1; j++)
			{
				deleted = deleted->next;
			}

			deleted->next = temp->next;
			temp->next->prev = deleted;
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

void DoublyLinkedList::removeByPosition(int position)
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
		temp->next->prev = NULL;
		head = temp->next;
		delete deleted;
		temp = head;
	}
	else if (position == count())
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		deleted = temp->next;
		temp->next = NULL;
		tail = temp;
		delete deleted;
		temp->next = NULL;
		return;
	}
	else
	{
		for (int i = 0; i < position - 1; i++)
		{
			deleted = temp;
			temp = temp->next;
		}
		deleted->next = temp->next;
		temp->next->prev = deleted;
		delete temp;
		return;
	}
}

void DoublyLinkedList::removeDuplicates()
{
	Node* temp = head;
	Node* temp2, *duplicate;

	while (temp != NULL && temp->next != NULL)
	{
		temp2 = temp;

		while (temp2->next != NULL)
		{
			if (temp->data == temp2->next->data)
			{
				duplicate = temp2->next;
				temp2->next = temp2->next->next;
				if (temp2->next != NULL)
					temp2->next->prev = temp2;
				else
					tail = temp2;
				delete duplicate;
			}
			else
				temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void DoublyLinkedList::reverse()
{
	Node* temp = head;
	Node* next = NULL;
	tail = head;

	while (temp != NULL)
	{
		next = temp->prev;
		temp->prev = temp->next;
		temp->next = next;
		temp = temp->prev;
	}
	if (next != NULL)
		head = next->prev;
}

void DoublyLinkedList::sort()
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

void DoublyLinkedList::swap(Node * a, Node * b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int DoublyLinkedList::count()
{
	Node* temp = head;
	int number = 0;

	while (temp)
	{
		number++;
		temp = temp->next;
	}
	return number;
}

void DoublyLinkedList::display()
{
	Node* temp = head;

	cout << endl << endl << "The Linked List: " << endl;

	while (temp)
	{
		cout << "Data: " << temp->data << endl;
		temp = temp->next;
	}
}
