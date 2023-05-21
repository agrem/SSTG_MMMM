#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> dane;
int licznik = 0;

void WPDV()
{
	string pom = "";
	ifstream IMP("genetyka.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		dane.push_back(pom);
		licznik++;
	}
}

void DTFS()
{
	for (auto x : dane)
	{
		cout << x << endl;
	}
}

void SCGWD()
{
	int licznikkol = 0;
	string dod = "";
	string dodd = "";
	int znacz = 0;
	for (int i = 0; i < licznik; i++)
	{
		dodd = dane[i];
		while (znacz == 0)
		{
			for (int a = 0; a < dodd.length() - 2; a += 2)
			{
				if (dodd[a] == 'B' && dodd[a + 1] == 'D')
				{
					dod = dod + 'A';
				}
				if (dodd[a] == 'C' && dodd[a + 1] == 'A')
				{
					dod = dod + 'B';
				}
				if (dodd[a] == 'C' && dodd[a + 1] == 'D')
				{
					dod = dod + 'B';
				}
				if (dodd[a] == 'D' && dodd[a + 1] == 'D')
				{
					dod = dod + 'C';
				}
				if (dodd[a] == 'B' && dodd[a + 1] == 'C')
				{
					dod = dod + 'D';
				}
				else
				{
					cout << dane[i] << " NIE DA SIE" << endl;
					licznikkol++;
					znacz = 1;
					break;
				}
				if (dod.length() == 1)
				{
					cout << dane[i] << "     DA SIE" << endl;
					znacz = 1;
					break;
				}
			}
			dod = "";
			dodd = dod;
		}
		znacz = 0;
	}
	cout << "JEST " << licznikkol << " ZLYCH CIAGOW" << endl;
}

int main()
{
	system("CLS");
	WPDV();
	// DTFS();
	SCGWD();
	return 0;
}