#include "SortingAlgorithms.h"
#include <iostream>
#include <random>
using namespace std;


SortingAlgorithms::SortingAlgorithms()
{
}


SortingAlgorithms::~SortingAlgorithms()
{
}

void SortingAlgorithms::createRandomArray(int *sarray, int *sarray2, int *sarray3, int *sarray4, int *sarray5, int size)
{
	for (int i = 0; i < size; i++)
	{
		sarray[i] = rand() % 10000 +1;
		sarray2[i] = sarray[i];
		sarray3[i] = sarray[i];
		sarray4[i] = sarray[i];
		sarray5[i] = sarray[i];
	}
}

void SortingAlgorithms::BubbleSort(int * sarray, int size)
{
	int temp, j = 0;
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		j++;

		for (int i = 0; i < size - j; i++)
		{
			if (sarray[i] > sarray[i + 1])
			{
				temp = sarray[i];
				sarray[i] = sarray[i + 1];
				sarray[i + 1] = temp;

				swapped = true;
			}
		}
	}
}

void SortingAlgorithms::QuickSort(int * sarray, int low, int high)
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
		QuickSort(sarray, low, j);

	if (i < high)
		QuickSort(sarray, i, high);
}

void SortingAlgorithms::InsertionSort(int * sarray, int size)
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

void SortingAlgorithms::SelectionSort(int * sarray, int size)
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

void SortingAlgorithms::MergeSort(int * sarray, int size)
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

	MergeSort(l, mid);
	MergeSort(r, size - mid);
	Merge(sarray, l, mid, r, size - mid);
}

void SortingAlgorithms::Merge(int * sarray, int * l, int sL, int * r, int sR)
{
	int i = 0, j = 0, k = 0;

	while (i < sL && j < sR)
	{
		if (l[i] < r[j])
			sarray[k++] = l[i++];
		else
			sarray[k++] = r[j++];
	}

	while (i < sL)
		sarray[k++] = l[i++];

	while (j < sR)
		sarray[k++] = r[j++];
}
