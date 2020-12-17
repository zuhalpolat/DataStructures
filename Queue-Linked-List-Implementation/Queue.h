class Queue
{
public:
	Queue();
	~Queue();

	void enqueue(int data);
	int dequeue();
	int front();
	bool isEmpty();
	void print();

private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;
	Node* tail;
};