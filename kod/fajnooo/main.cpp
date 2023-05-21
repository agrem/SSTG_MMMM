#include <iterator>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;
char bufor[5000000];
void wpb()
{
	FILE *we;
	we = fopen("stuka.jpg", "rb");
	fread(bufor, sizeof(bufor), 1, we);

	FILE *wy;
	wy = fopen("stukat.jpg", "wb");
	fwrite(bufor, sizeof(bufor), 1, wy);
}

int main()
{
	wpb();
	return 0;
}