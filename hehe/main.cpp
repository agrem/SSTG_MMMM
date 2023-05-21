#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void WPB()
{
	uint8_t dupa = 0;
	ifstream IMP("write.exe", ios::binary);
	ofstream EXP("test.exe", ios::binary);
	while (!IMP.eof())
	{
		IMP >> dupa;
		EXP << dupa;
	}
	IMP.close();
	EXP.close();
}

int main()
{
	system("CLS");
	WPB();
	return 0;
}
