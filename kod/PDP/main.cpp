#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

float xpp = 0; //!x poczatku pierwszej
float ypp = 0; //!y poczatku pierwszej
float xkp = 0; //!x konca pierwszej
float ykp = 0; //!y konca pierwszej
float xpd = 0; //!x poczatku drugiej
float ypd = 0; //!y poczatku drugiej
float xkd = 0; //!x konca drugiej
float ykd = 0; //!y konca drugiej
float ap = 0;  //!a pierwszej
float ad = 0;  //!a drugiej
float bp = 0;  //!b pierwszej
float bd = 0;  //!b drugiej
float wynik1 = 0;
float wynik2 = 0;
float wynik3 = 0;
float wynik4 = 0;

void cdpsp()
{
	cout << "PODAJ X POCZATKU PIERWSZEJ" << endl;
	cin >> xpp;
	cout << "PODAJ Y POCZATKU PIERWSZEJ" << endl;
	cin >> ypp;
	cout << "PODAJ X KONCA PIERWSZEJ" << endl;
	cin >> xkp;
	cout << "PODAJ Y KONCA PIERWSZEJ" << endl;
	cin >> ykp;
	cout << "PODAJ X POCZATKU DRUGIEJ" << endl;
	cin >> xpd;
	cout << "PODAJ Y POCZATKU DRUGIEJ" << endl;
	cin >> ypd;
	cout << "PODAJ X KONCA DRUGIEJ" << endl;
	cin >> xkd;
	cout << "PODAJ Y KONCA DRUGIEJ" << endl;
	cin >> ykd;
	ap = (ypp - ykp) / (xpp - xkp);
	ad = (ypd - ykd) / (xpd - xkd);
	ap = abs(ap);
	ad = abs(ad);
	bp = ypp - (ap * xpp);
	bd = ypd - (ad * xpd);
	wynik1 = ap * xpd + bp;
	wynik2 = ap * xkd + bp;
	wynik3 = ad * xpp + bd;
	wynik4 = ad * xkp + bd;
	if (wynik1 < ypp && wynik2 < ykp)
	{
		cout << "NIE PRZECINA SIE" << endl;
	}
	if(wynik1<ypp && wynik2>ykp)
	{
		if(wynik3<ypd && wynik4>ykd)
		{
			
		}
	}
}
int main()
{
	system("CLS");
	cdpsp();
	return 0;
}
