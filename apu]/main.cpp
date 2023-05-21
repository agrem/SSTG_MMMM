#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> liczbav;
vector<int> sumav;
vector<int> sumavr;
long long suma = 0;
int licznik = 0;
int licznikl = 0;
int liczniks = 0;

void gl()
{
	int b = 0;
	int a = 0;
	for (long long i = 1; i <= 10000000; i++)
	{
		a = i;
		while (a != 0)
		{
			liczbav.push_back(a % 10);
			suma += (a % 10) * (a % 10);
			a = a / 10;
			licznik++;
		}
		licznik -= 1;
		// cout << "SUMA     " << suma << endl;
		while (suma != 0)
		{
			sumav.push_back(suma % 10);
			suma = suma / 10;
			liczniks++;
		}
		for (auto x : sumav)
		{
			sumavr.push_back(x);
		}
		liczniks -= 1;
		// cout << "LICZBA   ";
		// for (int i = licznik; i >= 0; i--)
		// cout << liczbav[i];
		for (int i = 0; i < liczniks; i++)
		{
			if (sumav[i] != sumavr[i])
			{
				break;
			}
			if (i == liczniks - 1)
			{
				licznikl++;
				break;
			}
		}
		// cout << endl;
		// cout << endl;
		liczbav.clear();
		suma = 0;
		licznik = 0;
		liczniks = 0;
	}
	cout << licznikl << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	gl();
	return 0;
}
