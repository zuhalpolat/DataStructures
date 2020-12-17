#include "BST.h"
#include <iostream>
#include <iomanip>
using namespace std;


BST::BST()
{
	root = NULL;
}


BST::~BST()
{
}

void BST::insert(int data)
{
	if (root == NULL)
	{
		root = new Node(data);
	}
	else
	{
		insert(root, data);
	}
}

void BST::insert(Node * node, int data)
{
	if (data < node->data)
	{
		if (node->left == NULL)
		{
			node->left = new Node(data);
		}
		else
		{
			insert(node->left, data);
		}
	}
	else
	{
		if (node->right == NULL)
		{
			node->right = new Node(data);
		}
		else
		{
			insert(node->right, data);
		}
	}
}

bool BST::remove(int data)
{
	return remove(NULL, root, data);
}

bool BST::remove(Node * parent, Node * current, int data)
{
	if (!current)
		return false;

	if (current->data == data)
	{
		if (!current->right && !current->left)
		{
			if (parent->left == current)
				parent->left = NULL;
			else
				parent->right = NULL;

			delete current;
			current = NULL;
			return true;
		}
		else if (!current->left || !current->right)
		{
			Node* child = current->left;

			if (!child)
				child = current->right;

			if (!parent)
			{
				this->root = child;
			}
			else
			{
				if (current->data > parent->data)
					parent->right = child;
				else
					parent->left = child;
			}

			delete current;
			current = NULL;
			return true;
		}
		else
		{
			Node* temp = current->right;
			Node* tempParent = current;

			while (temp->left != NULL)
			{
				tempParent = temp;
				temp = temp->left;
			}

			current->data = temp->data;

			if (temp->right != NULL)
			{
				tempParent->left = temp->right;
			}
			else
			{
				tempParent->left = NULL;
			}
			return true;
		}
	}
	else if (current->data > data)
		return remove(current, current->left, data);
	else
		return remove(current, current->right, data);
}

void BST::print()
{
	cout << endl << "Tree: " << endl;
	print(root, 0);
}


void BST::print(Node * node, int space)
{
	if (node != NULL) {
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

int BST::maxValue()
{
	Node* temp = root;

	if (!temp)
		return 0;
	else
	{
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp->data;
	}
}

int BST::minValue()
{
	Node* temp = root;

	if (!temp)
		return 0;
	else
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp->data;
	}
}

int BST::height()
{
	return height(root);
}

int BST::height(Node * node)
{
	if (node == NULL)
		return 0;

	// find the height of each subtree
	int lh = height(node->left);
	int rh = height(node->right);

	if (lh < rh)
		return rh + 1;
	else
		return 1 + lh;
}
