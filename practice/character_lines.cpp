#include <iostream>
#include <cstring>
using namespace std;

void main()
{
	// alphabet

	setlocale(LC_ALL, "Russian"); 
	char abc[80];
	int g = 192;
	int h = 223;

	for (int i = 0; i < 32; i++)
	{
		abc[i] = g;
		cout << abc[i] << ends;
		++g;
	}
	cout << endl;
	char * abs = "asdfbhfvb\0";
	// number of characters 
	
	cout << endl << strlen(abs) << endl;

	// conversely alphabet

	for (int i = 31; i > -1; i--)
	{
		cout << abc[i] << ends;
	}
	cout << endl;

	system("pause");
}