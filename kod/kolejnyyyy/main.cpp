#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> liczby51; //!dane 5-1
vector<int> liczby52; //!dane 5-2
vector<int> liczby53; //!dane 5-3
vector<int> liczby54; //!dane 5-4

void wd51() //!wczytywanie danych 5-1
{
	int p = 0;
	ifstream wep("dane5-1.txt");
	for (int a = 0; a < 20; a++)
	{
		wep >> p;
		liczby51.push_back(p);
	}
	wep.close();
}
void wd52() //!wczytywanie danych 5-2
{
	int p = 0;
	ifstream wep("dane5-2.txt");
	for (int a = 0; a < 200; a++)
	{
		wep >> p;
		liczby52.push_back(p);
	}
	wep.close();
}
void wd53() //!wczytywanie danych 5-3
{
	int p = 0;
	ifstream wep("dane5-3.txt");
	for (int a = 0; a < 10000; a++)
	{
		wep >> p;
		liczby53.push_back(p);
	}
	wep.close();
}
void wd54() //!wczytywanie danych 5-4
{
	int p = 0;
	ifstream wep("dane5-4.txt");
	for (int a = 0; a < 1000000; a++)
	{
		wep >> p;
		liczby54.push_back(p);
	}
	wep.close();
}

void zc51() //!znajdowanie ciągu 5-1
{
	int suma = 0;
	int nsuma = 0;
	int kon = 0;
	int poc = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int a = i; a < 20; a++)
		{
			suma += liczby51[a];
			if (suma > nsuma)
			{
				nsuma = suma;
				poc = i;
				kon = a;
			}
		}
		suma = 0;
	}
	cout << kon - poc + 1 << endl;
	cout << nsuma << endl;
	for (int i = poc; i <= kon; i++)
		cout << liczby51[i] << " ";
	cout << endl;
}
void zc52() //!znajdowanie ciągu 5-2
{
	int suma = 0;
	int nsuma = 0;
	int kon = 0;
	int poc = 0;
	for (int i = 0; i < 200; i++)
	{
		for (int a = i; a < 200; a++)
		{
			suma += liczby52[a];
			if (suma > nsuma)
			{
				nsuma = suma;
				poc = i;
				kon = a;
			}
		}
		suma = 0;
	}
	cout << kon - poc + 1 << endl;
	cout << nsuma << endl;
	for (int i = poc; i <= kon; i++)
		cout << liczby52[i] << " ";
	cout << endl;
}
void zc53() //!znajdowanie ciągu 5-3
{
	int suma = 0;
	int nsuma = 0;
	int kon = 0;
	int poc = 0;
	for (int i = 0; i < 10000; i++)
	{
		for (int a = i; a < 10000; a++)
		{
			suma += liczby53[a];
			if (suma > nsuma)
			{
				nsuma = suma;
				poc = i;
				kon = a;
			}
		}
		suma = 0;
	}
	cout << kon - poc + 1 << endl;
	cout << nsuma << endl;
	for (int i = poc; i <= kon; i++)
		cout << liczby53[i] << " ";
	cout << endl;
}
void zc54() //!znajdowanie ciągu 5-4
{
	int suma = 0;
	int nsuma = 0;
	int kon = 0;
	int poc = 0;
	for (int i = 0; i < 1000000; i++)
	{
		for (int a = i; a < 1000000; a++)
		{
			suma += liczby54[a];
			if (suma > nsuma)
			{
				nsuma = suma;
				poc = i;
				kon = a;
			}
		}
		suma = 0;
	}
	cout << kon - poc + 1 << endl;
	cout << nsuma << endl;
	for (int i = poc; i <= kon; i++)
		cout << liczby54[i] << " ";
	cout << endl;
}

int main()
{
	system("CLS");
	wd51();
	wd52();
	wd53();
	wd54();
	zc54();
	return 0;
}
