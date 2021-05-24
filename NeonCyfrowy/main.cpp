#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>

#define VD 2000 //!ilosc instrukcji (przyklad.txt=20;instrukcje.txt=2000)

using namespace std;

vector<vector<string>> INSTRUKCJE(VD, vector<string>(2)); //!vector instrukcji

string napis;

void IRS() //!wczytuje instrukcje
{
  ifstream we("instrukcje.txt");
  //ifstream we("przyklad.txt");
  for (int a = 0; a < VD; a++)
  {
    for (int i = 0; i < 2; i++)
    {
      we >> INSTRUKCJE[a][i];
    }
  }
  we.close();
}

void LOT() //!4.1 dlugosc napisu
{
  int licznik = 0;
  for (int a = 0; a < VD; a++)
  {
    if (INSTRUKCJE[a][0] == "DOPISZ")
      licznik++;
    if (INSTRUKCJE[a][0] == "USUN")
      licznik--;
  }
  cout << "=============================4.1=============================" << endl;
  cout << licznik << endl;
  cout << endl;
}

void NCI() //!4.2 najdluzszy ciag instrukcji
{
  int licznik = 0;
  int najlicz = 0;
  string najins = "";
  for (int a = 0; a < VD - 1; a++)
  {
    if (INSTRUKCJE[a][0] == INSTRUKCJE[a + 1][0])
      licznik++;
    if (licznik + 1 > najlicz)
    {
      najlicz = licznik + 1;
      najins = INSTRUKCJE[a][0];
    }
    if (INSTRUKCJE[a][0] != INSTRUKCJE[a + 1][0])
      licznik = 0;
  }
  cout << "=============================4.2=============================" << endl;
  cout << najins << endl;
  cout << najlicz << endl;
  cout << endl;
}

void NWLD() //!4.3 najczestsza litera
{
  int najlit = 0;
  string najlitlit = "";
  map<string, int> litery;
  for (auto l : INSTRUKCJE)
  {
    if (l[0] == "DOPISZ")
      litery[l[1]]++;
  }
  for (auto k : litery)
    if (k.second > najlit)
    {
      najlit = k.second;
      najlitlit = k.first;
    }
  cout << "=============================4.3=============================" << endl;
  cout << najlitlit << endl;
  cout << najlit << endl;
  cout << endl;
}
//!============================4.4 drukowanie napisu============================
void DOPISZ(string a) //!dopisywanie
{
  napis += a;
}

void ZAMIEN(string a) //!zamiana
{
  napis.back() = a[0];
}

void USUN() //!usuwanie
{
  napis.erase(napis.length() - 1);
}

void PRZESUN(string a) //!przesuwanie
{
  int NL = napis.length();
  for (int b = 0; b < NL; b++)
  {
    if (napis[b] == a[0])
    {
      if (napis[b] != 'Z')
      {
        napis[b] = napis[b] + 1;
        break;
      }
      if (napis[b] == 'Z')
      {
        napis[b] = 'A';
        break;
      }
    }
  }
}

void WI()
{
  for (int x = 0; x < VD; x++)
  {
    if (INSTRUKCJE[x][0] == "DOPISZ")
      DOPISZ(INSTRUKCJE[x][1]);
    if (INSTRUKCJE[x][0] == "ZMIEN")
      ZAMIEN(INSTRUKCJE[x][1]);
    if (INSTRUKCJE[x][0] == "USUN")
      USUN();
    if (INSTRUKCJE[x][0] == "PRZESUN")
      PRZESUN(INSTRUKCJE[x][1]);
  }
  cout << "=============================4.3=============================" << endl;
  cout << napis << endl;
  cout << endl;
}

int main()
{
  system("CLS");
  IRS();
  LOT();
  NCI();
  NWLD();
  WI();
  return 0;
}