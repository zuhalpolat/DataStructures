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
		cout << "\t\Insertion Sort" << endl;
		cout << "-----------------------------------" << endl;

		insertArray(SSarray, sizeOfArray);

		cout << endl << endl << "The Array Before Sorting: " << endl;
		cout << endl << "\t\t >>  ";
		printArray(SSarray, sizeOfArray);

		sortArray(SSarray, sizeOfArray);

		cout << endl << endl << "The Array After Sorting: " << endl;
		cout << endl << "\t\t >>  ";
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
		cout << " Enter " << i + 1 << ". " << "number: ";
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
	int i, j, temp;

	for (i = 1; i < size; i++)
	{
		j = i;

		while (j > 0 && sarray[j - 1] > sarray[j])
		{
			temp = sarray[j];
			sarray[j] = sarray[j - 1];
			sarray[j - 1] = temp;
			j--;
		}
	}
}