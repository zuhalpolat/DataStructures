#include <iostream>
#include <conio.h>
#include "Queue.h"
using namespace std;

int main()
{
	int size, number, menu;
	char choice;
	Queue test;

	while (1)
	{
		cout << "\t\tQueue" << endl;
		cout << "---------------------------------" << endl;
		cout << endl << "Please select any of the following options: " << endl;
		cout << "\t1- Enqueue a number to queue" << endl;
		cout << "\t2- Dequeue a number from queue" << endl;
		cout << "\t3- Front number in the queue" << endl;
		cout << "\t4- Print the queue" << endl;
		cout << "\t0- Exit" << endl << endl;

		cout << endl << endl << "Enter the choice: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case 1:
		{
			cout << "Enter a number to insert to queue: ";
			cin >> number;
			test.enqueue(number);
			test.print();
			break;
		}
		case 2:
		{
			number = test.dequeue();
			if (number != -1)
				cout << endl << "The number " << number << " has dequeued." << endl;
			test.print();
			break;
		}
		case 3:
		{
			number = test.front();
			if (number != -1)
				cout << endl << "The number in the front is " << number << endl;
			break;
		}
		case 4:
		{
			test.print();
			break;
		}
		case 0:
		{
			exit(0);
		}
		default:
		{
			cout << "Enter a choice from the menu!!" << endl;
		}
		}
		cout << endl << endl;
		cout << "Press Enter to Continue";
		_getch();
		system("cls");
	}

	system("pause");
}