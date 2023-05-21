#include <iostream>

using namespace std;

unsigned int wl = 5;
unsigned int wlk = wl;
unsigned int poi = 1;
unsigned int kon = 1;
int y = 0;

void CLBP() //!czy_liczba_binarnie_jest_palindromem
{
	poi = poi << 31;
	while (!!(wl & poi) == 0)
	{
		poi = poi >> 1;
	}
	poi = poi << 1;
	while (poi > kon)
	{
		if ((wl & poi) != (wl & kon))
			cout << "NP" << endl;
		poi = poi >> 1;
		kon = kon << 1;
	}
}

int main()
{
	system("CLS");
	CLBP();
	cout << endl;
	return 0;
}
