#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>
#include <windows.h>

using namespace std;

void DK()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int srednica = 0;
	cout << "PODAJ SREDNICE:" << endl;
	cin >> srednica;
	system("CLS");
	int promien = srednica / 2;
	for (int i = 0; i < promien; i++)
	{
		for (int a = 0; a < 2 * promien - (promien + sqrt((2 * promien - i) * i)); a++)
			cout << " ";
		SetConsoleTextAttribute(hConsole, 4);
		cout << "*";
		for (int a = 0; a <= promien - (promien - (promien + sqrt((2 * promien - i) * i))) - promien - 1; a++)
		{
			cout << "**";
		}
		cout << "*" << endl;
	}
	for (int i = promien; i >= 0; i--)
	{
		for (int a = 0; a < 2 * promien - (promien + sqrt((2 * promien - i) * i)); a++)
			cout << " ";
		cout << "*";
		for (int a = 0; a <= promien - (promien - (promien + sqrt((2 * promien - i) * i))) - promien - 1; a++)
			cout << "**";
		cout << "*" << endl;
	}
}

int main()
{
	system("CLS");
	DK();
	return 0;
}
