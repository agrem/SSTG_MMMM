#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> pi;
vector<string> dr;

int dlug = 0;

void WLDV() //!wczytaj_liczby_do_vectora
{
	string pom = "";
	ifstream we("dane.txt");
	while (!we.eof())
	{
		getline(we, pom, ' ');
		pi.push_back(pom);
		getline(we, pom);
		dr.push_back(pom);
		dlug++;
	}
}

void DVL() //!drukuj_vector_liczb
{
	for (int i = 0; i < dlug; i++)
		cout << pi[i] << "  " << dr[i] << endl;
}

void CLJP() //!czy_liczba_jest_palindromem
{
	int licznik = 0;
	string pomi = "";
	string pomo = "";
	for (int i = 0; i < dlug; i++)
	{
		pomi = pi[i];
		pomo = dr[i];
		reverse(pomi.begin(), pomi.end());
		reverse(pomo.begin(), pomo.end());
		if (pomo == dr[i])
			licznik++;
		if (pomi == pi[i])
			licznik++;
	}
	cout << licznik << endl;
}

void IJZ()
{
	int licznikd = 0;
	int dlugw = 0;
	int dluga = 0;
	for (int i = 0; i < dlug; i++)
	{
		dluga = dr[i].length();
		dlugw = pi[i].length() - dr[i].length();
		for (int a = 0; a <= dlugw; a++)
		{
			if (pi[i].substr(a, dluga) == dr[i])
			{
				licznikd++;
				break;
			}
		}
	}
	cout << licznikd << endl;
}

void IJLPS()//!ile_jest_liczb_potrzebujacych_sklejenia
{
	for (int i = 0; i < 200;i++)
	{
		
	}
}

int main()
{
	system("CLS");
	WLDV();
	//DVL();
	CLJP();
	IJZ();
	return 0;
}
