#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int liczby[1001];
int dlugosc = 1000;

void gl()
{
	for (int i = 1; i <= 1000; i++)
	{
		liczby[i] = i;
	}
}

void sito()
{
	for (int i = 2; i * i <= dlugosc; i++)
	{
		for (int a = 0; a <= dlugosc; a += i)
		{
			if (a != i)
			{
				liczby[a] = 0;
			}
			else
			{
			}
		}
	}
	for (int i = 0; i < 1000; i++)
		if (liczby[i] != 0)
		{
			cout << liczby[i] << endl;
		}
}

int main(int argc, char *argv[])
{
	system("CLS");
	gl();
	sito();
	return 0;
}
