#include "Node.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void insert(int data);
	bool remove(int data);
	void print();
	int maxValue();
	int minValue();
	int height();
	bool search(int data);

private:
	Node * root;

	Node* insert(Node* node, int data);
	Node* remove(Node* node, int data);
	void print(Node* node, int space);
	int height(Node* node);
	Node* leftRotation(Node* node);
	Node* rightRotation(Node* node);
	Node* leftLeftRotation(Node* node);
	Node* rightRightRotation(Node* node);
	Node* minValue(Node* node);
	bool search(Node* node, int data);
};
