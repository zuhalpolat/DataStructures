#include <iostream>
#include <conio.h>
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
	DoublyLinkedList test;
	int data, position, choice;

	while (1)
	{
		cout << "\tDoubly Linked List" << endl;
		cout << "----------------------------------------" << endl;
		cout << "\t1-Insert At First" << endl;
		cout << "\t2-Insert At End" << endl;
		cout << "\t3-Insert At Position" << endl;
		cout << "\t4-Remove A Data" << endl;
		cout << "\t5-Remove By Position" << endl;
		cout << "\t6-Remove Duplicates" << endl;
		cout << "\t7-Reverse" << endl;
		cout << "\t8-Sort" << endl;
		cout << "\t9-Display" << endl;
		cout << "\t10-Count" << endl;
		cout << "\t0-Exit" << endl;

		cout << endl << endl << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				cout << "Enter a number to insert: ";
				cin >> data;
				test.insertAtBegin(data);
				test.display();
				break;
			}
			case 2:
			{
				cout << "Enter a number to insert: ";
				cin >> data;
				test.insertAtEnd(data);
				test.display();
				break;
			}
			case 3:
			{
				cout << "Enter a number to insert: ";
				cin >> data;
				cout << "Enter the position: ";
				cin >> position;
				test.insertAtPosition(data, position);
				test.display();
				break;
			}
			case 4:
			{
				cout << "Enter a number to remove: ";
				cin >> data;
				cout << "Before removing the datas: " << endl;
				test.display();
				test.removeDatas(data);
				cout << endl << "After removing the datas: " << endl;
				test.display();
				break;
			}
			case 5:
			{
				cout << "Enter an index to remove data: ";
				cin >> position;
				cout << endl << "Before removing the data: " << endl;
				test.display();
				test.removeByPosition(position);
				cout << endl << "After removing the data: " << endl;
				test.display();
				break;
			}
			case 6:
			{
				cout << endl << "Before removing the duplicates: " << endl;
				test.display();
				test.removeDuplicates();
				cout << endl << "After removing the duplicates: " << endl;
				test.display();
				break;
			}
			case 7:
			{
				cout << endl << "Before reversing: " << endl;
				test.display();
				test.reverse();
				cout << endl << "After reversing: " << endl;
				test.display();
				break;
			}
			case 8:
			{
				cout << endl << "Before sorting: " << endl;
				test.display();
				test.sort();
				cout << endl << "After sorting: " << endl;
				test.display();
				break;
			}
			case 9:
			{
				test.display();
				break;
			}
			case 10:
			{
				test.display();
				cout << endl << "The size of the linked list: " << test.count() << endl;
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
