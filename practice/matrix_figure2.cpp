#include <iostream>
#include <cstdlib>
using namespace std;

int main(void) // finding the greatest values ​​of matrix elements
{
	const int n = 10;
	int ar[n][n];
	int max1 = ar[0][0], max2 = ar[n / 2][n / 2];

	for (int i = 0; i < 100; i++) ar[0][i] = rand() % 90 + 10;

	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			cout << ar[q][w] << ends;
		}
		cout << endl;
	}
	cout << endl;

	// figure "a"

	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			if (q == w || q < w)
			{
				if (ar[q][w] > max1) max1 = ar[q][w];
			}
		}
	}
	cout << max1 << endl;
	max1 = ar[0][0];

	// figure "b"

	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			if (q == w || q > w)
			{
				if (ar[q][w] > max1) max1 = ar[q][w];
			}
		}
	}
	cout << max1 << endl;
	max1 = ar[0][0];

	// figure "v"

	for (int q = 0; q < n / 2 + 1; q++)
	{
		for (int w = q; w < n - q; w++)
		{
			if (ar[q][w] > max1) max1 = ar[q][w];
		}
	}
	cout << max1 << endl;

	// figure "g"

	for (int q = n/2; q < n; q++)
	{
		for (int w = n-q-1; w < q + 1; w++)
		{
			if (ar[q][w] > max2) max2 = ar[q][w];
		}
	}
	cout << max2 << endl;

	// figure "d"

	if (max1 < max2) cout << max2 << endl;
	else cout << max1 << endl << endl;

	max1 = ar[0][0];
	max2 = ar[n/2][n/2];

	// figure "e"

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) cout << ar[i][j] << " ";
			else if (i + 1 == n - j) cout << ar[i][j] << " ";
			else if (j < i && j < n - i) cout << ar[i][j] << " ";
			else if (i < j && n - i < j + 1) cout << ar[i][j] << " ";
			else cout << "  ";
		}
	}

	cout << endl << endl;

	// figure "i"

	int b = n;

	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < b; w++)
		{
			if (ar[q][w]>max1) max1=ar[q][w];
		}
		b = b - 1;
	}

	cout << max1 << endl;

	// figure "k"

	for (int q = 0; q < n; q++)
	{
		for (int w = n; w < b; w--)
		{
			if (ar[q][w]>max2) max2 = ar[q][w];
		}
		b = b - 1;
	}

	cout << max2 << endl;

	system("pause");
	return 0;
}