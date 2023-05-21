#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <windows.h>

using namespace std;

vector<string> dane;

void WADV()
{
	string pom = "";
	ifstream plik;
	plik.open("anagram.txt");
	while (!plik.eof())
	{
		plik >> pom;
		dane.push_back(pom);
	}
}

void DTV()
{
	for (auto x : dane)
	{
		cout << x << endl;
	}
}

void CDTS()
{
	cout << "                 TAKA SAMA DLUGOSC" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	int t4 = 0;
	int t5 = 0;
	for (int i = 0; i < 1000; i += 5)
	{
		t1 = dane[i].length();
		t2 = dane[i + 1].length();
		t3 = dane[i + 2].length();
		t4 = dane[i + 3].length();
		t5 = dane[i + 4].length();
		if (t1 == t2 && t1 == t3 && t1 == t4 && t1 == t5)
		{
			cout << "                 " << dane[i] << " " << dane[i + 1] << " " << dane[i + 2] << " " << dane[i + 3] << " " << dane[i + 4] << endl;
		}
	}
}

void IJAWV()
{
	cout << "                 ANAGRAMY" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	string s1 = "";
	string s2 = "";
	string s3 = "";
	string s4 = "";
	string s5 = "";
	for (int i = 0; i < 1000; i += 5)
	{
		s1 = dane[i];
		s2 = dane[i + 1];
		s3 = dane[i + 2];
		s4 = dane[i + 3];
		s5 = dane[i + 4];
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		sort(s3.begin(), s3.end());
		sort(s4.begin(), s4.end());
		sort(s5.begin(), s5.end());
		if (s1 == s2 && s1 == s3 && s1 == s4 && s1 == s5)
		{
			cout << "                 " << dane[i] << " " << dane[i + 1] << " " << dane[i + 2] << " " << dane[i + 3] << " " << dane[i + 4] << endl;
		}
	}
}

int main()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 0xD04); //! C robi kratke B robi pionowe linie A tez
	system("CLS");
	cout << endl;
	cout << endl;
	WADV();
	// DTV();
	CDTS();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	IJAWV();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cin.get();
	return 0;
}
