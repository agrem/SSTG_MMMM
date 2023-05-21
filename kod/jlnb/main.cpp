#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string alfabetm = "qwertyuiopasdfghjklzxcvbnm"; //!alfabet_maly
string alfabetz = "qwertyuiopasdfghjklzxcvbnm"; //!alfabet_zapasowy
string alfabetd = "QWERTYUIOPASDFGHJKLZXCVBNM"; //!alfabet_duzy
string samogloskim = "aeiouy";					//!samogloski_male
string tekst = "";								//!tekst_wpisany_z_klawiatury
string slowop = "";								//!slowo_pierwsze
string slowod = "";								//!slowo_drugie
string pl = "";									//!powtorzone_litery
int g = 0;
int y = 0;
int p = 1;
void sa() //!sortowanie_alfabetow
{
	sort(alfabetm.begin(), alfabetm.end());
	sort(alfabetd.begin(), alfabetd.end());
}
void jlnb() //!jaka_litera_nie_wystapila
{
	getline(cin, tekst);
	for (int i = 0; i < tekst.length(); i++)
		for (int a = 0; a < alfabetm.length(); a++)
		{
			if (tekst[i] == alfabetm[a] && alfabetm[a] != ' ')
				alfabetd[a] = ' ';
			if (tekst[i] == alfabetd[a] && alfabetd[a] != ' ')
				alfabetd[a] = ' ';
		}
	for (int i = 0; i < alfabetm.length(); i++)
		if (alfabetd[i] != ' ')
		{
			g++;
			cout << alfabetd[i] << " ";
		}
	if (g == 0)
		cout << "WSZYSTKIE LITERY WYSTAPILY";
	cout << endl;
}
void ls() //!liwiduj_samogloski
{
	for (int i = 0; i < tekst.length(); i++)
		for (int a = 0; a < samogloskim.length(); a++)
			if (tekst[i] == samogloskim[a])
				tekst[i] = '=';
	for (int i = 0; i < tekst.length(); i++)
		if (tekst[i] != '=')
			cout << tekst[i];
	cout << endl;
}
void jzsp() //!jakie_znaki_sie_powtarzaja
{
	getline(cin, slowop);
	getline(cin, slowod);
	for (int i = 0; i < slowop.length(); i++)
		for (int a = 0; a < slowod.length(); a++)
			if (slowop[i] == slowod[a] && slowop[i] != '=')
			{
				for (int o = 0; o < alfabetz.length(); o++)
					if (slowop[i] == alfabetz[o])
						alfabetz[o] = '=';
				for (int l = 0; l < alfabetz.length(); l++)
				{
					if (alfabetz[l] == '=')
						cout << alfabetd[l] << " ";
				}
				slowop[i] == '=';
				slowod[a] == '=';
			}
	sort(pl.begin(), pl.end());
	cout << pl << endl;
}
int main()
{
	system("CLS");
	sa();
	jlnb();
	ls();
	jzsp();
	return 0;
}
