#include <iostream>
#include <vector>

using namespace std;

struct Graph
{
	int i;
	Graph * l, * r;
};

int foo1(Graph * gr)
{
	if(0 == gr->l && 0 == gr->r)
		return 1;
	else
		return foo1()
}

int foo2(Graph * gr)
{
	vector<Graph *> s;
	s.push_back(gr);
	vector<Graph *> c;

	int n = 0;

	while (!s.empty())
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (0 == s[i]->l && 0 == s[i]->r)
			{
				cout << ++n;
			}
			else if (0 == s[i]->l)
			{
				c.push_back(c[i]->r);
			}
			else if (0 == s[i]->r)
			{
				c.push_back(c[i]->l);
			}
			else
			{
				c.push_back(c[i]->r);
				c.push_back(c[i]->l);
			}
		}
		s = c;
		c.clear();
	}
	
	return n;
}

int main(void)
{
	Graph * gr = new Graph;

	return 0;
}