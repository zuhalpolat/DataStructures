#include <iostream>
#include <conio.h>
#include "Stack.h"
using namespace std;

int main()
{
	int size, number, menu;
	char choice;
	Stack test;

	while (1)
	{
		cout << "\t\tStack" << endl;
		cout << "------------------------------" << endl;
		cout << "Please select any of the following options: " << endl;
		cout << "\t1- Push a number to stack" << endl;
		cout << "\t2- Pop the number from the satck" << endl;
		cout << "\t3- Top number in the stack" << endl;
		cout << "\t4- Print the stack" << endl;
		cout << "\t0- Exit" << endl << endl;

		cout << endl << endl << "Enter the choice: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case 1:
		{
			cout << "Enter a number to push to stack: ";
			cin >> number;
			test.push(number);
			test.print();
			break;
		}
		case 2:
		{
			test.pop();
			test.print();
			break;
		}
		case 3:
		{
			test.top();
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
