#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

vector<int> sumy;
vector<int> liczby(2001);
vector<int> liczbypom;
vector<int> podciag;
vector<int> podciagm;
int licznikpod = 0;
int licznikpodm = 0;
int licznik = 0;
int liczniks = 0;
int licznikm = 0;
int liczbam = 0;
int p = 0;

void WL()
{
	ifstream wep("liczby.txt");
	for (int a = 0; a < 2002; a++)
	{
		wep >> liczby[a];
	}
	wep.close();
}

int CP(int a) //!czy pierwsza
{
	for (int i = 3; i < a; i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
		if (i = a - 1)
		{
			return 1;
		}
	}
}

void SKC(int a) //!suma kwadratow cyfr
{
	int suma = 0;
	vector<int> cyfry;
	while (a != 0)
	{
		cyfry.push_back(a % 10);
		a = a / 10;
	}
	for (auto x : cyfry)
	{
		suma += x * x;
	}
	sumy.push_back(suma);
	liczniks++;
}

void ZLS(int liczba) //!znajdywanie liczb smiesznych
{
	int pom = 0;
	SKC(liczba);
	while (pom == 0)
	{
		SKC(sumy.back());
		for (auto x : sumy)
		{
			if (x == 1)
			{
				//cout << liczba << "  JEST SMIESZNA" << endl;
				pom = 1;
				licznik++;
				licznikpod++;
				podciag.push_back(liczba);
				if (licznikpod > licznikpodm)
				{
					licznikpodm = licznikpod;
					podciagm = podciag;
				}
				if (CP(liczba) == 1)
					p++;
				break;
			}
			if (x == 145)
			{
				//cout << liczba << "  NIE JEST SMIESZNA" << endl;
				licznikpod = 0;
				podciag.clear();
				pom = 2;
				break;
			}
		}
	}
	if (pom == 1)
	{
		if (liczniks > licznikm)
		{
			liczbam = liczba;
			licznikm = liczniks;
			liczbypom = sumy;
		}
	}
	liczniks = 0;
	sumy.clear();
}

int main()
{
	system("CLS");
	WL();
	for (auto x : liczby)
		ZLS(x);
	cout << "============================4.1============================" << endl;
	cout << "JEST " << licznik << " TAKICH LICZB" << endl;
	licznik = 0;
	for (int i = 1; i <= 1000; i++)
		ZLS(i);
	cout << endl;
	cout << "============================4.2============================" << endl;
	cout << liczbam << endl;
	cout << licznikm << endl;
	cout << endl;
	for (auto x : liczbypom)
	{
		cout << x << " ";
	}
	cout << endl;
	p = 0;
	for (auto x : liczby)
		ZLS(x);
	cout << "============================4.3============================" << endl;
	cout << licznikpodm << endl;
	for (auto x : podciagm)
		cout << x << " " << endl;
	cout << endl;
	cout << "============================4.4============================" << endl;
	cout << p << endl;
	cout << endl;
	return 0;
}
