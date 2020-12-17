#include <iostream>
#include <conio.h>
using namespace std;

void insertArray(int *sarray, int size);
void printArray(int *sarray, int size);
void sortArray(int *sarray, int size);

int main()
{
	int SSarray[10];
	int sizeOfArray = 10;

	while (1)
	{
		cout << "\t\tSelection Sort" << endl;
		cout << "----------------------------------------------------" << endl;

		insertArray(SSarray, sizeOfArray);

		cout << endl << endl << "The Array Before Sorting: " << endl;
		cout << endl << "\t\t >>";
		printArray(SSarray, sizeOfArray);

		sortArray(SSarray, sizeOfArray);

		cout << endl << endl << "The Array After Sorting: " << endl;
		cout << endl << "\t\t >>";
		printArray(SSarray, sizeOfArray);

		cout << endl << endl;
		cout << "Press Enter to Continue";
		_getch();
		system("cls");
	}

	system("pause");
}

void insertArray(int * sarray, int size)
{
	int number;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << ". " << "number: ";
		cin >> number;
		sarray[i] = number;
	}
}

void printArray(int * sarray, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
			cout << sarray[i] << ", ";
		else
			cout << sarray[i] << endl;
	}
}

void sortArray(int * sarray, int size)
{
	int temp, min;

	for (int i = 0; i < size; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (sarray[j] < sarray[min])
				min = j;
		}

		if (min != i)
		{
			temp = sarray[i];
			sarray[i] = sarray[min];
			sarray[min] = temp;
		}
	}
}
