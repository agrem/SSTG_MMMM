#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct galerie
{
  string kraj = "";
  string miasto = "";
  int liczby[70];
  int powierzchnia = 0;
  int liczba_lokali = 0;
};

struct min_max
{
  string miasto = "";
  int powierzchnia = 0;
};

struct MIN_MAX_2
{
  string miasto = "";
  int ilosc_rodzajow_lokalu = 0;
  int ilosc_lokali = 0;
};

vector<galerie> GALERIE(50);

void wczytywanie() //wczytywanie wszystkiego do vectora
{
  ifstream we("galerie.txt");
  for (auto &k : GALERIE)
  {
    we >> k.kraj >> k.miasto;
    for (int i = 0; i < 70; i++)
    {
      int a = 0, b = 0;
      we >> a >> b;
      k.liczby[i] = a * b;
    }
  }
  we.close();
}

void powierzchnie() //liczenie powierzchni calkowitej galerii
{
  for (auto &k : GALERIE)
    for (int i = 0; i < 70; i++)
    {
      if (k.liczby[i] != 0)
        k.liczba_lokali++;
      k.powierzchnia += k.liczby[i];
    }
}

void max_min() //maksymalna i minimalna powierzchnia calkowita gelerii
{
  min_max maks;
  min_max mini;
  mini.powierzchnia = 100000;
  for (auto k : GALERIE)
  {
    if (k.powierzchnia > maks.powierzchnia)
    {
      maks.powierzchnia = k.powierzchnia;
      maks.miasto = k.miasto;
    }
    if (k.powierzchnia < mini.powierzchnia)
    {
      mini.powierzchnia = k.powierzchnia;
      mini.miasto = k.miasto;
    }
  }
  cout << maks.miasto << "   " << maks.powierzchnia << "   " << mini.miasto << "   " << mini.powierzchnia << endl;
}

void drukuj() //drukowanie
{
  for (auto x : GALERIE)
  {
    cout << x.miasto << "   ";
    cout << x.powierzchnia << "   " << x.liczba_lokali << endl;
  }
}

void liczensko() //ilosc galerii w panstwach
{
  map<string, int> galeriee;
  for (auto l : GALERIE)
    galeriee[l.kraj]++;
  for (auto k : galeriee)
    cout << k.first << "   " << k.second << endl;
}

void lokale_max()
{
  int licznik = 0;
  MIN_MAX_2 lokalee;
  for (auto l : GALERIE)
  {
    map<int, int> lokale;
    licznik = 0;
    for (int i = 0; i < 70; i++)
      lokale[l.liczby[i]]++;
    for (auto x : lokale)
    {
      if (x.first != 0 && x.second != 0)
      {
        //cout << l.miasto << "   " << x.first << "    " << x.second << "   " << licznik << endl;
        licznik++;
      }
    }
    if (licznik > lokalee.ilosc_rodzajow_lokalu)
    {
      lokalee.ilosc_rodzajow_lokalu = licznik;
      lokalee.miasto = l.miasto;
    }
  }
  cout << lokalee.miasto << "   " << lokalee.ilosc_rodzajow_lokalu << endl;
}

void lokale_min()
{
  int licznik = 0;
  MIN_MAX_2 lokaleee;
  lokaleee.ilosc_rodzajow_lokalu = 100000;
  for (auto l : GALERIE)
  {
    map<int, int> lokale;
    licznik = 0;
    for (int i = 0; i < 70; i++)
      lokale[l.liczby[i]]++;
    for (auto x : lokale)
    {
      if (x.first != 0 && x.second != 0)
      {
        //cout << l.miasto << "   " << x.first << "    " << licznik << endl;
        licznik++;
      }
    }
    if (licznik < lokaleee.ilosc_rodzajow_lokalu)
    {
      lokaleee.ilosc_rodzajow_lokalu = licznik;
      lokaleee.miasto = l.miasto;
    }
  }
  cout << lokaleee.miasto << "   " << lokaleee.ilosc_rodzajow_lokalu << endl;
}

int main()
{
  wczytywanie();
  cout << "==================PKT 4.1==================" << endl;
  liczensko();
  cout << endl;
  cout << "==================PKT 4.2 A==================" << endl;
  powierzchnie();
  drukuj();
  cout << endl;
  cout << "==================PKT 4.2 B==================" << endl;
  max_min();
  cout << endl;
  cout << "==================PKT 4.3==================" << endl;
  lokale_max();
  lokale_min();
  return 0;
}
