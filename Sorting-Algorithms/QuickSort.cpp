#include <iostream>
#include <conio.h>
using namespace std;

void insertArray(int *sarray, int size);
void printArray(int *sarray, int size);
void sortArray(int *sarray, int low, int high);

int main()
{
	int SSarray[10];
	int sizeOfArray = 10;

	while (1)
	{
		cout << "\t\Quick Sort" << endl;
		cout << "-----------------------------------" << endl;

		insertArray(SSarray, sizeOfArray);

		cout << endl << endl << "The Array Before Sorting: " << endl;
		cout << endl << "\t\t >>  ";
		printArray(SSarray, sizeOfArray);

		sortArray(SSarray, 0, sizeOfArray - 1);

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

void sortArray(int * sarray, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = sarray[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (sarray[i] < pivot)
			i++;
		while (sarray[j] > pivot)
			j--;

		if (i <= j)
		{
			temp = sarray[i];
			sarray[i] = sarray[j];
			sarray[j] = temp;
			
			i++;
			j--;
		}
	}
	if (j > low)
		sortArray(sarray, low, j);

	if (i < high)
		sortArray(sarray, i, high);
}