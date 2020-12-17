#include <iostream>
#include <conio.h>
#include "BST.h"
using namespace std;

int main()
{
	BST test;
	int choice, number;

	while (1)
	{
		cout << "\t\tBinary Search Tree" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Please select any of the following options: " << endl;
		cout << "\t1- Insert a number " << endl;
		cout << "\t2- Remove a number" << endl;
		cout << "\t3- Print" << endl;
		cout << "\t4- The Info About The Tree" << endl;
		cout << "\t0- Exit" << endl << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 0)
			break;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter a number to insert: ";
			cin >> number;
			test.insert(number);
			cout << endl;
			test.print();
			break;
		}
		case 2:
		{
			cout << "Enter a number to insert: ";
			cin >> number;
			test.remove(number);
			cout << endl;
			test.print();
			break;
		}
		case 3:
		{
			cout << endl;
			test.print();
			break;
		}
		case 4:
		{
			cout << endl;
			cout << "The max value in the tree: " << test.maxValue() << endl;
			cout << "The min value in the tree: " << test.minValue() << endl;
			cout << "The height of the tree: " << test.height() << endl;
			test.print();
			break;
		}
		case 0:
		{
			exit(0);
		}
		default:
		{
			cout << "Please enter a number from the menu!!" << endl;
		}
		}
		cout << endl << endl;
		cout << "Press Enter to Continue";
		_getch();
		system("cls");
	}
	system("pause");
}