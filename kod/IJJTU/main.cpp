#include <fstream>
#include <iostream>

using namespace std;

int IJ1(int liczba)
{
	int licznik = 0;
	while (liczba != 0)
	{
		licznik += liczba % 2;
		liczba = liczba / 2;
	}
	return licznik;
}

int IJN(string napis)
{
	int licznik = 0;
	for (int i = 0; i < napis.length(); i++)
	{
		licznik += IJ1((int)napis[i]);
	}
	return licznik;
}
int main()
{
	system("CLS");
	cout << IJ1(1) << endl;
	cout << IJN("ABC") << endl;
	return 0;
}