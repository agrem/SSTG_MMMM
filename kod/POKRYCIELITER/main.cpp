#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string pier = "";
string drug = "";
int dluga = 36;
int dlugmax = 0;
string alfp = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890";
string alfd = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890";
string alfk = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890";

void ILJP()
{
	sort(alfp.begin(), alfp.end());
	sort(alfd.begin(), alfd.end());
	sort(alfk.begin(), alfk.end());
	getline(cin, pier);
	getline(cin, drug);
	sort(pier.begin(), pier.end());
	sort(drug.begin(), drug.end());
	for (int i = 0; i < pier.length(); i++)
	{
		pier[i] = toupper(pier[i]);
	}
	for (int i = 0; i < drug.length(); i++)
	{
		drug[i] = toupper(drug[i]);
	}
	for (int i = 0; i < dluga; i++)
	{
		for (int a = 0; a < pier.length(); a++)
			if (pier[a] == alfp[i])
			{
				alfp[i] = '-';
			}
	}
	for (int i = 0; i < dluga; i++)
	{
		for (int a = 0; a < pier.length(); a++)
			if (drug[a] == alfd[i])
			{
				alfd[i] = '-';
			}
	}
	for (int i = 0; i < 26; i++)
	{
		if (alfp[i] == '-' && alfd[i] == '-')
		{
			cout << alfk[i] << " ";
		}
	}
	cout << endl;
	cout << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	ILJP();
	return 0;
}