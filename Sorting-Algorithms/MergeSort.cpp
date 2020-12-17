#include <iostream>
#include <conio.h>
using namespace std;

void insertArray(int *sarray, int size);
void printArray(int *sarray, int size);
void mergeSort(int *sarray, int size);
void merge(int *sarray, int *l, int sL, int *r, int sR);

int main()
{
	int SSarray[10];
	int sizeOfArray = 10;

	while (1)
	{
		cout << "\t\Merge Sort" << endl;
		cout << "-----------------------------------" << endl;

		insertArray(SSarray, sizeOfArray);

		cout << endl << endl << "The Array Before Sorting: " << endl;
		cout << endl << "\t\t >>  ";
		printArray(SSarray, sizeOfArray);

		mergeSort(SSarray, sizeOfArray);

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

void mergeSort(int * sarray, int size)
{
	if (size < 2)
		return;

	int mid = size / 2;
	int *l = (int *)malloc(mid * sizeof(int));
	int *r = (int *)malloc(sizeof(int)*(size - mid));

	for (int i = 0; i < mid; i++)
		l[i] = sarray[i]; 

	for (int i = mid; i < size; i++)
		r[i - mid] = sarray[i];

	mergeSort(l, mid);
	mergeSort(r, size - mid);
	merge(sarray, l, mid, r, size - mid);

}

void merge(int * sarray, int * l, int sL, int * r, int sR)
{
	int i = 0, j = 0, k = 0;

	while (i < sL && j < sR)
	{
		if (l[i] < r[j])
			sarray[k++] = l[i++];
		else
			sarray[k++] = r[j++];
	}
	
	while(i < sL)
		sarray[k++] = l[i++];

	while (j < sR)
		sarray[k++] = r[j++];

}
