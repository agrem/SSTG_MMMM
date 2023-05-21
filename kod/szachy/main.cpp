#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> plansze;
vector<string> planszek;
int dlug = 0;

void WPDV() //! wczytywanie_plansz_do_vectora
{
	string pom = "";
	ifstream wep("szachy.txt"); //!  szaczy.txt    szachy_przyklady.txt
	while (!wep.eof())
	{
		getline(wep, pom);
		plansze.push_back(pom);
		dlug++;
	}
	planszek = plansze;
}

void DVP() //! drukowanie_vectora_plansz
{
	for (int i = 0; i < dlug; i++)
	{
		cout << plansze[i] << endl;
	}
}

void P1M() //! punkt_pierwszy_matury
{
	int licz = 0;
	for (int a = 0; a < dlug; a += 9)
	{
		for (int i = 0; i < 8; i++)
		{
			if (plansze[a][i] == '.' && plansze[a + 1][i] == '.' && plansze[a + 2][i] == '.' && plansze[a + 3][i] == '.' && plansze[a + 4][i] == '.' && plansze[a + 5][i] == '.' && plansze[a + 6][i] == '.' && plansze[a + 7][i] == '.')
			{
				licz++;
				break;
			}
		}
	}
	cout << licz << "  ";
	int naj = 0;
	for (int a = 0; a < dlug; a += 9)
	{
		licz = 0;
		for (int i = 0; i < 8; i++)
		{
			if (plansze[a][i] == '.' && plansze[a + 1][i] == '.' && plansze[a + 2][i] == '.' && plansze[a + 3][i] == '.' && plansze[a + 4][i] == '.' && plansze[a + 5][i] == '.' && plansze[a + 6][i] == '.' && plansze[a + 7][i] == '.')
			{
				licz++;
			}
		}
		if (naj < licz)
			naj = licz;
	}
	cout << naj << endl;
}

void P2M() //! punkt_drugi_matury
{
	int liczw = 0;
	int liczm = 0;
	int najm = 100;
	string szachm;
	string szachd;
	for (int i = 0; i < dlug; i += 9)
	{
		szachm = "kwwsshggpppppppp";
		szachd = "KWWSSHGGPPPPPPPP";
		for (int a = i; a < i + 8; a++)
		{
			for (int k = 0; k < 16; k++)
			{
				for (int b = 0; b < 8; b++)
				{
					if (plansze[a][b] == szachm[k])
					{
						plansze[a][b] = '.';
						szachm[k] = '-';
					}
					if (plansze[a][b] == szachd[k])
					{
						plansze[a][b] = '.';
						szachd[k] = '-';
					}
				}
			}
		}
		for (int j = 0; j < 16; j++)
		{
			szachm[j] = toupper(szachm[j]);
		}
		if (szachm == szachd)
		{
			// cout << szachm << "   " << szachd << endl;
			for (int o = 0; o < 16; o++)
			{
				if (szachm[o] == '-' && szachm[o] == '-')
					liczm += 2;
			}
			liczw++;
			if (najm > liczm)
				najm = liczm;
		}
		liczm = 0;
	}
	cin.get();
	cout << "************************************************" << endl;
	cout << liczw << "  " << najm << endl;
}

void P3M() //! punkt_trzeci_matury
{
}

int main()
{
	system("CLS");
	WPDV();
	//! DVP();
	P1M();
	P2M();
	return 0;
}
