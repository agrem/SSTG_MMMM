#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> slowa;
vector<string> slowasort;
int dlug = 0;

void WSZL()
{
	string pom = "";
	ifstream we("anagram.txt");
	while (!we.eof())
	{
		getline(we, pom, ' ');
		slowa.push_back(pom);
		sort(pom.begin(), pom.end());
		slowasort.push_back(pom);
		getline(we, pom, ' ');
		slowa.push_back(pom);
		sort(pom.begin(), pom.end());
		slowasort.push_back(pom);
		getline(we, pom, ' ');
		slowa.push_back(pom);
		sort(pom.begin(), pom.end());
		slowasort.push_back(pom);
		getline(we, pom, ' ');
		slowa.push_back(pom);
		sort(pom.begin(), pom.end());
		slowasort.push_back(pom);
		getline(we, pom);
		slowa.push_back(pom);
		sort(pom.begin(), pom.end());
		slowasort.push_back(pom);
		dlug += 5;
	}
}

void DVS()
{
	for (int i = 0; i < dlug; i += 5)
	{
		for (int a = i; a < i + 5; a++)
			cout << slowa[a] << " ";
		cout << endl;
	}
}

void ILMS()
{
	int wskaz = 0;
	for (int i = 0; i < dlug; i += 5)
	{
		wskaz = 0;
		for (int a = i; a < i + 5; a++)
		{
			if (slowa[i].length() != slowa[a].length())
			{
				wskaz = 1;
				break;
			}
		}
		if (wskaz == 0)
		{
			for (int a = i; a < i + 5; a++)
				cout << slowa[a] << " ";
			cout << endl;
		}
	}
}

void CSSA()
{
	int wskaz = 0;
	for (int i = 0; i < dlug; i += 5)
	{
		wskaz = 0;
		for (int a = i; a < i + 5; a++)
		{
			if (slowasort[i] != slowasort[a])
			{
				wskaz = 1;
				break;
			}
		}
		if (wskaz == 0)
		{
			for (int a = i; a < i + 5; a++)
				cout << slowa[a] << " ";
			cout << endl;
		}
	}
}

int main()
{
	system("CLS");
	WSZL();
	//DVS();
	ILMS();
	cout << endl;
	cout << endl;
	cout << endl;
	CSSA();
	return 0;
}
