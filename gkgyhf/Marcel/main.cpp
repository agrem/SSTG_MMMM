#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

string MP = "";
string M = "";
string PW = "";

void WDDVP() //! wczytywanie pliku ale przyklad
{
	ifstream IMP("mecz_przyklad.txt");
	getline(IMP, MP);
	IMP.close();
}

void WDDV() //! wczytywanie pliku
{
	ifstream IMP("mecz.txt");
	getline(IMP, M);
	IMP.close();
}

void DTPINP() //! drukowanie testowe
{
	cout << "PLIK TESTOWY" << endl;
	cout << MP;
	cout << endl;
	cout << "PLIK NORMALNY" << endl;
	cout << endl;
	cout << M;
}

void SRP() //! 1.1
{
	int licznik = 0;
	for (int i = 0; i < PW.length() - 1; i++)
	{
		if (PW[i] != PW[i + 1])
		{
			licznik++;
		}
	}
	cout << "===============================1.1===============================" << endl;
	cout << licznik << endl;
	cout << endl;
}

void ZKWM()
{
	int licznikA = 0;
	int licznikB = 0;
	char DW;
	for (int i = 0; i < PW.length(); i++)
	{
		if (PW[i] == 'A')
		{
			licznikA++;
		}
		if (PW[i] == 'B')
		{
			licznikB++;
		}
		if (licznikB > licznikA)
		{
			DW = 'B';
		}
		if (licznikB < licznikA)
		{
			DW = 'A';
		}
		if (licznikA >= 1000 or licznikB >= 1000)
		{
			if (licznikA - licznikB >= 3 or licznikA - licznikB <= -3)
			{
				cout << "===============================1.2===============================" << endl;
				cout << "DRUZYNA WYGRANA : " << DW << " " << licznikA << ":" << licznikB << endl;
				cout << endl;
				break;
			}
		}
	}
}

void ZDP()
{
	int najl = 9;
	int najlA = 0;
	int najlB = 0;
	int licznik = 1;
	int licznikpasA = 0;
	int licznikpasB = 0;
	int wskaz = 0;
	char DP;
	for (int i = 0; i < PW.length(); i++)
	{
		if (PW[i] == PW[i + 1])
		{
			licznik++;
		}
		if (PW[i] != PW[i + 1])
		{
			licznik = 1;
			wskaz = 0;
		}
		if (licznik >= 10 && wskaz == 0)
		{
			if (PW[i] == 'A')
			{
				licznikpasA++;
				wskaz = 1;
			}
			if (PW[i] == 'B')
			{
				licznikpasB++;
				wskaz = 1;
			}
		}
	}
	cout << "===============================1.3===============================" << endl;
	cout << licznikpasA + licznikpasB << endl;

	for (int i = 0; i < PW.length(); i++)
	{
		if (PW[i] == PW[i + 1])
		{
			licznik++;
		}
		if (PW[i] != PW[i + 1])
		{
			licznik = 1;
			wskaz = 0;
		}
		if (licznik > najl)
		{
			if (PW[i] == 'A')
			{
				najl = licznik;
				najlA = najl;
			}
			if (PW[i] == 'B')
			{
				najl = licznik;
				najlB = najl;
				licznikpasB++;
			}
		}
	}
	if (najlA > najlB)
	{
		cout << "DRUZYNA A MIALA NAJDLUZSZA PASSE O DLUGOSCI " << najlA << endl;
	}
	if (najlA < najlB)
	{
		cout << "DRUZYNA B MIALA NAJDLUZSZA PASSE O DLUGOSCI " << najlB << endl;
	}
	cout << endl;
}

vector<int> LP;
vector<int> LZ;
int dlug = 0;
int dlugp = 0;

void WPGB() //! wczytywanie zadanie 3
{
	int pom = 0;
	ifstream IMP("liczby.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		LZ.push_back(pom);
		dlug++;
	}
}

void GLPDM() //! generowanie liczb pierwszych do 1000000
{
	LP.push_back(2);
	for (int i = 3; i <= 1000000; i++)
	{
		for (int a = 2; a < i; a++)
		{
			if (i % a == 0)
			{
				break;
			}
			if (a == i - 1)
			{
				LP.push_back(i);
				dlugp++;
			}
		}
	}
}

void XMJ() //! 3.2
{
	int licznikp = 0;
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 0; a < dlugp; a++)
		{
			if (LZ[i] - 1 == LP[a])
			{
				licznikp++;
			}
		}
	}
	cout << "===============================3.2===============================" << endl;
	cout << licznikp << endl;
	cout << endl;
}

void CGMR() //! 3.3
{
	int licznik = 0;
	int liczbanajw = 0;
	int liczbanajm = 0;
	int najw = 0;
	int najm = 9999999;
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 0; a < dlugp; a++)
		{
			for (int b = a; b < dlugp; b++)
			{
				if (LZ[i] - LP[a] == LP[b])
				{
					licznik++;
				}
			}
		}
		if (licznik > najw)
		{
			najw = licznik;
			liczbanajw = LZ[i];
		}
		if (licznik < najm)
		{
			najm = licznik;
			liczbanajm = LZ[i];
		}
		licznik = 0;
	}
	cout << "===============================3.3===============================" << endl;
	cout << liczbanajw << " " << najw << " " << liczbanajm << " " << najm << endl;
	cout << endl;
}

int main()
{
	system("CLS");
	WDDVP();
	WDDV();
	PW = M;
	// DTPINP();
	SRP();
	ZKWM();
	ZDP();
	WPGB();
	GLPDM();
	XMJ();
	CGMR();
	return 0;
}