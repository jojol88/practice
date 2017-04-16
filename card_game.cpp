#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit
{
	clubs, diamonds, hearts, spades
};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card
{
public:
	card()
	{}
	void set (int n, Suit s)
	{
		number = n, suit = s;
	}
	void display();

private:
	int number;
	Suit suit;
};

void card::display() // vuvod card na ekran
{
	if (number >= 2 && number <= 10)
	{
		cout << number;
	}
	else
		switch (number)
	{
		case jack: cout << "J"; break;
		case queen: cout << "Q"; break;
		case king: cout << "K"; break;
		case ace: cout << "A"; break;
	}
	switch (suit)
	{
	case clubs: cout << static_cast<char>(5);
		break;
	case diamonds: cout << static_cast<char>(4);
		break;
	case hearts: cout << static_cast<char>(3);
		break;
	case spades: cout << static_cast<char>(6);
		break;
	}
}

int main()
{
	card deck[52];
	int j;

	cout << endl;
	for ( j = 0; j < 52; j++)
	{
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num.su);
	}
	for ( j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if (!((j+1)%13))
		{
			cout << endl;
		}
	}
	srand(time(NULL));
	for ( j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << "  ";
		if (!((j+1)%13))
		{
			cout << endl;
		}
	}

	system("pause");
	return 0;
}