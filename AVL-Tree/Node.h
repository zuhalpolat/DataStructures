struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};