#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string liczba1 = "";
string liczba2 = "";

void DKDL(string a, string b) //! dodawanie_kurewsko_duzych_liczb
{
	int dluga = a.length();
	int dlugb = b.length();
	a = '0' + a;
	b = '0' + b;
	int pom = 0;
	if (dluga > dlugb)
	{
		for (int i = 0; i < dluga - dlugb; i++)
		{
			b = '0' + b;
		}
	}
	if (dluga < dlugb)
	{
		for (int i = 0; i < dlugb - dluga; i++)
		{
			a = '0' + a;
		}
	}
	int dlugw = a.length();
	int dlugv = 0;
	vector<int> sum;
	for (int i = 0; i < dlugw; i++)
	{
		pom = (int)a[i] - '0' + (int)b[i] - '0';
		sum.push_back(pom);
		dlugv++;
	}
	for (int i = 0; i < dlugv; i++)
	{
		if (sum[i] >= 10)
		{
			sum[i] -= 10;
			sum[i - 1] += 1;
		}
	}
	int pomo = 0;
	for (int i = 0; i < dlugv; i++)
	{
		if (sum[i] != 0)
		{
			pomo = 1;
		}
		if (pomo == 1)
		{
			cout << sum[i];
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}

void MZDL() //! mnozenie_zajebistych_duzych_liczb
{
	cin >> liczba1;
	cin >> liczba2;
	int dlug1 = liczba1.length();
	int dlug2 = liczba2.length();
	vector<int> liczbaw;
	for (int a = 0; a < dlug2; a++)
	{
		for (int i = 0; i < dlug1; i++)
		{
			liczbaw.push_back(((int)liczba1[i] - '0') * ((int)liczba2[0] - '0'));
		}
		for (int i = dlug1; i >= 1; i--)
		{
			if (liczbaw[i] >= 10)
			{
				liczbaw[i] -= (liczbaw[i] / 10) % 10;
				liczbaw[i + 1] += liczbaw[i] % 10;
			}
		}
	}
	for (auto x : liczbaw)
		cout << x;
	cout << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	MZDL();
	return 0;
}
