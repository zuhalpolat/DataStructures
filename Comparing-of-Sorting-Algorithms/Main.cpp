#include <iostream>
#include <chrono>
#include "SortingAlgorithms.h"
using namespace std;

int main()
{
	SortingAlgorithms test;

	int array1[10], array2[100], array3[1000];
	int array4[10], array5[100], array6[1000];
	int array7[10], array8[100], array9[1000];
	int array10[10], array11[100], array12[1000];
	int array13[10], array14[100], array15[1000];

	test.createRandomArray(array1, array4, array7, array10, array13, 10);
	test.createRandomArray(array2, array5, array8, array11, array14, 100);
	test.createRandomArray(array3, array6, array9, array12, array15, 1000);

	cout << "\t\t Comparison of The Sorting Algorithms" << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;

	cout << "\t\t      10 Number \t 100 Number \t 1000 Number" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	auto start = chrono::steady_clock::now();
	test.QuickSort(array4, 0, 10 - 1);
	auto end = chrono::steady_clock::now();
	auto diff1 = end - start;

	start = chrono::steady_clock::now();
	test.QuickSort(array5, 0, 100 - 1);
	end = chrono::steady_clock::now();
	auto diff2 = end - start;

	start = chrono::steady_clock::now();
	test.QuickSort(array6, 0, 1000 - 1);
	end = chrono::steady_clock::now();
	auto diff3 = end - start;

	cout << endl << endl << "Quick Sort:\t     " << chrono::duration <double, milli>(diff1).count() << " ms\t\t" << chrono::duration <double, milli>(diff2).count() << " ms\t" << chrono::duration <double, milli>(diff3).count() << " ms";

	start = chrono::steady_clock::now();
	test.MergeSort(array7, 10);
	end = chrono::steady_clock::now();
	diff1 = end - start;

	start = chrono::steady_clock::now();
	test.MergeSort(array8, 100);
	end = chrono::steady_clock::now();
	diff2 = end - start;

	start = chrono::steady_clock::now();
	test.MergeSort(array9, 1000);
	end = chrono::steady_clock::now();
	diff3 = end - start;

	cout << endl << endl << "Merge Sort:\t     " << chrono::duration <double, milli>(diff1).count() << " ms\t\t" << chrono::duration <double, milli>(diff2).count() << " ms\t" << chrono::duration <double, milli>(diff3).count() << " ms";

	start = chrono::steady_clock::now();
	test.SelectionSort(array10, 10);
	end = chrono::steady_clock::now();
	diff1 = end - start;

	start = chrono::steady_clock::now();
	test.SelectionSort(array11, 100);
	end = chrono::steady_clock::now();
	diff2 = end - start;

	start = chrono::steady_clock::now();
	test.SelectionSort(array12, 1000);
	end = chrono::steady_clock::now();
	diff3 = end - start;

	cout << endl << endl << "Selection Sort:\t     " << chrono::duration <double, milli>(diff1).count() << " ms\t\t" << chrono::duration <double, milli>(diff2).count() << " ms\t" << chrono::duration <double, milli>(diff3).count() << " ms";

	start = chrono::steady_clock::now();
	test.InsertionSort(array13, 10);
	end = chrono::steady_clock::now();
	diff1 = end - start;

	start = chrono::steady_clock::now();
	test.InsertionSort(array14, 100);
	end = chrono::steady_clock::now();
	diff2 = end - start;

	start = chrono::steady_clock::now();
	test.InsertionSort(array15, 1000);
	end = chrono::steady_clock::now();
	diff3 = end - start;

	cout << endl << endl << "Insertion Sort:\t     " << chrono::duration <double, milli>(diff1).count() << " ms\t\t" << chrono::duration <double, milli>(diff2).count() << " ms\t" << chrono::duration <double, milli>(diff3).count() << " ms";


	start = chrono::steady_clock::now();
	test.BubbleSort(array1, 10);
	end = chrono::steady_clock::now();
	diff1 = end - start;

	start = chrono::steady_clock::now();
	test.BubbleSort(array2, 100);
	end = chrono::steady_clock::now();
	diff2 = end - start;

	start = chrono::steady_clock::now();
	test.BubbleSort(array3, 1000);
	end = chrono::steady_clock::now();
	diff3 = end - start;

	cout << endl << endl << "Bubble Sort:\t     " << chrono::duration <double, milli>(diff1).count() << " ms\t\t" << chrono::duration <double, milli>(diff2).count() << " ms\t" << chrono::duration <double, milli>(diff3).count() << " ms";

	cout << endl << endl << endl;
	system("pause");
}