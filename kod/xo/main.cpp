#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;
int pgox[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //!plansza gry ox
int wpz = 0;							   //!wybor pozycji znaku
int ag = 1;								   //!aktualny gracz

void wpg() //!wyswietla plansze gry
{

	for (int i = 1; i < 10; i++)
	{
		if (pgox[i - 1] == 0)
			cout << "  ";
		if (pgox[i - 1] == 1)
			cout << "x ";
		if (pgox[i - 1] == -1)
			cout << "o ";
		if (i % 3 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void zpz() //!zapelnianie planszy znakami
{
	for (;;)
	{
		system("cls");
		wpg();
		cin >> wpz;
		if (wpz > 8 or pgox[wpz] != 0)
			cout << "NIE MOZNA TAK" << endl;
		else
		{
			pgox[wpz] = ag;
			ag = -ag;
		}
	}
}

void scw()
{
	if (pgox[0] ==)
}

int main()
{
	system("cls");
	zpz();
	return 0;
}
