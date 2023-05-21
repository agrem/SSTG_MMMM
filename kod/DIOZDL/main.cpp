#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>

using namespace std;

int i = 2;

int cp(int x) //! czy pierwsza
{
	int pier = x;
	for (int a = 2; a < pier; a++)
	{
		if (x % a == 0)
		{
			return 0;
		}
		if (a == pier - 1)
		{
			return 1;
		}
	}
}

void roz(string a, string b)
{
	int wskaz = 0;
	string pomoc = "";
	int dluga = a.length();
	int dlugb = b.length();
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
	if (a[0] < b[0])
	{
		pomoc = a;
		a = b;
		b = pomoc;
		wskaz = 1;
	}
	int pom = 0;
	int dlugw = a.length();
	int dlugv = 0;
	vector<int> roz;
	for (int i = 0; i < dlugw; i++)
	{
		pom = (int)a[i] - '0' - (int)b[i] - '0';
		roz.push_back(pom + '0' + '0');
		dlugv++;
	}
	for (int i = dlugw - 1; i > 0; i--)
	{
		if (roz[i] < 0)
		{
			roz[i] += 10;
			roz[i - 1] -= 1;
		}
	}
	int pomo = 0;
	if (wskaz == 1)
	{
		cout << "-";
	}
	for (int i = 0; i < dlugv; i++)
	{
		if (roz[i] != 0)
		{
			pomo = 1;
		}
		if (pomo == 1)
		{
			cout << roz[i];
		}
	}
	cout << endl;
}

void dod(string a, string b)
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

int main()
{
	system("CLS");
	int licz = 0;
	string te = "";
	string to = "";
	cin >> te;
	cout << "-" << endl;
	cin >> to;
	cout << "=" << endl;
	roz(te, to);
	return 0;
}
