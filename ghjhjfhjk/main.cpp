#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> czas1;
vector<int> czas2;
vector<int> programy{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
vector<int> podliczenia{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<string> blachy;
vector<string> blachy_kopia;
int dlug = 0;

void EJJWP()
{
	string TRA = "";
	int TRAI = 0;
	ifstream IMP("myjnia.txt");
	while (!IMP.eof())
	{
		getline(IMP, TRA, ';');
		TRAI = stoi(TRA);
		czas1.push_back(TRAI);
		getline(IMP, TRA, ';');
		TRAI = stoi(TRA);
		czas2.push_back(TRAI);
		getline(IMP, TRA);
		blachy.push_back(TRA);
		blachy_kopia.push_back(TRA.substr(0, 2));
		dlug++;
	}
}

void DTD()
{
	for (int i = 0; i < dlug; i++)
	{
		cout << czas1[i] << "  " << czas2[i] << "  " << blachy[i] << endl;
	}
}

void PPK()
{
	// vector<int> podl[15];
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 0; a < 15; a++)
		{
			if (czas2[i] == programy[a])
			{
				podliczenia[a]++;
				break;
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		cout << programy[i] << "    " << podliczenia[i] << endl;
	}
}

void TDGZ()
{
	int licznikd = 0;
	int licznikdd = 0;
	for (int i = 0; i < dlug; i++)
	{
		int licznik = 0;
		for (int a = 0; a < dlug; a++)
		{
			if (blachy_kopia[i] == blachy_kopia[a])
			{
				licznik++;
			}
			if (licznik > 2)
			{
				break;
			}
		}
		if (licznik == 1)
		{
			licznikd++;
		}
		if (licznik == 2)
		{
			licznikdd++;
		}
	}
	cout << licznikd << "   " << licznikdd << endl;
}

int main()
{
	vector<int> podl[15];

	system("CLS");

	EJJWP();
	// DTD();
	PPK();
	TDGZ();

	return 0;
}
