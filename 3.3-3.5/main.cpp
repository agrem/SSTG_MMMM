#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

vector<int> LM;
vector<int> LA;
vector<int> LB;
int dlug = 0;

void IMP()
{
	string pom = "";
	ifstream IMP("liczby_przyklad.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		LM.push_back(stoi(pom));
		IMP >> pom;
		LA.push_back(stoi(pom));
		IMP >> pom;
		LB.push_back(stoi(pom));
		dlug++;
	}
}

void TP()
{
	for (int i = 0; i < dlug; i++)
	{
		cout << LM[i] << " " << LA[i] << " " << LB[i] << endl;
	}
}

void ISPT()
{
	int licznik = 0;
	int wskaz = 0;
	for (int i = 0; i < dlug; i++)
	{
		wskaz = 0;
		if (LM[i] == 2)
		{
			licznik++;
		}
		for (int a = LM[i] - 1; a > 2; a--)
		{
			if (LM[i] % a == 0)
			{
				wskaz = 1;
			}
		}
		if (wskaz == 0)
		{
			licznik++;
		}
	}
	cout << licznik << endl;
}

void WPLMA()
{
	int licznik = 0;
	int wskaz = 0;
	for (int i = 0; i < dlug; i++)
	{
		wskaz = 0;
		if (LM[i] > LA[i])
		{
			for (int a = 2; a < LM[i]; a++)
			{
				if (LM[i] % a == 0 && LA[i] % a == 0)
				{
					wskaz = 1;
				}
			}
		}
		if (LM[i] <= LA[i])
		{
			for (int a = 2; a < LA[i]; a++)
			{
				if (LM[i] % a == 0 && LA[i] % a == 0)
				{
					wskaz = 1;
				}
			}
		}
		if (wskaz == 0)
		{
			licznik++;
		}
	}
	cout << licznik << endl;
}

void DUPA()
{
	int licznik = 0;
	int dupa = 0;
	for (int i = 0; i < dlug; i++)
	{
		dupa = LA[i];
		for (int x = 0; x < LM[i]; x++)
		{
			if (x == 0)
			{
				dupa = 1;
			}
			if (x != 0)
			{
				for (int b = 0; b < x; b++)
				{
					dupa = dupa * LA[i];
				}
			}
			if (dupa % LM[i] == LB[i])
			{
				licznik++;
				break;
			}
		}
	}
	cout << licznik << endl;
}

int main()
{
	system("CLS");
	IMP();
	// TP();
	ISPT();
	WPLMA();
	DUPA();
	return 0;
}
