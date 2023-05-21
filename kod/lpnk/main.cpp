#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string pliki[579807];

void cdir() //!czytanie dira
{
	system("dir /s /-C /OS C:\\ > test.txt"); //!C:\\ napisz to potem tu
}

void optdir()
{
	ifstream wep("test.txt");
	for (int a = 0; a < 579807; a++)
	{
		string g = "";
		getline(wep, g);
		if (g.find("Directory") == string::npos and g.find(":") != string::npos)
			if (g.find("<DIR>") == string::npos)
				pliki[a] = g;
	}
	wep.close();
}

int main()
{
	//cdir();
	optdir();
	for (int i = 0; i < 579807; i++)
		if (pliki[i][34] == '0' && pliki[i][33] == ' ')
			cout << pliki[i] << endl;
}
