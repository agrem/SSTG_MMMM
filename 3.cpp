#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

vector<vector<int>> PUNKTY(1000, vector<int>(2)); //!VECTOR

void WPDP() //!WCZYTYWANIE
{
  ifstream in("punkty.txt");
  for (int a = 0; a < 1000; a++)
    for (int i = 0; i < 2; i++)
      in >> PUNKTY[a][i];
}

void IPM() //!CZY PIERWSZA
{
  int PT = 0;
  int VC = 0;
  for (int i = 0; i < 1000; i++)
  {
    PT = 0;
    for (int o = 2; o < PUNKTY[i][0]; o++)
    {
      if (PUNKTY[i][0] % o == 0)
        break;
      if (o == PUNKTY[i][0] - 1)
        PT++;
    }
    for (int o = 2; o < PUNKTY[i][1]; o++)
    {
      if (PUNKTY[i][1] % o == 0)
        break;
      if (o == PUNKTY[i][1] - 1)
        PT++;
    }
    if (PT == 2)
      VC++;
  }
  cout << "===========================4.1===========================" << endl;
  cout << VC << endl;
}

void CP() //!CYFRY PODOBNE
{
  int CM = 0;
  for (int i = 0; i < 1000; i++)
  {
    map<int, int> MA, MB;
    for (auto a : to_string(PUNKTY[i][0]))
      MA[a] = 0;
    for (auto a : to_string(PUNKTY[i][1]))
      MB[a] = 0;
    if (MA == MB)
      CM++;
  }
  cout << "===========================4.2===========================" << endl;
  cout << CM << endl;
}

void NDP() //!NAJDALESZ PUNKTY 4.3
{
  float NP = 0;
  int xa = 0;
  int xb = 0;
  int ya = 0;
  int yb = 0;
  for (int a = 0; a < 1000; a++)
    for (int u = 0; u < 1000; u++)
    {
      int WTLX = (PUNKTY[u][0] - PUNKTY[a][0]);
      int WTLY = (PUNKTY[u][1] - PUNKTY[a][1]);
      int WTLXP = WTLX * WTLX;
      int WTLYP = WTLY * WTLY;
      int RWTLXY = sqrt((float)WTLXP + WTLYP);
      if (RWTLXY > NP)
      {
        NP = round(RWTLXY);
        xa = PUNKTY[a][0];
        xb = PUNKTY[u][0];
        ya = PUNKTY[a][1];
        yb = PUNKTY[u][1];
      }
    }
  cout << "===========================4.3===========================" << endl;
  cout << "WSPOLRZEDNE PIERWSZEGO PUNKTU[x,y]: " << xa << " , " << ya << endl;
  cout << "WSPOLRZEDNE DRUGIEGO PUNKTU[x,y]: " << xb << " , " << yb << endl;
  cout << "ODLEGLOSC PUNKTOW: " << NP << endl;
}

void NKW() //!WEWNATRZ KWADRATU 4.4
{
  int CNKW = 0;
  for (int i = 0; i < 1000; i++)
    if (PUNKTY[i][0] < 5000 && PUNKTY[i][1] < 5000)
      CNKW++;
  cout << "===========================4.4===========================" << endl;
  cout << "WEWNATRZ KWADRATU: ";
  cout << CNKW << endl;
}
void NKZ() //!ZEWNATRZ KWADRATU 4.4
{
  int CNKZ = 0;
  for (int i = 0; i < 1000; i++)
    if (PUNKTY[i][0] > 5000 || PUNKTY[i][1] > 5000)
      CNKZ++;
  cout << "ZEWNATRZ KWADRATU: ";
  cout << CNKZ << endl;
}
void NKB() //!NA BOKU KWADRATU 4.4
{
  int CNKB = 0;
  for (int i = 0; i < 1000; i++)
    if (PUNKTY[i][0] == 5000 or PUNKTY[i][1] == 5000)
      CNKB++;
  cout << "NA BOKU KWADRATU: ";
  cout << CNKB << endl;
}

void PV() //!DRUKUJE VECTORA
{
  for (int i = 0; i < 1000; i++)
  {
    for (int a = 0; a < 2; a++)
      cout << PUNKTY[i][a] << "  ";
    cout << endl;
  }
}

int main()
{
  WPDP();
  IPM();
  CP();
  NDP();
  NKW();
  NKZ();
  NKB();
  //PV();
  return 0;
}