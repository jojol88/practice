#include <iostream>

using std::cout;

void main(void)
{
	cout << "\t September\n pn vt sr ch pt sb vs \n";
	for (short i = 1, j = 1; i <= 30; i++)
	{
		if (i == 1 && j<2)
		{
			cout << "   ";
			i--;
		}
		else
		{
			if (i<10)
			{
				cout << " ";
			}

			cout << i << " ";
		}
		if (++j>7)
		{
			j = 1;
			cout << "\n";
		}
	}

	cout << "\n Thank, goodbye!!! \n";

	system("pause");
	return;
}