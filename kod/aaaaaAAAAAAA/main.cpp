#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

float xpp = 0;
float ypp = 0;
float xpk = 0;
float ypk = 0;
float xdp = 0;
float ydp = 0;
float xdk = 0;
float ydk = 0;
float ap = 0;
float bp = 0;
float ad = 0;
float bd = 0;
float xt = 0;
float xtt = 0;

void ZNRP() //!zamiana_na_rownanie_prostej
{
	cin >> xpp;
	cin >> ypp;
	cin >> xpk;
	cin >> ypk;
	cin >> xdp;
	cin >> ydp;
	cin >> xdk;
	cin >> ydk;
	ap = (ypp - ypk) / (xpp - xpk);
	bp = -ap * xpp + ypp;
	cout << "y=" << ap << "x"
		 << "+" << bp << endl;
	cout << endl;
	ad = (ydp - ydk) / (xdp - xdk);
	bd = -ad * xdp + ydp;
	cout << "y=" << ad << "x"
		 << "+" << bd << endl;
}

void SCLSP() //!sprawdzanie_czy_linie_sie_przetna
{
	if (ap * xdp + bp >= ydp)
	{
		xt = xt + 1;
	}
	else
	{
		xt = xt - 1;
	}
	if (ap * xdk + bp > ydk)
	{
		xt = xt + 1;
	}
	else
	{
		xt = xt - 1;
	}
	if (ad * xpp + bd >= ypp)
	{
		xtt = xtt + 1;
	}
	else
	{
		xtt = xtt - 1;
	}
	if (ad * xpk + bd > ypk)
	{
		xtt = xtt + 1;
	}
	else
	{
		xtt = xtt - 1;
	}
	if (xtt == 0 && xt == 0)
	{
		cout << "PRZETNO SIE" << endl;
	}
	else
	{
		cout << "NIE PRZETNO SIE" << endl;
	}
}

int main(int argc, char *argv[])
{
	ZNRP();
	SCLSP();
	cout << " CHUJ CIE BOLI STACHULA " << endl;

	return 0;
}
