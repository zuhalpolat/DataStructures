#pragma once
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
	int topValue = -1;
	int stackSize = 10;
	int myArray[10];
};

