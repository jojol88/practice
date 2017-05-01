#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const int line = 10;
	const int column = 10;
	int ar[line][column];

	for (int i = 0; i < 100; i++)
	{
		ar[0][i] = rand() % 100;
		cout << ar[0][i] << ends;
	}

	cout << "\n\n";
	int max = ar[0][0];

	for (int l = 0; l < line; l++)
	{
		for (int c = 0; c < column; c++)
		{
			if (l == c || l < c)
			{
				if (ar[l][c]>max)max = ar[l][c];
			}
		}
	}

	cout << max;
	cout << "\n\n";
	int max1 = ar[0][0];

	for (int l = 0; l < line; l++)
	{
		for (int c = 0; c < column; c++)
		{
			if (l == c || l > c)
			{
				if (ar[l][c]>max)max1 = ar[l][c];
			}
		}
	}

	cout << max1;
	cout << "\n\n";

	system("pause");
	return 0;
}