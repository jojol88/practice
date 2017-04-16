#include <iostream>
using namespace std;

class Distange
{
public:
	Distange() : feet(0), inches(0.0)
	{}
	Distange(int ft, float in) : feet(ft), inches(in)
	{}
	void getdist()
	{
		cin >> feet >> inches;
	}
	void showdist()const
	{
		cout << feet << "\'-" << inches << '\"';
	}
	Distange add_dist(const Distange&)const;

private:
	int feet;
	float inches;
};

Distange Distange::add_dist(const Distange& d2)const
{
	Distange temp;
	temp.inches = inches + d2.inches;
	if (temp.inches >= 12.0)
	{
		temp.inches -= 12.0;
		temp.feet = 1;
	}
	temp.feet += feet + d2.feet;
	return temp;
}

int main()
{
	Distange dist1, dist3;
	Distange dist2(11, 6.25);
	dist1.getdist();
	dist3 = dist1.add_dist(dist2);

	return 0;
}