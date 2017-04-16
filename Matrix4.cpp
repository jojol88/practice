#include <iostream>

int main()
{
	char arr[5][5];
	for (int i = 0; i < 25; i++) arr[0][i] = '_';
	for (int i = 0; i < 5; i++)	arr[i][4 - i] = 'X';
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}