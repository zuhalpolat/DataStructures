#include "Queue.h"
#include <iostream>
using namespace std;


Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::enqueue(int data)
{
	if (arraySize == queueSize)
		cout << endl << "The queue is full!" << endl;
	else if(isEmpty())
	{
		rearVal = frontVal = 0;
		myArray[rearVal] = data;
		queueSize++;
	}
	else
	{
		if (rearVal == 9 && queueSize != arraySize)
			rearVal = -1;

		myArray[++rearVal] = data;
		queueSize++;
	}
}

int Queue::dequeue()
{
	if (!isEmpty())
	{
		if (rearVal == frontVal)
		{
			int data = myArray[frontVal];
			myArray[frontVal] = NULL;
			rearVal = frontVal = -1;
			queueSize--;
			return data;
		}
		else
		{
			int data = myArray[frontVal];
			myArray[frontVal] = NULL;
			frontVal += 1;

			if (rearVal == frontVal)
				rearVal = frontVal = -1;

			if (frontVal >= arraySize)
				frontVal = 0;

			queueSize--;
			return data;
		}
	}
	else
		return -1;
}

int Queue::front()
{
	if (isEmpty())
		return -1;
	else 
		return myArray[frontVal];
}

bool Queue::isEmpty()
{
	if (frontVal == -1 && rearVal == -1)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if (queueSize == arraySize)
		return true;
	else
		return false;
}

void Queue::print()
{
	if (isEmpty())
		cout << endl << "The queue is empty!" << endl;
	else
	{
		cout << endl << "The queue: ";
		if (rearVal < frontVal)
		{
			for (int i = frontVal; i < arraySize; i++)
			{
				cout << myArray[i] << ", ";
			}
			for (int i = 0; i <= rearVal; i++)
			{
				if (i == rearVal)
					cout << myArray[i] << endl;
				else
					cout << myArray[i] << ", ";
			}
		}
		else
		{
			for (int i = frontVal; i <= rearVal; i++)
			{
				if (i == rearVal)
					cout << myArray[i] << endl;
				else
					cout << myArray[i] << ", ";
			}
		}
	}
}
