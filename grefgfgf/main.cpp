#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

vector<float> temp;
vector<int> opady;
vector<string> chmury;

int len = 0;

void WKTG()
{
	string pomm = "";
	string pom = "";
	float pomi = 0;
	ifstream IMP("pogoda.txt");
	IMP >> pom;
	while (!IMP.eof())
	{
		getline(IMP, pom, ';');
		getline(IMP, pom, ';');
		pomi = stof(pom);
		temp.push_back(pomi);
		getline(IMP, pom, ';');
		pomi = stoi(pom);
		opady.push_back(pomi);
		getline(IMP, pom, ';');
		pomm = pom;
		getline(IMP, pom);
		pomm = pomm + pom;
		chmury.push_back(pomm);
		len++;
	}
}

void DKT()
{
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << " " << temp[i] << " " << opady[i] << " " << chmury[i] << endl;
	}
}

void PPKM()
{
	int licznik = 0;
	for (int i = 0; i < len; i++)
	{
		if (temp[i] >= 20 && opady[i] <= 5)
			licznik++;
	}
	cout << licznik << endl;
}

void ZTPKCSPPSG()
{
	float C1 = 0;
	float C2 = 0;
	float C3 = 0;
	float C4 = 0;
	float C5 = 0;
	float S1 = 0;
	float S2 = 0;
	float S3 = 0;
	float S4 = 0;
	float S5 = 0;

	int C1l = 0;
	int C2l = 0;
	int C3l = 0;
	int C4l = 0;
	int C5l = 0;
	int S1l = 0;
	int S2l = 0;
	int S3l = 0;
	int S4l = 0;
	int S5l = 0;

	for (int i = 0; i < 300; i++)
	{
		if (chmury[i] == "C1")
		{
			C1 += opady[i];
			C1l++;
		}
		if (chmury[i] == "C2")
		{
			C2 += opady[i];
			C2l++;
		}
		if (chmury[i] == "C3")
		{
			C3 += opady[i];
			C3l++;
		}
		if (chmury[i] == "C4")
		{
			C4 += opady[i];
			C4l++;
		}
		if (chmury[i] == "C5")
		{
			C5 += opady[i];
			C5l++;
		}
		if (chmury[i] == "S1")
		{
			S1 += opady[i];
			S1l++;
		}
		if (chmury[i] == "S2")
		{
			S2 += opady[i];
			S2l++;
		}
		if (chmury[i] == "S3")
		{
			S3 += opady[i];
			S3l++;
		}
		if (chmury[i] == "S4")
		{
			S4 += opady[i];
			S4l++;
		}
		if (chmury[i] == "S5")
		{
			S5 += opady[i];
			S5l++;
		}
	}
	cout << "C1  " << round((C1 / C1l) * 100.0) / 100.0 << endl;
	cout << "C2  " << round((C2 / C2l) * 100.0) / 100.0 << endl;
	cout << "C3  " << round((C3 / C3l) * 100.0) / 100.0 << endl;
	cout << "C4  " << round((C4 / C4l) * 100.0) / 100.0 << endl;
	cout << "C5  " << round((C5 / C5l) * 100.0) / 100.0 << endl;
	cout << "S1  " << round((S1 / S1l) * 100.0) / 100.0 << endl;
	cout << "S2  " << round((S2 / S2l) * 100.0) / 100.0 << endl;
	cout << "S3  " << round((S3 / S3l) * 100.0) / 100.0 << endl;
	cout << "S4  " << round((S4 / S4l) * 100.0) / 100.0 << endl;
	cout << "S5  " << round((S5 / S5l) * 100.0) / 100.0 << endl;
}

int main()
{
	system("CLS");
	WKTG();
	// DKT();
	PPKM();
	ZTPKCSPPSG();
	return 0;
}
