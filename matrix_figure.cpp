#include <iostream>

using std::cout;
using std::ends;
using std::endl;

// finding the greatest values ??of matrix elements
void main(void)
{
	const unsigned _int8 n = 10;
	unsigned _int8 ar[n][n];
	unsigned _int8 max1 = ar[0][0], max2 = ar[n / 2][n / 2];

	for (unsigned _int8 i = 0; i < 100; i++) ar[0][i] = rand() % 90 + 10;

	for (unsigned _int8 q = 0; q < n; q++)
	{
		for (unsigned _int8 w = 0; w < n; w++)
		{
			cout << ar[q][w] << ends;
		}
		cout << endl;
	}
	cout << endl;

	// figure "a"

	for (unsigned _int8 q = 0; q < n; q++)
	{
		for (unsigned _int8 w = 0; w < n; w++)
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

	for (unsigned _int8 q = 0; q < n; q++)
	{
		for (unsigned _int8 w = 0; w < n; w++)
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

	for (unsigned _int8 q = 0; q < n / 2 + 1; q++)
	{
		for (unsigned _int8 w = q; w < n - q; w++)
		{
			if (ar[q][w] > max1) max1 = ar[q][w];
		}
	}
	cout << max1 << endl;

	// figure "g"

	for (unsigned _int8 q = n / 2; q < n; q++)
	{
		for (unsigned _int8 w = n - q - 1; w < q + 1; w++)
		{
			if (ar[q][w] > max2) max2 = ar[q][w];
		}
	}
	cout << max2 << endl;

	// figure "d"

	if (max1 < max2) cout << max2 << endl;
	else cout << max1 << endl << endl;

	max1 = ar[0][0];
	max2 = ar[n / 2][n / 2];

	// figure "e"

	for (unsigned _int8 i = 0; i < n; i++)
	{
		for (unsigned _int8 j = 0; j < n; j++)
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

	for (unsigned _int8 q = 0; q < n; q++)
	{
		for (unsigned _int8 w = 0; w < b; w++)
		{
			if (ar[q][w]>max1) max1 = ar[q][w];
		}
		b = b - 1;
	}

	cout << max1 << endl;

	// figure "k"

	for (unsigned _int8 q = 0; q < n; q++)
	{
		for (unsigned _int8 w = n; w < b; w--)
		{
			if (ar[q][w]>max2) max2 = ar[q][w];
		}
		b = b - 1;
	}

	cout << max2 << endl;

	cout << "\n Thank, goodbye!!! \n";

	system("pause");
	return;
}