#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> liczba1v;
vector<int> liczba2v;
int dlug1 = 0;
int dlug2 = 0;

void WZDLIKNV() //! wprowadzanie_zajebiscie_duzych_liczb_i_konwersja_na_vector
{
	string liczbap = "";
	string liczba1 = "";
	string liczba2 = "";
	cin >> liczba1;
	cin >> liczba2;
	if (liczba1.length() > liczba2.length())
	{
		liczbap = liczba1;
		liczba1 = liczba2;
		liczba2 = liczbap;
	}
	dlug1 = liczba1.length();
	dlug2 = liczba2.length();
	for (int i = 0; i < liczba1.length(); i++)
	{
		liczba1v.push_back(liczba1[i] - '0');
	}
	for (int i = 0; i < liczba2.length(); i++)
	{
		liczba2v.push_back(liczba2[i] - '0');
	}
}

void DVZL() //! drukowanie_vectorow_z_liczbami
{
	for (auto x : liczba1v)
		cout << x << " ";
	cout << endl;
	for (auto x : liczba2v)
		cout << x << " ";
	cout << endl;
}

vector<int> liczbas;

void MZDLPDRZ() //! mnozenie_zajebiscie_duzej_liczby_przez_druga_rownie_zajebista
{
	int dlugo = 0;
	for (int i = 0; i < dlug2; i++) //! mnozenie_z_wyrownaniem
	{
		dlugo = 0;
		vector<int> liczbasp;
		for (int a = 0; a < dlug1 + dlug2; a++)
		{
			liczbasp.push_back(0);
			dlugo++;
		}
		for (int a = 0; a < i; a++)
		{
			liczbasp.push_back(0);
			dlugo++;
		}
		for (int a = 0; a < dlug1; a++)
		{
			liczbasp.push_back(liczba2v[i] * liczba1v[a]);
			dlugo++;
		}
		for (int a = dlug2 - i; a > 1; a--)
		{
			liczbasp.push_back(0);
			dlugo++;
		}
		for (int a = dlugo - 1; a >= 1; a--) //! przeniesienie
		{
			liczbasp[a - 1] += liczbasp[a] / 10;
			liczbasp[a] = liczbasp[a] % 10;
		}
		if (i == 0)
		{
			liczbas = liczbasp;
		}
		else
		{
			for (int a = 0; a < dlugo; a++)
			{
				liczbas[a] += liczbasp[a];
			}
		}
		for (int a = dlugo - 1; a >= 1; a--)
		{
			liczbas[a - 1] += liczbas[a] / 10;
			liczbas[a] = liczbas[a] % 10;
		}
	}
	int wskaz = 1;
	for (int i = 0; i < dlugo; i++)
	{
		if (liczbas[i] != 0)
		{
			wskaz = 0;
		}
		if (wskaz == 0)
			cout << liczbas[i];
	}
	cout << endl;
}

int main()
{
	WZDLIKNV();
	// DVZL();
	MZDLPDRZ();
	return 0;
}
