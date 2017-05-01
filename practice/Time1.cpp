#include <iostream>
using namespace std;

int main()
{
	unsigned int time;
	int seconds, minutes, hours;

	cout << "Enter the number of seconds: ";
	cin >> time;

	/*hours = time / 3600;
	minutes = (time / 60) - (hours*60);
	seconds = time - ((time / 60) * 60);*/

	hours = time / 3600;
	minutes = (time % 3600) / 60;
	seconds = time % 60;

	cout << "\nHours: " << hours << "\tMinutes: " << minutes << "\tSeconds: " << seconds << endl;

	system("pause");
	return 0;
}