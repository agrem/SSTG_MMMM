#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> sygnal;
int licznik = 0;

void WS() //!wczytywanie_sygnalow
{
	string pom = "";
	ifstream we("sygnaly.txt");
	while (!we.eof())
	{
		we >> pom;
		sygnal.push_back(pom);
		licznik++;
	}
	we.close();
}

void SS() //!szukanie_sygnalow
{
	for (int i = 39; i < licznik; i += 40)
	{
		cout << sygnal[i][9];
	}
	cout << endl;
}

void NLS() //!najwiecej_liter_w_sygnale
{
	int licznika = 0;
	int najw = 0;
	int najl = 0;
	for (int a = 0; a < licznik; a++)
	{
		licznika = 0;
		string alfabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
		for (int i = 0; i < sygnal[a].length(); i++)
		{
			for (int h = 0; h < 26; h++)
			{
				if (sygnal[a][i] == alfabet[h])
				{
					alfabet[h] = '*';
				}
			}
		}
		for (int g = 0; g < 26; g++)
		{
			if (alfabet[g] == '*')
			{
				licznika++;
			}
		}
		if (licznika > najl)
		{
			najw = a;
			najl = licznika;
		}
	}
	cout << sygnal[najw] << "  " << najl << endl;
}

void OLWS() //!odlegosci_liter_w_sygnale
{
	int naj = 0;
	int najm = 200;
	for (int g = 0; g < licznik; g++)
	{
		naj = 0;
		najm = 200;
		for (int i = 0; i < sygnal[g].length(); i++)
		{
			if ((int)sygnal[g][i] < najm)
			{
				najm = (int)sygnal[g][i];
			}
			if ((int)sygnal[g][i] > naj)
			{
				naj = (int)sygnal[g][i];
			}
		}
		if (naj - najm <= 10)
		{
			cout << sygnal[g] << endl;
		}
	}
}

int main()
{
	system("CLS");
	WS();
	cout << "==========================4.1==========================" << endl;
	cout << endl;
	SS();
	cout << endl;
	cout << "==========================4.2==========================" << endl;
	cout << endl;
	NLS();
	cout << endl;
	cout << "==========================4.3==========================" << endl;
	cout << endl;
	OLWS();
	return 0;
}
