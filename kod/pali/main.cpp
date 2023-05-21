#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string alf = "qwertyuiopasdfghjklzxcvbnm";
string scp = "";   //!string_czy_palindrom
string scpsl = ""; //!string_czy_powtorzyla_sie_litera
string sjln = "";  //!string_jakiej_litery_niema

void ALF() //!sortuje_alfabet
{
	sort(alf.begin(), alf.end());
}

void cp() //!czy_palindrom
{
	string p = "";
	cin >> scp;
	for (int i = scp.length() - 1; i >= 0; i--)
	{
		p.push_back(scp[i]);
	}
	if (scp == p)
		cout << "JEST PALINODROM" << endl;
	else
		cout << "NIE JEST PALINDROM" << endl;
}

void cpsl() //!czy_powtorzyla_sie_litera
{
	int b = 0;
	cin >> scpsl;
	for (int i = 0; i < scpsl.length(); i++)
	{
		for (int h = i + 1; h < scpsl.length(); h++)
			if (scpsl[i] == scpsl[h])
			{
				b = 1;
				break;
			}
	}
	if (b == 1)
		cout << "POWTORZYLO SIE" << endl;
	else
		cout << "NIE POWTORZYLO" << endl;
}

void jln() //!jakiej_litery_niema
{
	cin >> sjln;
	for (int i = 0; i < sjln.length(); i++)
		for (int h = 0; h < alf.length(); h++)
		{
			if (sjln[i] == alf[h])
				alf[h] = '*';
		}
	for (int i = 0; i < alf.length(); i++)
		if (alf[i] != '*')
			cout << alf[i];
	cout << endl;
}

int main()
{
	ALF();
	system("CLS");
	cout << "CZY PALINDROM" << endl;
	cp();
	cout << "CZY LITERA SIE POWTORZYLA" << endl;
	cpsl();
	cout << "JAKA LITERA NIE WYSTAPILA" << endl;
	jln();
	return 0;
}
