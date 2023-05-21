#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

float krok = 0.00001;
float EP = 0;
float OM = 0;
float AL = 1.57;
float ti = 0;
float g = 10;
float l = 2;
float deg = 0;
float wspol = 360 / 6.283185307179586476925286766559;
string kat = "";
string czas = "";
int licznik = 0;

int main()
{
	ofstream we("dane.txt");
	while (ti <= 10)
	{
		EP = (g / l) * sin(AL);
		OM = OM - EP * krok;
		AL += OM * krok;
		ti += krok;
		deg = AL * wspol;
		kat = to_string(deg);
		czas = to_string(ti);
		for (int i = 0; i < kat.length(); i++)
		{
			if (kat[i] == '.')
				kat[i] = ',';
		}
		for (int i = 0; i < czas.length(); i++)
		{
			if (czas[i] == '.')
				czas[i] = ',';
		}
		licznik++;
		if (licznik % 1000 or licznik == 0)
			we << kat << " ; " << czas << endl;
	}
	we.close();
	return 0;
}
