#pragma once
class SortingAlgorithms
{
public:
	SortingAlgorithms();
	~SortingAlgorithms();

	void createRandomArray(int *sarray, int *sarray2, int *sarray3, int *sarray4, int *sarray5, int size);

	void BubbleSort(int *sarray, int size);
	void QuickSort(int *sarray, int low, int high);
	void InsertionSort(int *sarray, int size);
	void SelectionSort(int *sarray, int size);
	void MergeSort(int *sarray, int size);
	void Merge(int *sarray, int *l, int sL, int *r, int sR);
};

