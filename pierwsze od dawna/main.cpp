#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

string liczba = "";
int liczbad = 0;
int systemBaza = 0;
int systemKonw = 0;

void WD()
{
	string liczbaKonw = "";
	cout << "WPISZ LICZBE                      ";
	cin >> liczba;
	cout << endl;
	cout << "WPISZ BAZE SYSTEMU                ";
	cin >> systemBaza;
	cout << endl;
	cout << "WPISZ BAZE SYSTEMU DO KONWERSJI   ";
	cin >> systemKonw;
}

void ZND()
{
	int systembazapom = 1;
	int literka = 0;
	for (int i = liczba.length() - 1; i >= 0; i--)
	{
		if (liczba[i] >= 'A' && liczba[i] <= 'F')
		{
			liczbad += 10 * systembazapom;
			systembazapom = systembazapom * systemBaza;
		}
		else
		{
			liczbad += (int(liczba[i]) - '0') * systembazapom;
			systembazapom = systembazapom * systemBaza;
		}
	}
	cout << liczbad << endl;
}

int ZSLM()
{
	cout << endl;
	cout << endl;
	int licznik = 0;
	while (liczbad != 0)
	{
		liczbad % systemKonw;
		cout << liczbad % systemKonw;
		liczbad = liczbad / systemKonw;
		licznik++;
	}
	cout << endl;
	cout << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	WD();
	system("CLS");
	ZND();
	system("CLS");
	ZSLM();
	return 0;
}
