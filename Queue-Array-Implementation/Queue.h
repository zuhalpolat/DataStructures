#pragma once
class Queue
{
public:
	Queue();
	~Queue();

	void enqueue(int data);
	int dequeue();
	int front();
	bool isEmpty();
	bool isFull();
	void print();

private:
	int frontVal = -1;
	int rearVal = -1;
	int myArray[10];
	int arraySize = 10;
	int queueSize = 0;
};

