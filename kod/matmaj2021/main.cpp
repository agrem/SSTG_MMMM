#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int liczb = 0;
vector<int> liczbw;

void dc()
{
	int i = 0;
	int g = 1;
	int liczbaw = 0;
	cin >> liczb;
	while (liczb != 0)
	{
		liczbw.push_back(9 - liczb % 10);
		liczb = liczb / 10;
		i++;
	}
	for (int a = i - 1; a >= 0; a--)
	{
		cout << liczbw[a];
		liczbaw += liczbw[a] * g;
		g *= 10;
	}
	cout << endl;
	cout << liczbaw << endl;
}

int main(int argc, char *argv[])
{
	system("CLS");
	dc();
	return 0;
}
