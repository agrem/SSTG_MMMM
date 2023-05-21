#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

vector<string> liczby;
vector<string> revliczby;
int licznik = 0;

int IP(int x)
{
	if (x == 2)
		return 1;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

void WPDV()
{
	string LICZBA_IMP = "";
	ifstream IMP("liczby.txt");
	while (!IMP.eof())
	{
		IMP >> LICZBA_IMP;
		liczby.push_back(LICZBA_IMP);
		licznik++;
	}
}

void TO()
{
	for (int i = 0; i < licznik; i++)
	{
		string liczbas = liczby[i];
		reverse(liczbas.begin(), liczbas.end());
		revliczby.push_back(liczbas);
	}
}

void ROL()
{
	cout << "============================1============================" << endl;
	for (int i = 0; i < licznik; i++)
	{
		string liczbas = revliczby[i];
		int liczbat = stoi(liczbas);
		if (liczbat % 17 == 0)
		{
			cout << liczbat << endl;
		}
	}
}

void ZNR()
{
	cout << "============================2============================" << endl;
	int naj = 0;
	int roz = 0;
	string liczba = "";
	for (int i = 0; i < licznik; i++)
	{
		roz = stoi(liczby[i]) - stoi(revliczby[i]);
		if (roz < 0)
			roz = -roz;
		if (roz > naj)
		{
			naj = roz;
			liczba = liczby[i];
		}
	}
	cout << liczba << " " << naj << endl;
}

void SLP()
{
	cout << "============================3============================" << endl;
	for (int i = 0; i < licznik; i++)
	{
		if (IP(stoi(liczby[i])) == 1 && IP(stoi(revliczby[i])) == 1)
		{
			cout << liczby[i] << endl;
		}
	}
}

void RLIIG()
{
	cout << "============================4============================" << endl;
	string poprzednie = liczby[0];
	int licznikk = 0;
	for (int i = 0; i < licznik; i++)
	{
		if (liczby[i] != poprzednie)
			licznikk++;
		poprzednie = liczby[i];
	}
	cout << licznikk << endl;
	for (int i = 0; i < licznik; i++)
	{
		for (int a = i; a < licznik;a++)
		{
			if(liczby)
		}
	}
}

int main()
{
	system("CLS");
	WPDV();
	TO();
	ROL();
	ZNR();
	SLP();
	RLIIG();
	return 0;
}
