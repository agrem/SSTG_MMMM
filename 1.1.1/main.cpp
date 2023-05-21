#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> sys;
vector<string> liczb;
vector<int> wyniki;
int dlug = 0;

void IMP()
{
	ifstream IMP("symetryczne.txt");
	while (!IMP.eof())
	{
		int pomi = 0;
		string poms = "";
		IMP >> pomi;
		IMP >> poms;
		sys.push_back(pomi);
		liczb.push_back(poms);
		dlug++;
	}
}

void TDV()
{
	for (int i = 0; i < dlug; i++)
	{
		cout << sys[i] << " " << liczb[i] << endl;
	}
}

void SLS()
{
	int licznik = 0;
	string pom = "";
	for (int i = 0; i < dlug; i++)
	{
		pom = liczb[i];
		reverse(pom.begin(), pom.end());
		if (liczb[i] == pom)
		{
			licznik++;
		}
	}
	cout << licznik << endl;
}

int KND(int x, string a)
{
	int wynik = 0;
	int dupa = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '0')
		{
			dupa = 0;
		}
		if (a[i] == '1')
		{
			dupa = 1;
		}
		if (a[i] == '2')
		{
			dupa = 2;
		}
		if (a[i] == '3')
		{
			dupa = 3;
		}
		if (a[i] == '4')
		{
			dupa = 4;
		}
		if (a[i] == '5')
		{
			dupa = 5;
		}
		if (a[i] == '6')
		{
			dupa = 6;
		}
		if (a[i] == '7')
		{
			dupa = 7;
		}
		if (a[i] == '8')
		{
			dupa = 8;
		}
		if (a[i] == '9')
		{
			dupa = 9;
		}
		if (a[i] == 'A')
		{
			dupa = 10;
		}
		if (a[i] == 'B')
		{
			dupa = 11;
		}
		if (a[i] == 'C')
		{
			dupa = 12;
		}
		if (a[i] == 'D')
		{
			dupa = 13;
		}
		if (a[i] == 'E')
		{
			dupa = 14;
		}
		if (a[i] == 'F')
		{
			dupa = 15;
		}
		wynik = wynik * x + dupa;
	}
	return wynik;
}

void NSDA()
{
	for (int i = 0; i < dlug; i++)
	{
		wyniki.push_back(KND(sys[i], liczb[i]));
	}
}

void KDNB()
{
	for (int i = 0; i < dlug; i++)
	{
		
	}
}

int main()
{
	system("CLS");
	IMP();
	// TDV();
	SLS();
	NSDA();
	return 0;
}
