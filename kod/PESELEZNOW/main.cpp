#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dane;
vector<string> danen;
int dlug = 0;

void WPDV()
{
	string pom = "";
	ifstream we("pesel.txt");
	while (!we.eof())
	{
		getline(we, pom);
		dane.push_back(pom);
		dlug++;
	}
	we.close();
}

void DDZV()
{
	for (auto x : dane)
		cout << x << endl;
}

void ILUG()
{
	int licznik = 0;
	for (int i = 0; i < dlug; i++)
	{
		if (dane[i].substr(2, 2) == "12")
			licznik++;
	}
	cout << licznik << endl;
}

void IKPB()
{
	int licznik = 0;
	for (int i = 0; i < dlug; i++)
	{
		if (stoi(dane[i].substr(9, 1)) % 2 == 0)
			licznik++;
	}
	cout << licznik << endl;
}

void WRUN()
{
	int licznik = 0;
	int naj = 0;
	string najrok = "";
	for (int i = 0; i < dlug; i++)
	{
		licznik = 0;
		for (int a = i + 1; a < dlug; a++)
		{
			if (dane[i].substr(0, 2) == dane[a].substr(0, 2))
			{
				licznik++;
			}
		}
		if (licznik > naj)
		{
			naj = licznik;
			najrok = dane[i].substr(0, 2);
		}
	}
	cout << naj << "  19" << najrok << endl;
}

void SCPP()
{
	for (int i = 0; i < dlug; i++)
	{
		int a = stoi(dane[i].substr(0, 1)) * 1;
		int b = stoi(dane[i].substr(1, 1)) * 3;
		int c = stoi(dane[i].substr(2, 1)) * 7;
		int d = stoi(dane[i].substr(3, 1)) * 9;
		int e = stoi(dane[i].substr(4, 1)) * 1;
		int f = stoi(dane[i].substr(5, 1)) * 3;
		int g = stoi(dane[i].substr(6, 1)) * 7;
		int h = stoi(dane[i].substr(7, 1)) * 9;
		int l = stoi(dane[i].substr(8, 1)) * 1;
		int j = stoi(dane[i].substr(9, 1)) * 3;
		int k = stoi(dane[i].substr(10, 1));
		int pom = a + b + c + d + e + f + g + h + l + j;
		if (pom % 10 == 0 && k != 0)
		{
			danen.push_back(dane[i]);
		}
		if (10 - pom % 10 != k && pom % 10 != 0)
			danen.push_back(dane[i]);
	}
	sort(danen.begin(), danen.end());
	for (auto x : danen)
		cout << x << endl;
}

void SWDU()
{
	int licznik5 = 0;
	int licznik6 = 0;
	int licznik7 = 0;
	int licznik8 = 0;
	int licznik9 = 0;
	for (int i = 0; i < dlug; i++)
	{
		if (dane[i].substr(0, 1) == "5")
			licznik5++;
		if (dane[i].substr(0, 1) == "6")
			licznik6++;
		if (dane[i].substr(0, 1) == "7")
			licznik7++;
		if (dane[i].substr(0, 1) == "8")
			licznik8++;
		if (dane[i].substr(0, 1) == "9")
			licznik9++;
	}
	cout << licznik5 << "  lata 50  ";
	for (int i = 0; i < licznik5; i++)
		cout << "=";
	cout << endl;
	cout << licznik6 << "  lata 60  ";
	for (int i = 0; i < licznik6; i++)
		cout << "=";
	cout << endl;
	cout << licznik7 << "  lata 70  ";
	for (int i = 0; i < licznik7; i++)
		cout << "=";
	cout << endl;
	cout << licznik8 << "  lata 80  ";
	for (int i = 0; i < licznik8; i++)
		cout << "=";
	cout << endl;
	cout << licznik9 << "   lata 90  ";
	for (int i = 0; i < licznik9; i++)
		cout << "=";
	cout << endl;
}

int main()
{
	system("CLS");
	cout << endl;
	WPDV();
	//DDZV();
	ILUG();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	IKPB();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	WRUN();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SCPP();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SWDU();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	return 0;
}
