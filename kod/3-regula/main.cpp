#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int RDO(string napis)
{
	int ndlug = 0;
	int ntdlug = 0;
	ndlug = napis.length();
	if (ndlug == 1)
	{
		return 1;
	}
	if (ndlug % 3 != 0)
	{
		return 0;
	}
	ntdlug = ndlug / 3;
	string np = napis.substr(0, ntdlug);
	string nd = napis.substr(ntdlug, ntdlug);
	string nt = napis.substr(2 * ntdlug, ntdlug);
	cout << np << endl;
	cout << nd << endl;
	cout << nt << endl;
	if (np == nt || np == nd)
	{
		return RDO(np);
	}
	if (np != nd && np != nt)
	{
		return 0;
	}
}

void WIO3R()
{
	string napis = "";
	cin >> napis;
	cout << RDO(napis) << endl;
}

int main()
{
	WIO3R();
	return 0;
}
