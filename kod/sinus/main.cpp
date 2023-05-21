#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

void rys()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	for (float i = 0; i > -1; i += 0.08)
	{
		int g = 15 * sin(i) + 0.5;
		int h = 15 * -sin(i) + 0.5;
		for (float a = 0; a < g + 50; a += 0.6)
		{
			cout << " ";
		}
		SetConsoleTextAttribute(hConsole, 2);
		cout << "_*_" << endl;
		for (float a = 0; a < h + 50; a += 0.6)
		{
			cout << " ";
		}
		SetConsoleTextAttribute(hConsole, 4);
		cout << "_*_" << endl;
		std::this_thread::sleep_for(2ms);
	}
}

int main()
{
	rys();
	return 0;
}
