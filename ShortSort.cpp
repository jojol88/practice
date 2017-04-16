#include <iostream>
using namespace std;

void Sort1(int a[], int low, int high);

int main()
{
	const int n = 12;
	int arr[n];
	for (int i = 0; i < n; i++)	arr[i] = rand() % 50;
	int low = 0;
	int high = n - 1;
	Sort1(arr, low, high);
	for (int i = 0; i < n; i++)	cout << arr[i] << ends;

	system("pause");
	return 0;
}

void Sort1(int a[], int low, int high)
{
	int i = low;
	int j = high;
	int x = a[(low + high) / 2];
	do {
		while (a[i] < x) ++i;
		while (a[j] > x) --j;
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	} while (i < j);

	if (low < j) Sort1(a, low, j);
	if (i < high) Sort1(a, i, high);
}