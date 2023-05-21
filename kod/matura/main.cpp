#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> dane;
int dlug = 0;

void WDDV() //! wczytywanie danych do vectora
{
	ifstream WV("przyklad.txt"); //! napisy.txt     przyklad.txt
	string pomoc = "";
	while (!WV.eof())
	{
		getline(WV, pomoc);
		dane.push_back(pomoc);
		dlug++;
	}
}

void DTV() //! drukowanie testowe vectora
{
	for (auto x : dane)
		cout << x << endl;
}

void ICJWP() //! ile cyfr jest w pliku
{
	int licznikl = 0;
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 0; a < dane[i].length(); a++)
		{
			if ((int)dane[i][a] <= 57 && (int)dane[i][a] >= 48)
			{
				licznikl++;
			}
		}
	}
	cout << licznikl << endl;
}

void SHWV() //! szukanie hasla w vectorze
{
	string haslo = "";
	int poz = 0;
	for (int i = 19; i < dlug; i += 20)
	{
		cout << dane[i][poz];
		poz++;
	}
	cout << endl;
}

void CPPK() //! czy palindrom poraz kolejny
{
	string haslo = "";
	string pomoc = "";
	string pomocr = "";
	string dpomoc = "";
	string dpomocr = "";
	for (int i = 0; i < dlug; i++)
	{
		pomoc = dane[i] + dane[i][0];
		pomocr = dane[i] + dane[i][0];
		dpomoc = dane[i][49] + dane[i];
		dpomocr = dane[i][49] + dane[i];
		reverse(pomocr.begin(), pomocr.end());
		reverse(dpomocr.begin(), dpomocr.end());
		if (pomoc == pomocr && dpomoc != dpomocr)
		{
			haslo = haslo + pomoc[25];
		}
		if (dpomoc == dpomocr && pomoc != pomocr)
		{
			haslo = haslo + dpomoc[25];
		}
	}
	cout << haslo << endl;
}

void OHWV()
{
	string haslo = "";
	vector<string> cyfry{dlug};
	for (int i = 0; i < dlug; i++)
	{
		for (int a = 0; a < dane[i].length(); a++)
		{
			if ((int)dane[i][a] <= 57 && (int)dane[i][a] >= 48)
			{
				cyfry[i] = cyfry[i] + dane[i][a];
			}
		}
	}
	for (int i = 0; i < dlug; i++)
	{
		if (cyfry[i].length() >= 2)
		{
			for (int a = 0; a < cyfry[i].length() - 2; a++)
			{
				int pier = (int)cyfry[i][a] - '0';
				pier = pier * 10;
				int drug = (int)cyfry[i][a + 1] - '0';
				int sum = pier + drug;
				if (sum >= 65 && sum <= 90)
				{
					haslo = haslo + (char)sum;
				}
			}
		}
	}
	cout << haslo << endl;
}

int main()
{
	system("CLS");
	WDDV();
	// DTV();
	ICJWP();
	SHWV();
	CPPK();
	OHWV();
	return 0;
}
