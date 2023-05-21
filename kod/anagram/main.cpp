#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> slowa;

string slowo = "";

int dlugs = 0;

void DSNL() //!dzielenie_slowa_na_litery
{
	system("CLS");
	cout << "napisz slowo" << endl;
	cin >> slowo;
	dlugs = slowo.length();
	system("CLS");
	for (int i = 0; i < dlugs - 1; i++)
	{
		sort(slowo.begin(), slowo.end());
		while (next_permutation(slowo.begin(), slowo.end()))
			cout << slowo << endl;
	}
}

int main()
{
	DSNL();
	return 0;
}
