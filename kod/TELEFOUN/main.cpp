#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> numery;
vector<string> daty;
vector<int> czas;
vector<int> liczniki;
vector<int> datykom;
vector<int> datysta;

void WST() //!wczytywanie_spisu_telefonow
{
	string pomp = "";
	string pomd = "";
	ifstream wet("telefony.txt");
	getline(wet, pomp);
	while (!wet.eof())
	{
		getline(wet, pomp, ' ');
		numery.push_back(pomp);
		getline(wet, pomp, ' ');
		daty.push_back(pomp);
		getline(wet, pomp, ' ');
		getline(wet, pomd);
		czas.push_back((stoi(pomd.substr(0, 2)) * 3600 + stoi(pomd.substr(3, 2)) * 60 + stoi(pomd.substr(6, 2))) - (stoi(pomp.substr(0, 2)) * 3600 + stoi(pomp.substr(3, 2)) * 60 + stoi(pomp.substr(6, 2))));
	}
}

void DST() //!drukuj_spis_telefonow
{
	for (int i = 0; i < 2148; i++)
	{
		cout << numery[i] << " " << daty[i] << " " << czas[i] << endl;
	}
}

void NDZN() //!najczesciej_dzwoniace_telefony
{
	int najp = 0;
	int najd = 0;
	int najt = 0;
	int najpw = 0;
	int najdw = 0;
	int najtw = 0;
	int licz = 0;
	for (int a = 0; a < 2148; a++)
	{
		licz = 0;
		for (int i = 1; i < 2148; i++)
		{
			if (numery[a] == numery[i])
			{
				licz++;
			}
		}
		liczniki.push_back(licz);
	}
	for (int i = 0; i < 2148; i++)
	{
		if (liczniki[i] > najp)
		{
			najp = liczniki[i];
			najpw = i;
		}
		if (liczniki[i] > najd && liczniki[i] < najp)
		{
			najd = liczniki[i];
			najdw = i;
		}
		if (liczniki[i] > najt && liczniki[i] < najd)
		{
			najt = liczniki[i];
			najtw = i;
		}
	}
	cout << numery[najpw] << " " << najp << "  " << numery[najdw] << " " << najd << "  " << numery[najtw] << " " << najt << endl;
}

void WSP() //!wykres_spisu_polaczen
{
	int licznikkom = 0;
	int liczniksta = 0;
	for (int i = 0; i < 2148; i++)
	{
		if (daty[i] == " ")
		{
			break;
		}
		for (int a = 0; a < 2148; a++)
		{
			if (numery[a].length() == 7 && daty[i] == daty[a])
			{
				daty[a] = " ";
				liczniksta++;
			}
			if (numery[a].length() == 8 && daty[i] == daty[a])
			{
				daty[a] = " ";
				licznikkom++;
			}
			if (daty[a] != daty[i])
			{
				break;
			}
		}
		cout << daty[i] << "  " << licznikkom << "   " << liczniksta << endl;
		licznikkom = 0;
		liczniksta = 0;
	}
}

int main()
{
	system("CLS");
	WST();
	NDZN();
	WSP();
	return 0;
}
