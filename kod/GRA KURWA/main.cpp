#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

void DUPA()
{
	vector<int> ruchy;
	int wielplan = 0;
	int dlug = 0;
	string x = "";
	while (x != "end")
	{
		cin >> x;
		if (x != "end")
		{
			ruchy.push_back(stoi(x));
			dlug++;
		}
	}
	cin >> wielplan;
	wielplan += 1;
	string plansza = "";
	for (int i = 0; i < wielplan; i++)
	{
		if (i == wielplan - 1)
			plansza = plansza + '*';
		else
			plansza = plansza + '_';
	}
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 0; a < wielplan; a++)
		{
			if (plansza[a + ruchy[i]] == '*')
			{
				plansza[a] = '*';
			}
		}
	}
	int wskaz = 0;
	for (int i = 0; i < wielplan; i++)
	{
		if (plansza[i] == '_')
		{
			wskaz = 1;
			break;
		}
	}
	cout << plansza << endl;
	if (wskaz == 0)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
}

int main()
{
	system("CLS");
	DUPA();
	return 0;
}
