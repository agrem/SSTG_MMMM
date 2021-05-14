#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;
int bud = 800;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int kom = 0;
int sta = 0;
int zag = 0;
int kom_po = 0;
int sta_po = 0;
int zag_po = 0;
struct telefon
{
  string numer = "";
  string data = "";
  string pocz = "";
  string kon = "";
};

struct czas
{
  int godz = 0;
  int minuta = 0;
  int sekunda = 0;
};

vector<telefon> telefony(2148);

void wczytywanie()
{
  ifstream we("telefony.txt");
  string a = "";
  getline(we, a);
  for (auto &k : telefony)
  {
    we >> k.numer >> k.data >> k.pocz >> k.kon;
  }
  we.close();
}

int min(string s)
{
  czas j;
  j.godz = stoi(s.substr(0, 2));
  j.minuta = stoi(s.substr(3, 2));
  j.sekunda = stoi(s.substr(6, 2));
  int h = 3600 * j.godz + 60 * j.minuta + j.sekunda;
  if (h % 60 != 0)
    return h / 60 + 1;
  else
    return h / 60;
}
int sek(string s)
{
  czas j;
  j.godz = stoi(s.substr(0, 2));
  j.minuta = stoi(s.substr(3, 2));
  j.sekunda = stoi(s.substr(6, 2));
  int g = 3600 * j.godz + 60 * j.minuta + j.sekunda;
  return g;
}

void odej()
{
  for (auto x : telefony)
  {
    if (bud == 0)
      break;
    if (x.numer.length() == 7)
    {
      a = min(x.kon) - min(x.pocz);
      if (a < bud)
        bud -= a;
      else
      {
        a -= bud;
        bud = 0;
        kom += b;
      }
      x.numer = "-";
      x.data = "-";
      x.pocz = "-";
      x.kon = "-";
    }
    if (x.numer.length() == 8)
    {
      b = min(x.kon) - min(x.pocz);
      if (b < bud)
        bud -= b;
      else
      {
        b -= bud;
        bud = 0;
        kom += b;
      }
      x.numer = "-";
      x.data = "-";
      x.pocz = "-";
      x.kon = "-";
    }
  }
}

void dodaj_kom_sta()
{
  for (auto x : telefony)
  {
    if (x.numer.length() == 7)
    {
      c = min(x.kon) - min(x.pocz);
      sta += c;
    }
    if (x.numer.length() == 8)
    {
      d = min(x.kon) - min(x.pocz);
      kom += d;
    }
  }
}

void dodaj_zag()
{
  for (auto x : telefony)
  {
    if (x.numer.length() >= 10)
    {
      e = sek(x.kon) - sek(x.pocz);
      zag += e;
    }
  }
}

void policz_kom_sta_zag()
{
  kom_po = kom / 100 * 6;
  sta_po = sta / 100 * 5;
  zag_po = zag / 60;
}

int main()
{
  wczytywanie();
  odej();
  dodaj_kom_sta();
  dodaj_zag();
  policz_kom_sta_zag();
  cout << "KOMORKOWE:" << kom_po << "PLN   "
       << "STACJONARNE:" << sta_po << "PLN   "
       << "ZAGRANICZNE:" << zag_po << "PLN   "
       << "ABONAMENT: 50PLN"
       << "   "
       << "CALOSC:" << kom_po + sta_po + zag_po + 50 << "PLN" << endl;
  return 0;
}
