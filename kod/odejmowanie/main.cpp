#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string pier = "";
string drug = "";

void OKDL() //! odejmowanie_kurewsko_duzych_liczb
{
	cin >> pier;
	cin >> drug;
	if (pier.length() > drug.length())
	{
		for (int i = 0; i < pier.length() - drug.length() + 1; i++)
		{
			drug = '0' + drug;
		}
	}
	if (pier.length() < drug.length())
	{
		for (int i = 0; i < drug.length() - pier.length() + 1; i++)
		{
			pier = '0' + pier;
		}
	}
	cout << pier << endl;
	cout << drug << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	OKDL();
	return 0;
}
