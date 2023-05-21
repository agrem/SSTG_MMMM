#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> trzy;
vector<string> slowa;
int ilosc = 0;

void WP()
{
	string pom = "";
	ifstream IMP("slowa.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		slowa.push_back(pom);
		ilosc++;
	}
}

void DT()
{
	for (auto x : slowa)
		cout << x << endl;
}

void DTT()
{
	for (auto x : trzy)
		cout << x << endl;
}

void SWS()
{
	int dlug = 0;
	string pom = "";
	// DT();
	for (int i = 0; i < ilosc; i++)
	{
		for (int a = 0; a < slowa[i].length() - 2; a++)
		{

			pom = pom + slowa[i][a] + slowa[i][a + 1] + slowa[i][a + 2];
			trzy.push_back(pom);
			dlug++;
			pom = "";
		}
	}
	int licznik = 0;
	int maks = 0;
	string makss = "";
	for (int i = 0; i < dlug; i++)
	{
		for (int a = i + 1; a < dlug; a++)
		{
			if (trzy[i] == trzy[a])
			{
				licznik++;
			}
		}
		if (licznik > maks)
		{
			maks = licznik;
			makss = trzy[i];
		}
	}
	cout << makss << " " << maks << endl;
}

int main()
{
	system("CLS");
	WP();
	// DT();
	SWS();
	return 0;
}
