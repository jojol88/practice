#include <iostream>
#include <cstdlib>

using namespace std;

namespace NVariables
{
	const int s1(5);
}

int main()
{
	char ar[NVariables::s1][NVariables::s1];
	
	for (int i = 0; i < 25; i++) ar[0][i] = ' ';
	
	int v = NVariables::s1 - 1;
	for (int i = 0; i < NVariables::s1; i++)
	{
		ar[i][i] = 'x';
		if (i == 4 - i) continue;
		ar[i][4-i] = 'x';
	}


	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k <= 4; k++)
		{
			cout << ar[i][k];
		} 
		cout << endl;
	
	}

	int b = s1 / 2;
	for (int i = s1 / 2; i <= s1; i++)
	{
		for (int k = 0; k <= b; k++)
		{
			ar[i][k] = 'x';
		}
		--b;
	}
		
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k <= 4; k++)
		{
			cout << ar[i][k];
		} 
		cout << endl;
	}

	system("pause");
	return 0;
}