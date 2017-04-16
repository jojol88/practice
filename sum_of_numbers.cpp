#include<iostream>
using namespace std;

int main()
{
	int digit, sum = 0;
	cout << "Enter of digit: ";
	cin >> digit;

	for (; digit != 0; digit /= 10) {
		sum += digit % 10;
	}
	cout << sum;

	return 0;
}