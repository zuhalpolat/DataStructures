#include "Node.h"

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void insertAtBegin(int data);
	void insertAtEnd(int data);
	void insertAtPosition(int data, int position);
	void removeDatas(int data);
	void removeByPosition(int position);
	void removeDuplicates();
	void reverse();
	void sort();
	void swap(Node* a, Node* b);
	int count();
	void display();

private:
	Node* head;
	Node* tail;
};

