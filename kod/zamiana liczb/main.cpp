#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string liczba = "";
int dlugoscl = 0;
int pot = 1;
int liczbad = 0;

void z7n10() //!zamiana z 7 na 10
{
	cin >> liczba;
	dlugoscl = liczba.length();
	for (int i = 0; i < liczba.length(); i++)
	{
		liczbad += stoi(liczba.substr(i, 1)) * pot;
		pot = pot * 7;
	}
	cout << liczbad;
}

int main()
{
	system("CLS");
	z7n10();
	return 0;
}
