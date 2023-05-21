#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

vector<long long> pierw;

void ZAD1()
{
	int x = 0;
	cout << "PODAJ LICZBE CALKOWITA : ";
	cin >> x;
	cout << endl;
	cout << "ODRWOCONA LICZBA       : ";
	while (x != 0)
	{
		cout << x % 10;
		x = x / 10;
	}
	cout << endl;
}

int CP(long long x)
{
	long long licz = sqrt(x);
	for (long long i = 2; i < licz; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
		if (i == licz - 1)
		{
			return 1;
		}
	}
}

void ZAD2()
{
	vector<long long> dzielniki;
	long long x = 5854374255182;
	for (long long i = 2; i < sqrt(x); i++)
	{
		if (x % i == 0)
		{
			dzielniki.push_back(i);
		}
	}
	cout << endl;
	cout << "DZIELNIKI          : ";
	for (auto x : dzielniki)
		cout << x << " ";
	cout << endl;
	cout << "DZIELNIKI PIERWSZE : ";
	cout << "2 ";
	for (auto x : dzielniki)
		if (CP(x) == 1)
			cout << x << " ";
	cout << endl;
}

void ZAD3()
{
	string pier = "";
	string drug = "";
	cout << "NAPIS 1 : ";
	cin >> pier;
	cout << "NAPIS 2 : ";
	cin >> drug;
	int i = 0;
	for (int a = 0; a < drug.length(); a++)
	{
		if (pier[i] == pier[a])
		{
			pier[i] = '-';
			drug[a] = '-';
			i++;
			break;
		}
	}
	cout << endl;
	if (pier == drug)
	{
		cout << "JEST ANAGRAM" << endl;
	}
	if (pier != drug)
	{
		cout << "NIE JEST ANAGRAM" << endl;
	}
	cout << endl;
}

void ZAD4()
{
	string napis = "";
	string nawiasy = "";
	cout << "PODAJ NAPIS : ";
	cin >> napis;
	for (int i = 0; i < napis.length(); i++)
	{
		if (napis[i] == '(' or napis[i] == ')' or napis[i] == '[' or napis[i] == ']')
		{
			nawiasy += napis[i];
		}
	}
	int stanp = 0;
	int stand = 0;
	if (nawiasy[0] == ')' or nawiasy[0] == ']')
	{
		cout << "ZLEEEEEEE" << endl;
	}
	for (int i = 0; i < nawiasy.length(); i++)
	{
		if (nawiasy[i] == '(')
		{
			stanp++;
		}
		if (nawiasy[i] == '[')
		{
			stand++;
		}
	}
}

void ZAD5()
{
	vector<int> dzielniki;
	int a = 0;
	int b = 0;
	int c = 0;
	int licznik = 0;
	cout << "PIERWSZA LICZBA : ";
	cin >> a;
	cout << "DRUGA LICZBA    : ";
	cin >> b;
	cout << "TRZECIA LICZBA  : ";
	cin >> c;
	int najm = a;
	if (najm > b)
	{
		najm = b;
	}
	if (najm > c)
	{
		najm = c;
	}
	for (int i = 1; i <= najm; i++)
	{
		if (najm % i == 0)
		{
			licznik++;
			dzielniki.push_back(i);
		}
	}
	for (int i = licznik - 1; i >= 0; i--)
	{
		if (a % dzielniki[i] == 0 && b % dzielniki[i] == 0 && c % dzielniki[i] == 0)
		{
			cout << dzielniki[i] << endl;
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	system("CLS");
	ZAD1(); //! ZROBIONE
	ZAD2(); //! ZROBIONE
	ZAD3(); //! ZROBIONE
	// ZAD4();
	ZAD5(); //! ZROBIONE
	return 0;
}
