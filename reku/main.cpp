#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int N = 100000;

void rysuj(int x, int y)
{
	if (2 * x <= N)
	{
		if (2 * x == y)
		{
			cout << x << " " << y << endl;
		}
		else
		{
			rysuj(2 * x, y);
		}
	}
	if (2 * x + 1 <= N)
	{
		if (2 * x + 1 == y)
		{
			cout << x << " " << y << endl;
		}
		else
		{
			rysuj(2 * x + 1, y);
		}
	}
}

int main()
{
	system("CLS");
	rysuj(10, 230);
	return 0;
}
