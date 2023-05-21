#include <stdio.h>
#include <time.h>
#include <ctime>
#include <stdint.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <ostream>

using namespace std;

int main(void)
{
	time_t now;
	time(&now);

	struct tm beg;

	beg = *localtime(&now);

	beg.tm_hour = 0;
	beg.tm_min = 0;
	beg.tm_sec = 0;
	beg.tm_mday = 1;
	beg.tm_mon = 10;
	beg.tm_year = 20;

	double seconds = difftime(now, mktime(&beg));

	cout << seconds << endl;
}