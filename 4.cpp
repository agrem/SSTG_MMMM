#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct telefon
{
  string numer = "";
  string data = "";
  string kom_sta = "";
};

vector<telefon> telefony(2148);

map<string, int> telefonyy;

void wczytywanie()
{
  ifstream we("telefony.txt");
  string a = "";
  getline(we, a);
  for (auto &k : telefony)
  {
    we >> k.numer >> k.data;
    getline(we, a);
  }
  we.close();
}

void pol()
{
  for (auto k : telefony)
    telefonyy[k.numer]++;
}

void najpol()
{
  int naj_p = 0;
  string tel_p = "";
  int naj_d = 0;
  string tel_d = "";
  int naj_t = 0;
  string tel_t = "";
  for (auto s : telefonyy)
  {
    if (s.second > naj_p)
    {
      naj_p = s.second;
      tel_p = s.first;
    }
  }
  for (auto g : telefonyy)
  {
    if (g.second > naj_d && g.second != naj_p)
    {
      naj_d = g.second;
      tel_d = g.first;
    }
  }
  for (auto h : telefonyy)
  {
    if (h.second > naj_t && h.second != naj_p && h.second != naj_d)
    {
      naj_t = h.second;
      tel_t = h.first;
    }
  }
  cout << "=======================5.1=======================" << endl;
  cout << naj_p << "   " << tel_p << endl;
  cout << naj_d << "   " << tel_d << endl;
  cout << naj_t << "   " << tel_t << endl;
}

void polaczenia()
{
  for (auto &f : telefony)
  {
    if (f.numer.length() == 8)
      f.kom_sta = "komorkowy";
    if (f.numer.length() == 7)
      f.kom_sta = "stacjonarny";
  }
  map<string, int> KOM_STA;
  for (auto h : telefony)
  {
    if (h.kom_sta != "")
      KOM_STA[h.kom_sta]++;
  }
  map<string, int> polaczeniastac;
  for (auto g : telefony)
  {
    if (g.kom_sta == "stacjonarny")
      polaczeniastac[g.data]++;
  }
  map<string, int> polaczeniakom;
  for (auto g : telefony)
  {
    if (g.kom_sta == "komorkowy")
      polaczeniakom[g.data]++;
  }
  cout << "=======================5.2=======================" << endl;
  cout << "=======================KOMORKOWE=======================" << endl;
  for (auto x : polaczeniakom)
  {
    cout << x.first << "   " << x.second << endl;
  }
  cout << "=======================STACJONARNE=======================" << endl;
  for (auto x : polaczeniastac)
  {
    cout << x.first << "   " << x.second << endl;
  }
}

void drukuj()
{
  for (auto x : telefony)
    cout << x.numer.length() << endl;
}

int main()
{
  wczytywanie();
  pol();
  najpol();
  polaczenia();
  //drukuj();
  cout << endl;
  return 0;
}
