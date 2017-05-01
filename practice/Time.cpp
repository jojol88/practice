#include <iostream>
using namespace std;

class time
{
public:
	time() : hour(0), minute(0), second(0)
	{}
	time(int ho, int mi, int se) : hour(ho), minute(mi), second(se)
	{}
	void sum(time t1, time t2)
	{
		second = t1.second + t2.second;
		if (second >= 60)
		{
			second -= 60;
			++minute;
		}
		minute += t1.minute + t2.minute;
		if (minute >= 60)
		{
			minute -= 60;
			++hour;
		}
		hour += t1.hour + t2.hour;
	}
	void display() const
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}

private:
	int hour;
	int minute;
	int second;
};

int main()
{
	const time T1(12, 54, 57), T2(05, 36, 20);
	time T3;
	T3.sum(T1, T2);
	T3.display();

	system("pause");
	return 0;
}