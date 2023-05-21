#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> dane = {5, 28, 3, 17, 64, 31, 0, 2, 55, 3, 2};

void IS() //!INSERTION SORT
{
	vector<int> dane_is = dane;
	for (int i = 0; i < dane_is.size(); i++)
	{
	}
}

void SS() //!SELECT SORT
{
	vector<int> dane_ss = dane;
	int nl = dane_ss[0];
	int wnl = 0;
	for (int a = 0; a < dane_ss.size() - 1; a++)
	{
		for (int i = a; i < dane_ss.size(); i++)
		{
			if (nl > dane_ss[i])
			{
				nl = dane_ss[i];
				wnl = i;
			}
		}
		swap(dane_ss[wnl], dane_ss[a]);
		nl = dane_ss[a];
		for (auto x : dane_ss)
			cout << x << " ";
		cout << endl;
	}
}

int main()
{
	system("CLS");
	SS();
	return 0;
}
