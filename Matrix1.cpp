#include<iostream>
using namespace std;

int main()
{
	const int row = 3;
	const int col = 3;
	int arr[] = { 2, 3, 5, 5, 6, 3, 8, 9, 2 };

	int mr[][3] = { { 2, 3, 5 }, { 5, 6, 3 }, { 8, 9, 2 } };

	//------------------------------------------------
	for (int k = 0; k < 9; k++) cout << mr[0][k]<<endl;
	//------------------------------------------------


	for (int i = 0, j = 0; i < row; i++)
	{
		cout << mr[i][j] << " ";
		j++;
		cout << mr[i][j] << " ";
		j++;
		cout << mr[i][j];
		j = j - 2;

		cout << "\n";
	}

	system("pause");
	return 0;
}

	for (int i = 0; i < N; i++)
	{
		cout << i + 1;
		while (!(cin >> ar[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			
			cout << i + 1;
		}
	}