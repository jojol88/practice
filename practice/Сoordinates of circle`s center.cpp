#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int x0, y0, r1, r2, x, y;
	float L;
	cout << "Input coordinates of circle`s center (X0, Y0): ";
	cin >> x0 >> y0;
	cout << "Input circle radiuses R1 and R2: ";
	cin >> r1 >> r2;
	cout << "Input point coordinates (X, Y): ";
	cin >> x >> y;
	L = sqrt(pow(x - x0, 2)) + (pow(y - y0, 2));
	if ((r1<L) && (L<r2))	{
		cout << "this point is situated inside the circle.\n";
	}
	else {
		cout << "This point is not situated inside the circle.\n";
	}
}