#include "Node.h"
#include <string>

class LinkedList
{  
public:
	LinkedList();
	~LinkedList();

	void insertAtBegin(int data);
	void insertAtEnd(int data);
	void insertAtPosition(int data, int position);
	void removeByData(int data);
	void removeByPosition(int position);
	void removeDuplicate();
	void display();
	void reverse();
	void sort();
	void swap(Node* a, Node* b);
	int count();
	

private:
	Node* head;
	Node* tail;
};
