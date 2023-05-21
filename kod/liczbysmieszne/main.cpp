#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> LP;

vector<string> dane;
int dlug = 0;

bool CP(int n)
{
	if (n % 2 == 0 && n != 2 || n < 2)
		return false;
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void WDDV()
{
	ifstream w("przyklad.txt"); //!    przyklad.txt    liczby.txt
	string pom = "";
	while (!w.eof())
	{
		dlug++;
		getline(w, pom);
		dane.push_back(pom);
	}
}

void DTV()
{
	for (auto x : dane)
		cout << x << endl;
}

void PIOIIJ()
{
	int licznik = 0;
	int wskaz = 0;
	for (int i = 0; i < dlug; i++)
	{
		if (dane[i][0] == dane[i][dane[i].length() - 1])
		{
			licznik++;
			if (wskaz == 0)
			{
				cout << dane[i] << endl;
			}
			wskaz = 1;
		}
	}
	cout << licznik << endl;
}

int main()
{
	cout << CP(4) << endl;
	// GLP();
	// DVLP();
	//  WDDV();
	//   DTV();
	//  PIOIIJ();
	return 0;
}
