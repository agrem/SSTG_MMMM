#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> DCN;
int dlug = 0;

void WDD()
{
	string pom = "";
	ifstream IMP("identyfikator.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		DCN.push_back(pom);
		dlug++;
	}
	IMP.close();
}
void WTD()
{
	string pom = "";
	ifstream IMP("identyfikator_przyklad.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		DCN.push_back(pom);
		dlug++;
	}
	IMP.close();
}

void DTD()
{
	for (int i = 0; i < dlug; i++)
	{
		cout << DCN[i] << endl;
	}
}

void NSN()
{
	int najs = 0;
	int suma = 0;
	vector<string> najw;
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 3; a < DCN[i].length(); a++)
		{
			suma += stoi(DCN[i].substr(a, 1));
		}
		if (suma > najs)
		{
			najs = suma;
		}
		suma = 0;
	}
	cout << najs << " " < < < endl;
}

int main()
{
	system("CLS");
	WTD();
	DTD();
	NSN();
	return 0;
}
