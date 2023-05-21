#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

string napis;
int ilosci[26];
int naj = 0;

void DN() //!dzielenie_napisu
{
	getline(cin, napis);
	system("CLS");
	for (int i = 0; i < napis.length(); i++)
	{
		for (int a = 0; a <= 25; a++)
		{
			if ((int)napis[i] == a + 65)
			{
				ilosci[a]++;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (ilosci[i] > naj)
			naj = ilosci[i];
	}
}

void DW()
{
	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
	cout << "___________________________________________________" << endl;
	cout << endl;
	int g = naj;
	for (int a = 0; a < naj; a++)
	{
		for (int i = 0; i < 26; i++)
		{
			if (ilosci[i] - g < 0)
			{
				cout << "  ";
			}
			if (ilosci[i] - g >= 0)
			{
				cout << "* ";
				ilosci[i]--;
			}
		}
		cout << endl;
		g--;
	}
	cout << "___________________________________________________" << endl;
	cout << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	DN();
	DW();
	return 0;
}
