#include <iostream>
#include "LinkedList.h"
#include <conio.h>
using namespace std;

int main()
{
	LinkedList test;
	int choice, number, position;

	while (1)
	{
		cout << "\t\tLinked List" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Please select any of the following options: " << endl;
		cout << "\t1- Insert a number at the begining" << endl;
		cout << "\t2- Insert a number at the end" << endl;
		cout << "\t3- Insert a number at any position" << endl;
		cout << "\t4- Remove a data" << endl;
		cout << "\t5- Remove a data by position index" << endl;
		cout << "\t6- Remove duplicate datas" << endl;
		cout << "\t7- Display the linked list" << endl;
		cout << "\t8- Reverse the linked list" << endl;
		cout << "\t9- Sort the linked list" << endl;
		cout << "\t10- Count the linked list" << endl;
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
				test.insertAtBegin(number);
				cout << endl;
				test.display();
				break;
			}
			case 2:
			{
				cout << "Enter a number to insert: ";
				cin >> number;
				test.insertAtEnd(number);
				cout << endl;
				test.display();
				break;
			}
			case 3:
			{
				cout << "Enter a number to insert: ";
				cin >> number;
				cout << "Enter the index: ";
				cin >> position;
				test.insertAtPosition(number, position);
				cout << endl;
				test.display();
				break;
			}
			case 4:
			{
				cout << "Enter a number to remove: ";
				cin >> number;
				test.removeByData(number);
				cout << endl;
				test.display();
				break;
			}
			case 5:
			{
				cout << "Enter the index to remove the data: ";
				cin >> position;
				test.removeByPosition(position);
				cout << endl;
				test.display();
				break;
			}
			case 6:
			{
				cout << "Before remove the duplicates: " << endl;
				test.display();
				cout << endl << "After remove the duplicates: " << endl;
				test.removeDuplicate();
				test.display();
				break;
			}
			case 7:
			{
				cout << "The linked list: " << endl;
				test.display();
				break;
			}
			case 8:
			{
				cout << "Before reversing the linked list: " << endl;
				test.display();
				cout << endl << "After reversing the linked list: " << endl;
				test.reverse();
				test.display();
				break;
			}
			case 9:
			{
				cout << "Before sorting the linked list: " << endl;
				test.display();
				cout << endl << "After sorting the linked list: " << endl;
				test.sort();
				test.display();
				break;
			}
			case 10:
			{
				cout << "The size of the linked list is " << test.count() << endl;
				cout << endl << "The linked list: ";
				test.display();
				break;
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