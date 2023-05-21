#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> LSBP; //!liczby_super_b_pierwsze

int CLJP(int x) //!czy_liczba_jest_pierwsza
{
	if (x == 1)
		return 0;
	if (x == 2)
		return 1;
	if (x == 3)
		return 1;
	if (x == 4)
		return 0;
	for (int i = 3; i < x; i++)
	{
		if (x % i == 0)
			return 0;
		if (i == x - 1)
			return 1;
	}
}

int SCL(int x) //!suma_cyfr_liczby
{
	int pom = x;
	int suma = 0;
	while (pom != 0)
	{
		suma += pom % 10;
		pom = pom / 10;
	}
	return suma;
}

int SCLB(int y) //!suma_cyfr_liczby_binarnie
{
	int pom = y;
	int suma = 0;
	while (pom != 0)
	{
		suma += pom % 2;
		pom = pom / 2;
	}
	return suma;
}

void ILSBP() //!ile_liczb_super_b_pierwszych
{
	int sumap = 0;
	int sumad = 0;
	int sumat = 0;
	for (int i = 2; i <= 1000; i++)
	{
		if (CLJP(i) == 1 && CLJP(SCL(i)) == 1 && CLJP(SCLB(i)) == 1)
		{
			cout << i << endl;
			sumap++;
		}
	}
	for (int i = 100; i <= 10000; i++)
	{
		if (CLJP(i) == 1 && CLJP(SCL(i)) == 1 && CLJP(SCLB(i)) == 1)
		{
			cout << i << endl;
			LSBP.push_back(i);
			sumad++;
		}
	}
	for (int i = 1000; i <= 100000; i++)
	{
		if (CLJP(i) == 1 && CLJP(SCL(i)) == 1 && CLJP(SCLB(i)) == 1)
			sumat++;
	}
	cout << "===========================A===========================" << endl;
	cout << "SUMA 1 PRZEDZIALU " << sumap << endl;
	cout << "SUMA 2 PRZEDZIALU " << sumad << endl;
	cout << "SUMA 3 PRZEDZIALU " << sumat << endl;
}

void ILMSCP() //!ile_liczb_ma_sume_cyfr_pierwsza
{
	int sumas = 0;
	for (int i = 100; i <= 10000; i++)
	{
		if (CLJP(SCL(i)) == 1)
			sumas++;
	}
	cout << "===========================B===========================" << endl;
	cout << "JEST " << sumas << " TAKICH LICZB" << endl;
}

void CSLSPJP() //!czy_suma_liczb_super_pierwszych_jest_pierwsza
{
	int sumay = 0;
	for (auto a : LSBP)
	{
		sumay += a;
	}
	if (CLJP(sumay) == 1)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
}

int main()
{
	system("CLS");
	ILSBP();
	ILMSCP();
	CSLSPJP();
	return 0;
}
