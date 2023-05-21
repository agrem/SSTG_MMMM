#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<int> VTL;
vector<int> VPL;

vector<int> VL;

void WLDV3()
{
	int pom = 0;
	ifstream wv("liczby.txt"); //! liczby.txt    przyklad.txt     dlugosc 200
	while (!wv.eof())
	{
		wv >> pom;
		VL.push_back(pom);
	}
	sort(VL.begin(), VL.end());
}

int licznik = 0;
void SD3()
{
	for (int i = 0; i < 200; i++)
	{
		for (int a = i + 1; a < 200; a++)
		{
			if (VL[a] % VL[i] == 0 && VL[a] > VL[i])
			{
				for (int b = a + 1; b < 200; b++)
				{
					if (VL[b] % VL[a] == 0 && VL[b] > VL[a])
					{
						VTL.push_back(VL[i]);
						VTL.push_back(VL[a]);
						VTL.push_back(VL[b]);
						licznik += 3;
					}
				}
			}
		}
	}
}

int licznikp = 0;
void SD5()
{
	for (int i = 0; i < 200; i++)
	{
		for (int a = i + 1; a < 200; a++)
		{
			if (VL[a] % VL[i] == 0 && VL[a] > VL[i])
			{
				for (int b = a + 1; b < 200; b++)
				{
					if (VL[b] % VL[a] == 0 && VL[b] > VL[a])
					{
						for (int c = b + 1; c < 200; c++)
						{
							if (VL[c] % VL[b] == 0 && VL[c] > VL[b])
							{
								for (int d = c + 1; d < 200; d++)
								{
									if (VL[d] % VL[c] == 0 && VL[d] > VL[c])
									{
										VPL.push_back(VL[i]);
										VPL.push_back(VL[a]);
										VPL.push_back(VL[b]);
										VPL.push_back(VL[c]);
										VPL.push_back(VL[d]);
										licznikp += 5;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void DVPL()
{
	for (int i = 0; i < licznikp; i += 5)
	{
		cout << VPL[i] << " " << VPL[i + 1] << " " << VPL[i + 2] << " " << VPL[i + 3] << " " << VPL[i + 4] << endl;
	}
}

void DVTL()
{
	for (int i = 0; i < licznik; i += 3)
	{
		cout << VTL[i] << " " << VTL[i + 1] << " " << VTL[i + 2] << endl;
	}
}

int main()
{
	system("CLS");
	WLDV3();
	SD3();
	DVTL();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SD5();
	DVPL();
	cin.get();
	return 0;
}
