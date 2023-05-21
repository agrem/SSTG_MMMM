#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

vector<char> dupa;
string tekst = "BTLLTU_EL_EOYPM_APJZLCYNDREOKYLI_ZMFO_AGJY_O_N_DEWFWGISYSII_LEI_";
//string tekst = "DPUA";
int dlugs = 0;

void ODS() //!obliczanie_dlugosci_scian
{
	float dlug = tekst.length();
	dlugs = ceil(sqrt(dlug));
}

void TTIDS() //!tworzenie_tablic_i_dopisywanie_spacji
{
	int pod = (dlugs * dlugs) - tekst.length();
	for (auto x : tekst)
	{
		dupa.push_back(x);
	}
	if (tekst.length() != dlugs * dlugs)
	{
		for (int i = 0; i < pod; i++)
		{
			dupa.push_back('_');
		}
	}
}

void OZZ() //!odszyfrowaywanie_zaszyfrowanego_zdania
{
	for (int i = 0; i < dlugs; i++)
	{
		for (int a = 0; a < dlugs * dlugs; a += dlugs)
			cout << dupa[i + a];
	}
}

void DS() //!drukowanie_szyfru
{
	for (auto x : dupa)
		cout << x;
	cout << endl;
}

int main()
{
	system("CLS");
	ODS();
	TTIDS();
	OZZ();
	return 0;
}
