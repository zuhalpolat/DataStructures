#include "Node.h"

class BST
{
public:
	BST();
	~BST();

	void insert(int data);
	bool remove(int data);
	void print();
	int maxValue();
	int minValue();
	int height();

private:
	Node* root;

	void insert(Node* node, int data);
	bool remove(Node* parent, Node* current, int data);
	void print(Node* node, int space);
	int height(Node* node);
};

