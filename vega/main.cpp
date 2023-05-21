#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> dane;

int len = 0;

void WPN()
{
	string pom = "";
	ifstream IMP("sygnaly.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		dane.push_back(pom);
		len++;
	}
}

void WPT()
{
	string pom = "";
	ifstream IMP("przyklad.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		dane.push_back(pom);
		len++;
	}
}

void DTCDSW()
{
	for (int i = 0; i < len; i++)
	{
		cout << dane[i] << endl;
	}
}

void PPWDL()
{
	string wyraz = "";
	for (int i = 39; i < len; i += 40)
	{
		wyraz = wyraz + dane[i][9];
	}
	cout << wyraz << endl;
}

void ZNLRL()
{
	int licznik = 0;
	int naj = 0;
	string wyraz = "";
	for (int i = 0; i < len; i++)
	{
		string alf = "QWERTYUIOPASDFGHJKLZXCVBNM";
		for (int a = 0; a < dane[i].length(); a++)
		{
			for (int b = 0; b < alf.length(); b++)
			{
				if (dane[i][a] == alf[b])
				{
					alf[b] = '*';
					break;
				}
			}
		}
		for (int a = 0; a < alf.length(); a++)
		{
			if (alf[a] == '*')
			{
				licznik++;
			}
		}
		if (licznik > naj)
		{
			naj = licznik;
			wyraz = dane[i];
		}
		licznik = 0;
	}
	cout << wyraz << " " << naj << endl;
}

void OPKLSKC()
{
	int licznik = 0;
	int znak = 0;
	for (int i = 0; i < len; i++)
	{
		znak = 0;
		for (int a = 0; a < dane[i].length() - 1; a++)
		{
			for (int b = a + 1; b < dane[i].length(); b++)
			{
				if ((int)dane[i][a] - (int)dane[i][b] > 10 or (int) dane[i][a] - (int)dane[i][b] < -10)
				{
					znak = 1;
				}
			}
		}
		if (znak == 0)
		{
			cout << dane[i] << endl;
			licznik++;
		}
	}
	cout << licznik << endl;
}

int main()
{
	system("CLS");
	WPN();
	// WPT();
	//  DTCDSW();
	cout << endl;
	PPWDL();
	cout << endl;
	ZNLRL();
	cout << endl;
	OPKLSKC();
	return 0;
}
