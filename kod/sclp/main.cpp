#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

long long int liczba = 0;
long long int suma = 0;

void sc() //!suma_cyfr
{
	cin >> liczba;
	while (liczba != 0)
	{
		suma += liczba % 10;
		liczba = liczba / 10;
	}
	cout << suma << endl;
}

int main()
{
	sc();
	return 0;
}
