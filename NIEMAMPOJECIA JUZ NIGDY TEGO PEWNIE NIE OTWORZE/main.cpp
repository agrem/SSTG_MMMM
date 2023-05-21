#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

vector<int> nwd;

vector<int> dane;

int dlug = 0;

void WJPS()
{
	int x = 0;
	ifstream IMP("przyklad.txt"); //!      liczby.txt          przyklad.txt;
	while (!IMP.eof())
	{
		IMP >> x;
		dane.push_back(x);
		dlug++;
	}
}

void TD()
{
	for (auto x : dane)
		cout << x << endl;
}

void CPGAD()
{
	int licznika = 0;
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 1; a <= 100000; a = a * 3)
		{
			if (dane[i] == a)
			{
				licznika++;
				break;
			}
		}
	}
	cout << licznika << endl;
}

int silnia(int x)
{
	int wynik = 1;
	if (x == 0)
	{
		return 1;
	}
	for (int i = x; i > 0; i--)
	{
		wynik = wynik * i;
	}
	return wynik;
}

void DUPA()
{
	int pom = 0;
	for (int i = 0; i < dlug; i++)
	{
		int suma = 0;
		pom = dane[i];
		while (pom != 0)
		{
			suma = suma + silnia(pom % 10);
			pom = pom / 10;
		}
		if (suma == dane[i])
		{
			cout << dane[i] << endl;
		}
	}
}

void OKZAU()
{
	int licznika = 0;
	int zapis1 = 0;
	int zapis2 = 0;
	int zapis3 = 0;
	int zapisn1 = 0;
	int zapisn2 = 0;
	int zapisn3 = 0;
	int wskaz = 0;
	for (int i = 0; i < dlug - 1; i++)
	{
		nwd.push_back(gcd(i, i + 1));
		licznika++;
	}
	for (int i = 0; i < licznika - 1; i++)
	{
		if (nwd[i] == nwd[i + 1])
		{
			zapis1++;
			if (wskaz == 0)
			{
				zapis2 = dane[i];
				zapis3 = nwd[i];
				wskaz = 1;
			}
		}
		if (nwd[i] != nwd[i + 1])
		{
			zapis1 = 0;
			zapis2 = 0;
			zapis3 = 0;
			wskaz = 0;
		}
		if (zapis1 > zapisn1)
		{
			zapisn1 = zapis1;
			zapisn2 = zapis2;
			zapisn3 = zapis3;
		}
	}
	cout << zapisn1 << endl;
	cout << zapisn2 << endl;
	cout << zapisn3 << endl;
}

int main()
{
	system("CLS");
	WJPS();
	// TD();
	CPGAD();
	DUPA();
	OKZAU();
	return 0;
}
