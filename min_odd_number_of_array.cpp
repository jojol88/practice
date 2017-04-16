#include <iostream>

using namespace std;

int main() // Min odd number of array
{
	const int size = 5;
	int ar[size] = { 23, 11, 9, 18, 25 };

	int min = 0;

	for (int i = 0; i < size; i++)
	{
		if (ar[i] % 2 == 1)
		{
			for (int d = i + 1; d < size; d++)
			{
				if (ar[i]>ar[d] && ar[d]%2 == 1)
					min = ar[d];
			}
		}
	}
	cout << "Min odd number " << min << endl;

	system("pause");
	return 0;
}