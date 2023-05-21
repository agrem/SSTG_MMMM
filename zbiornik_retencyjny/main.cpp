#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<string> dane;
vector<int> daneint;

int len = 0;

void WPZKM()
{
	string pom = "";
	int pomint = 0;
	ifstream IMP("woda.txt");
	while (!IMP.eof())
	{
		IMP >> pom;
		IMP >> pomint;
		dane.push_back(pom);
		daneint.push_back(pomint);
		len++;
	}
}

void DTKSN()
{
	for (int i = 0; i < len; i++)
	{
		cout << dane[i] << " " << daneint[i] << endl;
	}
}

void NCJKJP()
{
	for (int i = 0; i < len; i++)
	{
		if ()
	}
}

int main()
{
	system("CLS");
	WPZKM();
	// DTKSN();
	return 0;
}
