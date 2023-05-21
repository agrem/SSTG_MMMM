#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

float podst = 0;
int wysa = 0;
int wys = 0;
int polp = 0;

void rtnk() //!rysowanie trojkata na konsoli
{
	cin >> podst;
	wysa = podst;
	wys = 2 * podst;
}

int main()
{
	system("CLS");
	rtnk();
	return 0;
}
