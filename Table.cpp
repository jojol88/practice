#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

void Table()
{
	cout << setfill('.') << setw(4) << "1990" << setw(9) << "135\n" << setfill('.')
		<< setw(4) << "1990" << setw(9) << "135\n"
		<< setw(4) << "1991" << setw(9) << "7290\n" 
		<< setw(4) << "1992" << setw(9) << "11300\n"
		<< setw(4) << "1993" << setw(9) << "16200\n";
}

void Islow()
{
	char litera;
	cin >> litera;
	if (islower(litera)) cout << "1\n";
	else cout << "0\n";
}

void main()
{
	Table();
	Islow();
	system("pause");
}

cout << setiosflags(ios::left) << setw(15) << "Second name" << setw(15) << "Name" << setw(16) << "City" << "\n"
		<< setfill('.') << setw(46) << "." << endl << setfill(' ')
		<< setw(15) << "Petrov" << setw(15) << "Vasiliy" << setw(16) << "Saint Petersburg" << "\n"
		<< setw(15) << "Ivanov" << setw(15) << "Sergey" << setw(16) << "Naxodka" << "\n"
		<< setw(15) << "Ivanov" << setw(15) << "Sergey" << setw(16) << "Naxodka" << "\n"
		<< setw(15) << "Sidorov" << setw(15) << "Ivan" << setw(16) << "Kaliningrad" << "\n";