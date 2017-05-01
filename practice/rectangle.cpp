#include <iostream>
using namespace std;

int main()
{
	int str, star_count, lenght = 19;
	str = 1;
	
	for (; str <= 9; str++)
	{
		star_count = 1;
		if (str == 1 || str == 5 || str == 9)
		{
			while (star_count <= lenght)
			{
				cout << "*";
				star_count++;
			}
		}
		else
		{
			while (star_count <= lenght)
			{
				if (star_count == 1 || star_count == 9 || star_count == 17)cout << "*";
				cout << " ";
				star_count++;
			}
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}