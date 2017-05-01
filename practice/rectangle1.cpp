#include <iostream>
using namespace std;

int main()
{
	const int row = 20;
	const int col = 20;
	char mr[row][col];

	for (int i = 0; i < 400; i++)mr[0][i] = '*';

	for (int i = 0; i < row; i++)
	{
		for (int j = 0, b = 0; j < col; j++)
		{
			if (i == 0 || i == 19 || j == 0)cout << mr[i][j];
			else if (i == 9)cout << mr[i][j];
			else if (j == 19)cout << "         " << mr[i][j];
			else if (j == 9)cout << "        " << mr[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0, b = 1, d = 19; j < col; j++)
		{
			if (i == j)
			{
				for (int k = 1; k < b; k++)
				{
					cout << " ";
				}
				cout << mr[i][j];
			}
			++b;
			if (i == 0 && j == 19)
			{
				for (int z = 1; z < d; z++)
				{
					cout << " ";
				}
				cout << mr[i][j];
			}
			--d;
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}