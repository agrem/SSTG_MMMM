#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;
void CP(int a) //*CZY PIERWSZA
{
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
			break;
		if (i == a - 1)
			cout << a << " ";
	}
}
void PTLP() //*PIERWSZE 1000 LICZB PIERWSZYCH
{
	cout << "2 ";
	for (int i = 2; i < 10000; i++)
		CP(i);
}

int main()
{
	cout << endl;
	cout << endl;
	PTLP();
	cout << endl;
	cout << endl;
	cout << "sTo lAT!" << endl;
	return 0;
}
