#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(int data)
{
	if (topValue >= stackSize - 1)
		cout << endl << "Stack Overflow!" << endl;
	else
		myArray[++topValue] = data;
}

void Stack::pop()
{
	if (isEmpty())
		cout << endl << "The stack is empty!" << endl;
	else
		cout << endl << "The " << myArray[topValue--] << " popped." << endl;
}

void Stack::top()
{
	if (isEmpty())
		cout << endl << "The stack is empty!" << endl;
	else
		cout << endl << "The top value is " << myArray[topValue] << endl;
}

bool Stack::isEmpty()
{	
	if (topValue < 0)
		return true;
	else
		return false;
}

void Stack::print()
{
	cout << endl << "The stack: ";
	for (int i = 0; i <= topValue; i++)
	{
		if (i != topValue)
			cout << myArray[i] << ", ";
		else
			cout << myArray[i];
	}
}
