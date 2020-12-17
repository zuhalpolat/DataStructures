class Stack
{
public:
	Stack();
	~Stack();

	void push(int data);
	void pop();
	void top();
	bool isEmpty();
	void print();

private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;
};
