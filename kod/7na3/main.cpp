#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
string L7 = "";
string L3 = "";
int L10L7 = 0;
int n = 7;
int nd = 3;
//string ZZ = "01234n6789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//int SWE = 0;
//int SWY = 0;
void WL7() //*WCZYTYWANIE LICZBY I WYBOR SYSTEMU
{
	//cout << "JAKI SYSTEM WEJSCIA" << endl;
	//cin >> SWE;
	cout << "LICZBA" << endl;
	cin >> L7;
	//cout << "JAKI SYSTEM WYJSCIA" << endl;
	//cin >> SWY;
}

void PL7N10() //*PRZERABIANIE LICZBY SIODEMKOWEJ NA DZIESIETNA
{
	L10L7 = (((((((stoi(L7.substr(0, 1)) * n + stoi(L7.substr(1, 1))) * n + stoi(L7.substr(2, 1))) * n + stoi(L7.substr(3, 1))) * n + stoi(L7.substr(4, 1))) * n + stoi(L7.substr(5, 1))) * n + stoi(L7.substr(6, 1))) * n + stoi(L7.substr(7, 1)) * n + stoi(L7.substr(8, 1))) * n + stoi(L7.substr(9, 1));
}

void P10N3() //*PRZERABIANIE LICZBY DZISIETNEJ NA TROJKOWA
{
	while (L10L7 > 0)
	{
		L3.push_back(L10L7 % nd);
		L10L7 = L10L7 / nd;
	}
}

int main()
{
	system("CLS");
	WL7();
	PL7N10();
	cout << L10L7 << endl;
	P10N3();
	cout << L3 << endl;
	return 0;
}
