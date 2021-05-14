#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> liczby_a(1000, vector<int>(10));
vector<vector<int>> liczby_b(1000, vector<int>(10));
vector<vector<int>> liczby_a_2(1000, vector<int>(10));
vector<vector<int>> liczby_b_2(1000, vector<int>(10));
vector<vector<int>> liczby_scalone(1000, vector<int>(20));

void wczyt_liczby_a()
{
  string n = "";
  string ni = "";
  ifstream we("dane1.txt");
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      we >> liczby_a[a][i];
    }
  }
  we.close();
}

void wczyt_liczby_b()
{
  string n = "";
  string ni = "";
  ifstream we("dane2.txt");
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      we >> liczby_b[a][i];
    }
  }
  we.close();
}

void wczyt_liczby_a_2()
{
  string n = "";
  string ni = "";
  ifstream we("dane1.txt");
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      we >> liczby_a_2[a][i];
    }
  }
  we.close();
}

void wczyt_liczby_b_2()
{
  string n = "";
  string ni = "";
  ifstream we("dane2.txt");
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      we >> liczby_b_2[a][i];
    }
  }
  we.close();
}

void comp() //!4.1
{
  int licznik = 0;
  for (int a = 0; a < 1000; a++)
    if (liczby_a[a][9] == liczby_b[a][9])
      licznik++;
  cout << "===========================4.1===========================" << endl;
  cout << licznik << endl;
}

void p_np() //!4.2
{
  int licznik_p_a = 0;
  int licznik_p_b = 0;
  int licznik_p_w = 0;
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      if (liczby_a[a][i] % 2 == 0)
        licznik_p_a++;
    }
    for (int i = 0; i < 10; i++)
    {
      if (liczby_b[a][i] % 2 == 0)
        licznik_p_b++;
    }
    if (licznik_p_a == licznik_p_b && licznik_p_b == 5)
      licznik_p_w++;
    licznik_p_a = 0;
    licznik_p_b = 0;
  }
  cout << "===========================4.2===========================" << endl;
  cout << licznik_p_w << endl;
}

void TSL() //!4.3
{
  int wskaz = 0;
  vector<int> wiersze(1000);
  int licznik_TSL = 0;
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
      for (int y = 0; y < 10; y++)
        if (liczby_a[a][i] == liczby_b[a][y])
        {
          liczby_b[a][y] = 0;
        }
  }
  for (int k = 0; k < 1000; k++)
  {
    wskaz = 0;
    for (int j = 0; j < 10; j++)
    {
      if (liczby_b[k][j] != 0)
      {
        wskaz = 1;
        break;
      }
    }
    if (wskaz == 0)
    {
      wiersze[licznik_TSL] = k;
      licznik_TSL++;
    }
  }
  cout << "===========================4.3===========================" << endl;
  cout << licznik_TSL << endl;
  long long o = wiersze.size();
  if (licznik_TSL != 0)
    cout << wiersze[0] + 1 << endl;
  for (int h = 1; h < o + 1; h++)
    if (wiersze[h] != 0)
      cout << wiersze[h] + 1 << endl;
}

void drukuj_a()
{
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      cout << liczby_a_2[a][i] << " ";
    }
    cout << endl;
  }
}
void drukuj_b()
{
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 10; i++)
    {
      cout << liczby_b_2[a][i] << " ";
    }
    cout << endl;
  }
}

void drukuj_scalone()
{
  for (int a = 0; a < 1000; a++)
  {
    for (int i = 0; i < 20; i++)
    {
      cout << liczby_scalone[a][i] << " ";
    }
    cout << endl;
  }
}

void MS() //!4.4
{
  int mem = 0;
  for (int i = 0; i < 1000; i++)
  {
    for (int h = 0; h < 20; h += 2)
    {
      if (h < 10)
        liczby_scalone[i][h] = liczby_a_2[i][h / 2];
      if (h >= 10)
        liczby_scalone[i][h] = liczby_a_2[i][h / 2];
    }
    for (int h = 1; h < 20; h += 2)
    {
      if (h < 10)
        liczby_scalone[i][h] = liczby_b_2[i][h / 2];
      if (h >= 10)
        liczby_scalone[i][h] = liczby_b_2[i][h / 2];
    }
  }
  for (int a = 0; a < 1000; a++)
    for (int y = 0; y < 19; y++)
    {
      if (liczby_scalone[a][y] > liczby_scalone[a][y + 1])
      {
        mem = liczby_scalone[a][y];
        liczby_scalone[a][y] = liczby_scalone[a][y + 1];
        liczby_scalone[a][y + 1] = mem;
      }
    }
}

int main()
{
  wczyt_liczby_a();
  wczyt_liczby_b();
  comp();
  p_np();
  TSL();
  wczyt_liczby_a_2();
  wczyt_liczby_b_2();
  MS();
  drukuj_scalone();
  drukuj_a();
  drukuj_b();
  return 0;
}