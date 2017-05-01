#include <iostream>

using namespace std;

int main()
{
	char str[20];
	char str1[20];

	cin.getline(str, 20);
	system("cls");
	cout << str << endl;
	int i = strlen(str) - 1, j = 0;
	for (; i >= 0; i--,j++)
	{
		str1[j] = str[i];
	}
	str1[j] = '\0';
	cout << str1 << endl;

	bool inWord = false;
	bool Word = false;
	int Number;
	for (int i = 0; str[j] != '\0'; i++)
	{
		if (!(inWord) && isalpha(str[i]))
		{
			inWord = true;
			Word = false;
		}
		if (!isalpha(str[i]))
		{
			inWord = false;
		}
		if (inWord)
		{
			if ((str[i] == 'b' || str[i] == 'B') && !Word)
			{
				Number++;
				Word = true;
			}
		}
	}

	cout << Number;

	system("pause");
	return 0;
}