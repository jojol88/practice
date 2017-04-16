#include <iostream>
using namespace std;

void main()
{
	const int size = 10;
	int ar[size];
	for (int i = 0; i < size; i++)	ar[i] = rand() % 50;
	insertionSort(ar, size);

	system("pause");
}

void insertionSort(int ar[], int size)
{
	if (size < 2) return;

	for (int i = 1; i < size; i++)
	{
		for (int j = i; j && ar[j] < ar[j - 1]; j--) swap(ar[j], ar[j - 1]);
	}
}
