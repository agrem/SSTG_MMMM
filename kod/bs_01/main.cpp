#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
int a = 0;
int w = 0;
int tab[] = {37, 35, 28, 11, 3, 3, 15, 63, 125, 35, 17, 18};
int wt = sizeof(tab) / sizeof(int);
int loga = log(wt) / log(2);

void sb() //!sortowanie_bablekowe
{
	for (int a = 0; a < wt; a++)
	{
		for (int i = 0; i < wt - 1; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(tab[i], tab[i + 1]);
			}
		}
	}
	for (int i = 0; i < wt; i++)
		cout << tab[i] << endl;
}

void bs() //!binary_search
{
	cout << "CO ZNALESC: ";
	cin >> a;
	int pocz = 0;
	int konc = wt - 1;
	for (int i = 0; i < loga + 1; i++)
	{
		int srod = (pocz + konc) / 2;
		if (tab[srod] > a)
		{
			konc = srod - 1;
		}
		if (tab[srod] < a)
		{
			pocz = srod + 1;
		}
		if (tab[srod] == a)
		{
			cout << "LICZBA ZNALEZIONA NA POZYCJI: ";
			cout << srod + 1 << endl;
			w = 1;
			break;
		}
		}
	if (w == 0)
	{
		cout << "NIE MA" << endl;
	}
}

main()
{
	system("CLS");
	sb();
	bs();
	return 0;
}
