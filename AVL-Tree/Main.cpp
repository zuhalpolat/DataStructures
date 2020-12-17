#include <iostream>
#include <conio.h>
#include "AVLTree.h"
using namespace std;

int main()
{
	AVLTree test;
	int choice, number;
	bool status;

	while (1)
	{
		cout << "\t\t\tAVL Tree" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Please select any of the following options: " << endl;
		cout << "\t1- Insert a number " << endl;
		cout << "\t2- Remove a number" << endl;
		cout << "\t3- Print" << endl;
		cout << "\t4- The Info About The Tree" << endl;
		cout << "\t5- Search A Number In The Tree" << endl;
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
		case 5:
		{
			cout << endl;
			cout << "Enter a number to search: ";
			cin >> number;
			status = test.search(number);

			if (status)
				cout << endl << " >> The value exists on the tree" << endl;
			else
				cout << endl << " >> The value does not exist on the tree" << endl;

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