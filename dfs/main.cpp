#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> dane;
int licznik = 0;

void WD()
{
	string napis = "";
	ifstream we("napisy.txt");
	while (!we.eof())
	{
		we >> napis;
		dane.push_back(napis);
		licznik++;
	}
	cout << licznik << endl;
}

void DTD()
{
	for (auto x : dane)
	{
		cout << x << endl;
	}
}

void Z41()
{
	int licznikc = 0;
	for (int i = 0; i < licznik; i++)
	{
		for (int a = 0; a < 50; a++)
		{
			if ((int)dane[i][a] >= 48 && (int)dane[i][a] <= 57)
			{
				licznikc++;
			}
		}
	}
	cout << licznikc << endl;
}

void Z42()
{
	string haslo = "";
	int a = 0;
	for (int i = 19; i < 1000; i += 20)
	{
		haslo = haslo + dane[i][a];
		a++;
	}
	cout << haslo << endl;
}

void Z43()
{
	string test1 = "";
	string test2 = "";
	for (int i = 0; i < 1000; i++)
	{
		test1 = dane[i] + dane[i][0];
		test2 = dane[i] + dane[i][0];
		reverse(test2.begin(), test2.end());
		if (test1 == test2)
		{
			// cout << dane[i] << endl;
			cout << test1[25];
		}
		test1 = dane[i][49] + dane[i];
		test2 = dane[i][49] + dane[i];
		reverse(test2.begin(), test2.end());
		if (test1 == test2)
		{
			// cout << dane[i] << endl;
			cout << test1[25];
		}
	}
	cout << endl;
}

void Z44()
{
	int haslo2 = 0;
	string haslod = "";
	for (int i = 0; i < 1000; i++)
	{
		for (int a = 0; a < 50; a++)
		{
			if ((int)dane[i][a] >= 48 && (int)dane[i][a] <= 57 && (int)dane[i][a + 1] >= 48 && (int)dane[i][a + 1] <= 57)
			{
				haslo2 = ((int)dane[i][a] - '0') * 10 + (int)dane[i][a + 1] - '0';
				if (haslo2 >= 65 && haslo2 <= 90)
					haslod = haslod + (char)haslo2;
				if (a + 1 != 49)
				{
					a++;
				}
				// cout << haslo2 << endl;
			}
		}
	}
	for (int i = 0; i < haslod.length(); i++)
	{
		if (haslod[i] == 'X' && haslod[i + 1] == 'X' && haslod[i + 2] == 'X')
			break;
		cout << haslod[i];
		}
	cout << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	WD();
	// DTD();
	Z41();
	Z42();
	Z43();
	Z44();
	return 0;
}
