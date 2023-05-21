#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string samo = "aeouiy";
string SAMO = "AEOUIY";
string slowo = "";

void us()
{
	getline(cin, slowo);
	for (int i = 0; i < slowo.length(); i++)
	{
		for (int a = 0; a < 6; a++)
		{
			if (slowo[i] == samo[a] or slowo[i] == SAMO[a])
				slowo[i] = '*';
		}
	}
	cout << slowo << endl;
}

int main()
{
	system("CLS");
	us();
	return 0;
}
