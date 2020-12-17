#include "AVLTree.h"
#include <iostream>
#include <iomanip>
using namespace std;



AVLTree::AVLTree()
{
	root = NULL;
}


AVLTree::~AVLTree()
{
}

void AVLTree::insert(int data)
{
	if (!root)
	{
		root = new Node(data);
	}
	else
	{
		root = insert(root, data);
	}
}

Node* AVLTree::insert(Node * node, int data)
{
	if (node->data > data)
	{
		if (!node->left)
		{
			node->left = new Node(data);
		}
		else
		{
			node->left = insert(node->left, data);
		}


		if (height(node->left) - height(node->right) == 2)
		{
			if (data < node->left->data)
				node = rightRotation(node);
			else
				node = rightRightRotation(node);
		}
	}
	else
	{
		if (!node->right)
		{
			node->right = new Node(data);
		}
		else
		{
			node->right = insert(node->right, data);
		}

		if (height(node->right) - height(node->left) == 2)
		{
			if (data >= node->right->data)
				node = leftRotation(node);
			else
				node = leftLeftRotation(node);
		}
	}
	return node;
}

bool AVLTree::remove(int data)
{
	remove(root, data);
	return true;
}

Node* AVLTree::remove(Node * node, int data)
{
	Node* temp;

	if (!node)
	{
		return NULL;
	}
	else if (data < node->data)
	{
		node->left = remove(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = remove(node->right, data);
	}
	else if (node->right && node->left)
	{
		temp = minValue(node->right);
		node->data = temp->data;
		node->right = remove(node->right, node->data);
	}
	else
	{
		temp = node;

		if (node->left == NULL)
			node = node->right;
		else if (node->right == NULL)
			node = node->left;
		delete temp;
	}
	if (node == NULL)
		return node;

	if (height(node->left) - height(node->right) == 2)
	{
		if (height(node->left->left) - height(node->left->right) == 1)
			return leftRotation(node);
		else
			return leftLeftRotation(node);
	}
	else if (height(node->right) - height(node->left) == 2)
	{
		if (height(node->right->right) - height(node->right->left) == 1)
			return rightRotation(node);
		else
			return rightRightRotation(node);
	}
	return node;
}

void AVLTree::print()
{
	cout << endl << "Tree: " << endl;
	print(root, 0);
}

void AVLTree::print(Node * node, int space)
{
	if (node != NULL) 
	{
		if (node->right) 
		{
			print(node->right, space + 4);
		}
		
		if (space) 
		{
			std::cout << std::setw(space) << ' ';
		}
		
		if (node->right) std::cout << " /\n" << std::setw(space) << ' ';
		
		std::cout << node->data << "\n ";
		
		if (node->left) 
		{
			std::cout << std::setw(space) << ' ' << " \\\n";
			print(node->left, space + 4);
		}
	}
}

int AVLTree::maxValue()
{
	Node* temp = root;

	if (!temp)
		return 0;
	else
	{
		while (temp->right)
		{
			temp = temp->right;
		}
		return temp->data;
	}
}

int AVLTree::minValue()
{
	Node* temp = root;

	if (!temp)
		return 0;
	else
	{
		while (temp->left)
		{
			temp = temp->left;
		}
		return temp->data;
	}
}

int AVLTree::height()
{
	return height(root);
}

int AVLTree::height(Node * node)
{ 
	if (node == NULL)
		return 0;

	int lh = height(node->left);
	int rh = height(node->right);

	if (lh < rh)
		return rh + 1;
	else
		return 1 + lh;
}

Node* AVLTree::leftRotation(Node * node)
{
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

Node* AVLTree::rightRotation(Node * node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

Node * AVLTree::leftLeftRotation(Node * node)
{
	node->right = rightRotation(node->right);
	return leftRotation(node);
}

Node * AVLTree::rightRightRotation(Node * node)
{
	node->left = leftRotation(node->left);
	return rightRotation(node);
}

Node * AVLTree::minValue(Node * node)
{
	if (node == NULL)
		return NULL;
	else if (node->left == NULL)
		return node;
	else
		return minValue(node->left);
}

bool AVLTree::search(int data)
{
	return search(root, data);
}

bool AVLTree::search(Node * node, int data)
{
	if (!node)
		return false;
	else
	{
		if (node->data == data)
			return true;
		else
		{
			if (node->data < data)
				return search(node->right, data);
			else
				return search(node->left, data);
		}
	}
	return false;
}
