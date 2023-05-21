#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string rownanie = "";
int stan = 0;
int alarm = 0;

void wr() //!wpisywanie równania
{
	cout << "WPISZ ROWNANIE" << endl;
	getline(cin, rownanie);
	system("CLS");
}

void spn() //!sprawdzanie prawidłowości nawiasów
{
	wr();
	int a = rownanie.length();
	for (int i = 0; i < a; i++)
	{
		if (rownanie[i] == '(')
			stan++;
		if (rownanie[i] == ')')
			stan--;
		if (stan < 0)
		{
			alarm = 1;
			break;
		}
	}
	if (stan > 0)
	{
		alarm = 1;
	}
	if (alarm == 1)
		cout << "DUPAAAA CHCIALES MNIE OSZUKC ZAWIASY SIE NIE ZGADZAJA SZCZYLU" << endl;
	if (alarm == 0)
		cout << "MASZ SZCZESCIE ZGADZA SIE" << endl;
}

void znk() //!zamiana na kalkulator
{
}

int main()
{
	system("CLS");
	spn();
	if (alarm == 0)
	{
		znk();
	}
	system("CLS");
	cout<<"JESLI TU SIE ZALOGOWALES TO WYCHODZ"
	return 0;
}
