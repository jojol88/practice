#include <iostream>
using namespace std;

void selectSort(int a[], int size)
{
	int k, x;

	for (int i = 0; i < size; i++)
	{
		k = i;
		x = a[i];
		for (int j = i + 1; j < size; j++)
		{
			if (a[j]<x)
			{
				k = j;
				x = a[j];
			}
		}
		a[k] = a[i];
		a[i] = x;
	}
}

void main()
{
	const int size = 10;
	int ar[size];
	for (int i = 0; i < size; i++)	ar[i] = rand() % 50;
	selectSort(ar, size);

	system("pause");
}