#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <windows.h>

using namespace std;

int PLA = 0;
int PLY = 0;

void WPN() //! WPISYWANIE_PLANSZY
{
	cout << "WPISZ PLANSZE : ";
	cin >> PLA;
	cout << "WPISZ GRACZA ZACZYNAJACEGO ( AI - 1 / HU - 0 ) : ";
	cin >> PLY;
	if (PLY == 0)
	{
		PLY = -1;
	}
	system("CLS");
}

void OGG(int PLA, int PLY) //! DRUKOWANIE_PLANSZY
{
	int PLAP = PLA;
	int PLA3 = PLAP % 10;
	PLAP = PLAP / 10;
	int PLA2 = PLAP % 10;
	PLAP = PLAP / 10;
	int PLA1 = PLAP % 10;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "           1           ";
	for (int i = 0; i < PLA1; i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << endl;
	cout << "           2           ";
	for (int i = 0; i < PLA2; i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << endl;
	cout << "           3           ";
	for (int i = 0; i < PLA3; i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "           AKTUALNY GRACZ : ";
	if (PLY == 1)
	{
		cout << "AI" << endl;
	}
	else
	{
		cout << "HU" << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}

void RC() //! czesc czlowieka
{
	int LRPLA = 0;
	int PRPLA = 0;
	int RPLA;
	cout << "           FORMAT WPISYWANIA NP. 001 ZABIERA NA MIEJSCU 3 JEDEN PATYCZEK" << endl;
	cout << "           WPISZ ILE PATYCZKOW ZABRAC : ";
	cin >> RPLA;
	PRPLA = RPLA;
	if (PRPLA % 10 != 0)
	{
		LRPLA++;
	}
	PRPLA = PRPLA / 10;
	if (PRPLA % 10 != 0)
	{
		LRPLA++;
	}
	PRPLA = PRPLA / 10;
	if (PRPLA % 10 != 0)
	{
		LRPLA++;
	}
	if (LRPLA > 1)
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "           NIE DA SIE HURR ZA DUZO LICZB DURR" << endl;
		_sleep(3000);
		for (int i = 1; i > 0; i++)
		{
			cout << "JFDBGKFJDBVKREBNFLNOLWUPO NIE ROBI SIE TAK IRUFHTRBYIVEGVNTIREGBNITV";
		}
	}
	if (RPLA <= PLA)
	{
		PLA = PLA - RPLA;
	}
	else
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "           NIE DA SIE HURR ZA DUZO LICZB DURR" << endl;
		_sleep(3000);
		for (int i = 1; i > 0; i++)
		{
			cout << "JFDBGKFJDBVKREBNFLNOLWUPO NIE ROBI SIE TAK IRUFHTRBYIVEGVNTIREGBNITV";
		}
	}
}

int WSK = 0;

void CKP()
{
	if (PLA == 0)
	{
		WSK = 1;
	}
}

int main()
{
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
	system("CLS");
	WPN();
	while (WSK == 0)
	{
		system("CLS");
		OGG(PLA, PLY);
		RC();
		PLY = -PLY;
		if (PLY == 1)
			SetConsoleTextAttribute(console_color, 0x416);
		else
			SetConsoleTextAttribute(
				console_color, 0x116);
	}
	return 0;
}
