#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

vector<string> pesele_string(150);
vector<int> lata_urodzenia(150);
vector<string> zle_pesele;
vector<int> dekady_urodzenia(150);

void WPDVSTRING() //!wczytywanie do vectora stringow
{
  ifstream wep("pesel.txt");
  for (int a = 0; a < 150; a++)
    getline(wep, pesele_string[a]);
  wep.close();
}

void DVPSTRING() //!drukowanie vectora stringow
{
  for (int a = 0; a < 150; a++)
    cout << pesele_string[a] << endl;
}

void IOUG() //!ile osob urodzilo sie w grudniu
{
  int licznik = 0;
  for (int a = 0; a < 150; a++)
    if (pesele_string[a].substr(2, 2) == "12")
      licznik++;
  cout << "=====================================ZAD_1=====================================" << endl;
  cout << licznik << endl;
  cout << endl;
}

void IKPB() //!ile kobiet pracuje w biurze
{
  int licznik = 0;
  for (int a = 0; a < 150; a++)
    if (stoi(pesele_string[a].substr(9, 1)) % 2 == 0)
      licznik++;
  cout << "=====================================ZAD_2=====================================" << endl;
  cout << licznik << endl;
  cout << endl;
}

void RWKN() //!rok w ktorym urodzilo sie najwiecej
{
  int naj = 0;
  int najrok = 0;
  for (int a = 0; a < 150; a++)
  {
    lata_urodzenia[a] = stoi(pesele_string[a].substr(0, 2));
  }
  map<int, int> lata;
  for (auto x : lata_urodzenia)
    lata[x]++;
  for (auto j : lata)
  {
    if (j.second > naj)
    {
      naj = j.second;
      najrok = j.first;
    }
  }
  cout << "=====================================ZAD_3=====================================" << endl;
  cout << "19" << najrok << endl;
  cout << endl;
}

void OLKP() //!obliczanie liczby kontrolnej w peselu
{
  for (int a = 0; a < 150; a++)
  {
    int lk = 0;
    int a1 = stoi(pesele_string[a].substr(0, 1)) * 1;
    int a2 = stoi(pesele_string[a].substr(1, 1)) * 3;
    int a3 = stoi(pesele_string[a].substr(2, 1)) * 7;
    int a4 = stoi(pesele_string[a].substr(3, 1)) * 9;
    int a5 = stoi(pesele_string[a].substr(4, 1)) * 1;
    int a6 = stoi(pesele_string[a].substr(5, 1)) * 3;
    int a7 = stoi(pesele_string[a].substr(6, 1)) * 7;
    int a8 = stoi(pesele_string[a].substr(7, 1)) * 9;
    int a9 = stoi(pesele_string[a].substr(8, 1)) * 1;
    int ab = stoi(pesele_string[a].substr(9, 1)) * 3;
    int suma = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + ab;
    if (suma % 10 == 0)
      lk = 0;
    else
      lk = 10 - suma % 10;
    if (stoi(pesele_string[a].substr(10, 1)) != lk)
      zle_pesele.push_back(pesele_string[a]);
  }
  sort(zle_pesele.begin(), zle_pesele.end());
  cout << "=====================================ZAD_4=====================================" << endl;
  for (auto h : zle_pesele)
    cout << h << endl;
  cout << endl;
}

void WDU()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int kolor = 0;
  for (int a = 0; a < 150; a++)
  {
    dekady_urodzenia[a] = stoi(pesele_string[a].substr(0, 1));
  }
  map<int, int> dekady;
  for (auto x : dekady_urodzenia)
    dekady[x]++;
  cout << "=====================================ZAD_5=====================================" << endl;
  for (auto k : dekady)
  {
    kolor += 3;
    int procent = k.second / 1.5;
    cout << k.first << "0-te " << k.second << "   ";
    if (k.first == 9)
      cout << " ";
    for (int i = 0; i < procent; i++)
    {
      SetConsoleCP(437);
      SetConsoleOutputCP(437);
      SetConsoleTextAttribute(hConsole, kolor);
      cout << (char)178;
      SetConsoleTextAttribute(hConsole, 10);
    }
    cout << endl;
    cout << endl;
  }
}

int main()
{
  WPDVSTRING();
  //DVPSTRING();
  IOUG();
  IKPB();
  RWKN();
  OLKP();
  WDU();
  return 0;
}
