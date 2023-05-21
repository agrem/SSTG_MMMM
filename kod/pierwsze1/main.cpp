#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int liczba = 0;
int liczbap = 0;
int licznik = 0;
int licznikp = 0;

void gl() //!generacja liczb
{
	for (int i = 1; i <= 1000; i++)
	{
		liczba = i;
		liczbap = i;
		licznik = 0;
		while (liczba != 0)
		{
			licznik += liczba % 10;
			liczba = liczba / 10;
		}
		if (licznik == 2)
		{
			licznikp++;
			cout << licznik << " " << liczbap << endl;
		}
		for (int a = 2; a < licznik; a++)
		{
			if (licznik % a == 0)
				break;
			if (a == licznik - 1)
			{
				licznikp++;
				cout << licznik << " " << liczbap << endl;
			}
		}
	}
	cout << endl;
	cout << "JEST " << licznikp << " TAKICH LICZB" << endl;
	cout << endl;
}

int main()
{
	system("CLS");
	gl();
	return 0;
}
