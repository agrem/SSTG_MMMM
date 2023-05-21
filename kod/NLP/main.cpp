#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int liczban = 0;
long long liczba = 0;
long long liczbaw = 0;
long long liczbad = 0;
int G = 0;
int D = 0;
int licznik = 0;

void NLP()
{
	cin >> liczba;
	liczbaw = liczba;
	liczbad = liczba;
	int a = sqrt(liczba);
	while (G == 0)
	{
		for (int i = 2; i < a; i++)
		{
			if (liczba % i == 0)
			{
				break;
			}
			if (i == a - 1)
			{
				cout << "DO GORY : ";
				cout << liczba << "    PRZESUNIETE : " << liczba - liczbaw << endl;
				G = 1;
			}
		}
		liczba++;
	}
	while (D == 0)
	{
		for (int i = 2; i < a; i++)
		{
			if (liczbad % i == 0)
			{
				break;
			}
			if (i == a - 1)
			{
				cout << "W DOL   : ";
				cout << liczbad << "    PRZESUNIETE : " << liczbad - liczbaw << endl;
				D = 1;
			}
		}
		liczbad--;
	}
}

void IJMLWD()
{
	cin >> liczban;
	while (liczban != 0)
	{
		licznik += liczban % 2;
		liczban = liczban / 2;
	}
	cout << licznik << endl;
}

int main()
{
	//NLP();
	IJMLWD();
	return 0;
}
